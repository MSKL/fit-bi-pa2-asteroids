#ifndef SDL2_UI_SCORETEXT_H
#define SDL2_UI_SCORETEXT_H

#include "../../GameObjectTypes/GraphicsObject.h"
#include "UI_Character.h"

/*!
 * This class draws numbers specified in the constructor
 */
class UI_ScoreText final : public GraphicsObject {
public:
    /*!
     * The constructor of UIScore
     * @param spawnPosition position to be drawn. Specifies the bottom left corner
     * @param spawnRotation
     * @param _scoreToDraw number to be drawn
     */
    UI_ScoreText(const DVector2D & spawnPosition = DVector2D(-100, -100), const Rotation & spawnRotation = Rotation(0), int _scoreToDraw = 42);

    /*!
     * Draw the number specified in the constructor
     */
    void Draw () override;

private:
    int score_to_draw = 42;
};

#endif //SDL2_UI_SCORETEXT_H
