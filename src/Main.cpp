#include "Position.h"
#include "Score.h"  
#include "Jeu.h"   
 
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