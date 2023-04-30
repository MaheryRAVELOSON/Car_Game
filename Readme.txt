===========================noms/prénoms/numéros des étudiants==========================
- Yamani Abdeslam P2207683
- RAVELOSON Maherinirina P2003422

====================================comment compiler===================================
- "make" => il va créer les executable "Main", "Main_Sdl" et "Main_Txt". Il va aussi
  créer les objet "Jeu.o"  "Main.o"  "Main_Sdl.o"  "Main_Txt.o"  "Niveau.o"  "Obstacle.o"
  "Position.o"  "Score.o"  "Sdl.o"  "Voiture.o"  "winTxt.o"   
- pour mettre à jour la documentaion doxygen: "make maj"
- pour créer la documentation doxygen: "make doxy"

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
- le projet permet de créer un jeu de voiture dont le but est d'éviter des obstacles .
- On a 3 niveaux différent: Le niveau un est un démplacement verticale vers le bas de
  chaque obstacle. Le niveau 2 est le niveau 1 + dépalcement horizontale de chaque
  obstacle. Le Niveau 3 est le niveau 2 + grossissement/retrecissement de chaque obstacle.
  Après le niveau trois, la vitesse de déplacement de la voiture, le déplacement
  horizontale et verticale des obstacles s'incrément automatiquement tout les 3 obstacle
  qui arrive en bas de la fenêtre.
- Pour joueur au jeu:
	- la touche "q" pour déplacer la voiture vers la gauche.
	- la touche "d" pour déplacer la voiture vers la droite.
	- la touche "z" pour déplacer la voiture vers le haut: disponible qu'à partir du
	  niveau 2 inclus.
	- la touche "s" pour déplacer la voiture vers le bas: disponible qu'à partir du
	  niveau 2 inclus.
	- la touche "Echap" permet de fermer la fenêtre Sdl qui affiche le jeu.
============================ce que fait chacun des executables=========================
- l'executable "Main_Sdl" permet d'afficher le jeu dans une fenêtre SDL.
- l'executable "Main_Txt" affiche la voiture en mode texte sur le terminal.
- l'executable "Main" execute quelque teste de regression.

===============================l'organisation de l'archive=============================
- dossier src: il contient tout les fichier .cpp et .h ainsi que la documentation.h
- dossier data: il contient les images et la musique.
- dossier doc/: 
	- il contient le fichier de configuration de doxygen: NomModule.doxy.
	- il contient aussi le repertoire html/ qui contiendra la page index.html générée avec
	  doxygen
- dossier obj: il contient le .objet: les .o

============================La dépendance des fichiers/classes=========================
- On a 7 classes différents + 3 main.cpp (un pour le mode txt, un pour sdl, et un pour
  la teste de regression) ainsi que la documentation.h: Jeu, Niveau, Position, Score,
  Voiture, Obstacle,  Sdl (et le winTxt).
	- la classe Voiture a comme donnée membre la classe Position.
	- la classe Obstacle a comme donnée membre une tableau de classe Position
	- la classe Niveau inclus le Obstacle.h
	- la classe Jeux a comme donnée membre la classe Score, Niveau, Voiture, Obstacle
	- La classe Sdl a comme donnée membre la classe Jeu.
- le Main.cpp inclue la classe Jeu.h
- le Main_Txt.cpp inclues la classe Jeu.h et winTxt.h
- le Main_Sdl.cpp inclues la classe Sdl.h