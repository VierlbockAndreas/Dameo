#include <curses.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../header/joueur.h"

using namespace std;

Plateau::Plateau()
{
	taille = 8;
//	std::vector<std::vector<int> > tableau(taille);
tableau.resize(taille);
}

Plateau::Plateau(int nouvelleTaille)
{
	taille = nouvelleTaille;
	tableau.resize(taille);
}

Plateau::~Plateau()
{
	tableau.clear();
}

int Plateau::getSize()
{
	return taille;
}

void Plateau::initialise()
{
	for(int i = 0; i < tableau.size(); i++)
	{
		for(int j = 0; j < tableau.size(); j++)
		{
			if(i == 0)
				tableau[i].push_back(1);
			else if(i == 1 && (j > 0 && j < tableau.size()-1))
				tableau[i].push_back(1);
			else if(i == 2 && (j > 1 && j < tableau.size()-2))
				tableau[i].push_back(1);

			else if(i == tableau.size()-1)
				tableau[i].push_back(2);
			else if(i == tableau.size()-2 && (j > 0 && j < tableau.size()-1))
				tableau[i].push_back(2);
			else if(i == tableau.size()-3 && (j > 1 && j < tableau.size()-2))
				tableau[i].push_back(2);
			else
				tableau[i].push_back(0);
		}
	}
}

void Plateau::display()
{
	system("clear");
	for(int i=0; i<tableau.size(); i++)
  {
		for(int j = 0; j < tableau.size(); j++)
		{
			cout << tableau[i][j] << ' ';
		}
		cout << endl;
	}
}

void Plateau::display(int x, int y)
{
	system("clear");
	for(int i=0; i<tableau.size(); i++)
  {
		for(int j = 0; j < tableau.size(); j++)
		{
			if(i == x && j == y)
				cout << "> ";
			else
				cout << tableau[i][j] << ' ';
		}
		cout << endl;
	}
}
