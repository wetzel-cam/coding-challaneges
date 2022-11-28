#include "Star.h"
#include <stdlib.h>

Circle* Star_CreateCircle(int radius, uint32_t color)
{
  Circle* c = malloc(sizeof(Circle));
  c->radius = radius;
  c->color  = color;

  return c;
}

Star* Star_Create(int x_init, int y_init, int x_velocity, int y_velocity)
{
  Star* s = malloc(sizeof(Star));
  s->position[0]  = x_init;
  s->position[1]  = y_init;
  s->velocity[0]  = x_velocity;
  s->velocity[1]  = y_velocity;
  s->x_offset     = 0;
  s->y_offset     = 0;
  s->z_factor     = rand() % 640;
  s->circle       = Star_CreateCircle(5, 0xffffffff);

  return s;
}

void Star_Update(Star* star)
{
  star->z_factor    -= 1;

  if (star->z_factor < 1)
  {
    star->z_factor    = 480;
    star->position[0] = randRange(-640, 640);
    star->position[1] = randRange(-480, 480);
  }

  // star->position[0] += star->velocity[0];
  // star->position[1] += star->velocity[1];
  star->x_offset = (int)map(((float)star->position[0] / star->z_factor), 0.0f, 1.0f, 0.0f, 640.0f);
  star->y_offset = (int)map(((float)star->position[1] / star->z_factor), 0.0f, 1.0f, 0.0f, 480.0f);
}

void Star_Render(Star* star, SDL_Renderer* renderer)
{
  // map(@x_pos.fdiv(@z_factor), 0, 1, 0, @@window.width) + @@x_offset

  // printf("x-val:%i\ny-val: %i\nz-value: %i\n\n", star->x_offset, star->y_offset,star->z_factor);

  filledCircleColor(
    renderer,
    star->x_offset + (640 / 2),
    star->y_offset + (480 / 2),
    star->circle->radius,
    star->circle->color
  );
}
 
float map(float value, float fromLow, float fromHigh, float toLow, float toHigh)
{
  // printf("init val: %f\nfromLow: %f\nfromHigh: %f\ntoLow: %f\ntoHigh: %f\n\n",
         // value, fromLow, fromHigh, toLow, toHigh);
  float ranged_value = (value - fromLow) / (fromHigh - fromLow);
  // printf("ranged value: %f\n", ranged_value);
  float scaled_value = ranged_value * (toHigh - toLow) + toLow;
  // printf("scaled value: %f\n", scaled_value);
  return scaled_value;
}

int randRange(int lower, int upper)
{
  return (rand() % (upper - lower + 1)) + lower;
}