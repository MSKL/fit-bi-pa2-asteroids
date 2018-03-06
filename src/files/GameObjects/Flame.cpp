#include "Flame.h"

Flame::Flame(const DVector2D &spawnPosition, const Rotation &spawnRotation)
        : GraphicsObject(spawnPosition, spawnRotation) {

    std::vector<DVector2D> points;
    points.push_back(DVector2D(0, -14));
    points.push_back(DVector2D(-3, -11));
    points.push_back(DVector2D(3, -11));

    SetPointVector(points);
}
