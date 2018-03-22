#include <iostream>
#include "../header/plateau.h"

using namespace std;

int Min(Plateau & p,int profondeur);
int Max(Plateau & p,int profondeur);
int eval(Plateau & p);


bool verifieAvant(int i, int j, Plateau p)
{
    if(p.tableau[i][j] == 1 && p.tableau[i+1][j] == 0)
      return true;
    return false;
}

void enAvant(int i, int j, Plateau & p)
{
  p.tableau[i+1][j] = 1;
  p.tableau[i][j] = 0;
}

void annuleAvant(int i,int j, Plateau & p)
{
  p.tableau[i+1][j] = 0;
  p.tableau[i][j] = 1;
}

bool verifieDroite(int i, int j, Plateau p)
{
  if(p.tableau[i][j] == 1 && p.tableau[i+1][j+1] == 0)
    return true;
  return false;
}

void aDroite(int i, int j, Plateau & p)
{
  p.tableau[i+1][j+1] = 1;
  p.tableau[i][j] = 0;
}

void annuleDroite(int i, int j, Plateau & p)
{
  p.tableau[i+1][j+1] = 0;
  p.tableau[i][j] = 1;
}

bool verifieGauche(int i, int j, Plateau p)
{
  if(p.tableau[i][j] == 1 && p.tableau[i+1][j-1] == 0)
    return true;
  return false;
}

void aGauche(int i, int j, Plateau & p)
{
  p.tableau[i+1][j-1] = 1;
  p.tableau[i][j] = 0;
}

void annuleGauche(int i, int j, Plateau & p)
{
  p.tableau[i+1][j-1] = 0;
  p.tableau[i][j] = 1;
}

int Min(Plateau & p,int profondeur)
{
  if(profondeur == 0)
  {
    return eval(p);
  }
     int min = 10000;
     int i,j,tmp;


     for(i=0;i < p.tableau.size(); i++)
     {
       for(j = 0; j < p.tableau.size(); j++)
       {
         if(verifieAvant(i,j,p))
         {
           enAvant(i,j,p);
           tmp = Max(p,profondeur-1);
           if(tmp < min)
            {
              min = tmp;
            }
           annuleAvant(i,j,p);
         }

         if(verifieDroite(i,j,p))
         {
           aDroite(i,j,p);
           tmp = Max(p,profondeur-1);
           if(tmp < min)
          {
            min = tmp;
          }
           annuleDroite(i,j,p);
         }
         if(verifieGauche(i,j,p))
         {
           aGauche(i,j,p);
           tmp = Max(p,profondeur-1);

           if(tmp < min)
           {
              min = tmp;
            }
           annuleGauche(i,j,p);
         }
       }
     }
     return min;
}

int Max(Plateau & p, int profondeur)
{
  if(profondeur == 0)
  {
    return eval(p);
  }
  int max = -10000;
  int i,j,tmp;
  for(i=0;i < p.tableau.size(); i++)
   {
    for(j = 0; j < p.tableau.size(); j++)
    {
     if(verifieAvant(i,j,p))
     {
       enAvant(i,j,p);
       tmp = Min(p,profondeur-1);
        if(tmp > max)
        {
          max = tmp;
        }
        annuleAvant(i,j,p);

        if(verifieDroite(i,j,p))
        {
          enAvant(i,j,p);
          tmp = Min(p,profondeur-1);
           if(tmp > max)
           {
             max = tmp;
           }
           annuleDroite(i,j,p);
        }
        if(verifieGauche(i,j,p))
        {
          enAvant(i,j,p);
          tmp = Min(p,profondeur-1);
           if(tmp > max)
           {
             max = tmp;
           }
           annuleGauche(i,j,p);
        }
      }

    }
  }
return max;
}

int eval(Plateau & p)
{

}

void jouerIA(Plateau & p, int profondeur)
{
  int max = -99999;
  int tmp;
  int maxi;
  int maxj;
  int i;
  int j;

  for(i=0;i < p.tableau.size(); i++)
  {
    for(j = 0; j < p.tableau.size(); j++)
    {
      if(verifieAvant(i,j,p))
      {
        enAvant(i,j,p);
        tmp = Min(p,profondeur-1);

        if(tmp > max)
        {
          max = tmp;
          maxi = i;
          maxj = j;
        }
        annuleAvant(i,j,p);
      }

      if(verifieDroite(i,j,p))
      {
        aDroite(i,j,p);
        tmp = Min(p,profondeur-1);

        if(tmp > max)
        {
          max = tmp;
          maxi = i;
          maxj = j;
        }
        annuleDroite(i,j,p);
      }
      if(verifieGauche(i,j,p))
      {
        aGauche(i,j,p);
        tmp = Min(p,profondeur-1);

        if(tmp > max)
        {
          max = tmp;
          maxi = i;
          maxj = j;
        }
        annuleGauche(i,j,p);
      }
    }
  }
  p.tableau[maxi][maxj] = 1;
  if(p.tableau[maxi - 1][j] == 1)
    p.tableau[maxi-1][j] = 0;
  else if(p.tableau[maxi-1][j+1])
    p.tableau[maxi-1][j+1] = 0;
  else if(p.tableau[maxi-1][j-1])
    p.tableau[maxi-1][j-1] = 0;
}
