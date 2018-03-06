#ifndef SDL2_DOUBLEVECTOR_H
#define SDL2_DOUBLEVECTOR_H

#include <cmath>

/*!
 * The 2D vector class
 * contains x and y double values
 */
class DVector2D {
public:
    /*!
     * Construct the DVector2D
     * @param _x x value
     * @param _y y value
     */
    DVector2D (const double _x = 0, const double _y = 0);

    /*!
     * Add together two DVector2D's
     * @param left
     * @param right
     * @return result of addition
     */
    friend DVector2D operator + (const DVector2D & left, const DVector2D & right);

    /*!
     * Add to the current DVector2D
     * @param left
     * @param right
     * @return
     */
    friend DVector2D & operator += (DVector2D & left, const DVector2D & right);

    /*!
     * Subtract from the current DVector2D
     * @param left
     * @param right
     * @return
     */
    friend DVector2D & operator -= (DVector2D & left, const DVector2D & right);

    /*!
     * Subtract right from the left DVector2D
     * @param left
     * @param right
     * @return
     */
    friend DVector2D operator - (const DVector2D & left, const DVector2D & right);

    /*!
     * Multiply left DVector2D by a double value on right
     * @param left
     * @param right
     * @return
     */
    friend DVector2D operator * (const DVector2D & left, const double & right);

    /*!
     * Multiply right DVector2D by a double value on left
     * @param left
     * @param right
     * @return
     */
    friend DVector2D operator * (const double & left, const DVector2D & right);

    /*!
     * Divide the DVector2D by the double on right
     * @param left
     * @param right
     * @return
     */
    friend DVector2D operator / (const DVector2D & left, const double & right);

    /*!
     * Rotate the current vector by angle in radians
     * @param _theta angle in radians
     * @return
     */
    DVector2D RotateRad (const double _theta) const;

    /*!
     * Normalise this vector
     * return a vector of lenght 1
     * @return
     */
    DVector2D Normalised() const;

    /*!
     * Get the lenght of the current DVector2D
     * @return lenght
     */
    double Length() const;

    /*! The x component of the DVector2D */
    double x;

    /*! The y component of the DVector2D */
    double y;
};

#endif //SDL2_DOUBLEVECTOR_H
