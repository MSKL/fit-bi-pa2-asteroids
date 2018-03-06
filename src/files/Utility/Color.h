#ifndef SDL2_COLOR_H
#define SDL2_COLOR_H

#include <cstdint>

/*!
 * Color management class
 * contains basic color definitions
 */
class Color {
public:
    /*!
     * The constructor of Color sets the channels
     * @param _r red
     * @param _g green
     * @param _b blue
     * @param _a alpha default not transparent
     */
    Color (uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a = 0xFF);

    /*! red channel of color */
    uint8_t r;
    /*! green channel of color */
    uint8_t g;
    /*! blue channel of color */
    uint8_t b;
    /*! alpha channel of color */
    uint8_t a;
};

/*! white color */
const Color white = Color(255, 255, 255);

/*! black color */
const Color black = Color(0, 0, 0);

#endif //SDL2_COLOR_H
