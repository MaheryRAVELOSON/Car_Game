MAIN= src/Main
POSITION= src/Position

POSITION_O = obj/Position.o
MAIN_O = obj/Main.o

MAIN_OUT = bin/Main

INCLUDE_DIR_SDL = -I/usr/include/SDL2
PETIT_L = -lSDL2 -lSDL2_ttf -lSDL2_image


all: $(MAIN_OUT)

$(MAIN_OUT): $(MAIN_O) $(POSITION_O)
	g++ -g $(MAIN_O) $(POSITION_O) -o $(MAIN_OUT) $(PETIT_L)


$(MAIN_O): $(POSITION).h $(MAIN).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAIN).cpp -o $(MAIN_O)

$(POSITION_O): $(POSITION).h $(POSITION).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(IMAGE).cpp -o $(IMAGE_O)


clean:
	rm bin/* obj/*

valgrind:
	valgrind $(MAIN_OUT)