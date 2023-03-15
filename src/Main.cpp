#include "Position.h" 
#include "Jeu.h"
#include "Score.h"
 
int main (int argc, char** argv)
{
 
   Position Posi;
   Posi.TestRegression();

   Score ScoreJ;
   ScoreJ.TestRegression();
   
   Jeu JeuJ;
   JeuJ.TestRegression();
 
   return 0;
}