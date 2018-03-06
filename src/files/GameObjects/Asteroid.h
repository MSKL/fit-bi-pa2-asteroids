#ifndef SDL2_ASTEROID_H
#define SDL2_ASTEROID_H

#include "../GameObjectTypes/PhysicsObject.h"
#include "../Managers/InputManager.h"
#include "../Utility/Random.h"
#include "Upgrade.h"

/*!
 * Asteroid is a final prefab of PhysicsObject
 */
class Asteroid final: public PhysicsObject {
public:
    /*!
     * A constructor that is used when deriving from other asteroid that was destroyed
     * @param spawnPosition spawn position
     * @param spawnRotation spawn rotation in radians
     * @param _points vector of points
     * @param _asteroidSize size of the asteroid
     * @param _derivedVelocity velocity of a parent
     * @param _derivedAngularVelocity angular velocity of a parent
     */
    Asteroid(const DVector2D & spawnPosition, const Rotation & spawnRotation, const std::vector<DVector2D> & _points,
             const int _asteroidSize, const DVector2D _derivedVelocity = DVector2D(0, 0), const double & _derivedAngularVelocity = 0);

    /*!
     * GetHit should be called on a collision with a shot
     * There is a chance for Upgrade to drop
     */
    virtual void GetHit() override;

private:
    int asteroid_size = 0;

};

#endif //SDL2_ASTEROID_H
