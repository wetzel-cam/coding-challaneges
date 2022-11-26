#include "Star.h"

Circle* Star_CreateCircle(int radius, uint32_t color)
{
  Circle* c = malloc(sizeof(Circle));
  c->radius = radius;
  c->color  = color;

  return c;
}

Star* Star_Create()
{
  Star* s = malloc(sizeof(Star));
  s->position[0]  = 100;
  s->position[1]  = 100;
  s->velocity[0]  = 1;
  s->velocity[1]  = 1;
  s->x_offset     = 0;
  s->y_offset     = 0;
  s->z_factor     = 0.f;
  s->circle       = Star_CreateCircle(5, 0xff0000ff);

  return s;
}

void Star_Update(Star* star)
{
  star->position[0] += star->velocity[0];
  star->position[1] += star->velocity[1];
}

void Star_Render(Star* star, SDL_Renderer* renderer)
{
  filledCircleColor(
    renderer,
    star->position[0],
    star->position[1],
    star->circle->radius,
    star->circle->color
  );
}