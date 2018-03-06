#include <string>
#include "../../GameObjectTypes/GraphicsObject.h"
#include "UI_Character.h"

#ifndef SDL2_UI_ANYTEXT_H
#define SDL2_UI_ANYTEXT_H

/*!
 * Class that draws text
 * all characters must be defined
 */
class UI_AnyText final : public GraphicsObject {
public:
    /*!
     * The default constructor
     * @param spawnPosition bottom left position of text
     * @param spawnRotation spawn rotation
     * @param _toDraw string to be shown
     */
    UI_AnyText(const DVector2D & spawnPosition = DVector2D(-100, -100), const Rotation & spawnRotation = Rotation(0), const std::string & _toDraw = "");

    /*!
     * Draw all characters in text
     */
    void Draw () override;

private:
    // The string to be displayed after the draw function is called
    std::string to_draw;
};

#endif //SDL2_UI_ANYTEXT_H
