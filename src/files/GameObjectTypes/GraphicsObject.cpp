#include "GraphicsObject.h"

GraphicsObject::GraphicsObject(const DVector2D &_spawnPosition, const Rotation &_spawnRotation)
        : GameObject(_spawnPosition, _spawnRotation) {
}

void GraphicsObject::Draw() {
    DrawGraphics(this, SuperManager().Instance()->renderManager);
}

bool GraphicsObject::IsClosedLoop() const {
    return closed_loop;
}

std::vector<DVector2D> GraphicsObject::GetPointVector() const {
    return pointVector;
}

void GraphicsObject::SetPointVector(const std::vector<DVector2D> &_newPoints, bool _isClosedLoop) {
    closed_loop = _isClosedLoop;

    // Insert point into the array
    pointVector.clear();
    pointVector.reserve(_newPoints.size());
    pointVector.insert(pointVector.begin(), _newPoints.begin(), _newPoints.end());
}

void GraphicsObject::RescaleGraphics(const double &_rescaleFactor) {
    for(unsigned int i = 0; i < pointVector.size(); i++) {
        pointVector[i] = pointVector[i] * _rescaleFactor;
    }
}

void GraphicsObject::DrawGraphics(const GraphicsObject *target, RenderManager &_lineRenderer) {
    size_t vector_size = target->pointVector.size();

    // Do nothing if there is 0 points
    if (vector_size == 0) {
        return;
    }

    // Draw lines between all points in rectangle
    for (size_t i = 0; i < vector_size - 1; i++) {
        _lineRenderer.Draw(GetRealCoordinates(target->pointVector[i]), GetRealCoordinates(target->pointVector[i + 1]));
    }

    // If the loop is closed draw the last line
    if (target->closed_loop) {
        _lineRenderer.Draw(GetRealCoordinates(target->pointVector[0]), GetRealCoordinates(target->pointVector[vector_size - 1]));
    }
}

DVector2D GraphicsObject::GetRealCoordinates(const DVector2D &_localCoord) const {
    return position + _localCoord.RotateRad(rotation.GetRAD());
}
