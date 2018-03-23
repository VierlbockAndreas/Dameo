#include <iostream>
#include "../header/joueur.h"

using namespace std;

bool verifieAvant(int,int,Plateau);
void enAvant(int,int,Plateau&);
void aGauche(int,int,Plateau&);
void jouerIA(Plateau & p, int profondeur);

int main()
{
	Plateau p;
	p.initialise();


	Joueurs Skymble("Skymble",2);
	Joueurs Andreas("Andreas",1);
//	cout << Andreas.verifLigne(0, 0,1,0,p) << endl;
	while(!Skymble.conditionVictoire(p))
	{
//		Andreas.joue(p);
		Skymble.joue(p);
		
		jouerIA(p,2);
		p.display();
	}




	return 0;
}
