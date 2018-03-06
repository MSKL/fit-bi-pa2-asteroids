#ifndef SDL2_SHOT_H
#define SDL2_SHOT_H

#include "../GameObjectTypes/PhysicsObject.h"
#include "../Managers/SuperManager.h"

/*!
 * Shot class
 * Includes a check if the shot should or should not be destroyed
 */
class Shot final: public PhysicsObject {
public:
    /*!
     * The default constructor of shot
     * @param spawnPosition
     * @param spawnRotation
     * @param _velocity speed of shot
     * @param _timeToLive time to live in ms
     * @param _timeCreated time created
     */
    Shot(const DVector2D & spawnPosition, const Rotation & spawnRotation, DVector2D _velocity, uint32_t _timeToLive, uint32_t _timeCreated);

    /*!
     * Returns true if the shot should be destroyed
     * @return true if the shot lives too long
     */
    bool ToDestroy() const override;

private:
    // TTL in microseconds
    uint32_t timeToLive = 0;

    // Creation time in microseconds since the start of application
    uint32_t timeCreated;
};

#endif //SDL2_SHOT_H
