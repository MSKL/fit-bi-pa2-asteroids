#ifndef SDL2_GAMEMANAGER_H
#define SDL2_GAMEMANAGER_H

#include <fstream>
#include <stdio.h>
#include <algorithm>
#include "SDL2/SDL.h"
#include "SuperManager.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Asteroid.h"
#include "../Utility/Random.h"
#include "../GameObjects/UI/UI_PlayerIcon.h"
#include "../GameObjects/UI/UI_ScoreText.h"
#include "../GameObjects/UI/UI_AnyText.h"
#include "../GameObjects/UI/UI_Line.h"

/*!
 * GameManager class manages the game states
 * GameManager instantiates all GameObjects
 */
class GameManager {
public:
    /*!
     * Main game loop that runs the whole game
     * @return 0 for success 1 for error
     */
    int Run();

private:
    // The intro loop
    void LoopIntro();

    // Switch from Intro to Game
    void SwitchToGame();

    // The game loop
    void LoopGame();

    // Switch from Game to Scoreboard
    void SwitchToScoreboard();

    // Draw the Scoreboard
    void LoopScoreBoard();

    // Switch from Scoreboard to Intro
    void SwitchToIntro();

    // Get the vector of asteroids from the file
    std::vector<DVector2D> AsteroidPointsFromFile(std::ifstream & f);

    // Parse a file containing asteroid definitions
    void ParseAsteroidsFile(const char *fileName);

    // Parse the HighScores from the file
    std::vector<int> ParseHighScoresFile(const char *fileName);

    // Erases the file and writes the contents of the _inVect file
    void WriteToHighScoresFile(const char *fileName, std::vector<int> _inVect);

    // Spawn the biggest asteroids
    void SpawnNumOfBigAsteroids(const int _num);

    // Draws the UI in the GAME mode
    void DrawUI();

    // Ticks of last switch of scenes
    unsigned int last_switch = 0;

    // Vector of Vector of points form the file
    std::vector<std::vector<DVector2D>> asteroid_point_vectors;

    // Vector of highscores is used when drawing the scoreboard
    std::vector<int> high_score_vector;
};

#endif //SDL2_GAMEMANAGER_H