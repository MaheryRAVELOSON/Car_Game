#include "Obstacle.h"

//_____________________________________________________________________________
Obstacle::Obstacle(int TailleTab, int Largeur_Voiture, int Deplacement_Voiture)
{
    srand (time(NULL));  /* initialize random seed: */
    
    TailleTab_Obstacle = TailleTab;

    Tab_Obstacle= new Position[TailleTab_Obstacle];

    Distance_Obstacle = Largeur_Voiture;

    passage_possible = false;
    
}

//_____________________________________________________________________________
Obstacle::~Obstacle()
{
    delete [] Tab_Obstacle;
}

//_____________________________________________________________________________
void Obstacle::Init_Obstacle(int TailleEcranX)
{
    /*!!!!REMARQUE!!!! Dans la classe Obstacle, on ne manipule plus CentreX, Y
    et le Rayon de la Position mais directement les X et Y avec leur set et get
    */

   int val= 0;
   int passage;
   int pourcent=2;
   int Largeur_Min_Obstacle= TailleEcranX*0.16;
//------------Initialisation de la première case
   
   do {
    
    val= rand()%(TailleEcranX*3/4);
    Tab_Obstacle[0].setX1(val);

    passage= Distance_Obstacle + Distance_Obstacle/pourcent;
    //on laissera une passage de 150% de la taille de la voiture
    val = TailleEcranX - passage - Largeur_Min_Obstacle - val;

    if(val<=0)
    {
        val= 1;
    }

    val= (rand()%(val)) + Tab_Obstacle[0].getX1() + Largeur_Min_Obstacle;
    // "+100" => chaque obstacle aura une taille à 100 pixel au minimum.
    Tab_Obstacle[0].setX2(val);
    assert(Tab_Obstacle[0].getX2()<=TailleEcranX);
    //Tab_Obstacle[0].setX2(Tab_Obstacle[0].getX1() + 100);

    passage= Distance_Obstacle + Distance_Obstacle/(pourcent+1);
    if (Tab_Obstacle[0].getX1()>=passage)
    {
            passage_possible= true;
    }

    else
    {
            if (Tab_Obstacle[0].getX2()<= (TailleEcranX-passage))
            {
                passage_possible= true;
            }
    }

   }while(passage_possible != true);

   assert(passage_possible == true);

   Tab_Obstacle[0].setY2(0);
   Tab_Obstacle[0].setY1(Tab_Obstacle[0].getY2()-Distance_Obstacle);

   passage_possible= false;

   Tab_Obstacle[0].Largeur= Tab_Obstacle[0].getX2() - Tab_Obstacle[0].getX1();
   Tab_Obstacle[0].Hauteur= Tab_Obstacle[0].getY2() - Tab_Obstacle[0].getY1();

//------------Initialisation du reste des cases

    for(int i=1; i<TailleTab_Obstacle; i++)
    {
        /*REMARQUE: on ne passe à l'obstacle actuel que si l'obstacle précédent
        a ses coordonnée en règles*/
        
        do {
            val= rand()%(TailleEcranX*3/4);
            Tab_Obstacle[i].setX1(val);

            passage= Distance_Obstacle + Distance_Obstacle/pourcent;
            //on laissera une passage de 150% de la taille de la voiture
            val = TailleEcranX - passage - Largeur_Min_Obstacle - val;

            if(val<=0)
            {
                val= 1;
            }
            

            val= (rand()%(val)) + Tab_Obstacle[i].getX1() + Largeur_Min_Obstacle;
            // "+100" => chaque obstacle aura une taille à 100 pixel au minimum.
            Tab_Obstacle[i].setX2(val);
            assert(Tab_Obstacle[i].getX2()<=TailleEcranX);

            passage= Distance_Obstacle + Distance_Obstacle/(pourcent+1);


            passage_possible= false;

            assert((i-1)>=0);

            passage= Distance_Obstacle + Distance_Obstacle/(pourcent+1);
            if (Tab_Obstacle[i].getX1()>=passage)
            {
                passage_possible= true;
            }

            if (!passage_possible)
            {
                assert((i-1)>=0);

                if (Tab_Obstacle[i].getX2()<= (TailleEcranX - passage))
                {
                    passage_possible= true;
                    }
            }


        }while(passage_possible != true);

        assert(passage_possible == true);

        val = Distance_Obstacle; //Rappel: "Distance_Obstacle" = la rayon de la Voiture
        val *= 6;
        assert((i-1)>=0);
        Tab_Obstacle[i].setY2(Tab_Obstacle[i-1].getY1() - val);
        Tab_Obstacle[i].setY1(Tab_Obstacle[i].getY2()-Distance_Obstacle);

        passage_possible= false;

        Tab_Obstacle[i].Largeur= Tab_Obstacle[i].getX2() - Tab_Obstacle[i].getX1();
        Tab_Obstacle[i].Hauteur= Tab_Obstacle[i].getY2() - Tab_Obstacle[i].getY1();
        
    }

}

//_____________________________________________________________________________
int Obstacle::Verif_Apparition(Score &Score_Joueur, int TailleEcranX, int TailleEcranY,
float * N3_Tab_Etat_de_Modif)
{

    int count = 0;
    int j;
    int val= 0;
    int passage;
    int pourcent= 2;
    for (int i=0; i<TailleTab_Obstacle; i++)
    {
        
        if (Tab_Obstacle[i].getY1()>TailleEcranY)
        {
                val= rand()%(TailleEcranX/pourcent);
                Tab_Obstacle[i].setX1(val);

                passage= Distance_Obstacle + Distance_Obstacle/pourcent;
                //on laissera une passage de 150% de la taille de la voiture
                val = TailleEcranX -(val + passage + 100);

                if(val<=0)
                {
                    val= 1;
                }
                

                val= (rand()%val) + Tab_Obstacle[i].getX1() + 100;
                Tab_Obstacle[i].setX2(val);
                assert(Tab_Obstacle[i].getX2()<=TailleEcranX);

                passage= Distance_Obstacle + Distance_Obstacle/(pourcent+1);


                if ((i-1)<0)
                {
                    j=TailleTab_Obstacle -1;
                }
                else
                {
                    j= i-1;
                }
                
                assert(j>=0);
                assert(j<TailleTab_Obstacle);

                passage_possible= false;

                passage= Distance_Obstacle + Distance_Obstacle/pourcent+1;
                if (Tab_Obstacle[i].getX1()>=passage)
                {
                    passage_possible= true;
                }

                if (Tab_Obstacle[i].getX2()<= (TailleEcranX - passage))
                {
                    passage_possible= true;
                }


           assert(passage_possible == true);

            
            val = Distance_Obstacle *6 ; //Rappel: "Distance_Obstacle" = la largeur de la Voiture

            passage= Distance_Obstacle/(pourcent+1);
            
            Tab_Obstacle[i].setY2(Tab_Obstacle[j].getY1() - val + N3_Tab_Etat_de_Modif[j]);
            Tab_Obstacle[i].setY1(Tab_Obstacle[i].getY2()-Distance_Obstacle);
            N3_Tab_Etat_de_Modif[i]= 0.0;

            /*
            cout<<endl<<"Distance entre 2 obs (normalement 360 pour Distance_Obs = "
            <<"LargeurVoiture = 10 pourcent de 600x800 = 60): "
            <<Tab_Obstacle[j].getY1() - Tab_Obstacle[i].getY2() + N3_Tab_Etat_de_Modif[j]
            <<" de Obtacle.Verif_Apparition"<<endl;
            */


            passage_possible= false;
            Score_Joueur.score= Score_Joueur.score + 1;
            Score_Joueur.score_Majoree= Score_Joueur.score_Majoree + 1;   
            /*
            cout<<endl<<"Score: "<<Score_Joueur.score<<" de Obtacle.Verif_Apparition"
            <<endl;
            */

            Tab_Obstacle[i].Largeur= Tab_Obstacle[i].getX2() - Tab_Obstacle[i].getX1();
            Tab_Obstacle[i].Hauteur= Tab_Obstacle[i].getY2() - Tab_Obstacle[i].getY1();

        }

    }

    return count;
}

//_____________________________________________________________________________
bool Obstacle::Collision(Voiture &Voiture_Joueur)
{
    float precision= 10;
    bool resultat= false;
    for(int i=0; i<TailleTab_Obstacle; i++)
    {
        //Coin en haut à gauche de la voiture
        if((Tab_Obstacle[i].getX1()<Voiture_Joueur.Voiture_Position->getX1()+precision) &&
        (Tab_Obstacle[i].getX2()>Voiture_Joueur.Voiture_Position->getX1()+precision))
        {
            if((Tab_Obstacle[i].getY1()<Voiture_Joueur.Voiture_Position->getY1()+precision) &&
            (Tab_Obstacle[i].getY2()>Voiture_Joueur.Voiture_Position->getY1()+precision))
            {
                resultat= true;
                return resultat;
            }
        }

        // Coin en bas à gauche de la voiture
        if((Tab_Obstacle[i].getX1()<Voiture_Joueur.Voiture_Position->getX1()+precision) &&
        (Tab_Obstacle[i].getX2()>Voiture_Joueur.Voiture_Position->getX1()+precision))
        {
            if((Tab_Obstacle[i].getY1()<Voiture_Joueur.Voiture_Position->getY2()-precision) &&
            (Tab_Obstacle[i].getY2()>Voiture_Joueur.Voiture_Position->getY2()-precision))
            {
                resultat= true;
                return resultat;
            }
        }

        //Coin en haut à droite de la voiture
        if((Tab_Obstacle[i].getX1()<Voiture_Joueur.Voiture_Position->getX2()-precision) &&
        (Tab_Obstacle[i].getX2()>Voiture_Joueur.Voiture_Position->getX2()-precision))
        {
            if((Tab_Obstacle[i].getY1()<Voiture_Joueur.Voiture_Position->getY1()+precision) &&
            (Tab_Obstacle[i].getY2()>Voiture_Joueur.Voiture_Position->getY1()+precision))
            {
                resultat= true;
                return resultat;
            }
        }

        //Coin en bas à droite de la voiture
        if((Tab_Obstacle[i].getX1()<Voiture_Joueur.Voiture_Position->getX2()-precision) &&
        (Tab_Obstacle[i].getX2()>Voiture_Joueur.Voiture_Position->getX2()-precision))
        {
            if((Tab_Obstacle[i].getY1()<Voiture_Joueur.Voiture_Position->getY2()-precision) &&
            (Tab_Obstacle[i].getY2()>Voiture_Joueur.Voiture_Position->getY2()-precision))
            {
                resultat= true;
                return resultat;
            }
        }
    }

    return resultat;
}