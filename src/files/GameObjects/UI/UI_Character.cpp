#include "UI_Character.h"

UI_Character::UI_Character(const DVector2D &spawnPosition, const Rotation &spawnRotation, const int _ASCIIcharToDraw)
        : GraphicsObject(spawnPosition, spawnRotation) {

    // The vector of points for the GraphicsObject
    std::vector<DVector2D> points;

    // Select the right letter
    if(_ASCIIcharToDraw == 'A') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -40));
        points.push_back(DVector2D(20, -60));
        points.push_back(DVector2D(40, -40));
        points.push_back(DVector2D(40, -20));
        points.push_back(DVector2D(0, -20));
        points.push_back(DVector2D(40, -20));
        points.push_back(DVector2D(40, -0));
    }
    else if(_ASCIIcharToDraw == 'S') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == 'T') {
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(20, -60));
        points.push_back(DVector2D(20, -0));
        points.push_back(DVector2D(20, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == 'E') {
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(30, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == 'R') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(20, -30));
        points.push_back(DVector2D(40, -0));
    }
    else if(_ASCIIcharToDraw =='O') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(0, -0));
    }
    else if(_ASCIIcharToDraw == 'I') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(20, -0));
        points.push_back(DVector2D(20, -60));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == 'D') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(20, -60));
        points.push_back(DVector2D(40, -40));
        points.push_back(DVector2D(40, -20));
        points.push_back(DVector2D(20, -0));
        points.push_back(DVector2D(0, -0));
    }
    else if(_ASCIIcharToDraw == 'C') {
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == 'P') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
    }
    else if(_ASCIIcharToDraw == 'B') {
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(30, -0));
        points.push_back(DVector2D(40, -10));
        points.push_back(DVector2D(40, -20));
        points.push_back(DVector2D(30, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(30, -60));
        points.push_back(DVector2D(40, -50));
        points.push_back(DVector2D(40, -40));
        points.push_back(DVector2D(30, -30));
    }
    else if(_ASCIIcharToDraw == '0') { // 0
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(0, -0));
    }
    else if(_ASCIIcharToDraw == '1') {
        points.push_back(DVector2D(20, -0));
        points.push_back(DVector2D(20, -60));
    }
    else if(_ASCIIcharToDraw == '2') {
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(0, -60));
    }
    else if(_ASCIIcharToDraw == '3') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(0, -60));
    }
    else if(_ASCIIcharToDraw == '4') {
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == '5') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
    }
    else if(_ASCIIcharToDraw == '6') {
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
    }
    else if(_ASCIIcharToDraw == '7') {
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -0));
    }
    else if(_ASCIIcharToDraw == '8') {
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -30));
    }
    else if(_ASCIIcharToDraw == '9') {
        points.push_back(DVector2D(0, -0));
        points.push_back(DVector2D(40, -0));
        points.push_back(DVector2D(40, -30));
        points.push_back(DVector2D(0, -30));
        points.push_back(DVector2D(0, -60));
        points.push_back(DVector2D(40, -60));
        points.push_back(DVector2D(40, -30));
    }
    else if(_ASCIIcharToDraw == ' ') {
        // Do nothing on space
    }
    else {
        // The character was not defined
        throw error::CharacterDoesNotExistException();
    }

    // Save the vector points into the GraphicsObject
    SetPointVector(points, false);
}
