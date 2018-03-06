#include "SuperManager.h"

SuperManager *  SuperManager::instance      = nullptr;
SDLManager      SuperManager::sdlManager    = SDLManager();
InputManager    SuperManager::inputManager  = InputManager();
TimerManager    SuperManager::timerManager  = TimerManager();
RenderManager   SuperManager::renderManager = RenderManager();

SuperManager *SuperManager::Instance() {
    if(instance == nullptr) {
        instance = new SuperManager();
        instance->Initialise();
    }
    return instance;
}

void SuperManager::Destroy() {
    // Clean all allocated GameObjects
    Cleanup();

    // Quit the SDL
    sdlManager.QuitSDL();
}

SuperManager::~SuperManager() {
    // Use Destroy to quit
}

void SuperManager::TickGraphicsOnly() {
    // Start the FPS timer
    timerManager.StartTick();
    // Clear screen
    renderManager.ClearScreen(white);

    // Set color to black
    renderManager.SetColor(black);

    DrawList(graphics_list);
    CleanList(graphics_list);

    // Update screen
    SDL_RenderPresent(sdlManager.GetSDLRenderer());
    // Wait for the next frame
    timerManager.WaitForFPS(settings::GAME_FPS);
}

void SuperManager::TickGame() {
    // Start the FPS timer
    timerManager.StartTick();
    // Clear screen
    renderManager.ClearScreen(white);
    // Set color to black
    renderManager.SetColor(black);

    //// DO PHYSICS
    PhysicsTickList(shot_list);
    PhysicsTickList(asteroid_list);

    CheckToBeDestroyedList(shot_list);
    CheckToBeDestroyedList(upgrade_list);

    if (player != nullptr) {
        Instance()->player->Steer();
        Instance()->player->PhysicsTick();
    }

    //// CHECK BOUNDS
    CheckBoundCollisionsList(shot_list);
    CheckBoundCollisionsList(asteroid_list);

    if (player != nullptr) {
        Instance()->player->CheckSideCollisions();
    }

    //// CHECK Collisions
    PlayerAsteroidCollision();
    AsteroidShotCollision();
    PlayerUpgradeCollision();

    //// DRAW EVERYTHING
    DrawList(shot_list);
    DrawList(asteroid_list);
    DrawList(upgrade_list);
    DrawList(graphics_list);

    if (player != nullptr) {
        Instance()->player->Draw();
    }

    //// CLEAR GRAPHICS

    // Destroy all graphics
    CleanList(graphics_list);

    // Update screen
    SDL_RenderPresent(sdlManager.GetSDLRenderer());
    // Wait for the next frame
    timerManager.WaitForFPS(settings::GAME_FPS);
}

void SuperManager::Cleanup() {
    // Destroy the player
    if(player != nullptr) {
        delete player;
        player = nullptr;
    }

    // Clean all GameObjectLists
    CleanList(shot_list);
    CleanList(asteroid_list);
    CleanList(graphics_list);
    CleanList(upgrade_list);
}

int SuperManager::GetScore() const {
    return score;
}

void SuperManager::IncrementScore() {
    score++;
}

void SuperManager::ResetScore() {
    score = 0;
}

int SuperManager::GetLevel() const {
    return level;
}

void SuperManager::IncrementLevel() {
    level++;
}

void SuperManager::ResetLevel() {
    level = 0;
}

void SuperManager::SetUpgrade(SuperManager::UpgradeType _up, uint32_t _duration) {
    upgrade_valid_until = timerManager.GetCurrentTicks() + _duration;
    upgrade_current = _up;
}

SuperManager::UpgradeType SuperManager::GetCurrentUpgrade() const {
    return upgrade_current;
}

int SuperManager::GetUpgradeActiveUntil() const {
    return upgrade_valid_until;
}

bool SuperManager::IsCurrentUpgradeActive() const {
    return upgrade_valid_until - (int)timerManager.GetCurrentTicks() > 0;
}

void SuperManager::Initialise() {
    sdlManager.Initialise(settings::APP_NAME, settings::SCREEN_WIDTH, settings::SCREEN_HEIGHT); // Init the APP with settings from settings file
    renderManager.Initialise(sdlManager.GetSDLRenderer());                                      // Init the Renderer
}

void SuperManager::CleanList(std::list<GameObject *> &_toClean) {
    for(std::list<GameObject*>::iterator s = _toClean.begin(); s != _toClean.end(); s++) {
        if((*s) != nullptr) {
            delete (*s);
            (*s) = nullptr;
        }
    }
    _toClean.clear();
}

void SuperManager::DrawList(std::list<GameObject *> &_list) {
    for(std::list<GameObject*>::iterator s = _list.begin(); s != _list.end(); s++) {
        if((*s) != nullptr)
            (*s)->Draw();
    }
}

void SuperManager::PhysicsTickList(std::list<GameObject *> &_list) {
    for(std::list<GameObject*>::iterator s = _list.begin(); s != _list.end(); s++) {
        if((*s) != nullptr)
            (*s)->PhysicsTick();
    }
}

void SuperManager::CheckBoundCollisionsList(std::list<GameObject *> &_list) {
    for(std::list<GameObject*>::iterator s = _list.begin(); s != _list.end(); s++) {
        if((*s) != nullptr)
            (*s)->CheckSideCollisions();
    }
}

void SuperManager::CheckToBeDestroyedList(std::list<GameObject *> &_list) {
    for(std::list<GameObject*>::iterator s = _list.begin(); s != _list.end(); s++) {
        if((*s) != nullptr)
            if((*s)->ToDestroy()) {
                delete (*s);
                (*s) = nullptr;
                s = _list.erase(s);
            }
    }
}

void SuperManager::AsteroidShotCollision() {
    while(true) {
        // Set the collision flag to false
        bool collision = false;
        for(std::list<GameObject*>::iterator ast =  asteroid_list.begin(); ast !=  asteroid_list.end(); ast++) {
            for(std::list<GameObject*>::iterator sho = shot_list.begin(); sho != shot_list.end(); sho++) {
                // If there was a collision, break from both loops and start over
                if ((*ast)->Collision((*sho))) {

                    // Call GetHit on asteroid to spawn children
                    (*ast)->GetHit();

                    delete (*ast);
                    (*ast) = nullptr;
                    ast =  asteroid_list.erase(ast);

                    delete (*sho);
                    (*sho) = nullptr;
                    sho = shot_list.erase(sho);

                    collision = true;
                    break;
                }
            }
            if(collision) break;
        }

        // Break out of the loop if no collision happened
        if(!collision) break;
    }
}

void SuperManager::PlayerAsteroidCollision() {
    if(player != nullptr) {
        for (std::list<GameObject*>::iterator s = asteroid_list.begin(); s != asteroid_list.end(); s++) {
            if ((*s)->Collision(player)) {
                delete (*s);
                (*s) = nullptr;
                s = asteroid_list.erase(s);
                player->GetHit();
            }
        }
    }
}

void SuperManager::PlayerUpgradeCollision() {
    if(player != nullptr) {
        for (std::list<GameObject*>::iterator s = upgrade_list.begin(); s != upgrade_list.end(); s++) {
            if ((*s)->Collision(player)) {

                // Apply the hit to the upgrade
                (*s)->GetHit();

                delete (*s);
                (*s) = nullptr;
                s = upgrade_list.erase(s);
            }
        }
    }
}
