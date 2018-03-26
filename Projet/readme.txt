				Projet L2 Dameo


Compilation : makefile

Aucune installation de librairie, la fonction getch() a était réécrite pour fonctionner avec les librairies de bases. Dans le doute, voici les librairies qu'elle utilise :
- <termios.h>
- <unistd.h>
- <sys/types.h>
- <sys/time.h>

Ce qui reste à faire :

- Faire en sorte que l'IA mange les pions
- L'IA joue avec les rois
- Changer la fonction de déplacement des roi (verifMoveRoi) qui accepte qu'on passe au dessus des pions en diagonale
- Créer une interface plus intuitif pour que le joueurs puisse jouer sans problème