#include "Player.h"

Player::Player(const DVector2D &spawnPosition, const Rotation &spawnRotation)
        : PhysicsObject(spawnPosition, spawnRotation){

    lives_remaining = settings::PLAYER_START_LIVES;
    velocity_damp = settings::PLAYER_VELOCITY_DAMP;

    // Construct player's spaceship
    std::vector<DVector2D> points;
    points.push_back(DVector2D(0, 10));
    points.push_back(DVector2D(5, -7));
    points.push_back(DVector2D(-5, -7));

    SetPointVector(points, true);
}

void Player::Accelerate() {
    // Make 2D acc vector pointing up
    DVector2D acc = DVector2D(0, settings::PLAYER_ACCELERATION_SPEED);

    // Rotate it according to current ship's rotation
    acc = acc.RotateRad(rotation.GetRAD());

    // Add it to the current speed
    if(velocity.Length() < settings::PLAYER_MAX_SPEED) {
        velocity += acc;
    }
}

void Player::Steer() {
    // Steer to sides
    rotation.SetRAD(rotation.GetRAD() + SuperManager().Instance()->inputManager.GetHorizontal() * settings::PLAYER_ROTATION_SPEED);

    // Accelerate forward
    if(SuperManager().Instance()->inputManager.GetVertical() == 1) {
        // Accelerate the ship
        Accelerate();

        Flame* flame = new Flame(position + velocity, rotation.GetRAD() + angular_velocity);
        SuperManager().Instance()->graphics_list.push_back(flame);
    }

    // Shoot with SPACE
    if(SuperManager().Instance()->inputManager.GetSpace()) {
        Shoot();
    }
}

void Player::GetHit() {
    if (SuperManager().Instance()->IsCurrentUpgradeActive()
        && (SuperManager().Instance()->GetCurrentUpgrade() == SuperManager::terminator)) {
        // Do not remove lives if the terminator is active
    }
    else {
        lives_remaining--;
    }
}

void Player::Draw() {
    // Draw with different color when in terminator mode
    if ((SuperManager().Instance()->IsCurrentUpgradeActive())
        && (SuperManager().Instance()->GetCurrentUpgrade() == SuperManager::terminator)) {
        SuperManager().Instance()->renderManager.SetColor(Color(208, 60, 242));
        GraphicsObject::Draw();
        SuperManager().Instance()->renderManager.SetColor(black);
    }
    else {
        GraphicsObject::Draw();
    }
}

void Player::AddLife() {
    lives_remaining++;
}

int Player::GetLives() const {
    return lives_remaining;
}

void Player::Shoot() {
    // Get the current ticks
    int currentTicks = SuperManager().Instance()->timerManager.GetCurrentTicks();

    // Do not shoot if there is an delay
    if (currentTicks - lastTimeShot < delay) {
        return;
    }

    // Update the last time a shot was fired
    lastTimeShot = currentTicks;

    // Calculate the directions of shot and default spawn position
    DVector2D shipTip_local = GetPointVector()[0].RotateRad(rotation.GetRAD());
    DVector2D shipTip_global = position + shipTip_local;
    DVector2D shotVelocity = shipTip_local.Normalised() * 4 + velocity;

    // If the upgrade is still valid, apply it..
    if ((SuperManager().Instance()->IsCurrentUpgradeActive())
        && (SuperManager().Instance()->GetCurrentUpgrade() == SuperManager::tripleshoot)) {
        Shot* shot1 = new Shot(shipTip_global, rotation.GetRAD() + 0.3, shotVelocity.RotateRad(0.3), 500, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot1);
        Shot* shot2 = new Shot(shipTip_global, rotation.GetRAD(), shotVelocity, 500, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot2);
        Shot* shot3 = new Shot(shipTip_global, rotation.GetRAD() - 0.3, shotVelocity.RotateRad(-0.3), 500, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot3);

        // Set the delay for the next shot
        delay = 100;
    }
    else if ((SuperManager().Instance()->IsCurrentUpgradeActive())
             && (SuperManager().Instance()->GetCurrentUpgrade() == SuperManager::doubleshoot)) {

        DVector2D normal = (shipTip_local.RotateRad(M_PI / 2).Normalised());

        Shot* shot1 = new Shot(shipTip_global - normal * 2, rotation.GetRAD(), shotVelocity, 1000, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot1);
        Shot* shot2 = new Shot(shipTip_global + normal * 2, rotation.GetRAD(), shotVelocity, 1000, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot2);

        // Set the delay for the next shot
        delay = 50;
    }
    else {
        Shot* shot = new Shot(shipTip_global, rotation.GetRAD(), shotVelocity, 2000, currentTicks);
        SuperManager().Instance()->shot_list.push_back(shot);

        // Set the delay for the next shot
        delay = 200;
    }
}
