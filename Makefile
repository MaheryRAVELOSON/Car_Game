MAIN= src/Main
POSITION= src/Position
SCORE= src/Score
JEU= src/Jeu
VOITURE = src/Voiture


POSITION_O = obj/Position.o
MAIN_O = obj/Main.o
SCORE_O = obj/Score.o
JEU_O = obj/Jeu.o
VOITURE_O = obj/Voiture.o


MAIN_OUT = bin/Main

INCLUDE_DIR_SDL = -I/usr/include/SDL2
PETIT_L = -lSDL2 -lSDL2_ttf -lSDL2_image


all: $(MAIN_OUT)

$(MAIN_OUT): $(MAIN_O) $(POSITION_O) $(SCORE_O) $(JEU_O) $(VOITURE_O)
	g++ -g $(MAIN_O) $(POSITION_O) $(SCORE_O) $(JEU_O) $(VOITURE_O) -o $(MAIN_OUT) $(PETIT_L)


$(MAIN_O): $(POSITION).h $(MAIN).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAIN).cpp -o $(MAIN_O)

$(POSITION_O): $(POSITION).h $(POSITION).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(POSITION).cpp -o $(POSITION_O)

$(SCORE_O): $(SCORE).h $(SCORE).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(SCORE).cpp -o $(SCORE_O)

$(JEU_O): $(JEU).h $(JEU).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(JEU).cpp -o $(JEU_O)

$(VOITURE_O): $(VOITURE).h $(VOITURE).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(VOITURE).cpp -o $(VOITURE_O)

clean:
	rm bin/* obj/*

v_t:
	valgrind $(MAIN_OUT)