#include "Shot.h"

Shot::Shot(const DVector2D &spawnPosition, const Rotation &spawnRotation, DVector2D _velocity, uint32_t _timeToLive,
           uint32_t _timeCreated)
        : PhysicsObject(spawnPosition, spawnRotation), timeToLive(_timeToLive) {

    // Push the individual points into the Graphic Object
    std::vector<DVector2D> points;
    points.push_back(DVector2D(0, -5));
    points.push_back(DVector2D(0, 5));
    SetPointVector(points, false);

    // Set the time of the creation and also the velocity
    timeCreated = _timeCreated;
    velocity = _velocity;
}

bool Shot::ToDestroy() const {
    // Check if the shot should be destroyed
    return (SuperManager().Instance()->timerManager.GetCurrentTicks() - timeCreated > timeToLive);
}
