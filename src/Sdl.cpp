#include "Sdl.h"

//_____________________________________________________________________________
Sdl::Sdl()
{
    fenetre = nullptr;
    Rendu = nullptr;
    surface = nullptr;
    Indice_Texture_R= -1;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // SDL_INIT_EVERYTHING aussi
    {
        cout << endl
             << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    else
    {
//-----------------------------Partie Audio SDL
        SDL_Init(SDL_INIT_AUDIO); // initilisation de  SDL2_mixer pour l'audio
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        music = Mix_LoadMUS("data/music.mp3"); // chargement du fichier audio
        if (!music)
        {
            cout << "erreur de chargement du fichier audio : " << Mix_GetError() << endl;
            exit(1);
        }
        Mix_PlayMusic(music, -1); // lecture de  la musique en boucle
//----------------------------Fin de la partie audio
    }

    fenetre = nullptr;
    fenetre = SDL_CreateWindow("CarGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               JEU.TailleX, JEU.TailleY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (fenetre == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError()
             << endl;
        SDL_Quit();
        exit(1);
    }

    Rendu = nullptr;
    Rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);

    //____________________________________Texture SDL
    // initialisation de l'image de SDL2
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    surface = IMG_Load("data/V.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/V.png" << endl;
        exit(1);
    }
    texture_V = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image

    surface = IMG_Load("data/V2.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/V2.png" << endl;
        exit(1);
    }
    texture_V2 = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image

    surface = IMG_Load("data/obs.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/obs.png" << endl;
        exit(1);
    }
    texture_Obs = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image

    surface = IMG_Load("data/R0.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/R0.png" << endl;
        exit(1);
    }
    texture_R0 = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image
    if (texture_R0 == nullptr)
    {
        cerr << endl
             << "Error: SDL_CreateTextureFromSurface" << endl
             << flush;
        exit(1);
    }

    surface = IMG_Load("data/R1.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/R1.png" << endl;
        exit(1);
    }
    texture_R1 = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image
    if (texture_R1 == nullptr)
    {
        cerr << endl
             << "Error: SDL_CreateTextureFromSurface" << endl
             << flush;
        exit(1);
    }

    surface = IMG_Load("data/R2.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/R2.png" << endl;
        exit(1);
    }
    texture_R2 = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image
    if (texture_R2 == nullptr)
    {
        cerr << endl
             << "Error: SDL_CreateTextureFromSurface" << endl
             << flush;
        exit(1);
    }

    surface = IMG_Load("data/R3.png"); // Charger une image
    //  !!!On ne met pas de .. devant le data !!!
    if (surface == nullptr)
    {
        cout << endl
             << "Error: cannot load data/R3.png" << endl;
        exit(1);
    }
    texture_R3 = SDL_CreateTextureFromSurface(Rendu, surface); // création d'une texture à partir de l'image
    if (texture_R3 == nullptr)
    {
        cerr << endl
             << "Error: SDL_CreateTextureFromSurface" << endl
             << flush;
        exit(1);
    }
    //____________________________________affichage texte SDL______________________
    
    if(TTF_Init() < 0)
    {
        cout<<endl<<"Erreur d'initialisation du TTF_init()" << endl;
        assert(TTF_Init());
    }
    textColor.r = 255;
    textColor.g = 0;
    textColor.b = 0;

    font = TTF_OpenFont("data/Font/SimplySans-Bold.ttf",24);
    if(font == nullptr)
    {
        cout << endl <<"Erreur d'ouverture du font "<< endl;
        assert(font != nullptr);
    }
}

//_____________________________________________________________________________
Sdl::~Sdl()
{   
    TTF_CloseFont(font);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_Quit();

    Mix_FreeMusic(music);
    Mix_CloseAudio();

    SDL_DestroyRenderer(Rendu);
    SDL_DestroyWindow(fenetre);
    SDL_DestroyTexture(texture_V);
    SDL_DestroyTexture(texture_V2);
    SDL_DestroyTexture(texture_Obs);
    SDL_DestroyTexture(texture_R0);
    SDL_DestroyTexture(texture_R1);
    SDL_DestroyTexture(texture_R2);
    SDL_DestroyTexture(texture_R3);
    SDL_FreeSurface(surface);
    IMG_Quit();
    SDL_Quit();
}

//_____________________________________________________________________________
void Sdl::MAJ_SDL()
{
    //----------nettoyage de la fenêtre

    // SDL_SetRenderDrawColor(Rendu, 0, 255, 0, 255);
    // mettre le vert comme rendu: Remplir l'écran de vert: le fond
    // SDL_RenderClear(Rendu);  // nettoyage de la fenêtre
    // on remplis toute la fentre par le rendu

    Indice_Texture_R ++;
    if(Indice_Texture_R>3)
    {
        Indice_Texture_R= 0;
    }

    if(Indice_Texture_R==0)
    {
        SDL_RenderCopy(Rendu, texture_R0, NULL, NULL);
    }
    if(Indice_Texture_R==1)
    {
        SDL_RenderCopy(Rendu, texture_R1, NULL, NULL);
    }
    if(Indice_Texture_R==2)
    {
        SDL_RenderCopy(Rendu, texture_R2, NULL, NULL);
    }
    if(Indice_Texture_R==3)
    {
        SDL_RenderCopy(Rendu, texture_R3, NULL, NULL);
    }

    /*!!!!Remarque: le SetRenderDrawColor doit absolument avant le RenderClear*/

    //----------Mis à jour
    SDL_Rect VarRect;
    // declaration d'un coordonnée en type rectangle

    VarRect.h = JEU.Ptr_Voiture->Voiture_Position->getY2() - JEU.Ptr_Voiture->Voiture_Position->getY1();
    VarRect.w = JEU.Ptr_Voiture->Voiture_Position->getX2() - JEU.Ptr_Voiture->Voiture_Position->getX1();
    VarRect.x = JEU.Ptr_Voiture->Voiture_Position->getX1();
    VarRect.y = JEU.Ptr_Voiture->Voiture_Position->getY1();

    // SDL_SetRenderDrawColor(Rendu, 0, 0, 255, 255); //définition de la couleur du pt
    // SDL_RenderFillRect(Rendu, &VarRect);

    if(JEU.Niveau<=2)
    {
        SDL_RenderCopy(Rendu, texture_V, NULL, &VarRect);
    }
    else
    {
        SDL_RenderCopy(Rendu, texture_V2, NULL, &VarRect);
    }


    for (int i = 0; i < JEU.Obs->TailleTab_Obstacle; i++)
    {
        SDL_Rect VarRect;
        VarRect.w = JEU.Obs->Tab_Obstacle[i].getX2() - JEU.Obs->Tab_Obstacle[i].getX1();
        VarRect.h = JEU.Obs->Tab_Obstacle[i].getY2() - JEU.Obs->Tab_Obstacle[i].getY1();
        VarRect.x = JEU.Obs->Tab_Obstacle[i].getX1();
        VarRect.y = JEU.Obs->Tab_Obstacle[i].getY1();

        // SDL_SetRenderDrawColor(Rendu, 255, 255, 255, 255);
        // SDL_RenderFillRect(Rendu, &VarRect);

        SDL_RenderCopy(Rendu, texture_Obs, NULL, &VarRect);
    }
    //-----------------------------------------affichage texte
        string Affiche_Score= to_string(JEU.Score_Joueur.score);
        Affiche_Score = "Score: " + Affiche_Score;
        
        textRect.x = 10;
        textRect.y = 10;
        textRect.w = 70;
        textRect.h = 50;
        
        textSurface= TTF_RenderText_Blended(font, Affiche_Score.c_str(),textColor);
        if (textSurface == nullptr)
        {
            cout<<endl<<"Erreur de TTF_RenderText_Blended"<<endl;
            assert(textSurface != nullptr);
        }
        
        textTexture= SDL_CreateTextureFromSurface(Rendu, textSurface);
        if (textTexture == nullptr)
        {
            cout<<endl<<"Erreur de SDL_CreateTextureFromSurface"<<endl;
            assert(textTexture != nullptr);
        }
        
        SDL_RenderCopy(Rendu, textTexture, NULL,&textRect);
    
    //----------Affichage de la mise à jour
    SDL_RenderPresent(Rendu);
    // MAJ de la fenêtre avec le nouveau dessiner
}

//_____________________________________________________________________________
void Sdl::afficherBoucle()
{
    sleep(1);
    SDL_Event evenement;
    bool isOpen = true;
    bool fin_Jeu = false;
    while (isOpen)
    {
        fin_Jeu = JEU.Obs->Collision((*JEU.Ptr_Voiture));
        if (fin_Jeu)
        {
            Mix_HaltMusic();
        }
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
                    // déplacement à gauche
                }
                if ((evenement.key.keysym.sym == SDLK_d) && (!fin_Jeu))
                {
                    JEU.Ptr_Voiture->Deplacer_Droite(JEU.TailleX);
                    // déplacement à droite
                }
                if ((evenement.key.keysym.sym == SDLK_z) && (!fin_Jeu))
                {
                    // JEU.Ptr_Voiture->Deplacer_Haut(2);
                    JEU.Ptr_Voiture->Deplacer_Haut(JEU.Niveau);
                    // déplacement en haut
                }
                if ((evenement.key.keysym.sym == SDLK_s) && (!fin_Jeu))
                {
                    // JEU.Ptr_Voiture->Deplacer_Bas(2, JEU.TailleY);
                    JEU.Ptr_Voiture->Deplacer_Bas(JEU.Niveau, JEU.TailleY);
                    // déplacement en bas
                }
                if ((evenement.key.keysym.sym == SDLK_r) && (!fin_Jeu))
                {
                    afficher();
                    // On recommence le jeu.
                }
                if ((evenement.key.keysym.sym == SDLK_o))
                {
                    isOpen = false;
                }

            default:
                isOpen = true;
            }
        }
        //________________________________Partie de mis à jour___________________________________
        if (!fin_Jeu)
        {
            JEU.Niv->N3_Modif_Des_Coords((*JEU.Obs), JEU.Niveau);
            JEU.Niv->N1_Mouv_Verticale((*JEU.Obs));
            JEU.Niv->N2_Mouv_Horizontale((*JEU.Obs), JEU.TailleX, JEU.Niveau);

            JEU.Obs->Verif_Apparition(JEU.Score_Joueur, JEU.TailleX, JEU.TailleY,
                                      JEU.Niv->N3_Tab_Etat_de_Modif);
        }
        MAJ_SDL();
        // cout<<endl<<JEU.Obs->Tab_Obstacle[0].getX1()<<endl;
        //----------MAJ des score
        if (JEU.Niveau <= 4)
        {
            if (JEU.Score_Joueur.score > 5)
            {
                JEU.Niveau = 2;
                if (JEU.Score_Joueur.score > 10)
                {
                    JEU.Niveau = 3;
                }
            }
        }
        //----------------incrémentation des vitesse
        if ((JEU.Score_Joueur.score_Majoree >= 3) && (JEU.Niveau>=3))
        {
            JEU.Niv->N1_Deplacement += 10 * JEU.Niv->N1_Deplacement / 100;
            JEU.Niv->N2_Deplacement += 10 * JEU.Niv->N2_Deplacement / 100;
            JEU.Ptr_Voiture->Deplacement += 10 * JEU.Ptr_Voiture->Deplacement / 100;
            JEU.Score_Joueur.score_Majoree = 0;
        }
        cout<<endl<<"N1_deplacement de SDL.cpp/affiche_boucle: "<<JEU.Niv->N1_Deplacement<<endl;
        //____________________________Fin de la partie de mise à jour_______________________________
    }
}

//_____________________________________________________________________________
void Sdl::afficher()
{
    afficherBoucle();

}