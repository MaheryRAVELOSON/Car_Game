MAIN= src/Main
POSITION= src/Position
SCORE= src/Score

POSITION_O = obj/Position.o
MAIN_O = obj/Main.o
SCORE_O = obj/Score.o


MAIN_OUT = bin/Main

INCLUDE_DIR_SDL = -I/usr/include/SDL2
PETIT_L = -lSDL2 -lSDL2_ttf -lSDL2_image


all: $(MAIN_OUT)

$(MAIN_OUT): $(MAIN_O) $(POSITION_O) $(SCORE_O)
	g++ -g $(MAIN_O) $(POSITION_O) $(SCORE_O) -o $(MAIN_OUT) $(PETIT_L)


$(MAIN_O): $(POSITION).h $(MAIN).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAIN).cpp -o $(MAIN_O)

$(POSITION_O): $(POSITION).h $(POSITION).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(POSITION).cpp -o $(POSITION_O)

$(SCORE_O): $(SCORE).h $(SCORE).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(SCORE).cpp -o $(SCORE_O)

clean:
	rm bin/* obj/*

v_t:
	valgrind $(MAIN_OUT)