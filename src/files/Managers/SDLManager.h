//
// Created by Matyáš Skalický on 14.05.17.
//

#ifndef SDL2_SDLMANAGER_H
#define SDL2_SDLMANAGER_H

#include <iostream>
#include "SDL2/SDL.h"
#include "../Settings/ThrowErrors.h"


/*!
 * Handles the creation and deletion of SDL components;
 * contains pointers to created window and renderer
 */
class SDLManager {
public:

    /*!
     * Initialise all SDL components needed for drawing vertices.
     * create a Window and a Renderer
     */
    void Initialise(const char* _appName, const int _screenWidth, const int _screenHeight);

    /*!
     * Get a window from the SDL Manager.
     * must be initialised
     * @return pointer to the Window created in InitSDL()
     */
    SDL_Window* GetWindow() const;

    /*!
     * Get SDL renderer from the SDL Manager.
     * must be initialised
     * @return pointer to the SDL renderer created in InitSDL()
     */
    SDL_Renderer* GetSDLRenderer() const;

    /*!
     * Quits the SDL library
     * destroys the Window and Renderer
     * quits the SDL library
     */
    void QuitSDL();

private:
    SDL_Window*     window      = NULL;
    SDL_Renderer*   sdlRenderer = NULL;

    // Create a window. Check for errors while creating
    void CreateWindow(const char* _appName, const int _screenWidth, const int _screenHeight);

    // Create a renderer. Check for errors while creating
    void CreateRenderer();
};


#endif //SDL2_SDLMANAGER_H
