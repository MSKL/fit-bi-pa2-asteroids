#ifndef SDL2_INPUTHANDLER_H
#define SDL2_INPUTHANDLER_H

#include <SDL2/SDL.h>
#include <iostream>

/*!
 * InputManager class manages the human input
 */
class InputManager {
public:
    /*!
     * Handles the input
     * must be called before checking the state of keys
     * @return false for exit event
     */
    bool HandleInput();

    /*!
     * Get the horizontal input axis
     * @return horizontal input axis
     */
    int GetHorizontal() const;

    /*!
     * Get the vertical input axis
     * @return vertical input axis
     */
    int GetVertical() const;

    /*!
     * Get the space bar press
     * @return space bar press
     */
    bool GetSpace() const;

private:
    // Resets the key values before next HandleInput call
    void ResetKeys();

    // horizontal input axis
    int horizontal = 0;

    // vertical input axis
    int vertical = 0;

    // indicates if the spacebar was pressed
    bool SPACE = false;
};

#endif //SDL2_INPUTHANDLER_H