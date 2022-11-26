#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "Starfield.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void cease();

SDL_Window* gWindow         = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer     = NULL;

bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    gWindow = SDL_CreateWindow(
      "CC1 Starfield",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
    );

    if (gWindow == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      // gScreenSurface = SDL_GetWindowSurface(gWindow);

      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (gRenderer == NULL)
      {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
      }
    }
  }

  return success;
}

bool loadMedia()
{
  bool success = true;

  

  return success;
}

void cease()
{
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow   = NULL;
  gRenderer = NULL;
  SDL_Quit();
}

int main()
{
  bool quit = false;
  bool x_forward = true;
  bool y_forward = true;
  Timer* fpsTimer = CreateTimer();
  int countedFrames = 0;
  float avgFPS;

  SDL_Event e;
  Star* star1 = Star_Create();

  // Seeds the random number generator with the curent time
  srand(time(NULL));

  if (!init())
  {
    printf("Failed to initialize\n");
  }
  else
  {
    if (!loadMedia())
    {
      printf("Failed to load media\n");
    }
    else
    {
      StartTimer(fpsTimer);
      while (!quit)
      {
        while (SDL_PollEvent(&e) != 0)
        {
          if (e.type == SDL_QUIT)
            quit = true;
        }

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // SDL_Rect fillRect = {
        //   SCREEN_WIDTH / 4,
        //   SCREEN_HEIGHT / 4,
        //   SCREEN_WIDTH / 2,
        //   SCREEN_HEIGHT / 2
        // };

        // Reverses the direction of movement if the screen limit is reached
        if (star1->position[0] > SCREEN_WIDTH || star1->position[0] < 0)
          x_forward = !x_forward;
        if (star1->position[1] > SCREEN_HEIGHT || star1->position[1] < 0)
          y_forward = !y_forward;


        // Moves the circle by unit amount in direction based on bool above
        if (x_forward)
          star1->velocity[0] = 1;
        else
          star1->velocity[0] = -1;

        if (y_forward)
          star1->velocity[1] = 1;
        else
          star1->velocity[1] = -1;

        Star_Update(star1);

        // SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        // SDL_RenderFillRect(gRenderer, &fillRect);

        Star_Render(star1, gRenderer);

        SDL_RenderPresent(gRenderer);
      }
    }
  }

  cease();

  return 0;
}