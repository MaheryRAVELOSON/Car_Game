#include "Position.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Position::Position()
{
    X1=0.0;
    X2=0.0;
    Y1=0.0;
    Y2=0.0;
    Largeur= 0.0;
    Hauteur= 0.0;
    
}

//_____________________________________________________________________________

void Position::setX1(float n)
{ 
    X1=n;

}


//_____________________________________________________________________________
void Position::setY1(float n)
{ 
    Y1=n;

}


//_____________________________________________________________________________
void Position::setX2(float n)
{ 
    X2=n;

}


//_____________________________________________________________________________
void Position::setY2(float n)
{ 
    Y2=n;

}

//_____________________________________________________________________________
float Position::getX1()
{
    return X1;
}

//_____________________________________________________________________________
float Position::getY1()
{
    return Y1;
}

//_____________________________________________________________________________
float Position::getX2()
{
    return X2;
}

//_____________________________________________________________________________
float Position::getY2()
{
    return Y2;
}

//_____________________________________________________________________________
void Position::TestRegression()
{
    Position * PtrPos= new Position;

    assert(PtrPos->getX1()==0);
    assert((* PtrPos).getY1()==0);
    assert(PtrPos->getX2()==10);
    assert((* PtrPos).getY2()==10);

    cout<<endl<<endl<<"--Test de Regression 'Position' terminée--"<<endl<<endl;


    delete PtrPos;
}
