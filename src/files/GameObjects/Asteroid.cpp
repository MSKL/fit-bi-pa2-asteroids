#include "Asteroid.h"

Asteroid::Asteroid(const DVector2D &spawnPosition, const Rotation &spawnRotation, const std::vector<DVector2D> &_points,
                   const int _asteroidSize, const DVector2D _derivedVelocity, const double &_derivedAngularVelocity)
        : PhysicsObject(spawnPosition, spawnRotation), asteroid_size(_asteroidSize) {

    // Save the points passed in by contructor into the GraphicsObject
    SetPointVector(_points, true);

    // The random number generator
    Random rnd;

    // Based on the size of asteroid resize and set the velocity
    switch(_asteroidSize){
        case(0): // Big asteroid
            RescaleGraphics(12);
            angular_velocity    = _derivedAngularVelocity + rnd.GetRandomDouble11() / 20;
            velocity            = _derivedVelocity + rnd.GetRandomVector() / 4;
            break;
        case(1): // Middle asteroid
            RescaleGraphics(0.5);
            angular_velocity    = _derivedAngularVelocity + rnd.GetRandomDouble11() / 10;
            velocity            = _derivedVelocity + rnd.GetRandomVector() * 3;
            break;
        case(2): // Small asteroid
            RescaleGraphics(0.5);
            angular_velocity    = _derivedAngularVelocity + rnd.GetRandomDouble11() / 5;
            velocity            = _derivedVelocity + rnd.GetRandomVector() * 3;
            break;
        default:
            std::cout << "Unknown size of Asteroid!" << std::endl;
            break;
    }
}

void Asteroid::GetHit() {
    // Random number generator
    Random rnd;

    // Get a random number of asteroids to be spawned
    int randNum = rnd.GetRandomInt(2, 5);

    // From 0 to 1
    if (asteroid_size == 0) {
        for (int i = 0; i < randNum; i++) {
            Asteroid * asteroid = new Asteroid(position, rotation, GetPointVector(), 1, velocity, angular_velocity);
            SuperManager().Instance()->asteroid_list.push_back(asteroid);
        }
    }

    // From 1 to 2
    if (asteroid_size == 1) {
        for (int i = 0; i < randNum; i++) {
            Asteroid * asteroid = new Asteroid(position, rotation, GetPointVector(), 2, velocity, angular_velocity);
            SuperManager().Instance()->asteroid_list.push_back(asteroid);
        }
    }

    // Increase score by 1
    SuperManager().Instance()->IncrementScore();

    // There is a chance that the powerup will be generated
    if(rnd.GetRandomDouble01() < settings::GAME_UPGRADE_DROP_CHANCE) {
        // Create the upgrade and put it inside an according list
        Upgrade * upgrade = new Upgrade(position, rotation);
        SuperManager().Instance()->upgrade_list.push_back(upgrade);
    }
}
