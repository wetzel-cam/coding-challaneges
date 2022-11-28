#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

typedef struct {
  int radius;
  uint32_t color;
} Circle;

typedef struct {
  int position[2]; // [0] = x, [1] = y
  int velocity[2]; // [0] = x velocity, [1] = y velocity
  int x_offset;
  int y_offset;
  int z_factor;
  Circle* circle;
} Star;

// Star* Star_Create();
Star* Star_Create(int, int, int, int);
Circle* Star_CreateCricle(int, uint32_t);
void Star_Update(Star*);
void Star_Render(Star*, SDL_Renderer*);
void Star_SetPosition(int[2]);
void Star_SetColor(Star*);
float map(float, float, float, float, float);
int randRange(int, int);
