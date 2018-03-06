#include "UI_AnyText.h"

UI_AnyText::UI_AnyText(const DVector2D &spawnPosition, const Rotation &spawnRotation, const std::string &_toDraw)
        : GraphicsObject(spawnPosition, spawnRotation), to_draw(_toDraw) {
}

void UI_AnyText::Draw() {
    // The indent of characters
    DVector2D indent = DVector2D(60, 0);

    // Draw all the individual characters
    for (int i = 0; i < (int)to_draw.size(); i++) {
        UI_Character ui_character = UI_Character(position + indent * i, Rotation(0), to_draw[i]);
        ui_character.Draw();
    }
}
