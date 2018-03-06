#ifndef SDL2_UI_PLAYERICON_H
#define SDL2_UI_PLAYERICON_H

#include "../../GameObjectTypes/GraphicsObject.h"
#include "../../Managers/SuperManager.h"

/*!
 * The player icon class draws a small players ship
 * This class is used to draw the lives in the UI
 */
class UI_PlayerIcon final: public GraphicsObject {
public:
    /*!
     * The default constructor creates the logo at the position
     * @param spawnPosition position of spawn
     * @param spawnRotation rotation at spawn
     */
    UI_PlayerIcon(const DVector2D & spawnPosition, const Rotation & spawnRotation);

    /*!
     * Draw the players logo in the green color
     */
    void Draw() override;
};

#endif //SDL2_UI_PLAYERICON_H
