#ifndef SDL2_GAMEOBJECTMANAGER_H
#define SDL2_GAMEOBJECTMANAGER_H

#include <list>
#include <vector>
#include <memory>
#include "InputManager.h"
#include "TimerManager.h"
#include "SDLManager.h"
#include "RenderManager.h"
#include "../Settings/Settings.h"
#include "../GameObjectTypes/GameObject.h"

/*!
 * Singleton that stores all GameObjects and is responsible for physics
 * It also contains the level and score info
 */
class SuperManager {
public:
    /*!
     * Get the instance of the singleton. If it is NULL, create a new one
     * @return instance of the SuperManager
     */
    static SuperManager* Instance();

    /*!
     * The Destroys the SuperManager
     * Cleans all allocated GameObjects and quits the SDL
     */
    virtual void Destroy();

    virtual ~SuperManager();

private:
    static SuperManager * instance;

public:
    /*!
     * One tick of Graphics
     * Is used for Intro and HighScores scene
     * All the inserted GameObjects will be destroyed at the end of the tick and must be added again
     */
    void TickGraphicsOnly();

    /*!
     * One tick of the Game
     */
    void TickGame();

    /*!
     * Cleans and destroys all allocated Objects
     */
    void Cleanup();

    /*!
     * Gets the current score
     * @return current score
     */
    int GetScore() const;

    /*!
     * Increments the current score
     */
    void IncrementScore();

    /*!
     * Resets the score
     */
    void ResetScore();

    /*!
     * Get the current level
     * @return current level
     */
    int GetLevel() const;

    /*!
     * Incerase the level by one
     */
    void IncrementLevel();

    /*!
     * Reset the level to 0
     */
    void ResetLevel();

    /*! Possible types of upgrades */
    enum UpgradeType {life, doubleshoot, tripleshoot, terminator};

    /*! The possible states of the game */
    enum Game_state {Intro, Game, Scoreboard};

    /*!
     * Set tge current upgrade and also update the valid_until
     * @param _up the type to be set
     * @param _duration duration of the upgrade to be set
     */
    void SetUpgrade (SuperManager::UpgradeType _up, uint32_t _duration);

    /*!
     * Get the current upgrade type
     * @return current upgrade type
     */
    SuperManager::UpgradeType GetCurrentUpgrade() const;

    /*!
     * Get the number of ticks until the upgrade is active
     * @return number of ticks until the upgrade is active
     */
    int GetUpgradeActiveUntil() const;

    /*!
     * Check if the current upgrade is active
     * @return true if the current upgrade is active
     */
    bool IsCurrentUpgradeActive() const;


    /*! The list that contains Shot classes stored as GameObject* */
    std::list<GameObject*>   shot_list;
    /*! The list that contains Shot asteroid stored as GameObject* */
    std::list<GameObject*>   asteroid_list;
    /*! The list that contains Graphics only classes stored as GameObject*. This list gets cleared and freed after every call. */
    std::list<GameObject*>   graphics_list;
    /*! The list that contains Upgrade only classes stored as GameObject*. */
    std::list<GameObject*>   upgrade_list;

    /*! The Player class stored as GameObject* */
    GameObject* player;

    /*! The class that takes care of SDL. */
    static SDLManager       sdlManager;
    /*! The class that manages rendering of lines in SDL. The sdlManager must be initialised. */
    static RenderManager    renderManager;
    /*! The class that handles inputs to the game. */
    static InputManager     inputManager;
    /*! The class that manages handling of FPS and game time. */
    static TimerManager     timerManager;

    /*! Current state of the game */
    Game_state game_state = Intro;

private:
    // Initialise the core components
    void Initialise();

    // Delete all contents of a list and dealloc its contents
    void CleanList(std::list<GameObject*> & _toClean);

    // Call a Draw function on each object from the list
    void DrawList(std::list<GameObject*> & _list);

    // Call a PhysicsTick function on each object from the list
    void PhysicsTickList(std::list<GameObject*> & _list);

    // Check bound collisions on each object from the list
    void CheckBoundCollisionsList(std::list<GameObject *> &_list);

    // Check if the ToDestroy function returned true. If so, destroy and dealloc the object
    void CheckToBeDestroyedList(std::list<GameObject*> & _list);

    // Check the collisions between Asteroids and Shots
    void AsteroidShotCollision();

    // Check the collisions between all asteroids and the Player
    void PlayerAsteroidCollision();

    // Check the collisions between each upgrade and the player's ship
    void PlayerUpgradeCollision();

    /*! The current upgrade */
    UpgradeType upgrade_current = life;

    /*! The time when was the last upgrade picked up */
    int upgrade_valid_until = 0;

    /*! Current score */
    int score = 0;

    /*! Current level */
    int level = 0;
};


#endif //SDL2_GAMEOBJECTMANAGER_H
