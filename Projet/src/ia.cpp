#include <iostream>
#include "../header/plateau.h"

using namespace std;

int Min(Plateau & p,int profondeur);
int Max(Plateau & p,int profondeur);
int eval(Plateau & p);


bool verifieAvant(int i, int j, Plateau p)
{
    if(i < p.getSize()-1 && p.tableau[i][j] == 1 && p.tableau[i+1][j] == 0)
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
  if(i < p.getSize()-1 && p.tableau[i][j] == 1 && p.tableau[i+1][j+1] == 0)
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
  if(i < p.getSize()-1 && p.tableau[i][j] == 1 && p.tableau[i+1][j-1] == 0)
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

bool verifieMange(int i, int j, Plateau & p)
{
  if(p.tableau[i-1][j] == 2 && p.tableau[i-2][j] == 0)
    return true;
  else if(p.tableau[i+1][j] == 2 && p.tableau[i+2][j] == 0)
    return true;
  else if(p.tableau[i][j-1] == 2 && p.tableau[i][j-2] == 0)
    return true;
  else if(p.tableau[i][j+1] == 2 && p.tableau[i][j+2] == 0)
    return true;
  else
    return false;
}

void mange(int i, int j, Plateau & p)
{
  if(p.tableau[i-1][j] == 2 && p.tableau[i-2][j] == 0)
  {
    p.tableau[i][j] = 0;
    p.tableau[i-1][j] = 0;
    p.tableau[i-2][j] = 1;
  }
  else if(p.tableau[i+1][j] == 2 && p.tableau[i+2][j] == 0)
  {
    p.tableau[i][j] = 0;
    p.tableau[i+1][j] = 0;
    p.tableau[i+2][j] = 1;
  }
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

bool gagnant(Plateau p)
{
  int cpt = 0;
  for(int i=0;i<p.tableau.size();i++)
  {
    for(int j=0;j<p.tableau.size();j++)
    {
      if(p.tableau[i][j] == 2)
        cpt+=1;
    }
  }
  if(cpt == 0)
    return true;
  return false;
}

bool perdant(Plateau p)
{
  int cpt = 0;
  for(int i=0;i<p.tableau.size();i++)
  {
    for(int j=0;j<p.tableau.size();j++)
    {
      if(p.tableau[i][j] == 1)
        cpt+=1;
    }
  }
  if(cpt == 0)
    return true;
  return false;
}

int eval(Plateau & p)
{
  if(perdant(p))
 return -9999;
else if(gagnant(p))
 return 9999;
else
  return 0;



}

void jouerIA(Plateau & p, int profondeur)
{
  int max = -99999;
  int tmp = 0;
  int maxi = 0;
  int maxj = 0;
  int i;
  int j;
  int action = 0;

  for(i=0;i < p.tableau.size(); i++)
  {
    for(j = 0; j < p.tableau.size(); j++)
    {
      if(verifieAvant(i,j,p))
      {
        enAvant(i,j,p);
        tmp = Min(p,profondeur-1);
        cout << "verifAvant tmp = " << tmp << endl;
        if(tmp > max)
        {
          action = 1;
          max = tmp;
          maxi = i+1;
          maxj = j;
        }
        annuleAvant(i,j,p);
      }
      if(verifieDroite(i,j,p))
      {
        aDroite(i,j,p);
        tmp = Min(p,profondeur-1);
        cout << "verifDroite tmp = " << tmp << endl;
        if(tmp > max)
        {
          action = 2;
          max = tmp;
          maxi = i+1;
          maxj = j+1;
        }
        annuleDroite(i,j,p);
      }
      if(verifieGauche(i,j,p))
      {
        aGauche(i,j,p);
        tmp = Min(p,profondeur-1);
        cout << "verifGauche tmp = " << tmp << endl;
        if(tmp > max)
        {
          action = 3;
          max = tmp;
          maxi = i+1;
          maxj = j-1;
        }
        annuleGauche(i,j,p);
      }
    }
  }
  cerr << "maxi "  << maxi << endl;
  cerr << "maxj " << maxj << endl;
  cerr << "action " << action<< endl;
  p.tableau[maxi][maxj] = 1;
  if(action == 1)
  {
    p.tableau[maxi-1][maxj] = 0;
    cout << "action == 1 toi meme tu sais" << endl;
  }

  else if(action == 2)
    p.tableau[maxi-1][maxj-1] = 0;
  else if(action == 3)
    p.tableau[maxi-1][maxj+1] = 0;
}
