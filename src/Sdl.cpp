#include "Sdl.h"

//_____________________________________________________________________________
void Sdl::SdlConstructor(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)  //SDL_INIT_EVERYTHING aussi
    {
        cout<<endl<<"Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    fenetre = nullptr;
    fenetre = SDL_CreateWindow("CarGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              TailleEcran_X_sdl, TailleEcran_Y_sdl, SDL_WINDOW_SHOWN |
              SDL_WINDOW_RESIZABLE);

    if (fenetre == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError()
             << endl; 
        SDL_Quit(); 
        exit(1);
    }

    Rendu = nullptr;
    Rendu= SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);


}




//_____________________________________________________________________________
void Sdl::SdlDestuctor(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    SDL_DestroyRenderer(Rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}



//_____________________________________________________________________________
void Sdl::MAJ_SDL(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
//----------nettoyage de la fenêtre
    SDL_SetRenderDrawColor(Rendu, 0, 255, 0, 255);
    //mettre le vert comme rendu: Remplir l'écran de vert: le fond

    SDL_RenderClear(Rendu);  // nettoyage de la fenêtre
    //on remplis toute la fentre par le rendu

/*!!!!Remarque: le SetRenderDrawColor doit absolument avant le RenderClear*/


//----------Mis à jour
    SDL_Rect VarRect; 
    //declaration d'un coordonnée en type rectangle


    VarRect.h= Voiture_Joeur_Sdl->Voiture_Position->getRayon()*2;
    VarRect.w= Voiture_Joeur_Sdl->Voiture_Position->getRayon()*2;
    VarRect.x = Voiture_Joeur_Sdl->Voiture_Position->getX1();
    VarRect.y = Voiture_Joeur_Sdl->Voiture_Position->getY1();


    SDL_SetRenderDrawColor(Rendu, 0, 0, 255, 255);
    // définition de la couleur du pt

    SDL_RenderFillRect(Rendu, &VarRect);
        
//----------Affichage de la mis à jour
    SDL_RenderPresent(Rendu); 
    // MAJ de la fenêtre avec le nouveau dessiner
}


//_____________________________________________________________________________
void Sdl::afficherBoucle(SDL_Window* &fenetre, SDL_Renderer* &Rendu)
{
    SDL_Event evenement;
    bool isOpen= true;
    while (isOpen)
    {
        while (SDL_PollEvent(&evenement))
        {
            switch (evenement.type)
            {
                case SDL_QUIT:
                    isOpen = false;
                    break;
                case SDL_KEYDOWN:
                    if (evenement.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isOpen = false;
                        break;
                    }
                    if (evenement.key.keysym.sym == SDLK_q)
                    {
                        Voiture_Joeur_Sdl->Deplacer_Gauche();
                        //déplacement à gauche
                    }
                    if (evenement.key.keysym.sym == SDLK_d)
                    {
                        Voiture_Joeur_Sdl->Deplacer_Droite(TailleEcran_X_sdl);
                        //déplacement à droite
                    }
                    if (evenement.key.keysym.sym == SDLK_z)
                    {
                        //Voiture_Joeur_Sdl->Deplacer_Haut(2);
                        Voiture_Joeur_Sdl->Deplacer_Haut((* Niveau_Sdl));
                        //déplacement en haut
                    }
                    if (evenement.key.keysym.sym == SDLK_s)
                    {
                        //Voiture_Joeur_Sdl->Deplacer_Bas(2, TailleEcran_Y_sdl);
                        Voiture_Joeur_Sdl->Deplacer_Bas((* Niveau_Sdl), TailleEcran_Y_sdl);
                        //déplacement en bas
                    }
                default:
                    isOpen = true;
            }

//________________________________Parti de mis à jour___________________________________
            MAJ_SDL(fenetre, Rendu);
//____________________________fin de la Parti de mis à jour_______________________________
        }
    }
}


//_____________________________________________________________________________
void Sdl::afficher()
{
    SDL_Window* fenetre = nullptr;
    SDL_Renderer* Rendu = nullptr;
    SdlConstructor(fenetre, Rendu); 
    afficherBoucle(fenetre, Rendu);
    SdlDestuctor(fenetre, Rendu);
}


//_____________________________________________________________________________
Sdl::~Sdl()
{
    Voiture_Joeur_Sdl= nullptr;
    Niveau_Sdl=nullptr;

    /*Ces pointeur pointe sur des addresse memoire qui:
    - soit ont été alloué par
    la classe Jeu (donc qui sont aussi désalloué par le destructeur de cette
    classe)
    - soit sont des simple addresse memoire de variable de la classe Jeu et
    qui sont sur la pile: pas d'allocation.*/
}