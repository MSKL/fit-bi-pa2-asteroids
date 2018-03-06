#ifndef ASTEROIDS_FLAME_H
#define ASTEROIDS_FLAME_H

#include <cmath>
#include "../Managers/SuperManager.h"
#include "../GameObjectTypes/GraphicsObject.h"

/*!
 * The Flame of the ship
 */
class Flame final: public GraphicsObject {
public:
    /*!
     * The Flame constructor
     * @param spawnPosition position to spawn
     * @param spawnRotation rotation to spawn
     */
    Flame(const DVector2D & spawnPosition = DVector2D(-100, -100), const Rotation & spawnRotation = Rotation(0));
};

#endif //ASTEROIDS_FLAME_H
