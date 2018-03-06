#include "DVector2D.h"

DVector2D::DVector2D(const double _x, const double _y)
        : x(_x), y(_y) {
}

DVector2D operator+(const DVector2D &left, const DVector2D &right) {
    return DVector2D (left.x + right.x, left.y + right.y);
}

DVector2D &operator+=(DVector2D &left, const DVector2D &right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

DVector2D &operator-=(DVector2D &left, const DVector2D &right) {
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

DVector2D operator-(const DVector2D &left, const DVector2D &right) {
    return DVector2D (left.x - right.x, left.y - right.y);
}

DVector2D operator*(const DVector2D &left, const double &right) {
    return DVector2D(left.x * right, left.y * right);
}

DVector2D operator*(const double &left, const DVector2D &right) {
    return right * left;
}

DVector2D operator/(const DVector2D &left, const double &right) {
    return DVector2D(left.x / right, left.y / right);
}

DVector2D DVector2D::RotateRad(const double _theta) const {
    double cs = cos(_theta);
    double sn = sin(_theta);

    return DVector2D(x * cs - y * sn, x * sn + y * cs);
}

DVector2D DVector2D::Normalised() const {
    double curLenght = Length();

    // If the lenght is 0, avoid division by 0
    if(curLenght == 0) {
        return DVector2D(0, 0);
    }

    return DVector2D(x / curLenght, y / curLenght);
}

double DVector2D::Length() const {
    return sqrt(x*x + y*y);
}
