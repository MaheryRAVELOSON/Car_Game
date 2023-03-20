#include "Obstacle.h"

//_____________________________________________________________________________
Obstacle::Obstacle(int TailleTab)
{
    TailleTab_Obstacle = TailleTab;

    Tab_Obstacle= new Position[TailleTab_Obstacle];

    Niveau_Obstacle = nullptr; //il sera initialisé par rapport au donnée mbr 
                               // "Niveau" de la classe Jeu 

    TailleEcranX_Obstacle = nullptr; //il sera initialisé par rapport au donnée
                                     // mbr "TailleX" de la classe Jeu

    Distance_Obstacle = nullptr;

    Score_Obstacle = nullptr;

    /*!!!!REMARQUE!!!! Dans la classe Obstacle, on ne manipule plus CentreX, Y
    et le Rayon de la Position mais directement les X et Y avec leur set et get
    */
    
}

//_____________________________________________________________________________
Obstacle::~Obstacle()
{
    delete [] Tab_Obstacle;
}

//_____________________________________________________________________________
void Obstacle::Init_Obstacle()
{
    /*!!!!REMARQUE!!!! Dans la classe Obstacle, on ne manipule plus CentreX, Y
    et le Rayon de la Position mais directement les X et Y avec leur set et get
    */
}