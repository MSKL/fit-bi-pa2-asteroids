
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

# Linker flags are different on osx
LIBS_OSX = -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2
LIBS_LINUX = -lSDL2

# Output executable name
EXEC = ./skalimat

# All source (.cpp) files
SOURCES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp) $(wildcard src/*/*/*/*/*.cpp)

# All objectfiles (.h) from each cpp
OBJECTS = $(SOURCES:.cpp=.o)
 
#============================================================================================================================#

# Make for OSX testing
#Apple:
#	$(COMPILER) -c $(COMPILE_FLAGS) $(SOURCES)
#	-mkdir objectfiles 
#	-mv *.o objectfiles/ 
#	$(COMPILER) objectfiles/*.o $(LIBS_OSX) -o $(EXEC)

# Make for linux
$(EXEC): 
	$(COMPILER) -c $(COMPILE_FLAGS) $(SOURCES)
	-mkdir objectfiles 
	-mv *.o objectfiles/ 
	$(COMPILER) objectfiles/*.o $(LIBS_LINUX) -o $(EXEC)

#============================================================================================================================#

# Make all: generate the binary and documentation
all:
	make compile
	make doc

# Make compile
compile: $(EXEC)

# Clean
clean:
	-rm $(EXEC)
	-rm -rf doc objectfiles

# Create the documentation
doc:
	-mkdir doc
	doxygen Doxyfile

# Run the application
run:
	./$(EXEC)

# Get number of lines
count:
	find src -name *.h -print -o -name *.cpp -print | wc
