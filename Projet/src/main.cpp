#include <iostream>
#include "../header/joueur.h"

using namespace std;

bool verifieAvant(int,int,Plateau);
void enAvant(int,int,Plateau&);
void aGauche(int,int,Plateau&);

int main()
{
	Plateau p;
	p.initialise();

/*
	Joueurs Skymble("Skymble",1);
	Joueurs Andreas("Andreas",2);
	while(!Skymble.conditionVictoire(p))
	{
		Skymble.joue(p);
		Andreas.joue(p);
	}
*/

	aGauche(1,1,p);
	p.display();
	return 0;
}

/*

else if(numero == 1 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX+1 && nouveauY == curseurY+1))
	return true;

else if(numero == 1 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX+1 && nouveauY == curseurY-1) )
	return true;


else if(numero == 2 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX-1 && nouveauY == curseurY+1))
	return true;
else if(numero == 2 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX-1 && nouveauY == curseurY-1) )
	return true;
else
	return false;

	*/
