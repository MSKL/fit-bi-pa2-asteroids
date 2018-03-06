#ifndef SDL2_UPGRADE_H
#define SDL2_UPGRADE_H


#include "../GameObjectTypes/CollidableObject.h"
#include "../Managers/SuperManager.h"
#include "../Utility/Random.h"

/*!
 * The Upgrade for player
 */
class Upgrade final: public CollidableObject {
public:
    /*!
     * The Upgrade constructor. Contains definitions for upgrade symbols
     * @param spawnPosition position to spawn
     * @param spawnRotation rotation to spawn
     */
    Upgrade (const DVector2D & spawnPosition = DVector2D(100, 100), const Rotation & spawnRotation = Rotation(0));

    /*!
     * Draws the Upgrade and changes the color accordingly
     */
    void Draw() final override;

    /*!
     * Check if the upgrade should be destroyed
     * @return true if the upgrade has lived too long
     */
    bool ToDestroy() const override;

    /*!
     * When the upgrade gets hit by the Player, save it to the SuperManager
     */
    void GetHit() override;

private:
    // TTL in microseconds
    uint32_t timeToLive = 2000;

    // Creation time in microseconds since the start of application
    uint32_t timeCreated = 0;

    // The type of this upgrade
    SuperManager::UpgradeType upgrade_type;
};

#endif //SDL2_UPGRADE_H
