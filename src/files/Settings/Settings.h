#ifndef SDL2_GLOBALS_H
#define SDL2_GLOBALS_H

/*!
 * Includes core settings for tweaking the gameplay
 */
namespace settings {

    //   _____                         __  __  _
    //  / ___/__ ___ _  ___   ___ ___ / /_/ /_(_)__  ___ ____
    // / (_ / _ `/  ' \/ -_) (_-</ -_) __/ __/ / _ \/ _ `(_-<
    // \___/\_,_/_/_/_/\__/ /___/\__/\__/\__/_/_//_/\_, /___/
    //                                             /___/

    /*! The screen width */
    static const int SCREEN_WIDTH   = 800;
    /*! The screen height */
    static const int SCREEN_HEIGHT  = 600;

    /*! Name of the application */
    static const char* APP_NAME             = "Asteroids by Matyáš Skalický";

    /*! The location of the asteroid definition file */
    static const char* GAME_ASTEROIDS_FILE  = "examples/asteroids.txt";
    /*! The location of the highscores file */
    static const char* GAME_HIGHSCORES_FILE = "examples/highscores.txt";

    /*! Number of the frames per second for game to be refreshed */
    static const int GAME_FPS = 60;

    /*! The number of asteroids in the beginning of the game. Real number is +1 */
    static const int GAME_ASTEROIDS_START = 3;

    /*! Minimum wait time when switching scenes */
    static const int GAME_SCENE_SWITCH_WAIT = 1000;

    /*! Chance that an upgrade will be dropped after an asteroid was destroyed */
    static const double GAME_UPGRADE_DROP_CHANCE = 0.15;

    //    ___  __                            __  __  _
    //   / _ \/ /__ ___ _____ ____  ___ ___ / /_/ /_(_)__  ___ ____
    //  / ___/ / _ `/ // / -_) __/ (_-</ -_) __/ __/ / _ \/ _ `(_-<
    // /_/  /_/\_,_/\_, /\__/_/   /___/\__/\__/\__/_/_//_/\_, /___/
    //             /___/                                 /___/

    /*! The number of lives for player to start with */
    static const int PLAYER_START_LIVES = 3;

    /*! The acceleration speed of the players ship  */
    static const double PLAYER_ACCELERATION_SPEED   = 0.15;
    /*! The rotation speed of the players ship */
    static const double PLAYER_ROTATION_SPEED       = 1.0 / 20.0;
    /*! The maximum speed of the player */
    static const double PLAYER_MAX_SPEED            = 5;
    /*! The velocity damping of the players ship, should be between 0 and 1 */
    static const double PLAYER_VELOCITY_DAMP        = 0.99;

}

#endif //SDL2_GLOBALS_H
