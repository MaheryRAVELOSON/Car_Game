/**
 @mainpage CarGame

//___________________________________________________________________________
 @section Label_intro Introduction
Le projet CarGame regroupe trois fichier principale (main):
 \n  Le Main.cpp: pour réaliser un test de regression. il permet de créer 
un fichier executable Main dans le repertoire bin .
 \n Le Main_Sdl.cpp pour afficher avec SDL , il permet de créer un fichier 
executable Main_Sdl dans le repertoire bin . 
 \n Le Main_Txt.cpp pour afficher le jeu en mode texte dans le terminal .
Il permet de créeer un fichier excutable Main_Txt dans le répertoire bin .
 \n le projet permet de créer un jeu de voiture dont le but est d'éviter des obstacles .
 \n On a 3 niveaux différent: Le niveau un est un démplacement verticale vers le bas de
  chaque obstacle. Le niveau 2 est le niveau 1 + dépalcement horizontale de chaque
  obstacle. Le Niveau 3 est le niveau 2 + grossissement/retrecissement de chaque obstacle.
  Après le niveau trois, la vitesse de déplacement de la voiture, le déplacement
  horizontale et verticale des obstacles s'incrément automatiquement tout les 3 obstacle
  qui arrive en bas de la fenêtre.
 \n Pour joueur au jeu:
 \n   la touche "q" pour déplacer la voiture vers la gauche.
 \n   la touche "d" pour déplacer la voiture vers la droite.
 \n   la touche "z" pour déplacer la voiture vers le haut: disponible qu'à partir du
	  niveau 2 inclus.
 \n   la touche "s" pour déplacer la voiture vers le bas: disponible qu'à partir du
	  niveau 2 inclus.
 \n   la touche "Echap" permet de fermer la fenêtre Sdl qui affiche le jeu.  


//___________________________________________________________________________
 @section Label_compiler Pour compiler
- "make" => il va créer les executable "Main", "Main_Sdl" et "Main_Txt". Il va aussi
  créer les objet "Jeu.o"  "Main.o"  "Main_Sdl.o"  "Main_Txt.o"  "Niveau.o"  "Obstacle.o"
  "Position.o"  "Score.o"  "Sdl.o"  "Voiture.o"  "winTxt.o"   
 \n pour mettre à jour la documentaion doxygen: "make maj"
 \n pour créer la documentation doxygen: "make doxy"


//___________________________________________________________________________
 @section Label_executer Pour executer
Depuis le repertoire contenant le Makefile:
 \n "./bin/Main" pour l'executable "Main"
 \n "./bin/Main_Sdl" pour l'executable "Main_Sdl"
 \n "./bin/Main_Txt" pour l'executable "Main_Txt"
 \n Pour les executer avec valgrind:
 \n     "make v_t" pour l'executable "Main"
 \n     "make v_s" pour l'executable "Main_Sdl"
 \n     "make v_tx" pour l'executable "Main_Txt"


//___________________________________________________________________________
 @section Label_exec_valgrind executer avec Valgrind
"make v_t" pour executer le "Main" avec valgrind
\n "make v_s" pour executer le "Main_Sdl" avec valgrind
\n "make v_tx" pour executer le "Main_Txt" avec valgrind

*/
