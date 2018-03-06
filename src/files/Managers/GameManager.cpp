//
// Created by Matyáš Skalický on 25.07.17.
//

#include "GameManager.h"

int GameManager::Run() {
    // Load and parse the asteroids file. Exit on error..
    try {
        ParseAsteroidsFile(settings::GAME_ASTEROIDS_FILE);
    }
    catch (error::FileReadException) {
        std::cout << "Error in the asteroids.txt file syntax!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }
    catch (error::FileOpenException) {
        std::cout << "ERROR opening the asteroids.txt file!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }
    catch (...) {
        std::cout << "ERROR in the asteroids.txt file!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }

    // Try to check the highscores file to see if it exists and is valid
    try {
        ParseHighScoresFile(settings::GAME_HIGHSCORES_FILE);
    }
    catch (error::FileReadException) {
        std::cout << "Error in the highscores.txt file syntax!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }
    catch (error::FileOpenException) {
        std::cout << "ERROR opening the highscores.txt file!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }
    catch (...) {
        std::cout << "ERROR in the highscores.txt file!" << std::endl;
        std::cout << "Exiting the application. Check the file." << std::endl;
        return 1;
    }

    while (SuperManager::Instance()->inputManager.HandleInput())
    {
        // INTRO ================================================================================================ //
        if (SuperManager::Instance()->game_state == SuperManager::Instance()->Intro) {
            LoopIntro();

            // On space press go to main game
            if (SuperManager::Instance()->inputManager.GetSpace()) {
                if(SuperManager::Instance()->timerManager.GetCurrentTicks() - last_switch  > settings::GAME_SCENE_SWITCH_WAIT) {
                    SwitchToGame();
                }
            }
        }

        // GAME ================================================================================================= //
        if (SuperManager::Instance()->game_state == SuperManager::Instance()->Game) {
            if(SuperManager::Instance()->asteroid_list.size() == 0) {
                SuperManager::Instance()->IncrementLevel();
                SpawnNumOfBigAsteroids(SuperManager::Instance()->GetLevel() + settings::GAME_ASTEROIDS_START);
            }

            LoopGame();

            // When the player has 0 lives get to the ScoreBoard
            if (SuperManager::Instance()->player->GetLives() <= 0) {
                SwitchToScoreboard();
            }
        }

        // SCOREBOARD =========================================================================================== //
        if (SuperManager::Instance()->game_state == SuperManager::Instance()->Scoreboard) {
            LoopScoreBoard();

            // On space press go back to the Intro
            if (SuperManager::Instance()->inputManager.GetSpace()) {
                // Switch after a second has passed
                if(SuperManager::Instance()->timerManager.GetCurrentTicks() - last_switch  > settings::GAME_SCENE_SWITCH_WAIT) {
                    SwitchToIntro();
                }
            }
        }
    }

    // Destroy everything and quit SDL
    SuperManager::Instance()->Destroy();

    // Delete the singleton
    delete SuperManager::Instance();

    return 0;
}

void GameManager::LoopIntro() {
    // Spawn a logo at the right position
    DVector2D logo_center = DVector2D(settings::SCREEN_WIDTH / 2 - 270, settings::SCREEN_HEIGHT / 2);
    UI_AnyText * anyText = new UI_AnyText(logo_center, Rotation(0), "ASTEROIDS");

    // Push it into the graphics list
    SuperManager::Instance()->graphics_list.push_back(anyText);

    // Tick the graphics
    SuperManager::Instance()->TickGraphicsOnly();
}

void GameManager::SwitchToGame() {
    // Switch state to Game
    SuperManager::Instance()->game_state = SuperManager::Instance()->Game;

    // Update scores and level and reset validity
    SuperManager::Instance()->ResetLevel();
    SuperManager::Instance()->ResetScore();
    // Set the duration to 0 to reset any upgrades
    SuperManager::Instance()->SetUpgrade(SuperManager::terminator, 0);

    // Update last switch
    last_switch = SuperManager::Instance()->timerManager.GetCurrentTicks();

    // Spawn player
    DVector2D screen_center = DVector2D(settings::SCREEN_WIDTH / 2, settings::SCREEN_HEIGHT / 2);
    SuperManager::Instance()->player = new Player(screen_center, Rotation(M_PI));
}

void GameManager::SwitchToScoreboard() {
    try {
        // Get the previous ones
        high_score_vector = ParseHighScoresFile(settings::GAME_HIGHSCORES_FILE);

        // Add the current score
        high_score_vector.push_back(SuperManager::Instance()->GetScore());

        // Sort the vector
        std::sort(high_score_vector.begin(), high_score_vector.end(), std::greater<int>());

        // Remove the last one
        high_score_vector.erase(high_score_vector.end()-1);

        // Write the updated scores to the file
        WriteToHighScoresFile(settings::GAME_HIGHSCORES_FILE, high_score_vector);
    }
    catch (error::FileReadException) {
        std::cout << "Error in the highscores.txt file syntax!" << std::endl;
    }
    catch (error::FileOpenException) {
        std::cout << "ERROR opening the highscores.txt file!" << std::endl;
    }
    catch (...) {
        std::cout << "ERROR in the highscores.txt file!" << std::endl;
    }

    // Switch state to Scoreboard
    SuperManager::Instance()->game_state = SuperManager::Instance()->Scoreboard;

    // Update last switch
    last_switch = SuperManager::Instance()->timerManager.GetCurrentTicks();

    // Do a cleanup when exiting
    SuperManager::Instance()->Cleanup();
}

void GameManager::LoopGame() {
    // Draw the UI
    DrawUI();

    // Tick the game
    SuperManager::Instance()->TickGame();
}

void GameManager::LoopScoreBoard() {
    // Current score and label
    DVector2D cur_label_vect = DVector2D(settings::SCREEN_WIDTH / 6, settings::SCREEN_HEIGHT / 2 - 70);
    std::string cur_label_text = "SCORE";

    DVector2D score_cur_vect = DVector2D(settings::SCREEN_WIDTH / 6 + 400, settings::SCREEN_HEIGHT / 2 - 70);
    std::string score_cur_text = std::to_string(SuperManager::Instance()->GetScore());

    // Create the objects
    UI_AnyText * curLabel = new UI_AnyText(cur_label_vect, Rotation(0), cur_label_text);
    UI_AnyText * curScore = new UI_AnyText(score_cur_vect, Rotation(0), score_cur_text);

    // Push objects into the SuperManager
    SuperManager::Instance()->graphics_list.push_back(curLabel);
    SuperManager::Instance()->graphics_list.push_back(curScore);


    if (high_score_vector.size() == 3) {
        DVector2D best_label_vect = DVector2D(settings::SCREEN_WIDTH / 6, settings::SCREEN_HEIGHT / 2);
        std::string best_label_text = "BEST";
        DVector2D score_best1_vect = DVector2D(settings::SCREEN_WIDTH / 6 + 400, settings::SCREEN_HEIGHT / 2);
        std::string score_best1_text = std::to_string(high_score_vector[0]);
        DVector2D score_best2_vect = DVector2D(settings::SCREEN_WIDTH / 6 + 400, settings::SCREEN_HEIGHT / 2 + 70);
        std::string score_best2_text = std::to_string(high_score_vector[1]);
        DVector2D score_best3_vect = DVector2D(settings::SCREEN_WIDTH / 6 + 400, settings::SCREEN_HEIGHT / 2 + 140);
        std::string score_best3_text = std::to_string(high_score_vector[2]);

        UI_AnyText * bestLabel = new UI_AnyText(best_label_vect, Rotation(0), best_label_text);
        UI_AnyText * best1Score = new UI_AnyText(score_best1_vect, Rotation(0), score_best1_text);
        UI_AnyText * best2Score = new UI_AnyText(score_best2_vect, Rotation(0), score_best2_text);
        UI_AnyText * best3Score = new UI_AnyText(score_best3_vect, Rotation(0), score_best3_text);

        SuperManager::Instance()->graphics_list.push_back(bestLabel);
        SuperManager::Instance()->graphics_list.push_back(best1Score);
        SuperManager::Instance()->graphics_list.push_back(best2Score);
        SuperManager::Instance()->graphics_list.push_back(best3Score);
    }
    else {
        std::cout << "There was an error parsing the highscores.txt file!";
    }

    // Tick the graphics
    SuperManager::Instance()->TickGraphicsOnly();
}

void GameManager::SwitchToIntro() {
    // Switch state to Intro
    SuperManager::Instance()->game_state = SuperManager::Instance()->Intro;

    // Clean everything
    SuperManager::Instance()->Cleanup();

    // Update last switch
    last_switch = SuperManager::Instance()->timerManager.GetCurrentTicks();
}

std::vector<DVector2D> GameManager::AsteroidPointsFromFile(std::ifstream &f) {
    std::string             line;
    std::vector<DVector2D>  points;
    int                     x, y;

    while (std::getline(f, line))
    {
        if(line == "}") {
            return points;
        }

        // Parse the format from the file
        if (sscanf(line.c_str(), "(%d,%d)", &x, &y) == 2) {
            points.push_back(DVector2D(x, y));
        }
        else {
            throw error::FileReadException();
        }
    }
    throw error::FileReadException();
}

void GameManager::ParseAsteroidsFile(const char *fileName) {
    std::ifstream f (fileName);

    if (f.fail()) {
        f.close();
        throw error::FileOpenException();
    }

    std::string line;
    while (std::getline(f, line))
    {
        if (line == "Asteroid{") {
            asteroid_point_vectors.push_back(AsteroidPointsFromFile(f));
        }
        else {
            f.close();
            throw error::FileReadException();
        }
    }

    f.close();
}

std::vector<int> GameManager::ParseHighScoresFile(const char *fileName) {
    std::ifstream ifs (fileName);

    std::vector<int> scoresFromFile;
    if (ifs.fail()) {
        ifs.close();
        throw error::FileOpenException();
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        try {
            scoresFromFile.push_back(std::stoi( line ));
        } catch (...) {
            std::cout << "The highscore.txt file is corrupt!" << std::endl;
            ifs.close();
            throw error::FileReadException();
        }
    }

    ifs.close();

    if (scoresFromFile.size() != 3) {
        std::cout << "The highscore.txt contains more than 3 lines!" << std::endl;
        throw error::FileReadException();
    }

    return scoresFromFile;
}

void GameManager::WriteToHighScoresFile(const char *fileName, std::vector<int> _inVect) {
    std::ofstream ofs;

    if (_inVect.size() != 3) {
        std::cout << "The highscore.txt does not contain exactly 3 lines!" << std::endl;
        throw error::FileReadException();
    }

    // remove the contents of the file
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);

    if (ofs.fail()) {
        ofs.close();
        throw error::FileOpenException();
    }

    // Write to the file
    for (int i = 0; i < 3; i++) {
        ofs << _inVect[i] << "\n";
    }

    ofs.close();
}

void GameManager::SpawnNumOfBigAsteroids(const int _num) {
    Random rnd;
    DVector2D spawnPos;

    for (int i = 0; i < _num; i++) {
        // Set the random spawn Y position on the screen
        spawnPos.y = rnd.GetRandomDouble(settings::SCREEN_HEIGHT * (1/4.0), settings::SCREEN_HEIGHT * (3/4.0));

        // Check the player position X for asteroids to spawn so the player does not spawn on one of them
        if (SuperManager::Instance()->player != nullptr){
            if(SuperManager::Instance()->player->position.x < (settings::SCREEN_WIDTH / 2)){
                spawnPos.x =  settings::SCREEN_WIDTH * (3 / 4);
            } else {
                spawnPos.x = settings::SCREEN_WIDTH / 4;
            }
        }
        else {
            if (rnd.GetRandomInt(0, 1) == 0){
                spawnPos.x =  settings::SCREEN_WIDTH * (3 / 4);
            }
            else {
                spawnPos.x = settings::SCREEN_WIDTH / 4;
            }
        }

        // Choose a random asteroid from the list of asteroids
        int randAsteroidFromList = rnd.GetRandomInt(0, (int)asteroid_point_vectors.size() - 1);

        // Create a new Asteroid and save it in the SuperManager
        Asteroid * asteroid = new Asteroid(spawnPos, Rotation(0), asteroid_point_vectors[randAsteroidFromList], 0);
        SuperManager::Instance()->asteroid_list.push_back(asteroid);
    }
}

void GameManager::DrawUI() {
    // Draw lives
    for (int i = 0; i < SuperManager::Instance()->player->GetLives(); i++) {
        DVector2D iconPos = DVector2D(300, 300);

        iconPos.y = 20;
        iconPos.x = settings::SCREEN_WIDTH - 20 - i * 15;

        UI_PlayerIcon * playerIcon = new UI_PlayerIcon(iconPos, Rotation(M_PI));
        SuperManager::Instance()->graphics_list.push_back(playerIcon);
    }

    // Get the current time in ticks
    int currentTicks = SuperManager::Instance()->timerManager.GetCurrentTicks();

    // If there is an upgrade active, draw a bar indicating its duration
    if (SuperManager::Instance()->IsCurrentUpgradeActive()) {
        UI_Line * ui_line = new UI_Line((SuperManager::Instance()->GetUpgradeActiveUntil() - currentTicks) / 20, DVector2D(20, 20));
        SuperManager::Instance()->graphics_list.push_back(ui_line);
    }
}
