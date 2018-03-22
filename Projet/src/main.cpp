#include <iostream>
#include "../header/joueur.h"

using namespace std;

int main()
{
	Plateau p;
	p.initialise();

	Joueurs Skymble("Skymble",1);
	Joueurs Andreas("Andreas",2);
	while(!Skymble.conditionVictoire(p))
	{
		Skymble.joue(p);
		Andreas.joue(p);
	}

	return 0;
}
