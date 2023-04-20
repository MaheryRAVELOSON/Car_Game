#include "Niveau.h"
#include "Obstacle.h"

//_____________________________________________________________________________
Niveaux::Niveaux(int Nbr_Obstacle, float H_Obstacle)
{
    Total_Obstacle= Nbr_Obstacle;
    N1_Deplacement= 0.05;
    N2_Deplacement= 0.05;
    N2_Tab_Direction= new int[Total_Obstacle];
    //N3_Tab_Agrandissement= new  bool[Total_Obstacle];
    N3_Modif_Max= 5000;
    N3_Tab_Etat_de_Modif= new float[Total_Obstacle];
    N3_Taux_Modif= 0.01; // Doit être inf à N1 et N2 Deplacement car sinon grossi sur place
    N3_retrecissement= true;
    N3_Premier_Boucle= true;
    N3_Etat_de_Modif = N3_Modif_Max; //Taille_obs_max = obs_initial  + N3_Modif_Max*Taux_Modif
    N3_Pair= true;
    //N3_Opposee_N3_Etat_de_Modif = N3_Modif_Max - N3_Etat_de_Modif;
    N3_Hauteur_Min_Obstacle= H_Obstacle;

//----------Initialisation du N2_Tab_Direction:
    for(int i=0; i<Nbr_Obstacle; i++)
    {
        if((i%2)==0)
        {
            N2_Tab_Direction[i]= 1; //Deplacement vers la droite
        }
        else
        {
            N2_Tab_Direction[i]= -1; //Deplacement vers la gauche
        }

        N3_Tab_Etat_de_Modif[i]= 0;
        //cout<<endl<<"i%2= "<<i%2<<endl;
    }

}

//_____________________________________________________________________________
Niveaux::~Niveaux()
{
    delete [] N2_Tab_Direction;
    delete [] N3_Tab_Etat_de_Modif;
    //delete [] N3_Tab_Agrandissement;
}

//_____________________________________________________________________________
void Niveaux::N1_Mouv_Verticale(Obstacle &Obs)
{
    for (int i=0; i<Obs.TailleTab_Obstacle; i++)
    {
        Obs.Tab_Obstacle[i].setY2(Obs.Tab_Obstacle[i].getY2()+N1_Deplacement);
        Obs.Tab_Obstacle[i].setY1(Obs.Tab_Obstacle[i].getY1()+N1_Deplacement);
    }
}

//_____________________________________________________________________________
void Niveaux::N2_Mouv_Horizontale(Obstacle &Obs, int TailleEcranX, int Niveau_Joueur)
{
    if (Niveau_Joueur>=2)
    {
        for (int i=0; i<Obs.TailleTab_Obstacle; i++)
        {
            Obs.Tab_Obstacle[i].setX2(Obs.Tab_Obstacle[i].getX2() + N2_Deplacement*N2_Tab_Direction[i]);
            Obs.Tab_Obstacle[i].setX1(Obs.Tab_Obstacle[i].getX1() + N2_Deplacement*N2_Tab_Direction[i]);

            if(Obs.Tab_Obstacle[i].getX1()<0)
            {
                Obs.Tab_Obstacle[i].setX1(0);
                Obs.Tab_Obstacle[i].setX2(Obs.Tab_Obstacle[i].getX1() + Obs.Tab_Obstacle[i].Largeur);
                N2_Tab_Direction[i]=1;
            }

            if(Obs.Tab_Obstacle[i].getX2()>TailleEcranX)
            {
                Obs.Tab_Obstacle[i].setX2(TailleEcranX);
                Obs.Tab_Obstacle[i].setX1(Obs.Tab_Obstacle[i].getX2() - Obs.Tab_Obstacle[i].Largeur);
                N2_Tab_Direction[i]=-1;
            }
        }
    }
}

//_____________________________________________________________________________
void Niveaux::N3_Agrandissement(Obstacle &Obs, int Indice_Pos)
{
    N3_Tab_Etat_de_Modif[Indice_Pos] = N3_Etat_de_Modif * N3_Taux_Modif;

    Obs.Tab_Obstacle[Indice_Pos].setX1(Obs.Tab_Obstacle[Indice_Pos].getX1()-N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setX2(Obs.Tab_Obstacle[Indice_Pos].getX2()+N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setY1(Obs.Tab_Obstacle[Indice_Pos].getY1()-N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setY2(Obs.Tab_Obstacle[Indice_Pos].getY2()+N3_Taux_Modif);

    Obs.Tab_Obstacle[Indice_Pos].Largeur= Obs.Tab_Obstacle[Indice_Pos].getX2() - Obs.Tab_Obstacle[Indice_Pos].getX1();
    Obs.Tab_Obstacle[Indice_Pos].Hauteur= Obs.Tab_Obstacle[Indice_Pos].getY2() - Obs.Tab_Obstacle[Indice_Pos].getY1();
}

//_____________________________________________________________________________
void Niveaux::N3_Retrecissement(Obstacle &Obs, int Indice_Pos)
{
    N3_Tab_Etat_de_Modif[Indice_Pos] = N3_Etat_de_Modif * N3_Taux_Modif;
    Obs.Tab_Obstacle[Indice_Pos].setX1(Obs.Tab_Obstacle[Indice_Pos].getX1()+N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setX2(Obs.Tab_Obstacle[Indice_Pos].getX2()-N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setY1(Obs.Tab_Obstacle[Indice_Pos].getY1()+N3_Taux_Modif);
    Obs.Tab_Obstacle[Indice_Pos].setY2(Obs.Tab_Obstacle[Indice_Pos].getY2()-N3_Taux_Modif);

    Obs.Tab_Obstacle[Indice_Pos].Largeur= Obs.Tab_Obstacle[Indice_Pos].getX2() - Obs.Tab_Obstacle[Indice_Pos].getX1();
    Obs.Tab_Obstacle[Indice_Pos].Hauteur= Obs.Tab_Obstacle[Indice_Pos].getY2() - Obs.Tab_Obstacle[Indice_Pos].getY1();

    if(Obs.Tab_Obstacle[Indice_Pos].Hauteur<N3_Hauteur_Min_Obstacle)
    {
        N3_Agrandissement(Obs, Indice_Pos); // on lui rend sa coordonnee d'avant
        N3_Tab_Etat_de_Modif[Indice_Pos] = 0.0; //0 car c'est sa taille initiale => pas de modif
    }
}

//_____________________________________________________________________________
void Niveaux::N3_Modif_Des_Coords(Obstacle &Obs)
{
//_______________grocissement vers raptecissement et vice vers ça automatique
        if(N3_retrecissement)
        {
            if(N3_Premier_Boucle)
            {
                N3_Etat_de_Modif ++;
                N3_Premier_Boucle= false;
            }

            N3_Etat_de_Modif --;
            if(N3_Etat_de_Modif<0)
            {
                N3_retrecissement= false;
                N3_Etat_de_Modif += 2;

                if(N3_Pair==true)
                {
                    N3_Pair= false;
                }
                else 
                {
                    N3_Pair= true;
                }
            }

            //N3_Opposee_N3_Etat_de_Modif = N3_Modif_Max - N3_Etat_de_Modif;

            //cout<<endl<<N3_Etat_de_Modif<<endl;
            //sleep(1);
        }

        else
        {
            if(N3_Premier_Boucle)
            {
                N3_Etat_de_Modif --;
                N3_Premier_Boucle= false;
            }

            N3_Etat_de_Modif ++;
            if(N3_Etat_de_Modif>N3_Modif_Max)
            {
                N3_retrecissement=true;
                N3_Etat_de_Modif -= 2;

                if(N3_Pair==true)
                {
                    N3_Pair= false;
                }
                else 
                {
                    N3_Pair= true;
                }
            }

            //N3_Opposee_N3_Etat_de_Modif = N3_Modif_Max - N3_Etat_de_Modif;

            //cout<<endl<<N3_Etat_de_Modif<<endl;
            //sleep(1);
        }
//___________________fin de l'algo.
//___________________modification des données:

    if(N3_Pair)
    {
        for(int i=0; i<Obs.TailleTab_Obstacle; i++)
        {
            if((i%2)==0)
            {
                N3_Agrandissement(Obs, i);
            }
            else{
                N3_Retrecissement(Obs, i);
            }
        }

    }

    else
    {
        for(int i=0; i<Obs.TailleTab_Obstacle; i++)
        {
            if((i%2)==1)
            {
                N3_Agrandissement(Obs, i);
            }
            else{
                N3_Retrecissement(Obs, i);
            }
        }

    }

}

