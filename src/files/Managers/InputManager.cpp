#include "InputManager.h"

bool InputManager::HandleInput() {
    // Set all keys to false
    ResetKeys();

    // Make a SDLEvent e
    SDL_Event e;

    //Handle events on queue and check for quit
    while(SDL_PollEvent(&e) != 0)
    {
        // Check for quit flag
        if(e.type == SDL_QUIT) {
            return false;
        }
    }

    // Handle keyboard events
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_SPACE]) {
        SPACE = true;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        horizontal += 1;
    }
    if (state[SDL_SCANCODE_LEFT]){
        horizontal += -1;
    }
    if(state[SDL_SCANCODE_UP]){
        vertical += 1;
    }
    if(state[SDL_SCANCODE_DOWN]){
        vertical -= 1;
    }

    return true;
}

int InputManager::GetHorizontal() const {
    return horizontal;
}

int InputManager::GetVertical() const {
    return vertical;
}

bool InputManager::GetSpace() const {
    return SPACE;
}

void InputManager::ResetKeys() {
    horizontal = vertical = 0;
    SPACE = false;
}
