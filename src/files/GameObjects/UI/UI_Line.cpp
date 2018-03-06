#include "UI_Line.h"

UI_Line::UI_Line(const int _width, const DVector2D &_spawnPosition, const Rotation &_spawnRotation)
        : GraphicsObject(_spawnPosition, _spawnRotation) {

    // Save the points into the GraphicsObject
    std::vector<DVector2D> points;
    points.push_back(DVector2D(0, 0));
    points.push_back(DVector2D(0 + _width, 0));
    SetPointVector(points, false);
}

void UI_Line::Draw() {
    // select a different color
    SuperManager().Instance()->renderManager.SetColor(Color(61, 221, 229));
    // Draw in different color
    GraphicsObject::Draw();
    // Set the color back to black
    SuperManager().Instance()->renderManager.SetColor(black);
}
