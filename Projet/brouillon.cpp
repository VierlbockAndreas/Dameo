
bool Joueur::verifMove(Pions ** T, int taille, int vert, int hori)
{
	// Vérifie si la case est dans le tableau

	if(vert >= taille || hori >= taille || vert < 0 || hori < 0)
	{
		cout << "Cette case n'est pas dans le plateau" << endl;
		return false;
	}

	// Vérifie si le pion appartient au joueur qui joue son tour

	else if(T[vert][hori].color != numero_joueur)
	{
		cout << "Ce pion ne vous appartient pas" << endl;
		return false;
	}
	else
		return true;
}

void Joueur::move(Pions ** T, int taille, int vert, int hori,int oVert,int oHori)
{
	Pions p;
	T[vert][hori] = T[oVert][oHori];
	T[oVert][oHori] = p;
}

bool Joueur::verifPose(Pions ** T, int taille, int vert, int hori,int oVert,int oHori)
{

// Vérifie si la case est dans le tableau

	if(vert >= taille || hori >= taille || vert < 0 || hori < 0)
	{
		cout << "Cette case n'est pas dans le plateau" << endl;
		return false;
	}

	// Vérifie si la case est libre

	else if(T[vert][hori].color != 0)
	{
		cout << "Un pion est déjà sur cette case" << endl;
		return false;
	}

	// Vérifie que le joueurs avance

	if(numero_joueur == 1 && ( (vert != oVert-1)))
	{
		cout << "Vous devez vous déplacer de une case vers le camp adverse" << endl;
		return false;
	}
	else if(numero_joueur == 2 && ( (vert != oVert+1)))
	{
		cout << "Vous devez vous déplacer de une case vers le camp adverse" << endl;
		return false;
	}
	else
		return true;
}

bool Joueur::verifJump(Pions ** T, int taille, int vert, int hori, int oVert, int oHori)
{
	if(vert > taille || hori > taille || vert < 0 || hori < 0)
	{
		cout << "Cette case n'est pas dans le plateau" << endl;
		return false;
	}

	if(numero_joueur == 1 && T[vert][hori].color == 2)
	{
		if(vert == oVert && hori == oHori+1 && T[vert][hori+1].color == 0)       // droite
			return true;
		else if(vert == oVert && hori == oHori-1 && T[vert][hori-1].color == 0)  // gauche
			return true;
		else if(vert == oVert-1 && hori == oHori && T[vert-1][hori].color == 0)  // avancer
			return true;
		else if(vert == oVert+1 && hori == oHori && T[vert+1][hori].color == 0)  // reculer
		{
			return true;
		}
		else
		 return false;
	}


	else if(numero_joueur == 2 && T[vert][hori].color == 1)
	{
		if(vert == oVert && hori == oHori+1 && T[vert][hori+1].color == 0)       // droite
			return true;
		else if(vert == oVert && hori == oHori-1 && T[vert][hori-1].color == 0)  // gauche
			return true;
		else if(vert == oVert-1 && hori == oHori && T[vert-1][hori].color == 0)  // reculer
			return true;
		else if(vert == oVert+1 && hori == oHori && T[vert+1][hori].color == 0)  // avancer
		{
			return true;
		}
		else
		 return false;
	}
	return false;
}

void Joueur::jump(Pions ** T, int taille, int vert, int hori, int oVert, int oHori)
{
	Pions p;
	if(numero_joueur == 1 && T[vert][hori].color == 2)
	{
		if(vert == oVert && hori == oHori+1 && T[vert][hori+1].color == 0)       // droite
		{
			T[vert][hori+1] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert && hori == oHori-1 && T[vert][hori-1].color == 0)  // gauche
		{
			T[vert][hori-1] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert-1 && hori == oHori && T[vert-1][hori].color == 0)  // avancer
		{
			T[vert-1][hori] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert+1 && hori == oHori && T[vert+1][hori].color == 0)  // reculer
		{
			T[vert+1][hori] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
	}

	else if(numero_joueur == 2 && T[vert][hori].color == 1)
	{
		if(vert == oVert && hori == oHori+1 && T[vert][hori+1].color == 0)       // droite
		{
			T[vert][hori+1] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert && hori == oHori-1 && T[vert][hori-1].color == 0)  // gauche
		{
			T[vert][hori-1] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert-1 && hori == oHori && T[vert-1][hori].color == 0)  // reculer
		{
			T[vert-1][hori] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
		else if(vert == oVert+1 && hori == oHori && T[vert+1][hori].color == 0)  // avancer
		{
			T[vert+1][hori] = T[oVert][oHori];
			T[oVert][oHori] = p;
			T[vert][hori] = p;
		}
	}
}

bool Joueur::verifLigne(Pions ** T, int taille, int vert, int hori, int oVert, int oHori)
{

	if(vert >= taille || hori >= taille || vert < 0 || hori < 0)
	{
		cout << "Cette case n'est pas dans le plateau" << endl;
		return false;
	}
	if(numero_joueur == 1 && ( (vert != oVert-1)))
	{
		cout << "Vous devez vous déplacer de une case vers le camp adverse" << endl;
		return false;
	}
	else if(numero_joueur == 2 && ( (vert != oVert+1)))
	{
		cout << "Vous devez vous déplacer de une case vers le camp adverse" << endl;
		return false;
	}

	int tmpVert = vert;
	int tmpOvert = oVert;
	int tmpHori = hori;
	int tmpOhori = oHori;
	if(T[vert][hori].color == numero_joueur)
	{
		while(T[tmpVert][tmpHori].color == numero_joueur && tmpVert < taille && tmpHori < taille && tmpHori > 0 && tmpVert > 0)
		{
			if(numero_joueur == 1)
			{
				if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori+1)       // diagonale droite
				{
					tmpHori += 1;
					tmpOhori += 1;
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori-1)  // diagonale gauche
				{
					tmpHori -= 1;
					tmpOhori -= 1;
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori)  // avancer
				{
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // reculer
				{
					tmpVert += 1;
					tmpOvert += 1;
				}
			}
			else if(numero_joueur == 2)
			{
				if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori+1)       // diagonale droite
				{
					tmpHori += 1;
					tmpOhori += 1;
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori-1)  // diagonale gauche
				{
					tmpHori -= 1;
					tmpOhori -= 1;
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // avancer
				{
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // reculer
				{
					tmpVert -= 1;
					tmpOvert -= 1;
				}
			}
		}
		cerr << "Fin tant que" << endl;
		if(T[tmpVert][tmpHori].color == 0)
			return true;
		else
			return false;
	}
	return false;
}

void Joueur::moveLigne(Pions ** T, int taille, int vert, int hori, int oVert, int oHori)
{
	int tmpVert = vert;
	int tmpOvert = oVert;
	int tmpHori = hori;
	int tmpOhori = oHori;
	Pions p;
	if(T[vert][hori].color == numero_joueur)
	{
		while(T[tmpVert][tmpHori].color == numero_joueur && tmpVert < taille && tmpHori < taille && tmpHori > 0 && tmpVert > 0)
		{
			if(numero_joueur == 1)
			{
				if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori+1)       // diagonale droite
				{
					tmpHori += 1;
					tmpOhori += 1;
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori-1)  // diagonale gauche
				{
					tmpHori -= 1;
					tmpOhori -= 1;
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert-1 && tmpHori == tmpOhori)  // avancer
				{
					tmpVert -= 1;
					tmpOvert -= 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // reculer
				{
					tmpVert += 1;
					tmpOvert += 1;
				}
			}
			else if(numero_joueur == 2)
			{
				if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori+1)       // diagonale droite
				{
					tmpHori += 1;
					tmpOhori += 1;
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori-1)  // diagonale gauche
				{
					tmpHori -= 1;
					tmpOhori -= 1;
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // avancer
				{
					tmpVert += 1;
					tmpOvert += 1;
				}
				else if(tmpVert == tmpOvert+1 && tmpHori == tmpOhori)  // reculer
				{
					tmpVert -= 1;
					tmpOvert -= 1;
				}
			}
		}
		T[tmpVert][tmpHori] = T[oVert][oHori];
		T[oVert][oHori] = p;

	}
}

bool Joueur::verifJumpPlus(Pions ** T, int taille, int vert, int hori, int oVert, int oHori)
{

}

void Joueur::tour(Pions ** T,int taille)
{
	int vert;
	int hori;

	int nVert;	// nouvelle valeur vertical
	int nHori;	// nouvelle valeur horizontal

	bool continu = false;
	bool continu2 = false;

	while(!continu)
	{
		cout << "Entrez les coordonnées du pion que vous voulez déplacer (vertical puis horizontal)" << endl;
		cin >> vert;
		cin >> hori;

		if(verifMove(T,taille,vert,hori))
			continu = true;
	}

	while(!continu2)
	{
		cout << "Où voulez vous les placer ? " << endl;
		cin >> nVert;
		cin >> nHori;
		if(verifJump(T,taille,nVert,nHori,vert,hori))
			continu2 = true;
		else if (verifLigne(T,taille,nVert,nHori,vert,hori))
			continu2 = true;
		else if(verifPose(T,taille,nVert,nHori,vert,hori))
			continu2 = true;
	}
	if(verifJump(T,taille,nVert,nHori,vert,hori))
	{
		if(verifJumpPlus(T,taille,nVert,nHori,vert,hori))
		{
			cout << "verifJumpPlus bon" << endl;
		}
		else
		{
			jump(T,taille,nVert,nHori,vert,hori);
			cout << "verifJump bon" << endl;
		}
		jump(T,taille,nVert,nHori,vert,hori);
		cout << "verifJump bon" << endl;
	}
	else if(verifLigne(T,taille,nVert,nHori,vert,hori))
	{
		cout << "verifLigne entrée" << endl;
		moveLigne(T,taille,nVert,nHori,vert,hori);
		cout << "verifLigne bon" << endl;
	}
	else
	{
		move(T,taille,nVert,nHori,vert,hori);
	}
}
