#include "UI_ScoreText.h"

UI_ScoreText::UI_ScoreText(const DVector2D &spawnPosition, const Rotation &spawnRotation, int _scoreToDraw)
        : GraphicsObject(spawnPosition, spawnRotation), score_to_draw(_scoreToDraw) {
}

void UI_ScoreText::Draw() {
    // Indent of the text
    DVector2D indent = DVector2D(60, 0);

    // a temporary number that will be modified when drawing
    int tempNum = score_to_draw;
    int posCounter = 0;

    while (true) {
        // Get the individual character
        int numToDraw = tempNum % 10;

        // Create a new one and draw it
        UI_Character ui_character = UI_Character(position + indent * posCounter, Rotation(0), numToDraw + '0');
        ui_character.Draw();

        // Calculate the remaining numbers
        tempNum = tempNum - numToDraw;
        tempNum /= 10;

        // Increment position counter
        posCounter++;

        // Break if there are no other number to be drawn
        if(tempNum == 0) break;
    }
}
