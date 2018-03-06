#include "Rotation.h"

Rotation::Rotation(double _RADRotation) {
    RADRotation = _RADRotation;
}

void Rotation::SetRAD(double _RADRotation) {
    RADRotation = _RADRotation;
}

double Rotation::GetRAD() const {
    return RADRotation;
}
