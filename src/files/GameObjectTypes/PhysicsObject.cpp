#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(const DVector2D &_spawnPosition, const Rotation &_spawnRotation,
                             const DVector2D &_velocity, const double &_angularVelocity)
        : CollidableObject(_spawnPosition, _spawnRotation), velocity(_velocity), angular_velocity(_angularVelocity) {
}

void PhysicsObject::PhysicsTick() {
    position += velocity;   // Move the object

    // Damp the velocity and angular speed
    VelocityDampTick();
    AngularDampTick();

    // Rotate the object
    rotation.SetRAD(rotation.GetRAD() + angular_velocity);
}

double PhysicsObject::GetAngularVelocity() const {
    return angular_velocity;
}

void PhysicsObject::SetAngularVelocity(const double _angularVelocity) {
    angular_velocity = _angularVelocity;
}

void PhysicsObject::SetVelocityDamp(const double _velocityDamp) {
    velocity_damp = _velocityDamp;
}

DVector2D PhysicsObject::GetVelocity() const {
    return velocity;
}

void PhysicsObject::SetVelocity(const DVector2D &_velocity) {
    velocity = _velocity;
}

void PhysicsObject::VelocityDampTick() {
    velocity.x *= velocity_damp;
    velocity.y *= velocity_damp;
}

void PhysicsObject::AngularDampTick() {
    angular_velocity *= angular_damp;
}
