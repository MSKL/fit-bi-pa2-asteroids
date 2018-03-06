#include "SDLManager.h"

void SDLManager::Initialise(const char *_appName, const int _screenWidth, const int _screenHeight) {

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    // Init the video and check for errors
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        throw error::CannotInitSDLException();
    }

    // Create and save the window
    CreateWindow(_appName, _screenWidth, _screenHeight);

    // Create the renderer
    CreateRenderer();
}

SDL_Window *SDLManager::GetWindow() const {
    if (window == NULL) {
        throw error::WindowDoesNotExistException();
    }
    else {
        return window;
    }
}

SDL_Renderer *SDLManager::GetSDLRenderer() const {
    if (sdlRenderer == NULL) {
        throw error::RendererDoesNotExistException();
    }
    else {
        return sdlRenderer;
    }
}

void SDLManager::QuitSDL() {
    // Destroy renderer
    if (sdlRenderer == NULL) {
        throw error::RendererDoesNotExistException();
    }
    SDL_DestroyRenderer(sdlRenderer);

    // Destroys current window
    if (window == NULL) {
        throw error::WindowDoesNotExistException();
    }
    SDL_DestroyWindow(window);

    // Quit all the remaining subsystems
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);

    // Quits SDL
    SDL_Quit();
}

void SDLManager::CreateWindow(const char *_appName, const int _screenWidth, const int _screenHeight) {
    // If the window already exists, throw an exception
    if(window != NULL) {
        std::cout << "SDLManager: Cannot create a window. The current pointer is not NULL." << std::endl;
        throw error::CannotCreateWindowException();
    }

    // Create the window base on settings
    window = SDL_CreateWindow(_appName,
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              _screenWidth, _screenHeight,
                              SDL_WINDOW_SHOWN );

    // If the window is NULL, the creation of window has failed, throw an exception
    if(window == NULL) {
        std::cout << "SDLManager: Cannot create a window. SDL Error: " << SDL_GetError() << std::endl;
        throw error::CannotCreateWindowException();
    }
}

void SDLManager::CreateRenderer() {
    // If the renderer already exists, throw an exception
    if(sdlRenderer != NULL) {
        std::cout << "SDLManager: Cannot create a renderer. The current pointer is not NULL." << std::endl;
        throw error::CannotCreateRendererException();
    }

    // Create the renderer
    sdlRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

    // If the renderer is NULL, the creation of renderer has failed, throe an exception
    if (sdlRenderer == NULL) {
        std::cout << "SDLManager: Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
        throw error::CannotCreateRendererException();
    }
}
