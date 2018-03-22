#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>
#include <vector>
class Plateau
{


public:	//Ajouter getter plus tard
	int taille;
	std::vector<std::vector<int> > tableau;

	Plateau();
	Plateau(int);
	~Plateau();
	void initialise();
	void display();
	void display(int, int);
	int getSize();
};
#endif
