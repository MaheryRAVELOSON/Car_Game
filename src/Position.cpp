#include "Position.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Position::Position()
{
    X1=0;
    X2=0;
    Y1=0;
    Y2=0;
    CentreX=0;
    CentreY=0;
    Rayon= 0;
    
}

//_____________________________________________________________________________

void Position::setRayon(int n)
{ 
    Rayon=n;

}

//_____________________________________________________________________________

void Position::setX1(int n)
{ 
    X1=n;

}


//_____________________________________________________________________________
void Position::setY1(int n)
{ 
    Y1=n;

}


//_____________________________________________________________________________
void Position::setX2(int n)
{ 
    X2=n;

}


//_____________________________________________________________________________
void Position::setY2(int n)
{ 
    Y2=n;

}


//_____________________________________________________________________________
void Position::setCentreX(int n)
{
    CentreX=n;
}

//_____________________________________________________________________________
void Position::setCentreY(int n)
{
    CentreY = n;
}

//_____________________________________________________________________________
int Position::getX1()
{
    return X1;
}

//_____________________________________________________________________________
int Position::getY1()
{
    return Y1;
}

//_____________________________________________________________________________
int Position::getX2()
{
    return X2;
}

//_____________________________________________________________________________
int Position::getY2()
{
    return Y2;
}

//_____________________________________________________________________________
int Position::getCentreX()
{
    return CentreX;
}

//_____________________________________________________________________________
int Position::getCentreY()
{
    return CentreY;
}


//_____________________________________________________________________________
int Position::getRayon()
{
    return Rayon;
}

//_____________________________________________________________________________
void Position::TestRegression()
{
    Position * PtrPos= new Position;


    PtrPos->setCentreX(5);
    (* PtrPos).setCentreY(5);

    assert(PtrPos->getCentreX()==5);
    assert((* PtrPos).getCentreY()==5);

    assert(PtrPos->getX1()==0);
    assert((* PtrPos).getY1()==0);
    assert(PtrPos->getX2()==0);
    assert((* PtrPos).getY2()==0);
    assert(PtrPos->getRayon()==0);

    cout<<endl<<endl<<"--Test de Regression 'Position' terminée--"<<endl<<endl;


    delete PtrPos;
}
