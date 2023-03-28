#include "Sdl.h"

//_____________________________________________________________________________
void Sdl::SdlConstructor(SDL_Window* &fenetre, SDL_Renderer* &Rendu, SDL_Surface* &surface)
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


    //initialisation de l'image de SDL2
    int imgFlags= IMG_INIT_JPG | IMG_INIT_PNG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }



    surface = IMG_Load("data/Car3.png"); //Charger une image 
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout<<endl<<"Error: cannot load data/Car3.png"<<endl;
        exit(1);
    }
    texture_V = SDL_CreateTextureFromSurface(Rendu, surface); //création d'une texture à partir de l'image



    surface = IMG_Load("data/obs.png"); //Charger une image 
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout<<endl<<"Error: cannot load data/obs.png"<<endl;
        exit(1);
    }
    texture_Obs = SDL_CreateTextureFromSurface(Rendu, surface); //création d'une texture à partir de l'image

    surface = IMG_Load("data/route.jpg"); //Charger une image 
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout<<endl<<"Error: cannot load data/route.jpg"<<endl;
        exit(1);
    }

    texture_R = SDL_CreateTextureFromSurface(Rendu, surface); //création d'une texture à partir de l'image
    if (texture_R == nullptr)
    {
        cerr << endl << "Error: SDL_CreateTextureFromSurface" << endl << flush;
        exit(1);
    }



}




//_____________________________________________________________________________
void Sdl::SdlDestuctor(SDL_Window* &fenetre, SDL_Renderer* &Rendu, SDL_Surface* &surface)
{
    SDL_DestroyRenderer(Rendu);
    SDL_DestroyWindow(fenetre);
    SDL_DestroyTexture(texture_V);
    SDL_DestroyTexture(texture_Obs);
    SDL_DestroyTexture(texture_R);
    SDL_FreeSurface(surface);
    IMG_Quit();
    SDL_Quit();
}



//_____________________________________________________________________________
void Sdl::MAJ_SDL(SDL_Window* &fenetre, SDL_Renderer* &Rendu, SDL_Surface* &surface)
{
//----------nettoyage de la fenêtre
    

    //SDL_SetRenderDrawColor(Rendu, 0, 255, 0, 255);
    //mettre le vert comme rendu: Remplir l'écran de vert: le fond
    //SDL_RenderClear(Rendu);  // nettoyage de la fenêtre
    //on remplis toute la fentre par le rendu



    SDL_RenderCopy(Rendu, texture_R, NULL, NULL); 



    

/*!!!!Remarque: le SetRenderDrawColor doit absolument avant le RenderClear*/


//----------Mis à jour
    SDL_Rect VarRect; 
    //declaration d'un coordonnée en type rectangle


    VarRect.h= Voiture_Joeur_Sdl->Voiture_Position->getRayon()*2;
    VarRect.w= Voiture_Joeur_Sdl->Voiture_Position->getRayon()*1.5;
    VarRect.x = Voiture_Joeur_Sdl->Voiture_Position->getX1();
    VarRect.y = Voiture_Joeur_Sdl->Voiture_Position->getY1();


    //SDL_SetRenderDrawColor(Rendu, 0, 0, 255, 255); //définition de la couleur du pt
    //SDL_RenderFillRect(Rendu, &VarRect);

    
    

    SDL_RenderCopy(Rendu, texture_V, NULL, &VarRect); 




    for (int i=0; i<ObstacleSdl->TailleTab_Obstacle; i++)
    {
        SDL_Rect VarRect;
        VarRect.w= ObstacleSdl->Tab_Obstacle[i].getX2() - ObstacleSdl->Tab_Obstacle[i].getX1();
        VarRect.h= ObstacleSdl->Tab_Obstacle[i].getY2() - ObstacleSdl->Tab_Obstacle[i].getY1();
        VarRect.x= ObstacleSdl->Tab_Obstacle[i].getX1();
        VarRect.y= ObstacleSdl->Tab_Obstacle[i].getY1();

        //SDL_SetRenderDrawColor(Rendu, 255, 255, 255, 255);
        //SDL_RenderFillRect(Rendu, &VarRect);

        SDL_RenderCopy(Rendu, texture_Obs, NULL, &VarRect);
    }
        
//----------Affichage de la mise à jour
    SDL_RenderPresent(Rendu); 
    // MAJ de la fenêtre avec le nouveau dessiner

}


//_____________________________________________________________________________
void Sdl::afficherBoucle(SDL_Window* &fenetre, SDL_Renderer* &Rendu, SDL_Surface* &surface)
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
        }
//________________________________Partie de mis à jour___________________________________
        ObstacleSdl->Mouv_Obs_Verticale();
        ObstacleSdl->Verif_Apparition();
        MAJ_SDL(fenetre, Rendu, surface);
//____________________________Fin de la partie de mise à jour_______________________________
    }
}


//_____________________________________________________________________________
void Sdl::afficher()
{
    SDL_Window* fenetre = nullptr;
    SDL_Renderer* Rendu = nullptr;
    SDL_Surface* surface = nullptr;
    SdlConstructor(fenetre, Rendu, surface); 
    afficherBoucle(fenetre, Rendu, surface);
    SdlDestuctor(fenetre, Rendu, surface);
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