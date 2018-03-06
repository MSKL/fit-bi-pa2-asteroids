#ifndef SDL2_COLLIDABLEOBJECT_H
#define SDL2_COLLIDABLEOBJECT_H

#include "GraphicsObject.h"
#include "../Utility/DLine.h"
#include "../Settings/Settings.h"

/*!
 * GameObject that supports collisions
 */
class CollidableObject : public GraphicsObject {
public:
    /*!
     * Collidable object constructor
     * @param _spawnPosition the spawn position
     * @param _spawnRotation the spawn rotation
     */
    CollidableObject(const DVector2D & _spawnPosition, const Rotation & _spawnRotation);

    /*!
     * Set points of CollidableObject
     * @param _newPoints new points to be added
     * @param _isClosedLoop true if the rectangle is a closed loop
     */
    virtual void SetPointVector(const std::vector<DVector2D> & _newPoints, bool _isClosedLoop = true) override;

    /*!
     * Rescale all points in vector
     * @param _rescaleFactor the factor of resize
     */
    virtual void RescaleGraphics(const double & _rescaleFactor) override;

    /*!
     * Check screen boundary collisions and draw ghosts on the other side of the screen
     */
    void CheckSideCollisions() override;

    /*!
     * Checks collision between two collidable GameObjects
     * @param other GameObject to collide with
     * @return true if collision occured
     */
    virtual bool Collision(const GameObject * other) const override;

private:
    // Find the vector with biggest length
    double CalcCollisionRadius() const;

    template <typename _T, typename _K>
    void CheckBoundarySide(_T check, _K add, RenderManager & _lineRenderer);

    // Get the collision radius
    double GetCollisionRadius() const override;

    // Precomputed variable by InitCollisionRadius
    double collision_radius;

};

#endif //SDL2_COLLIDABLEOBJECT_H
