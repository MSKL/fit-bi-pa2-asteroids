#ifndef SDL2_PHYSICSOBECT_H
#define SDL2_PHYSICSOBECT_H

#include "CollidableObject.h"

/*!
 * The kinetic object class
 * Allows objects to move
 */
class PhysicsObject : public CollidableObject {
public:
    /*!
     * The default constructor
     * @param _spawnPosition
     * @param _spawnRotation
     * @param _velocity speed of movement
     * @param _angularVelocity speed of rotation
     */
    PhysicsObject(const DVector2D & _spawnPosition, const Rotation & _spawnRotation,
                  const DVector2D & _velocity = DVector2D(0, 0), const double & _angularVelocity = 0);

    /*!
     * One physics tick of the engine
     */
    void PhysicsTick() override;

    /*!
     * Obtain the speed of rotation
     * @return angular velocity
     */
    double GetAngularVelocity() const;

    /*!
     * Set the speed of rotation
     * @param _angularVelocity set the angular velocity
     */
    void SetAngularVelocity(const double _angularVelocity);

    /*!
     * The damping of the velocity
     * @param _velocityDamp number between 0 and 1
     */
    void SetVelocityDamp(const double _velocityDamp);

    /*!
     * Get the velocity of the PhysicsObject
     * @return the velocity of the PhysicsObject
     */
    DVector2D GetVelocity() const;

    /*!
     * Set the velocity of the PhysicsObject
     * @param _velocity velocity to be assigned
     */
    void SetVelocity(const DVector2D & _velocity);

protected:
    /*! The velocity of the PhysicsObject */
    DVector2D velocity;
    /*! The angular velocty of the PhysicsObject */
    double angular_velocity;
    /*! The velocity damp. Should be between 0 and 1 */
    double velocity_damp = 1;
    /*! Set the angular damp. Should be between 0 and 1 */
    double angular_damp = 1;

private:
    // Damp the velocity
    void VelocityDampTick();

    // Damp the rotation speed
    void AngularDampTick();
};

#endif //SDL2_PHYSICSOBECT_H
