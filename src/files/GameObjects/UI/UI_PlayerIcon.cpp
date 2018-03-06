#include "UI_PlayerIcon.h"

UI_PlayerIcon::UI_PlayerIcon(const DVector2D &spawnPosition, const Rotation &spawnRotation)
        : GraphicsObject(spawnPosition, spawnRotation) {

    std::vector<DVector2D> points;
    points.push_back(DVector2D(0, 10));
    points.push_back(DVector2D(5, -7));
    points.push_back(DVector2D(-5, -7));

    SetPointVector(points, true);

    RescaleGraphics(0.8);
}

void UI_PlayerIcon::Draw() {
    SuperManager().Instance()->renderManager.SetColor(Color(61, 221, 229));
    GraphicsObject::Draw();
    SuperManager().Instance()->renderManager.SetColor(black);
}
