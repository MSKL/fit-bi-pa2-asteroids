#include "DLine.h"

DLine::DLine(double _x1, double _y1, double _x2, double _y2) {
    p1.x = _x1;
    p1.y = _y1;
    p2.x = _x2;
    p2.y = _y2;
}

DLine::DLine(const DVector2D &iv1, const DVector2D &iv2) {
    p1 = iv1;
    p2 = iv2;
}

double DLine::PerpDot(const DVector2D &a, const DVector2D &b) const {
    return (a.x * b.y) - (a.y * b.x);       // Dot product with perpendicular vector (=cross product)
}                                           // |a| * |b| * sin(f)

bool DLine::Intersection(const DLine &_dLine) const {
    DVector2D a(_dLine.p2 - _dLine.p1);       // delta vector of the other line
    DVector2D b(this->p2 - this->p1);       // delta vector of this line

    double f = PerpDot(a, b);

    if (!f) return false;                   // The lines are parallel

    DVector2D c(this->p2 - _dLine.p2);      // vector from point 1 and 2 end points
    double aa = PerpDot(a,c);               // perpdot from connector and delta a
    double bb = PerpDot(b,c);               // perpdot from connector and delta b

    if (f < 0) {
        if(aa > 0)
            return false;
        if(bb > 0)
            return false;
        if(aa < f)
            return false;
        if(bb < f)
            return false;
    }
    else {
        if(aa < 0)
            return false;
        if(bb < 0)
            return false;
        if(aa > f)
            return false;
        if(bb > f)
            return false;
    }

    return true;
}