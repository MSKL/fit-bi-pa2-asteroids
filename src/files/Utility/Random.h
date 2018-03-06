#ifndef SDL2_RANDOM_H
#define SDL2_RANDOM_H

#include <random>
#include "DVector2D.h"
#include "../Settings/Settings.h"

/*!
 * Class for generating random numbers and vectors
 */
class Random {
public:
    /*!
     * Initialise the random number generator
     */
    Random() {
        // Initialise the random number generator
        rng = std::mt19937(rd());
    }

    /*!
     * Return a random position on a screen
     * @return random screen position
     */
    DVector2D GetRandomScreenPos() {
        // Nemůže být const kvůli RNG..
        std::uniform_int_distribution<int> wid(0, settings::SCREEN_WIDTH);
        std::uniform_int_distribution<int> hei(0, settings::SCREEN_HEIGHT);
        return DVector2D(wid(rng), hei(rng));
    }

    /*!
     * Get a random double in interval <-1, 1>
     * @return random in interval <-1, 1>
     */
    double GetRandomDouble11() {
        std::uniform_real_distribution<double> s(-1, 1);
        return s(rng);
    }

    /*!
     * Get a random double in interval <0, 1>
     * @return random in interval <0, 1>
     */
    double GetRandomDouble01() {
        std::uniform_real_distribution<double> s(0, 1);
        return s(rng);
    }

    /*!
     * Get a rendom double from range
     * @param _lowerBoundIncluded lower bound included
     * @param _upperBoundIncluded upper bound included
     * @return random double from range
     */
    double GetRandomDouble(const double _lowerBoundIncluded, const double _upperBoundIncluded) {
        std::uniform_real_distribution<double> s(_lowerBoundIncluded, _upperBoundIncluded);
        return s(rng);
    }

    /*!
     * Get a random integer from range
     * @param _lowerIncluded lower bound included
     * @param _upperBoundIncluded upper bound included
     * @return a random int from the range
     */
    int GetRandomInt(const int _lowerIncluded, const int _upperBoundIncluded) {
        std::uniform_int_distribution<int> s(_lowerIncluded, _upperBoundIncluded);
        return s(rng);
    }

    /*!
     * Generate a random vector of lenght 1
     * @return a random unit vector
     */
    DVector2D GetRandomUnitVector() {
        return GetRandomVector().Normalised();
    }

    /*!
     * Get a random vector with x: <-1, 1>, y: <-1, 1>
     * @return random vector with x and y in <-1, 1>
     */
    DVector2D GetRandomVector() {
        return DVector2D(GetRandomDouble11(), GetRandomDouble11());
    }

private:
    // used to initialise (seed) engine
    std::random_device rd;

    // random-number engine used
    std::mt19937 rng;
};

#endif //SDL2_RANDOM_H
