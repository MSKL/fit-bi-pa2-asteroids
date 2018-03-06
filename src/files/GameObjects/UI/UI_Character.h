#ifndef SDL2_UI_CHARACTER_H
#define SDL2_UI_CHARACTER_H

#include "../../GameObjectTypes/GraphicsObject.h"

/*!
 * This class contains definitions of individual characters
 */
class UI_Character final: public GraphicsObject {
public:
    /*!
     * Construct a character
     * @param spawnPosition
     * @param spawnRotation
     * @param _ASCIIcharToDraw the character to be drawn
     */
    UI_Character(const DVector2D & spawnPosition = DVector2D(0, 0), const Rotation & spawnRotation = Rotation(0), const int _ASCIIcharToDraw = 'A');
};

#endif //SDL2_UI_CHARACTER_H
