# make all nebo make vytvoří veškeré výstupy, generované ze zdrojového kódu.
# make compile vytvoří binární podobu semestrální práce, výsledek bude uložen do souboru <login>/<login>.
# make run spustí binární podobu semestrální práce.
# make clean smaže všechny vygenerované soubory a uvede adresář <login> do původního stavu.
# make doc vygeneruje dokumentaci do adresáře <login>/doc. Dokumentace může být vytvořená staticky ve formátu HTML (pak <tt>make doc</tt> nebude nic) nebo dynamicky generovaná programem doxygen (generována pouze v HTML).

# V Makefile smí být použity pouze tyto programy: rm, gcc, g++, mkdir, doxygen, cp, mv, cd, ar, make.

# Adresář <login>/src ve kterém budou všechny zdrojové kódy, tedy soubory .cpp, .c, .h, .hpp, apod.
# Adresář <login>/examples: zde budou obsaženy ukázkové vstupní soubory, pokud to charakter úlohy dovoluje.
# Adresář <login>/doc: pouze pokud není vaše dokumentace generovaná automaticky pomocí příkazu <tt>make doc</tt>.

# Set the compiler
COMPILER = g++

# Declare the compile flags
COMPILE_FLAGS = -Wall -pedantic -Wno-long-long -O0 -ggdb -g -std=c++11

# Linker flags are different on osx /Headers
LIBS_OSX = -I/Library/Frameworks/SDL2.framework/ -framework SDL2
LIBS_LINUX = -lSDL2

# Output executable name
EXEC = ./asteroids

#============================================================================================================================#

# Default rules for linux
$(EXEC): Asteroid.o Flame.o Player.o Shot.o UI_AnyText.o UI_Character.o UI_Line.o UI_PlayerIcon.o UI_ScoreText.o Upgrade.o InputManager.o RenderManager.o SDLManager.o SuperManager.o TimerManager.o Color.o DLine.o DVector2D.o Random.o Rotation.o main.o CollidableObject.o GameObject.o GraphicsObject.o PhysicsObject.o 
	$(COMPILER) *.o $(LIBS_LINUX) -o $(EXEC)

# Rules for OSX
Apple: Asteroid.o Flame.o Player.o Shot.o UI_AnyText.o UI_Character.o UI_Line.o UI_PlayerIcon.o UI_ScoreText.o Upgrade.o InputManager.o RenderManager.o SDLManager.o SuperManager.o TimerManager.o Color.o DLine.o DVector2D.o Random.o Rotation.o main.o CollidableObject.o GameObject.o GraphicsObject.o PhysicsObject.o 
	$(COMPILER) *.o $(LIBS_OSX) -o $(EXEC)

# Make compile
compile: $(EXEC)

# Make all: generate the binary and documentation
all:
	make compile
	make doc

# Run the application
run:
	$(EXEC)

# Clean
clean:
	-rm *.o
	-rm -rf doc
	-rm $(EXEC)

# Create the documentation
doc:
	-mkdir doc
	doxygen Doxyfile

#============================================================================================================================#

Asteroid.o: src/files/GameObjects/Asteroid.cpp \
	src/files/GameObjects/Asteroid.h \
	src/files/GameObjects/../GameObjectTypes/PhysicsObject.h \
	src/files/GameObjects/../GameObjectTypes/CollidableObject.h \
	src/files/GameObjects/../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/../GameObjectTypes/GameObject.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/Settings.h \
	src/files/GameObjects/../Utility/Random.h \
	src/files/GameObjects/Upgrade.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@	

Player.o: src/files/GameObjects/Player.cpp src/files/GameObjects/Player.h \
	src/files/GameObjects/../GameObjectTypes/PhysicsObject.h \
	src/files/GameObjects/../GameObjectTypes/CollidableObject.h \
	src/files/GameObjects/../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/../GameObjectTypes/GameObject.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/Settings.h \
	src/files/GameObjects/Shot.h src/files/GameObjects/Flame.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Flame.o: src/files/GameObjects/Flame.cpp src/files/GameObjects/Flame.h \
	src/files/GameObjects/../Managers/SuperManager.h \
	src/files/GameObjects/../Managers/InputManager.h \
	src/files/GameObjects/../Managers/TimerManager.h \
	src/files/GameObjects/../Managers/SDLManager.h \
	src/files/GameObjects/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/../Managers/RenderManager.h \
	src/files/GameObjects/../Managers/../Utility/Color.h \
	src/files/GameObjects/../Managers/../Utility/DLine.h \
	src/files/GameObjects/../Managers/../Utility/DVector2D.h \
	src/files/GameObjects/../Managers/../Settings/Settings.h \
	src/files/GameObjects/../Managers/../GameObjectTypes/GameObject.h \
	src/files/GameObjects/../Managers/../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/../GameObjectTypes/GraphicsObject.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Shot.o: src/files/GameObjects/Shot.cpp src/files/GameObjects/Shot.h \
	src/files/GameObjects/../GameObjectTypes/PhysicsObject.h \
	src/files/GameObjects/../GameObjectTypes/CollidableObject.h \
	src/files/GameObjects/../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/../GameObjectTypes/GameObject.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

UI_AnyText.o: src/files/GameObjects/UI/UI_AnyText.cpp \
	src/files/GameObjects/UI/UI_AnyText.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GameObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/Settings.h \
	src/files/GameObjects/UI/UI_Character.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

UI_Character.o: src/files/GameObjects/UI/UI_Character.cpp \
	src/files/GameObjects/UI/UI_Character.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GameObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

UI_Line.o: src/files/GameObjects/UI/UI_Line.cpp \
	src/files/GameObjects/UI/UI_Line.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GameObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

UI_PlayerIcon.o: src/files/GameObjects/UI/UI_PlayerIcon.cpp \
	src/files/GameObjects/UI/UI_PlayerIcon.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GameObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

UI_ScoreText.o: src/files/GameObjects/UI/UI_ScoreText.cpp \
	src/files/GameObjects/UI/UI_ScoreText.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/GameObject.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/UI/../../GameObjectTypes/../Managers/../Settings/Settings.h \
	src/files/GameObjects/UI/UI_Character.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Upgrade.o: src/files/GameObjects/Upgrade.cpp \
	src/files/GameObjects/Upgrade.h \
	src/files/GameObjects/../GameObjectTypes/CollidableObject.h \
	src/files/GameObjects/../GameObjectTypes/GraphicsObject.h \
	src/files/GameObjects/../GameObjectTypes/GameObject.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjects/../GameObjectTypes/../Utility/Color.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjects/../GameObjectTypes/../Managers/../Settings/Settings.h \
	src/files/GameObjects/../Utility/Random.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

CollidableObject.o: src/files/GameObjectTypes/CollidableObject.cpp \
	src/files/GameObjectTypes/CollidableObject.h \
	src/files/GameObjectTypes/GraphicsObject.h \
	src/files/GameObjectTypes/GameObject.h \
	src/files/GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjectTypes/../Utility/Color.h \
	src/files/GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

GameObject.o: src/files/GameObjectTypes/GameObject.cpp \
	src/files/GameObjectTypes/GameObject.h \
	src/files/GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjectTypes/../Settings/ThrowErrors.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

GraphicsObject.o: src/files/GameObjectTypes/GraphicsObject.cpp \
	src/files/GameObjectTypes/GraphicsObject.h \
	src/files/GameObjectTypes/GameObject.h \
	src/files/GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjectTypes/../Utility/Color.h \
	src/files/GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

PhysicsObject.o: src/files/GameObjectTypes/PhysicsObject.cpp \
	src/files/GameObjectTypes/PhysicsObject.h \
	src/files/GameObjectTypes/CollidableObject.h \
	src/files/GameObjectTypes/GraphicsObject.h \
	src/files/GameObjectTypes/GameObject.h \
	src/files/GameObjectTypes/../Utility/DVector2D.h \
	src/files/GameObjectTypes/../Utility/Rotation.h \
	src/files/GameObjectTypes/../Utility/Color.h \
	src/files/GameObjectTypes/../Managers/SuperManager.h \
	src/files/GameObjectTypes/../Managers/InputManager.h \
	src/files/GameObjectTypes/../Managers/TimerManager.h \
	src/files/GameObjectTypes/../Managers/SDLManager.h \
	src/files/GameObjectTypes/../Managers/../Settings/ThrowErrors.h \
	src/files/GameObjectTypes/../Managers/RenderManager.h \
	src/files/GameObjectTypes/../Managers/../Utility/DLine.h \
	src/files/GameObjectTypes/../Managers/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

InputManager.o: src/files/Managers/InputManager.cpp \
	src/files/Managers/InputManager.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

RenderManager.o: src/files/Managers/RenderManager.cpp \
	src/files/Managers/RenderManager.h \
	src/files/Managers/../Settings/ThrowErrors.h \
	src/files/Managers/../Utility/Color.h \
	src/files/Managers/../Utility/DLine.h \
	src/files/Managers/../Utility/DVector2D.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

SDLManager.o: src/files/Managers/SDLManager.cpp \
	src/files/Managers/SDLManager.h \
	src/files/Managers/../Settings/ThrowErrors.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

SuperManager.o: src/files/Managers/SuperManager.cpp \
	src/files/Managers/SuperManager.h src/files/Managers/InputManager.h \
	src/files/Managers/TimerManager.h src/files/Managers/SDLManager.h \
	src/files/Managers/../Settings/ThrowErrors.h \
	src/files/Managers/RenderManager.h \
	src/files/Managers/../Utility/Color.h \
	src/files/Managers/../Utility/DLine.h \
	src/files/Managers/../Utility/DVector2D.h \
	src/files/Managers/../Settings/Settings.h \
	src/files/Managers/../GameObjectTypes/GameObject.h \
	src/files/Managers/../GameObjectTypes/../Utility/Rotation.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

TimerManager.o: src/files/Managers/TimerManager.cpp \
	src/files/Managers/TimerManager.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Color.o: src/files/Utility/Color.cpp src/files/Utility/Color.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

DLine.o: src/files/Utility/DLine.cpp src/files/Utility/DLine.h \
	src/files/Utility/DVector2D.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

DVector2D.o: src/files/Utility/DVector2D.cpp \
	src/files/Utility/DVector2D.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Random.o: src/files/Utility/Random.cpp src/files/Utility/Random.h \
	src/files/Utility/DVector2D.h src/files/Utility/../Settings/Settings.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

Rotation.o: src/files/Utility/Rotation.cpp src/files/Utility/Rotation.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@

main.o: src/main.cpp src/files/Managers/GameManager.h \
	src/files/Managers/SuperManager.h src/files/Managers/InputManager.h \
	src/files/Managers/TimerManager.h src/files/Managers/SDLManager.h \
	src/files/Managers/../Settings/ThrowErrors.h \
	src/files/Managers/RenderManager.h \
	src/files/Managers/../Utility/Color.h \
	src/files/Managers/../Utility/DLine.h \
	src/files/Managers/../Utility/DVector2D.h \
	src/files/Managers/../Settings/Settings.h \
	src/files/Managers/../GameObjectTypes/GameObject.h \
	src/files/Managers/../GameObjectTypes/../Utility/Rotation.h \
	src/files/Managers/../GameObjects/Player.h \
	src/files/Managers/../GameObjects/../GameObjectTypes/PhysicsObject.h \
	src/files/Managers/../GameObjectTypes/CollidableObject.h \
	src/files/Managers/../GameObjectTypes/GraphicsObject.h \
	src/files/Managers/../GameObjects/Shot.h \
	src/files/Managers/../GameObjects/Flame.h \
	src/files/Managers/../GameObjects/Asteroid.h \
	src/files/Managers/../GameObjects/../Utility/Random.h \
	src/files/Managers/../GameObjects/Upgrade.h \
	src/files/Managers/../GameObjects/UI/UI_PlayerIcon.h \
	src/files/Managers/../GameObjects/UI/UI_ScoreText.h \
	src/files/Managers/../GameObjects/UI/UI_Character.h \
	src/files/Managers/../GameObjects/UI/UI_AnyText.h \
	src/files/Managers/../GameObjects/UI/UI_Line.h
	$(COMPILER) -c $(COMPILE_FLAGS) $< -o $@