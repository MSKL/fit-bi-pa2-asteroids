#include "RenderManager.h"

void RenderManager::Initialise(SDL_Renderer *_sdlRenderer) {
    sdlRenderer = _sdlRenderer;
}

void RenderManager::Draw(const int x1, const int y1, const int x2, const int y2) const {
    if(sdlRenderer == NULL) {
        throw error::RendererDoesNotExistException();
    }
    else {
        if(SDL_RenderDrawLine(sdlRenderer, x1, y1, x2, y2) != 0) {
            std::cout << "Error encountered in RenderDrawLine function! SDL Error: " << SDL_GetError() << std::endl;
            throw error::RenderDrawLineException();
        }
    }
}

void RenderManager::Draw(const DLine &line) const {
    Draw((int)line.p1.x, (int)line.p1.y, (int)line.p2.x, (int)line.p2.y);
}

void RenderManager::Draw(const DVector2D &i1, const DVector2D &i2) const {
    Draw((int)i1.x, (int)i1.y, (int)i2.x, (int)i2.y);
}

void RenderManager::ClearScreen(const Color _color) {
    // Set the background color
    SetColor(_color);

    // Clear the background with color
    if(SDL_RenderClear(sdlRenderer) != 0) {
        std::cout << "Error encountered in SetRenderClear function! SDL Error: " << SDL_GetError() << std::endl;
        throw error::RenderClearException();
    }
}

void RenderManager::SetColor(const Color &_color) {
    if(SDL_SetRenderDrawColor(sdlRenderer, _color.r, _color.g, _color.b, _color.a) != 0) {
        std::cout << "Error encountered in SetRenderDraw function! SDL Error: " << SDL_GetError() << std::endl;
        throw error::SetRenderDrawColorException();
    }
}
