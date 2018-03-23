#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "plateau.h"

class Joueurs
{
	std::string nom;
	int numero;
public:
	Joueurs(std::string,int);
	~Joueurs();
	void joue(Plateau &);
	bool verifNum(int X, int Y, Plateau p);
	void deplacementCurseur(int&, int&, Plateau);
	void deplacementCurseur2(int&, int&, Plateau);
	bool verifCoup(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	bool verifMange(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	bool verifMove(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	void mange(int curseurX, int curseurY, int& nouveauX, int nouveauY, Plateau & p);
	void move(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau& p);
	void promoteToKing(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau& p);
	bool estRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	bool verifPromote(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	bool verifDeplacementRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	void moveRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau & p);
	bool verifMoveRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	bool verifMangeRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p);
	void mangeRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau & p);
	bool conditionVictoire(Plateau);
	bool verifLigne(int curseurX, int curseurY,int nouveauX, int nouveauY, Plateau p);
	void moveLigne(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau & p);

};
#endif
