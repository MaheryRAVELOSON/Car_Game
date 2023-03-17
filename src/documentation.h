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


//___________________________________________________________________________
 @section Label_compiler Pour compiler
Tapez la commande "make" dans le repertoire contenant le fichier Makefie puis 
ça créera dans le repertoire "bin" les executables "Main", "Main_Sdl" et 
"Main_Txt" . 


//___________________________________________________________________________
 @section Label_executer Pour executer
"./bin/Main": il va faire des tests de régression de plusieurs classes .
\n "./bin/Main_Sdl": il va afficher le jeu dans une fenetre SDL.
\n "./bin/Main_Txt": il va afficher le jeu en mode texte sur le terminal .


//___________________________________________________________________________
 @section Label_exec_valgrind executer avec Valgrind
"make v_t" pour executer le "Main" avec valgrind
\n "make v_s" pour executer le "Main_Sdl" avec valgrind
\n "make v_tx" pour executer le "Main_Txt" avec valgrind

*/
