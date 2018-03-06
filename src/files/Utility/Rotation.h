#ifndef SDL2_ROTATION_H
#define SDL2_ROTATION_H

#include <math.h>

/*!
 * Rotation saves the rotation of GameObject
 */
class Rotation {
public:
    /*!
     * Constructor to initialise Rotation
     * @param _RADRotation rotation in radians
     */
    Rotation(double _RADRotation = 0);

    /*!
     * Set the rotation in radians
     * @param _RADRotation rotation in radians
     */
    void SetRAD(double _RADRotation);

    /*!
     * Get the current rotation in radians
     * @return rotation in radians
     */
    double GetRAD() const;

private:
    // Rotation in radians
    double RADRotation;
};

#endif //SDL2_ROTATION_H
