#include "Score.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Score::Score()
{
    score= 0;
    score_Majoree= 0;
}

//_____________________________________________________________________________
void Score::TestRegression()
{
    Score * PtrScore= new Score;


    assert(PtrScore->score==0);

    (* PtrScore).score=5;
    assert((* PtrScore).score==5);

    cout<<endl<<endl<<"--Test de Regression 'Score' terminée--"<<endl<<endl;


    delete PtrScore;
}
