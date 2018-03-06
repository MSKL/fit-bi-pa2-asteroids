#ifndef SDL2_FPSTIMER_H
#define SDL2_FPSTIMER_H

#include <iostream>
#include "SDL2/SDL.h"

/*!
 * TimerManager class handles the time from SDL
 */
class TimerManager {
public:
    /*!
     * Should be called in the beginning of a frame
     */
    void StartTick();

    /*!
     * WaitForFPS will pause the game untill a next frame is sheuldeued
     * @param _desiredFPS target FPS
     */
    void WaitForFPS(const int _desiredFPS) const;

    /*!
     * GetCurrentTicks return ticks since the initialisation of SDL
     * @return ms since the start of the game
     */
    uint32_t GetCurrentTicks() const;

private:
    uint32_t frame_start_milliseconds;
};

#endif //SDL2_FPSTIMER_H
