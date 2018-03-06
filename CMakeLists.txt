cmake_minimum_required(VERSION 3.7)
project(SDL2)

# See the compilation output in CLion
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2_SOURCE_DIR}/cmake")

set(SOURCE_FILES src/main.cpp src/files/GameObjectTypes/GameObject.h
        src/files/Settings/ThrowErrors.h src/files/Utility/Rotation.h
        src/files/GameObjectTypes/GraphicsObject.h src/files/Managers/RenderManager.h src/files/Utility/Color.h
        src/files/GameObjects/Player.h src/files/Managers/InputManager.h src/files/GameObjectTypes/PhysicsObject.h
        src/files/Utility/DLine.h src/files/Utility/DVector2D.h src/files/Managers/TimerManager.h
        src/files/GameObjects/Asteroid.h src/files/Managers/SuperManager.h src/files/GameObjects/Shot.h
        src/files/GameObjectTypes/CollidableObject.h src/files/GameObjects/Flame.h src/files/Utility/DVector2D.cpp
        src/files/Utility/DLine.cpp src/files/Utility/Rotation.cpp src/files/Utility/Color.cpp src/files/Utility/Random.cpp
        src/files/Utility/Random.h src/files/Settings/Settings.h
        src/files/Managers/GameManager.h src/files/Managers/SDLManager.h src/files/GameObjects/UI/UI_PlayerIcon.h
        src/files/GameObjects/UI/UI_Character.h src/files/GameObjects/UI/UI_ScoreText.h src/files/GameObjects/UI/UI_AnyText.h src/files/Managers/InputManager.cpp src/files/Managers/RenderManager.cpp src/files/Managers/SDLManager.cpp src/files/Managers/TimerManager.cpp src/files/GameObjects/Upgrade.h src/files/GameObjects/UI/UI_Line.h src/files/Managers/SuperManager.cpp src/files/GameObjectTypes/GameObject.cpp src/files/GameObjectTypes/GraphicsObject.cpp src/files/GameObjectTypes/CollidableObject.cpp src/files/GameObjectTypes/PhysicsObject.cpp src/files/GameObjects/UI/UI_AnyText.cpp src/files/GameObjects/UI/UI_Character.cpp src/files/GameObjects/UI/UI_Line.cpp src/files/GameObjects/UI/UI_PlayerIcon.cpp src/files/GameObjects/UI/UI_ScoreText.cpp src/files/GameObjects/Asteroid.cpp src/files/GameObjects/Flame.cpp src/files/GameObjects/Upgrade.cpp src/files/GameObjects/Shot.cpp src/files/GameObjects/Player.cpp src/files/Managers/GameManager.cpp)
add_executable(Asteroids ${SOURCE_FILES} src/files/GameObjectTypes/GameObject.h)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(Asteroids ${SDL2_LIBRARY})