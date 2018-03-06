#include "TimerManager.h"

void TimerManager::StartTick() {
    frame_start_milliseconds = SDL_GetTicks();
}

void TimerManager::WaitForFPS(const int _desiredFPS) const {
    // number of milliseconds for one tick
    unsigned int fps_milliseconds = (unsigned int)((1.0/_desiredFPS) * 1000.0);

    // Flag to detect lags
    bool waited = false;
    while (SDL_GetTicks() - frame_start_milliseconds < fps_milliseconds) {
        // If the loop runs at least once, flip the flag
        waited = true;
    }

    if (!waited) {
        std::cout << "FPS lag. Last frame took " << SDL_GetTicks() - frame_start_milliseconds << "milliseconds." << std::endl;
    }
}

uint32_t TimerManager::GetCurrentTicks() const {
    return SDL_GetTicks();
}
