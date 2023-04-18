#include "Niveau.h"
#include "Obstacle.h"

//_____________________________________________________________________________
Niveaux::Niveaux(int Nbr_Obstacle)
{
    Total_Obstacle= Nbr_Obstacle;
    N1_Deplacement= 0.05;
    N2_Deplacement= 0.05;
    N2_Tab_Direction= new int[Total_Obstacle];

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
        cout<<endl<<"i%2= "<<i%2<<endl;
    }

}

//_____________________________________________________________________________
Niveaux::~Niveaux()
{
    delete [] N2_Tab_Direction;
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