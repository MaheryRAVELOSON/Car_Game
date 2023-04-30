#include "Jeu.h"
 
int main (int argc, char** argv)
{
 
   srand (time(NULL));  /* initialize random seed: */
   
   Position Posi;
   Posi.TestRegression();

   Score ScoreJ;
   ScoreJ.TestRegression();
   
   Jeu JeuJ;
   JeuJ.TestRegression();
 
   return 0;
}