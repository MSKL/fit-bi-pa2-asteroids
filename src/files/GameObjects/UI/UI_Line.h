#ifndef SDL2_UI_LINE_H
#define SDL2_UI_LINE_H

#include "../../GameObjectTypes/GraphicsObject.h"
#include "../../Managers/SuperManager.h"

/*!
 * The UI Line icon
 * This class is used to draw the line segment to show upgrades
 */
class UI_Line final: public GraphicsObject {
public:
    /*!
     * The default constructor of UI_Line
     * @param _width the width of line to be drawn
     * @param _spawnPosition
     * @param _spawnRotation
     */
    UI_Line(const int _width, const DVector2D &_spawnPosition = DVector2D(0, 0), const Rotation &_spawnRotation = Rotation(0));

    /*!
     * Draw the line in different color
     */
    void Draw() override;
};


#endif //SDL2_UI_LINE_H
