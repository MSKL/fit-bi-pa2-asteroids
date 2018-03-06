#include "files/Managers/GameManager.h"

/*!
 * The main function that works as a beginning of the programme
 */
int main (void) {

    // Initialise the GameManager
    GameManager gameManager;

    // Run the game
    return gameManager.Run();
}

/*! \mainpage The classic game reborn
 *
 * \section intro Introduction
 *
 * This project was created as a semestral project for the PA2 subject at the FIT CTU. (Fakulta Informatiky ČVUT) <br>
 * I have tried to recreate the all time classic "Asteroids" using the SDL2 library. <br>
 * The main goal of this project was to work on a bigger project of length over 1000 lines of code. <br>
 *
 * \section handling Game controls
 *
 * The players ship is controlled by arrow keys. Shooting is set to the SPACEbar.
 *
 * \section requirements Project requirements (not translated)
 *
 *  Objekty, které je možné zničit (nepřátelské jednotky, statické barikády) <br>
 *  Pohybovat s hráčem (chůze panáčka, let vesmírné lodi, páčka na odrážení míčků) <br>
 *  Po zničení objektu s určitou pravděpodobností zůstane bonus, implementujte několik různých bonusů (munice, rychlejší nabíjení,...) <br>
 *  Implementujte jednoduchý "fyzikální" model (setrvačnost lodi, gravitace, odrážení, nabíjení zbrani,...) <br>
 *  Implementujte načítání (generátoru) mapy ze souboru a ukládání nejlepších skóre do souboru. <br>
 *
 * \section external_file External files requied
 *
 *  This game expects 2 files: <br>
 *  examples/<b>asteroids.txt</b> which contains definitions for the shapes of asteroids <br>
 *  examples/<b>highscores.txt</b> which contains high scores <br>
 *
 */