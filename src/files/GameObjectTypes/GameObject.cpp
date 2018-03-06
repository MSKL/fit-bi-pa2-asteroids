#include "GameObject.h"
#include "../Settings/ThrowErrors.h"

GameObject::GameObject(const DVector2D &_startPosition, const Rotation &_startRotation)
        : position(_startPosition), rotation(_startRotation) {
}

GameObject::~GameObject() {
    // Do nothing
}

void GameObject::Draw() {
    throw error::UnsupportedMethodException();
}

void GameObject::PhysicsTick() {
    throw error::UnsupportedMethodException();
}

void GameObject::CheckSideCollisions() {
    throw error::UnsupportedMethodException();
}

void GameObject::Steer() {
    throw error::UnsupportedMethodException();
}

int GameObject::GetLives() const {
    throw error::UnsupportedMethodException();
}

bool GameObject::Collision(const GameObject *other) const {
    throw error::UnsupportedMethodException();
}

double GameObject::GetCollisionRadius() const {
    throw error::UnsupportedMethodException();
}

bool GameObject::IsClosedLoop() const {
    throw error::UnsupportedMethodException();
}

std::vector<DVector2D> GameObject::GetPointVector() const {
    throw error::UnsupportedMethodException();
}

DVector2D GameObject::GetRealCoordinates(const DVector2D &_localCoord) const {
    throw error::UnsupportedMethodException();
}

void GameObject::GetHit() {
    throw error::UnsupportedMethodException();
}

void GameObject::AddLife() {
    throw error::UnsupportedMethodException();
}

bool GameObject::ToDestroy() const {
    throw error::UnsupportedMethodException();
}
