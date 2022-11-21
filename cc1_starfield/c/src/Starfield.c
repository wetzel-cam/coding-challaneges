#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2_gfx/SDL2_gfxPrimitives.h>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void cease();

SDL_Window* gWindow         = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer     = NULL;

typedef struct {
  int x_pos;
  int x_offset;
  int y_pos;
  int y_offset;
  float z_factor;
  int radius;
  uint32_t color;
} Star;

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

      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
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

  SDL_Event e;
  Star star1 = {
    SCREEN_WIDTH / 2,
    0,
    SCREEN_HEIGHT / 2,
    0,
    0,
    20.0,
    0xff0000ff
  };

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

        star1.x_pos += 1;
        star1.y_pos += 1;

        // SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        // SDL_RenderFillRect(gRenderer, &fillRect);
        filledCircleColor(
          gRenderer,
          star1.x_pos,
          star1.y_pos,
          star1.radius,
          star1.color
        );

        SDL_RenderPresent(gRenderer);
      }
    }
  }

  cease();

  return 0;
}