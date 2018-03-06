#include "Upgrade.h"

Upgrade::Upgrade(const DVector2D &spawnPosition, const Rotation &spawnRotation)
        : CollidableObject(spawnPosition, spawnRotation), timeToLive(3000) {

    // Set the time of creation
    timeCreated = SuperManager().Instance()->timerManager.GetCurrentTicks();

    // Randomness generator
    Random rnd;

    // get a random type
    upgrade_type = SuperManager::UpgradeType(rnd.GetRandomInt(0, 3));

    // The vector of points for the GraphicsObject
    std::vector<DVector2D> points;

    switch(upgrade_type) {
        case SuperManager::life:
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(10, 5));
            points.push_back(DVector2D(10, -5));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-5, -10));
            points.push_back(DVector2D(-10, -5));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-5, 10));
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(0, -5));
            points.push_back(DVector2D(-5, 10));
            break;
        case SuperManager::doubleshoot:
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(10, 5));
            points.push_back(DVector2D(10, -5));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-5, -10));
            points.push_back(DVector2D(-10, -5));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-5, 10));
            points.push_back(DVector2D(10, -5));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-5, 10));
            break;
        case SuperManager::tripleshoot:
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(10, 5));
            points.push_back(DVector2D(10, -5));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-5, -10));
            points.push_back(DVector2D(-10, -5));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-5, 10));
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-10, -5));
            break;
        case SuperManager::terminator:
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(10, 5));
            points.push_back(DVector2D(10, -5));
            points.push_back(DVector2D(5, -10));
            points.push_back(DVector2D(-5, -10));
            points.push_back(DVector2D(-10, -5));
            points.push_back(DVector2D(-10, 5));
            points.push_back(DVector2D(-5, 10));
            points.push_back(DVector2D(5, 10));
            points.push_back(DVector2D(0, 10));
            points.push_back(DVector2D(0, -5));
            points.push_back(DVector2D(0, 10));
            points.push_back(DVector2D(-5, 10));
            break;
        default:
            throw error::UpgradeDoesNotExistException();
    }

    // Save the vector of points
    SetPointVector(points);
}

void Upgrade::Draw() {
    // Change the color according to the type
    switch(upgrade_type) {
        case SuperManager::life:
            SuperManager().Instance()->renderManager.SetColor(Color(61, 221, 229));
            break;
        case SuperManager::doubleshoot:
            SuperManager().Instance()->renderManager.SetColor(Color(249, 97, 97));
            break;
        case SuperManager::tripleshoot:
            SuperManager().Instance()->renderManager.SetColor(Color(68, 252, 108));
            break;
        case SuperManager::terminator:
            SuperManager().Instance()->renderManager.SetColor(Color(208, 60, 242));
            break;
    }

    // Draw the GraphicsObject with color changed
    GraphicsObject::Draw();

    // Switch the color back
    SuperManager().Instance()->renderManager.SetColor(black);
}

bool Upgrade::ToDestroy() const {
    // Check if the Upgrade lived too long and should be destroyed
    return (SuperManager().Instance()->timerManager.GetCurrentTicks() - timeCreated > timeToLive);
}

void Upgrade::GetHit() {
    // Based on the tyoe of upgrade apply the upgrades
    switch(upgrade_type) {
        case SuperManager::life:
            SuperManager().Instance()->player->AddLife();
            break;
        case SuperManager::terminator:
            SuperManager().Instance()->SetUpgrade(upgrade_type, 4000);
            break;
        case SuperManager::doubleshoot:
            SuperManager().Instance()->SetUpgrade(upgrade_type, 3000);
            break;
        case SuperManager::tripleshoot:
            SuperManager().Instance()->SetUpgrade(upgrade_type, 3000);
            break;
    }
}
