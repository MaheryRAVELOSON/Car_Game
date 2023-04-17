#include "Niveau.h"
#include "Obstacle.h"

//_____________________________________________________________________________
Niveaux::Niveaux()
{
    Deplacement_Niveau= 0.02;
}

//_____________________________________________________________________________
void Niveaux::Mouv_Verticale(Obstacle &Obs)
{
    for (int i=0; i<Obs.TailleTab_Obstacle; i++)
    {
        Obs.Tab_Obstacle[i].setY2(Obs.Tab_Obstacle[i].getY2()+Deplacement_Niveau);
        Obs.Tab_Obstacle[i].setY1(Obs.Tab_Obstacle[i].getY1()+Deplacement_Niveau);
    }
}