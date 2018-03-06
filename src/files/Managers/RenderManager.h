#ifndef SDL2_LINERENDERER_H
#define SDL2_LINERENDERER_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../Settings/ThrowErrors.h"
#include "../Utility/Color.h"
#include "../Utility/DLine.h"

/*!
 * The class that handles rendering of lines
 * It requies that the SDL library is intialised
 */
class RenderManager {
public:
    /*!
     * Init the render manager
     * Must be done before any function calls
     * @param _sdlRenderer renderer from initialised SDL
     */
    void Initialise(SDL_Renderer* _sdlRenderer);

    /*!
     * Draw a line between point with codinates
     * @param x1 the x component of point 1
     * @param y1 the y component of point 1
     * @param x2 the x component of point 2
     * @param y2 the y component of point 2
     */
    void Draw (const int x1, const int y1, const int x2, const int y2) const;

    /*!
     * Draw a line
     * @param line to be drawn
     */
    void Draw (const DLine & line) const;

    /*!
     * Handle drawing of 2 DVector2D's
     * @param i1 point 1
     * @param i2 point 2
     */
    void Draw (const DVector2D & i1, const DVector2D & i2) const;

    /*!
     * Clear the screen with the color from parameter
     * @param _color color to fill the screen with
     */
    void ClearScreen (const Color _color = white);

    /*!
     * Set the color of renderer to the color in parameter
     * @param _color new color of the renderer
     */
    void SetColor (const Color & _color);

private:
    SDL_Renderer* sdlRenderer = NULL;   // Keep the SDL renderer saved for future calls
};

#endif //SDL2_LINERENDERER_H
