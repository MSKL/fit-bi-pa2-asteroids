# Asteroids by Matyáš Skalický
## The classic game reborn
This project was created as a semestral project for the PA2 subject at the FIT CTU (Fakulta Informatiky ČVUT). I have tried to recreate the all time classic "Asteroids" using the SDL2 library. The main goal of this project was to work on a bigger project of length over 1000 lines of code. 

## Game controls
The players ship is controlled by arrow keys. Shooting is set to the SPACEbar.

## Project requirements (not translated)
- Objekty, které je možné zničit (nepřátelské jednotky, statické barikády) 
- Pohybovat s hráčem (chůze panáčka, let vesmírné lodi, páčka na odrážení míčků) 
- Po zničení objektu s určitou pravděpodobností zůstane bonus, implementujte několik různých bonusů (munice, rychlejší nabíjení,...) 
- Implementujte jednoduchý "fyzikální" model (setrvačnost lodi, gravitace, odrážení, nabíjení zbrani,...) 
- Implementujte načítání (generátoru) mapy ze souboru a ukládání nejlepších skóre do souboru. 

## External files requied
This game expects 2 files: 
- `examples/asteroids.txt` which contains definitions for the shapes of asteroids 
- `examples/highscores.txt` which contains high scores 

## Documentation
Run `make doc` to generate the doxygene documentation. The documentation is generated into the `doc` folder. View the /doc/index.html file to see the generated documentation.

## How to compile
This project relies on the SDL2 framework that must be installed.
- On Linux type `make` to compile the project
- On OSX type `make Apple` to compile the project

To run the game type `make run`. Have Fun!

