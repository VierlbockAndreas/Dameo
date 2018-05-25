#include "../header/plateau.h"


#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include "../header/joueur.h"

using namespace std;

Joueurs::Joueurs(string nNom, int num)
{
	nom = nNom;
	numero = num;
}

Joueurs::~Joueurs()
{

}

int getch(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

bool Joueurs::verifNum(int X, int Y, Plateau p)
{
	if(p.tableau[X][Y] == numero || p.tableau[X][Y] == numero+2)
		return true;
	return false;
}

void Joueurs::deplacementCurseur(int & X, int & Y,Plateau p)
{
	bool continu = true;
	while(continu)
	{
		switch(getch())
		{
	    case 'z': cout << "haut" << endl;   // haut
					if(X > 0)
						X-=1;
	        break;
			case 'Z': cout << "haut" << endl;   // haut
					if(X > 0)
						X -= 1;
	        break;
	    case 's': cout << "bas" << endl;   // bas
					if(X < p.getSize()-1)
						X+=1;
	        break;
			case 'S': cout << "bas" << endl;   // bas
					if(X < p.getSize()-1)
						X+=1;
					break;
	    case 'd': cout << "droite" << endl;   // droite
					if(Y < p.getSize()-1)
						Y+=1;
	        break;
			case 'D': cout << "droite" << endl;   // droite
					if(Y < p.getSize()-1)
						Y+=1;
	        break;
	    case 'q': cout << "gauche" << endl;   // gauche
					if(Y > 0)
						Y-=1;
	        break;
			case 'Q': cout << "gauche" << endl;   // gauche
					if(Y > 0)
						Y-=1;
					break;
			case 'p': cout << "posé" << endl;
					if(X >= 0 && X <= p.getSize()-1 && Y >=0 && Y <= p.getSize() && verifNum(X,Y,p)){ continu = false;}
					break;
			case 'P': cout << "posé" << endl;
					if(X >= 0 && X <= p.getSize() && Y >=0 && Y <= p.getSize()  && verifNum(X,Y,p)){ continu = false;}
					break;
		}

		p.display(X,Y);
	}
}


void Joueurs::deplacementCurseur2(int & X, int & Y,Plateau p)
{
	bool continu = true;
	while(continu)
	{
		switch(getch())
		{
			case 'z': cout << "haut" << endl;   // haut
					if(X > 0)
						X-=1;
	        break;
			case 'Z': cout << "haut" << endl;   // haut
					if(X > 0)
						X -= 1;
	        break;
	    case 's': cout << "bas" << endl;   // bas
					if(X < p.getSize()-1)
						X+=1;
	        break;
			case 'S': cout << "bas" << endl;   // bas
					if(X < p.getSize()-1)
						X+=1;
					break;
	    case 'd': cout << "droite" << endl;   // droite
					if(Y < p.getSize()-1)
						Y+=1;
	        break;
			case 'D': cout << "droite" << endl;   // droite
					if(Y < p.getSize()-1)
						Y+=1;
	        break;
	    case 'q': cout << "gauche" << endl;   // gauche
					if(Y > 0)
						Y-=1;
	        break;
			case 'Q': cout << "gauche" << endl;   // gauche
					if(Y > 0)
						Y-=1;
					break;
			case 'p': cout << "posé" << endl;
					if(X >= 0 && X < p.getSize() && Y >=0 && Y < p.getSize()){ continu = false;}
					break;
			case 'P': cout << "posé" << endl;
					if(X >= 0 && X < p.getSize() && Y >=0 && Y < p.getSize()){ continu = false;}
					break;
		}
		p.display(X,Y);
	}
}

bool Joueurs::verifMange(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(numero == 1)
	{
		if(p.tableau[nouveauX][nouveauY] == 2 || p.tableau[nouveauX][nouveauY] == 4)
		{
			if(nouveauX == curseurX + 1 && nouveauY == curseurY && p.tableau[nouveauX+1][nouveauY] == 0)
				return true;
			else if(nouveauX == curseurX - 1 && nouveauY == curseurY && p.tableau[nouveauX-1][nouveauY] == 0)
				return true;
			else  if(nouveauX == curseurX && nouveauY == curseurY-1 && p.tableau[nouveauX][nouveauY-1] == 0)
				return true;
			else if(nouveauX == curseurX && nouveauY ==curseurY+1 && p.tableau[nouveauX][nouveauY+1] == 0)
				return true;
		}
	}
	else if(numero == 2)
	{
		if(p.tableau[nouveauX][nouveauY] == 1 || p.tableau[nouveauX][nouveauY] == 3)
		{
			if(nouveauX == curseurX + 1 && nouveauY == curseurY && p.tableau[nouveauX+1][nouveauY] == 0)
				return true;
			else if(nouveauX == curseurX - 1 && nouveauY == curseurY && p.tableau[nouveauX-1][nouveauY] == 0)
				return true;
			else  if(nouveauX == curseurX && nouveauY == curseurY-1 && p.tableau[nouveauX][nouveauY-1] == 0)
				return true;
			else if(nouveauX == curseurX && nouveauY ==curseurY+1 && p.tableau[nouveauX][nouveauY+1] == 0)
				return true;
		}
	}

	else
		return false;
}

bool Joueurs::verifMove(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(numero == 1 && p.tableau[nouveauX][nouveauY] == 0 && ((nouveauX == curseurX+1 )))
		return true;
	else if(numero == 1 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX+1 && nouveauY == curseurY+1))
		return true;
	else if(numero == 1 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX+1 && nouveauY == curseurY-1) )
		return true;

	else if(numero == 2 && p.tableau[nouveauX][nouveauY] == 0  && ((nouveauX == curseurX-1)))
		return true;
	else if(numero == 2 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX-1 && nouveauY == curseurY+1))
		return true;
	else if(numero == 2 && p.tableau[nouveauX][nouveauY] == 0  && (nouveauX == curseurX-1 && nouveauY == curseurY-1) )
		return true;
	else
		return false;
}

void Joueurs::mange(int curseurX, int curseurY, int& nouveauX, int nouveauY, Plateau & p)
{
	if(numero == 1)
	{
		if(p.tableau[nouveauX][nouveauY] == 2 || p.tableau[nouveauX][nouveauY] == 4)
		{
			if(nouveauX == curseurX + 1 && p.tableau[nouveauX+1][nouveauY] == 0)
			{
				p.tableau[nouveauX+1][nouveauY] = 1;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
				nouveauX = nouveauX+1;
			}
			else if(nouveauX == curseurX - 1 && p.tableau[nouveauX-1][nouveauY] == 0)
			{
				p.tableau[nouveauX-1][nouveauY] = 1;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
				nouveauX = nouveauX-1;
			}
			else  if(nouveauY == curseurY-1 && p.tableau[nouveauX][nouveauY-1] == 0)
			{
				p.tableau[nouveauX][nouveauY-1] = 1;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
			}
			else if(nouveauY ==curseurY+1 && p.tableau[nouveauX][nouveauY+1] == 0)
			{
				p.tableau[nouveauX][nouveauY+1] = 1;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
			}
		}
	}
	else if(numero == 2)
	{
		if(p.tableau[nouveauX][nouveauY] == 1 || p.tableau[nouveauX][nouveauY] == 3)
		{
			if(nouveauX == curseurX + 1 && p.tableau[nouveauX+1][nouveauY] == 0)
			{
				p.tableau[nouveauX+1][nouveauY] = 2;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
				nouveauX = nouveauX+1;
			}
			else if(nouveauX == curseurX - 1 && p.tableau[nouveauX-1][nouveauY] == 0)
			{
				p.tableau[nouveauX-1][nouveauY] = 2;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
				nouveauX = nouveauX-1;
			}
			else  if(nouveauY == curseurY-1 && p.tableau[nouveauX][nouveauY-1] == 0)
			{
				p.tableau[nouveauX][nouveauY-1] = 2;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
			}
			else if(nouveauY ==curseurY+1 && p.tableau[nouveauX][nouveauY+1] == 0)
			{
				p.tableau[nouveauX][nouveauY+1] = 2;
				p.tableau[curseurX][curseurY] = 0;
				p.tableau[nouveauX][nouveauY] = 0;
			}
		}
	}
}

bool Joueurs::verifPromote(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(numero == 1)
	{
		if(nouveauX == p.getSize()-1)
		{
			return true;
		}
	}
	else if(numero == 2)
	{
		if(nouveauX == 0)
		{
			return true;
		}
	}
	return false;
}

void Joueurs::promoteToKing(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau& p)
{
	if(numero == 1)
	{
		if(nouveauX == p.getSize()-1)
		{
			p.tableau[nouveauX][nouveauY] = 3;
		}
	}
	else if(numero == 2)
	{
		if(nouveauX == 0)
		{
			p.tableau[nouveauX][nouveauY] = 4;
		}
	}
}

bool Joueurs::estRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(p.tableau[curseurX][curseurY] == 3 || p.tableau[curseurX][curseurY] == 4 )
		return true;
	return false;
}

bool Joueurs::verifDeplacementRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(nouveauX < curseurX && nouveauY == curseurY)				// Vers le haut du plateau en ligne droite
		return true;
	else if(nouveauX > curseurX && nouveauY == curseurY)	// Vers le bas du plateau en ligne droite
		return true;
	else if(nouveauY - curseurY == curseurX - nouveauX)		// Diagonale haut droite
		return true;
	else if(curseurX-nouveauX == curseurY-nouveauY)				// Diagonale haut gauche
		return true;
	else if(nouveauX - curseurX == curseurY - nouveauY)		// Diagonale bas gauche
		return true;
	else if(curseurX - nouveauX == curseurY + nouveauY)		// Diagonale bas droite
		return true;
	else if(curseurX == nouveauX && nouveauY > curseurY)	// Vers la droite du plateau en ligne droite
		return true;
	else if(curseurX == nouveauX && nouveauY < curseurY)	// Vers la gauche du plateau en ligne droite
		return true;
	else
		return false;
}

bool Joueurs::verifMangeRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(numero == 1)
	{
		if(nouveauX < curseurX && nouveauY == curseurY) // vers le haut
		{
			int tmpX = curseurX;
			while(tmpX > nouveauX)
			{
				if((p.tableau[tmpX][nouveauY] == 2 || p.tableau[tmpX][nouveauY] == 4) && (p.tableau[tmpX-1][nouveauY] !=0))
				{
					return false;
				}
				tmpX-=1;
			}
			return true;
		}
		else if(nouveauX > curseurX && nouveauY == curseurY) // vers le bas
		{
			int tmpX = curseurX;
			while(tmpX < nouveauX)
			{
				if((p.tableau[tmpX][nouveauY] == 2 || p.tableau[tmpX][nouveauY] == 4) && (p.tableau[tmpX+1][nouveauY] != 0))
				{
					return false;
				}
				tmpX+=1;
			}
			return true;
		}
		else if(curseurX == nouveauX && nouveauY > curseurY) // vers la droite
		{
			int tmpY = curseurY;
			while(tmpY < nouveauY)
			{
				if((p.tableau[nouveauX][tmpY] == 2 || p.tableau[nouveauX][tmpY] == 4) && (p.tableau[nouveauX][tmpY+1] != 0))
				{
					return false;
				}
				tmpY+=1;
			}
			return true;
		}
		else if(curseurX == nouveauX && nouveauY < curseurY) // vers la gauche
		{
			int tmpY = curseurY;
			while(tmpY < nouveauY)
			{
				if((p.tableau[nouveauX][tmpY] == 2 || p.tableau[nouveauX][tmpY] == 4) && (p.tableau[nouveauX][tmpY-1] != 0))
				{
					return false;
				}
				tmpY-=1;
			}
			return true;
		}


		else if(numero == 2)
		{
			if(nouveauX < curseurX && nouveauY == curseurY) // vers le haut
			{
				int tmpX = curseurX;
				while(tmpX > nouveauX)
				{
					if((p.tableau[tmpX][nouveauY] == 1 || p.tableau[tmpX][nouveauY] == 3) && (p.tableau[tmpX-1][nouveauY] !=0))
					{
						return false;
					}
					tmpX-=1;
				}
				return true;
			}
			else if(nouveauX > curseurX && nouveauY == curseurY) // vers le bas
			{
				int tmpX = curseurX;
				while(tmpX < nouveauX)
				{
					if((p.tableau[tmpX][nouveauY] == 1 || p.tableau[tmpX][nouveauY] == 3) && (p.tableau[tmpX+1][nouveauY] =! 0))
					{
						return false;
					}
					tmpX+=1;
				}
				return true;
			}
			else if(curseurX == nouveauX && nouveauY > curseurY) // vers la droite
			{
				int tmpY = curseurY;
				while(tmpY < nouveauY)
				{
					if((p.tableau[nouveauX][tmpY] == 1 || p.tableau[nouveauX][tmpY] == 4) && (p.tableau[nouveauX][tmpY+1] != 0))
					{
						return false;
					}
					tmpY+=1;
				}
				return true;
			}
			else if(curseurX == nouveauX && nouveauY < curseurY) // vers la gauche
			{
				int tmpY = curseurY;
				while(tmpY < nouveauY)
				{
					if((p.tableau[nouveauX][tmpY] == 1 || p.tableau[nouveauX][tmpY] == 3) && (p.tableau[nouveauX][tmpY-1] != 0))
					{
						return false;
					}
					tmpY-=1;
				}
				return true;
			}

		}
	}
}


void Joueurs::mangeRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau & p)
{
	if(nouveauX < curseurX && nouveauY == curseurY) // Vers le haut du plateau
	{
		int tmpX = curseurX;
		while(nouveauX < tmpX)
		{
			p.tableau[tmpX][nouveauY] = 0;
			tmpX -= 1;
		}
	}
	else if(nouveauX > curseurX && nouveauY == curseurY)
	{
			int tmpX = curseurX;
			while(nouveauX > tmpX)
			{
				p.tableau[tmpX][nouveauY] = 0;
				tmpX += 1;
			}
	}
	else if(curseurX == nouveauX && nouveauY > curseurY)
	{
		int tmpY = curseurY;
		while(tmpY<nouveauY)
		{
			p.tableau[nouveauX][tmpY] = 0;
			tmpY+=1;
		}
	}
	else if(curseurX == nouveauX && nouveauY < curseurY)
	{
		int tmpY = curseurY;
		while(tmpY>nouveauY)
		{
			p.tableau[nouveauX][tmpY] = 0;
			tmpY -= 1;
		}
	}
	else if(nouveauX < curseurX && nouveauY < curseurY)	// Diagonale haut gauche
	{
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX < curseurX && tmpY < curseurY)
		{
			cout << "dd" << endl;
			p.tableau[tmpX][tmpY] = 0;
			tmpX+=1;
			tmpY+=1;
		}
	}
	else if(nouveauX < curseurX && nouveauY > curseurY)				// Diagonale haut droite
	{
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX < curseurX && tmpY < curseurY)
		{
			p.tableau[tmpX][tmpY] = 0;
			tmpX+=1;
			tmpY-=1;
		}
	}
	else if(nouveauX > curseurX && nouveauY < curseurY)		// Diagonale bas gauche
	{
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX > curseurX && tmpY < curseurY)
		{
			p.tableau[tmpX][tmpY] = 0;
			tmpX-=1;
			tmpY+=1;
		}
	}
	else if(nouveauX > curseurX && nouveauY < curseurY)		// Diagonale bas droite
	{
		int tmpX = nouveauX;
		int tmpY = nouveauX;
		while(tmpX>curseurX && tmpY<curseurY)
		{
			p.tableau[tmpX][tmpY] = 0;
			tmpX-=1;
			tmpY+=1;
		}
	}



	p.tableau[nouveauX][nouveauY] = numero + 2;
	p.tableau[curseurX][curseurY] = 0;

}

bool Joueurs::verifMoveRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{
	if(nouveauX < curseurX && nouveauY == curseurY) // Vers le haut du plateau
	{
		cout << "haut" << endl;
		int tmpX = nouveauX;
		while(tmpX < curseurX)
		{
			if(p.tableau[tmpX][nouveauY] != 0)
				return false;
			tmpX+=1;
		}
		return true;
	}
	else if(nouveauX > curseurX && nouveauY == curseurY) // vers le bas du plateau
	{
		cout << "bas" << endl;
		int tmpX = nouveauX;
		while(tmpX > curseurX)
		{
			if(p.tableau[tmpX][nouveauY] != 0)
				return false;
			tmpX -= 1;
		}
		return true;
	}
	else if(curseurX == nouveauX && nouveauY > curseurY) // vers la droite du plateau
	{
		cout << "droite" << endl;
		int tmpY = nouveauY;
		while(tmpY > curseurY)
		{
			if(p.tableau[nouveauX][tmpY] != 0)
				return false;
			tmpY-=1;
		}
		return true;
	}
	else if(curseurX == nouveauX && nouveauY < curseurY) // vers la gauche du plateau
	{
		cout << "gauche" << endl;
		int tmpY = nouveauY;
		while(tmpY < curseurY)
		{
			if(p.tableau[nouveauX][tmpY] != 0)
				return false;
			tmpY += 1;
		}
	}
	else if(curseurX-nouveauX == curseurY-nouveauY && nouveauX<curseurX)		// Diagonale haut gauche
	{
		cout << "diagonale haut gauche" << endl;
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX < curseurX && tmpY < curseurY)
		{
			if(p.tableau[tmpX][tmpY] != 0)
				return false;
			tmpX+=1;
			tmpY+=1;
		}
		return true;
	}
	else if(nouveauY - curseurY == curseurX - nouveauX && nouveauX<curseurX)				// Diagonale haut droite
	{
		cout << "diagonale haut droite" << endl;
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX < curseurX && tmpY > curseurY)
		{
			if(p.tableau[tmpX][tmpY] != 0)
				return false;
			tmpX+=1;
			tmpY-=1;
		}
		return true;
	}
	else if(nouveauX - curseurX == curseurY - nouveauY)		// Diagonale bas gauche
	{
		cout << "diagonale bas gauche" << endl;
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX > curseurX && tmpY < curseurY)
		{
			if(p.tableau[tmpX][tmpY] != 0)
				return false;
			tmpX-=1;
			tmpY+=1;
		}
		return true;
	}
	else if( curseurX - nouveauX == curseurY - nouveauY)		// Diagonale bas droite
	{
		cout << "diagonale bas droite" << endl;
		int tmpX = nouveauX;
		int tmpY = nouveauY;
		while(tmpX > curseurX && tmpY > curseurY)
		{
			if(p.tableau[tmpX][tmpY] != 0)
				return false;
			tmpX-=1;
			tmpY-=1;
		}
		return true;
	}
}

void Joueurs::move(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau& p)
{
	p.tableau[nouveauX][nouveauY] = numero;
	p.tableau[curseurX][curseurY] = 0;
}

void Joueurs::moveRoi(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau & p)
{
	p.tableau[nouveauX][nouveauY] = numero+2;
	p.tableau[curseurX][curseurY] = 0;
}

bool Joueurs::verifCoup(int curseurX, int curseurY, int nouveauX, int nouveauY, Plateau p)
{

	if(estRoi(curseurX,	curseurY,	nouveauX,	nouveauY,	p))
	{
		if(verifMangeRoi(curseurX,	curseurY,	nouveauX,	nouveauY,	p))
		{
			return true;
		}
		else if(verifDeplacementRoi(curseurX,	curseurY,	nouveauX,	nouveauY,	p))
		{
			if(verifMoveRoi(curseurX,	curseurY,	nouveauX,	nouveauY,	p))
				return true;
		}

	}
	else
	{
		if(verifMange(curseurX,	curseurY,	nouveauX,	nouveauY,	p) )
			return true;
		else if(verifMove(curseurX,	curseurY,	nouveauX,	nouveauY,	p))
			return true;
	}

	return false;
}

bool Joueurs::conditionVictoire(Plateau p)
{
	int nb1 = 0;
	int nb2 = 0;
	for(int i = 0; i < p.tableau.size(); i++)
	{
		for(int j = 0; j < p.tableau.size(); j++)
		{
			if(p.tableau[i][j] == 1 || p.tableau[i][j] == 3)
				nb1+=1;
			else if(p.tableau[i][j] == 2 || p.tableau[i][j] == 4)
				nb2+=1;
		}
	}
	if(nb1 == 0)
	{
		cout << "Joueur 2 a gagné" << endl;
		return true;
	}
	else if(nb2 == 0)
	{
		cout << "Joueur 1 a gagné" << endl;
		return true;
	}
	else
		return false;
}

void Joueurs::joue(Plateau & p)
{
	int curseurX = 0;	// X => numéro ligne
	int curseurY = 0; // Y => numéro colonne
	int nouvellePlaceX;
	int nouvellePlaceY;
	p.display(curseurX,curseurY);
	deplacementCurseur(curseurX,curseurY,p);
	cout << curseurX << endl;
	cout << curseurY << endl;
	nouvellePlaceX = curseurX;
	nouvellePlaceY = curseurY;
	deplacementCurseur2(nouvellePlaceX,nouvellePlaceY,p);
	cout << nouvellePlaceX << endl;
	cout << nouvellePlaceY << endl;



	if(verifCoup(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
	{
		if(estRoi(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
		{
			if(verifMoveRoi(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
			{
				moveRoi(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);

			}
			else if(verifMangeRoi(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
			{
				cout << "verifMangeRoi" << endl;
				mangeRoi(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);
			}

		}
		else
		{
			if(verifMange(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
			{
				mange(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);
				if(verifPromote(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
					promoteToKing(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);
			}
			else if(verifMove(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
			{
				move(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);
				if(verifPromote(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p))
					promoteToKing(curseurX,curseurY,nouvellePlaceX,nouvellePlaceY,p);
				p.display();
			}
		}
	}
}
