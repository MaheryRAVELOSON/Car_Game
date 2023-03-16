#include "Jeu.h"
#include "winTxt.h"

void txtAff(WinTXT & win, const Jeu & jeu)
{


	win.clear();

    // Affichage de Voiture
	win.print(jeu.Ptr_Voiture->Voiture_Position->getCentreX(),
    jeu.Ptr_Voiture->Voiture_Position->getCentreY(),'P');

    // Affichage des obstacles

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.TailleX,jeu.TailleY);

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		//usleep(100000);
        #endif // WIN32

        //fonction qui fait bouger les obstacles

		c = win.getCh();
		switch (c) {
			case 'q':
				jeu.Ptr_Voiture->Deplacer_Gauche();
				break;
			case 'd':
				jeu.Ptr_Voiture->Deplacer_Droite(jeu.TailleX);
				break;
			case 'z':
				jeu.Ptr_Voiture->Deplacer_Haut(2);
				break;
			case 's':
				jeu.Ptr_Voiture->Deplacer_Bas(2, jeu.TailleY);
				break;
			case 'l':
				ok = false;
				break;
		}

	} while (ok);

}


int main(int argc, char** argv)
{
    termClear();
    Jeu JeuTxt(40, 50);
    txtBoucle(JeuTxt);
    termClear();
    return 0;
}