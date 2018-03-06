#ifndef SDL2_PLAYER_H
#define SDL2_PLAYER_H

#include "../GameObjectTypes/PhysicsObject.h"
#include "../Managers/InputManager.h"
#include "../Managers/SuperManager.h"
#include "Shot.h"
#include "Flame.h"

/*!
 * The player class contains the ship and handling
 */
class Player final: public PhysicsObject {
public:
    /*!
     * The Player's constructor
     * @param spawnPosition position of spawn
     * @param spawnRotation rotation of spawn
     */
    Player(const DVector2D & spawnPosition, const Rotation & spawnRotation);

    /*!
     * Apply the steering
     */
    void Steer() override;

    /*!
     * Function that gets called when the player gets hit
     */
    void GetHit() override;

    /*!
     * Draw the players GraphicsObject
     */
    void Draw() override;

    /*!
     * Adds a life to the player
     */
    void AddLife() override;

    /*!
     * Get the number of lives of the player
     * @return number of lives
     */
    int GetLives() const override;

protected:
    /*! Number of lives remaining */
    int lives_remaining;

private:
    void Accelerate();
    void Shoot();

    int lastTimeShot = 0;
    int delay = 200;
};

#endif //SDL2_PLAYER_H
