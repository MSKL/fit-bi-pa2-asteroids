#ifndef SDL2_DOUBLELINE_H
#define SDL2_DOUBLELINE_H

#include "DVector2D.h"

/*!
 * DLine class contains two DVector2D's and utility to manage the line
 */
class DLine {
public:
    /*!
     * Construct the DLine by individual coordinates
     * @param _x1 point 1 x
     * @param _y1 point 1 y
     * @param _x2 point 2 x
     * @param _y2 point 2 y
     */
    DLine(double _x1 = 0, double _y1 = 0, double _x2 = 0, double _y2 = 0);

    /*!
     * Construct the DLine by two DVector2D's
     * @param iv1 point 1
     * @param iv2 point 2
     */
    DLine(const DVector2D & iv1 = DVector2D(0, 0), const DVector2D & iv2 = DVector2D(0, 0));

    /*!
     * Check for intersection between two line segments
     * @param _dLine other line of intersection
     * @return true if there is an intersection of line segments
     */
    bool Intersection(const DLine & _dLine) const;

    /*! point 1 of the line */
    DVector2D p1;

    /*! point 2 of the line */
    DVector2D p2;

private:
    // Perpendicular dot calculates the product
    double PerpDot (const DVector2D& a, const DVector2D& b) const;
};

#endif //SDL2_DOUBLELINE_H
