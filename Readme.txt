===========================noms/prénoms/numéros des étudiants==========================
- Yamani Abdeslam P2207683
- RAVELOSON Maherinirina P2003422

====================================comment compiler===================================
"make" => il va créer les executable "Main", "Main_Sdl" et "Main_Txt". Il va aussi créer objet 
Jeu.o  Main.o  Main_Sdl.o  Main_Txt.o  Position.o  Score.o  Sdl.o  Voiture.o  winTxt.o

====================================comment executer===================================
Depuis le repertoire contenant le Makefile:
- "./bin/Main" pour l'executable "Main"
- "./bin/Main_Sdl" pour l'executable "Main_Sdl"
- "./bin/Main_Txt" pour l'executable "Main_Txt"
- Pour les executer avec valgrind:
    - "make v_t" pour l'executable "Main"
    - "make v_s" pour l'executable "Main_Sdl"
    - "make v_tx" pour l'executable "Main_Txt"

==================================Ce que fait le projet================================
- le projet permet un jeu de voiture en evitant des obstacles . 
- Il affiche sur une fenetre SDL ou en mode texte sur le terminal . 

============================ce que fait chacun des executables=========================
- l'executable "Main" permet de faire le test de regression .
- lexecutable "Main_Sdl" permet d'afficher le jeu en SDL .
- l'executable "Main_Txt" permet d'afficher le jeu en mode texte sur le terminal .

===============================l'organisation de l'archive=============================
- dossier src: il contient tout les fichier .cpp et .h
- dossier data: il contient les images .
- dossier doc/: 
	- il contient le fichier de configuration de doxygen: NomModule.doxy.
	- il contient aussi le repertoire html/ qui contiendra la page index.html générée avec
	  doxygen
- dossier obj: il contient le objet: les .o