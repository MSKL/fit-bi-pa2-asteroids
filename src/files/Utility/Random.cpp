//
// Created by Matyáš Skalický on 11.05.17.
//

#include "Random.h"

Random::Random() {
    // Initialise the random number generator
    rng = std::mt19937(rd());
}

DVector2D Random::GetRandomScreenPos() {
    // Nemůže být const kvůli RNG..
    std::uniform_int_distribution<int> wid(0, settings::SCREEN_WIDTH);
    std::uniform_int_distribution<int> hei(0, settings::SCREEN_HEIGHT);
    return DVector2D(wid(rng), hei(rng));
}

double Random::GetRandomDouble11() {
    std::uniform_real_distribution<double> s(-1, 1);
    return s(rng);
}

double Random::GetRandomDouble01() {
    std::uniform_real_distribution<double> s(0, 1);
    return s(rng);
}

double Random::GetRandomDouble(const double _lowerBoundIncluded, const double _upperBoundIncluded) {
    std::uniform_real_distribution<double> s(_lowerBoundIncluded, _upperBoundIncluded);
    return s(rng);
}

int Random::GetRandomInt(const int _lowerIncluded, const int _upperBoundIncluded) {
    std::uniform_int_distribution<int> s(_lowerIncluded, _upperBoundIncluded);
    return s(rng);
}

DVector2D Random::GetRandomUnitVector() {
    return GetRandomVector().Normalised();
}

DVector2D Random::GetRandomVector() {
    return DVector2D(GetRandomDouble11(), GetRandomDouble11());
}
