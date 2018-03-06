#ifndef SDL2_GAMEOBJECT_H
#define SDL2_GAMEOBJECT_H

#include <vector>
#include "../Utility/DVector2D.h"
#include "../Utility/Rotation.h"

/*!
 * Base empty GameObject that has only position and rotation
 * includes virtual classes
 */
class GameObject {
public:
    /*!
     * The default constructor of GameObject
     * @param _startPosition the spawn position
     * @param _startRotation the spawn rotation
     */
    GameObject(const DVector2D & _startPosition, const Rotation & _startRotation);

    /*!
     * Virtual destructor of GameObject
     */
    virtual ~GameObject();

    /*!
     * Draws the graphics
     * should be overriden in GraphicObject
     */
    virtual void Draw();

    /*!
     * Computes the physics
     * should be overriden in PhysicsObject
     */
    virtual void PhysicsTick();

    /*!
     * Check the screen border collisions
     * should be overriden in CollidableObject
     */
    virtual void CheckSideCollisions();

    /*!
     * Steer the GameObject
     * should be overriden in GameObjects that should react to the user's input
     */
    virtual void Steer();

    /*!
     * Get the number of lives of player
     * should be overriden in Player class
     * @return number of lives
     */
    virtual int GetLives() const;

    /*!
     * Check for collision between two PhysicsObjects
     * should be overriden in PhysicsPbject
     * @param other other PhysicsObject to collide with
     * @return true if collision occured
     */
    virtual bool Collision(const GameObject * other) const;

    /*!
     * Get the collision radius from CollidableObject
     * should be overriden in CollidableObject
     * @return size of collision radius
     */
    virtual double GetCollisionRadius() const;

    /*!
     * Check if the GraphicsObject is a closed rectangle
     * should be overriden in GraphicsObject
     * @return true if the rectangle is clodes loop
     */
    virtual bool IsClosedLoop() const;

    /*!
     * Read the PointVector from a GraphicsObject
     * should be overriden in GraphicsObject
     * @return vector of DVector2D's from rectangle
     */
    virtual std::vector<DVector2D> GetPointVector() const;

    /*!
     * Obtain the coordinates of vector from current coordinates in global coordinates
     * should be overriden in GraphicsObject
     * @param _localCoord local position of a point
     * @return global position of a point
     */
    virtual DVector2D GetRealCoordinates (const DVector2D & _localCoord) const;

    /*!
     * Is called is Player gets hit
     * should be overriden in Player class
     */
    virtual void GetHit();

    /*!
     * Is called is Player picks up an life upgrade
     * should be overridden in Player class
     */
    virtual void AddLife();

    /*!
     * Checks if the GameObject should be destroyed in the next round
     * should be overriden in the Shot class
     * @return true if the GameObject should be destroyed
     */
    virtual bool ToDestroy() const;

    /*! The position of GameObject in world coordinates */
    DVector2D position;

    /*! The rotation of GameObject */
    Rotation rotation;
};


#endif //SDL2_GAMEOBJECT_H
