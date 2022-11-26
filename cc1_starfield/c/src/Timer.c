#include "Timer.h"

Timer* CreateTimer()
{
  Timer* t = malloc(sizeof(Timer));
  t->startTicks   = 0;
  t->pausedTicks  = 0;
  t->started      = false;
  t->paused       = false;

  return t;
}

void StartTimer(Timer* t)
{
  // Set start flag
  t->started = true;

  // Unpause timer
  t->paused = false;

  // Get current times
  t->startTicks = SDL_GetTicks();
  t->pausedTicks = 0;
}

// Pauses and resets the timer
void StopTimer(Timer* t)
{
  t->started      = false;
  t->paused       = false;
  t->startTicks   = 0;
  t->pausedTicks  = 0;
}

void PauseTimer(Timer* t)
{
  if (t->started && !t->paused)
  {
    // Pauses the timer
    t->paused = true;

    // Calculates the paused ticks
    t->pausedTicks = SDL_GetTicks() - t->startTicks;
    t->startTicks = 0;
  }
}

void UnpauseTimer(Timer* t)
{
  if (t->started && t->paused)
  {
    t->paused = false;
    t->startTicks = SDL_GetTicks() - t->pausedTicks;
    t->pausedTicks = 0;
  }
}

uint32_t GetTicks(Timer* t)
{
  uint32_t time = 0;

  if (t->started)
    if (t->paused)
      time = t->pausedTicks;
    else
      time = SDL_GetTicks() - t->startTicks;

  return time;
}

bool isStarted(Timer* t)
{
  return t->started;
}

bool isPaused(Timer* t)
{
  return t->started && t->paused;
}