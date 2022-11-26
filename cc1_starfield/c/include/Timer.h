#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
  // Ticks when timer was started
  uint32_t startTicks;
  // Ticks when timer was paused
  uint32_t pausedTicks;

  // Status flags
  bool paused;
  bool started;

} Timer;

Timer* CreateTimer();
void StartTimer(Timer* t);
void StopTimer(Timer* t);
void PauseTimer(Timer* t);
void UnpauseTimer(Timer* t);
uint32_t GetTicks(Timer* t);
bool isPaused(Timer* t);
bool isStarted(Timer* t);