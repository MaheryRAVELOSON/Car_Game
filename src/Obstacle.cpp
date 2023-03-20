#include "Obstacle.h"

//_____________________________________________________________________________
Obstacle::Obstacle(int TailleTab)
{
    srand (time(NULL));  /* initialize random seed: */
    
    TailleTab_Obstacle = TailleTab;

    Tab_Obstacle= new Position[TailleTab_Obstacle];

    Distance_Obstacle = &RayonVoiture;

    passage_possible = false;

    /*Niveau_Obstacle = nullptr; //il sera initialisé par rapport au donnée mbr 
                               // "Niveau" de la classe Jeu 

    TailleEcranX_Obstacle = nullptr; //il sera initialisé par rapport au donnée
                                     // mbr "TailleX" de la classe Jeu

    TailleEcranY_Obstacle = nullptr; //il sera initialisé par rapport au donnée
                                     // mbr "TailleY" de la classe Jeu

    Score_Obstacle = nullptr;

    Deplacement_Obstacle= nullptr;
    */

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

   int val= 0;
   int passage;
//------------Initialisation de la première case
   
   do {
    
    val= rand()%((* TailleEcranX_Obstacle)/2);
    Tab_Obstacle[0].setX1(val);

    passage= (* Distance_Obstacle) + (* Distance_Obstacle)/2;
    val = (* TailleEcranX_Obstacle)-(val + passage);
    //on laissera une passage de 150% de la taille de la voiture

    val= rand()%(val + 1);
    Tab_Obstacle[0].setX2(val);

    passage= (* Distance_Obstacle) + (* Distance_Obstacle)/3;
    if (Tab_Obstacle[0].getX1()>=passage)
    {
            passage_possible= true;
    }

    else
    {
            if (Tab_Obstacle[0].getX2()<= ((* TailleEcranX_Obstacle)-passage))
            {
                passage_possible= true;
            }
    }

   }while(passage_possible != true);

   Tab_Obstacle[0].setY2(0);
   Tab_Obstacle[0].setY1(Tab_Obstacle[0].getY2()-(* Distance_Obstacle));

   passage_possible= false;

//------------Initialisation du reste des cases

    for(int i=0; i<TailleTab_Obstacle; i++)
    {
        /*REMARQUE: on ne passe à l'obstacle actuel que si l'obstacle précédent
        a ses coordonnée en règles*/
        
        do {
            val= rand()%((* TailleEcranX_Obstacle)/2);
            Tab_Obstacle[i].setX1(val);

            passage= (* Distance_Obstacle) + (* Distance_Obstacle)/2;
            val = (* TailleEcranX_Obstacle) -(val + passage);
            //on laissera une passage de 150% de la taille de la voiture

            val= rand()%(val + 1);
            Tab_Obstacle[i].setX2(val);

            passage= (* Distance_Obstacle) + (* Distance_Obstacle)/3;


            passage_possible= false;
            if (Tab_Obstacle[i].getX1()<Tab_Obstacle[i-1].getX1())
            {
                passage= (* Distance_Obstacle) + (* Distance_Obstacle)/3;
                if (Tab_Obstacle[i].getX1()>=passage)
                {
                    passage_possible= true;
                }
            }
            else
            {
                if (Tab_Obstacle[i].getX2()>Tab_Obstacle[i-1].getX2())
                {
                    if (Tab_Obstacle[i].getX2()<= ((* TailleEcranX_Obstacle) - passage))
                    {
                        passage_possible= true;
                    }
                }
            }

        }while(passage_possible != true);

        passage= (* Distance_Obstacle)/3;
        val = (* Distance_Obstacle);
        val *= 6;
        val += rand()% passage;
        Tab_Obstacle[i].setY2(Tab_Obstacle[i-1].getY1() - val);
        Tab_Obstacle[i].setY1(Tab_Obstacle[i].getY2()-(* Distance_Obstacle));
        /*Entre deux obstacle, on aura une distance entre la hauteur de la
        voiture et la hauteur de la voiture + [hauteur de la voiture/3]*/

        passage_possible= false;
        
    }

}

//_____________________________________________________________________________
void Obstacle::Mouv_Obs_Verticale()
{
    int Mouv= (* Deplacement_Obstacle)/2;
    //on les fait déplacée 2x moins vite que la voiture.

    for (int i=0; i<TailleTab_Obstacle; i++)
    {
        Tab_Obstacle[i].setY2(Tab_Obstacle[i].getY2()+Mouv);
        Tab_Obstacle[i].setY1(Tab_Obstacle[i].getY1()+Mouv);
    }
}

//_____________________________________________________________________________
void Obstacle::Verif_Apparition()
{
    int j;
    int val= 0;
    int passage;
    for (int i=0; i<TailleTab_Obstacle; i++)
    {
        if (Tab_Obstacle[i].getY1()>(* TailleEcranY_Obstacle))
        {
        
            do {
                val= rand()%((* TailleEcranX_Obstacle)/2);
                Tab_Obstacle[i].setX1(val);

                passage= (* Distance_Obstacle) + (* Distance_Obstacle)/2;
                val = (* TailleEcranX_Obstacle) -(val + passage);
                //on laissera une passage de 150% de la taille de la voiture

                val= rand()%(val + 1);
                Tab_Obstacle[i].setX2(val);

                passage= (* Distance_Obstacle) + (* Distance_Obstacle)/3;


                if ((i-1)<0)
                {
                    j=TailleTab_Obstacle -1;
                }
                else
                {
                    j= i-1;
                }
                passage_possible= false;
                if (Tab_Obstacle[i].getX1()<Tab_Obstacle[j].getX1())
                {
                    passage= (* Distance_Obstacle) + (* Distance_Obstacle)/3;
                    if (Tab_Obstacle[i].getX1()>=passage)
                    {
                        passage_possible= true;
                    }
                }
                else
                {
                    if (Tab_Obstacle[i].getX2()>Tab_Obstacle[j].getX2())
                    {
                        if (Tab_Obstacle[i].getX2()<= ((* TailleEcranX_Obstacle) - passage))
                        {
                            passage_possible= true;
                        }
                    }
                }

            }while(passage_possible != true);

            
            val = (* Distance_Obstacle);
            val *= 6; // val correspond maintenant à la totalité de la taille 
                      // d'une coté de la voiture

            passage= (* Distance_Obstacle)/3;
            val += (rand()% passage);
            
            Tab_Obstacle[i].setY2(Tab_Obstacle[j].getY1() - val);
            Tab_Obstacle[i].setY1(Tab_Obstacle[i].getY2()-(* Distance_Obstacle));
            /*Entre deux obstacle, on aura une distance entre la hauteur de la
            voiture et la hauteur de la voiture + [hauteur de la voiture/3]*/

            passage_possible= false;
            
        }

    }
}

//_____________________________________________________________________________
