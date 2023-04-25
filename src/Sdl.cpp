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
              JEU.TailleX, JEU.TailleY, SDL_WINDOW_SHOWN |
              SDL_WINDOW_RESIZABLE);

    if (fenetre == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError()
             << endl; 
        SDL_Quit(); 
        exit(1);
    }

    Rendu = nullptr;
    Rendu= SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);



//____________________________________Texture SDL
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
//____________________________________Fin Texture SDL



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

    VarRect.h= JEU.Ptr_Voiture->Voiture_Position->getY2() - JEU.Ptr_Voiture->Voiture_Position->getY1();
    VarRect.w= JEU.Ptr_Voiture->Voiture_Position->getX2() - JEU.Ptr_Voiture->Voiture_Position->getX1();
    VarRect.x = JEU.Ptr_Voiture->Voiture_Position->getX1();
    VarRect.y = JEU.Ptr_Voiture->Voiture_Position->getY1();


    //SDL_SetRenderDrawColor(Rendu, 0, 0, 255, 255); //définition de la couleur du pt
    //SDL_RenderFillRect(Rendu, &VarRect);

    
    

    SDL_RenderCopy(Rendu, texture_V, NULL, &VarRect); 




    for (int i=0; i<JEU.Obs->TailleTab_Obstacle; i++)
    {
        SDL_Rect VarRect;
        VarRect.w= JEU.Obs->Tab_Obstacle[i].getX2() - JEU.Obs->Tab_Obstacle[i].getX1();
        VarRect.h= JEU.Obs->Tab_Obstacle[i].getY2() - JEU.Obs->Tab_Obstacle[i].getY1();
        VarRect.x= JEU.Obs->Tab_Obstacle[i].getX1();
        VarRect.y= JEU.Obs->Tab_Obstacle[i].getY1();

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
    sleep(1);
    SDL_Event evenement;
    bool isOpen= true;
    bool fin_Jeu= false;
    while (isOpen)
    {
        fin_Jeu= JEU.Obs->Collision((* JEU.Ptr_Voiture));
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
                        if ((evenement.key.keysym.sym == SDLK_q) && (!fin_Jeu))
                        {
                            JEU.Ptr_Voiture->Deplacer_Gauche();
                            //déplacement à gauche
                        }
                        if ((evenement.key.keysym.sym == SDLK_d) && (!fin_Jeu))
                        {
                            JEU.Ptr_Voiture->Deplacer_Droite(JEU.TailleX);
                            //déplacement à droite
                        }
                        if ((evenement.key.keysym.sym == SDLK_z) && (!fin_Jeu))
                        {
                            //JEU.Ptr_Voiture->Deplacer_Haut(2);
                            JEU.Ptr_Voiture->Deplacer_Haut(JEU.Niveau);
                            //déplacement en haut
                        }
                        if ((evenement.key.keysym.sym == SDLK_s) && (!fin_Jeu))
                        {
                            //JEU.Ptr_Voiture->Deplacer_Bas(2, JEU.TailleY);
                            JEU.Ptr_Voiture->Deplacer_Bas(JEU.Niveau, JEU.TailleY);
                            //déplacement en bas
                        }
                        if ((evenement.key.keysym.sym == SDLK_r) && (!fin_Jeu))
                        {
                            afficher();
                            //On recommence le jeu.
                        }
                        if ((evenement.key.keysym.sym == SDLK_l))
                        {
                            isOpen = false;
                        }

                    default:
                        isOpen = true;
                }
            }
//________________________________Partie de mis à jour___________________________________
        if(!fin_Jeu)
        {    
            JEU.Niv->N3_Modif_Des_Coords((* JEU.Obs), JEU.Niveau);
            JEU.Niv->N1_Mouv_Verticale((* JEU.Obs));
            JEU.Niv->N2_Mouv_Horizontale((* JEU.Obs), JEU.TailleX, JEU.Niveau);

            JEU.Obs->Verif_Apparition(JEU.Score_Joueur, JEU.TailleX, JEU.TailleY,
            JEU.Niv->N3_Tab_Etat_de_Modif);
        }
            MAJ_SDL(fenetre, Rendu, surface);
            //cout<<endl<<JEU.Obs->Tab_Obstacle[0].getX1()<<endl;
    //----------MAJ des score
        if(JEU.Niveau<=4)
        {
            if(JEU.Score_Joueur.score>5)
            {
                JEU.Niveau= 2;
                if(JEU.Score_Joueur.score>10)
                {
                    JEU.Niveau= 3;
                }
            }
        }
    //----------------incrémentation des vitesse
        if(JEU.Score_Joueur.score_Majoree==15)
        {
            JEU.Niv->N1_Deplacement += 10*JEU.Niv->N1_Deplacement/100;
            JEU.Niv->N2_Deplacement += 10*JEU.Niv->N2_Deplacement/100;
            JEU.Ptr_Voiture->Deplacement += 10*JEU.Ptr_Voiture->Deplacement/100;
            JEU.Score_Joueur.score_Majoree= 0;

        } 
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

    //Rien de special
}