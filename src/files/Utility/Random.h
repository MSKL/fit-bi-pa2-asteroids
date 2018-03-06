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
    Random();

    /*!
     * Return a random position on a screen
     * @return random screen position
     */
    DVector2D GetRandomScreenPos();

    /*!
     * Get a random double in interval <-1, 1>
     * @return random in interval <-1, 1>
     */
    double GetRandomDouble11();

    /*!
     * Get a random double in interval <0, 1>
     * @return random in interval <0, 1>
     */
    double GetRandomDouble01();

    /*!
     * Get a rendom double from range
     * @param _lowerBoundIncluded lower bound included
     * @param _upperBoundIncluded upper bound included
     * @return random double from range
     */
    double GetRandomDouble(const double _lowerBoundIncluded, const double _upperBoundIncluded);

    /*!
     * Get a random integer from range
     * @param _lowerIncluded lower bound included
     * @param _upperBoundIncluded upper bound included
     * @return a random int from the range
     */
    int GetRandomInt(const int _lowerIncluded, const int _upperBoundIncluded);

    /*!
     * Generate a random vector of lenght 1
     * @return a random unit vector
     */
    DVector2D GetRandomUnitVector();

    /*!
     * Get a random vector with x: <-1, 1>, y: <-1, 1>
     * @return random vector with x and y in <-1, 1>
     */
    DVector2D GetRandomVector();

private:
    // used to initialise (seed) engine
    std::random_device rd;

    // random-number engine used
    std::mt19937 rng;
};

#endif //SDL2_RANDOM_H
