#include "ai.h"
#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"
#include "GhostNode.h"
#include "PacNode.h"
#include "AleaNode.h"
#include "Node.h"
#include "global.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace global
{
	array<array<int, 399>, 399> Mat;
}

void MatriceAdj()
{
	array<array<int, Largeur>, Hauteur> map;
	
	int cpt = Hauteur * Largeur;
	//
	vector<int> tmp;

	for(int i = 0; i < cpt; i++)
	{
		for(int j = 0; j < cpt; j++)
		{
			global::Mat[i][j] = 99;
		}
	}

	cpt = 0;
	for(int i = 0; i < Hauteur; i++)
	{
		for(int j = 0; j < Largeur; j++)
		{
			map[i][j] = cpt++;
		}	
	}

	for(int i = 0; i < Hauteur; i++)
	{
		for(int j = 0; j < Largeur; j++)
		{
			if(Tableau[i][j] != M)
			{
				if(Tableau[i-1][j] != M)
				{
                    global::Mat[map[i][j]][map[i-1][j]] = 1;
                    global::Mat[map[i-1][j]][map[i][j]] = 1;
				}
				if(Tableau[i+1][j] != M)
				{
                    global::Mat[map[i][j]][map[i+1][j]] = 1;
                    global::Mat[map[i+1][j]][map[i][j]] = 1;
				}
				if(Tableau[i][j-1] != M)
				{
                    global::Mat[map[i][j]][map[i][j-1]] = 1;
                    global::Mat[map[i][j-1]][map[i][j]] = 1;
				}
				if(Tableau[i][j+1] != M)
				{
                    global::Mat[map[i][j]][map[i][j+1]] = 1;
                    global::Mat[map[i][j+1]][map[i][j]] = 1;
				}

			}
		}	
	}
    /*global::Mat[190][208] = 1;
    global::Mat[208][190] = 1;*/

	for(int k = 0; k < cpt; k++)
	{
		for(int i = 0; i < cpt; i++)
		{
			for(int j = 0; j < cpt; j++)
            global::Mat[i][j] = min(global::Mat[i][j],global::Mat[i][k]+global::Mat[k][j]);
		}	
	}

	//cout << Mat[9+19*15][8+19*9] << endl;

	// Pour accéder à la distance entre les cases A(X1,Y1) et B(X2,Y2), il faut lire Mat[X1+19*Y1][X2+19*Y2]

	/*ofstream matrice;
	matrice.open("matrice.txt");
	for(int i = 0; i < cpt; i++)
	{
		for(int j = 0; j < cpt; j++)
		{
			matrice << Mat[i][j] << " ";
		}	
		matrice << endl;
	}
	matrice.close();*/
}

/*
int main(int argc, char *argv[])
{
	cout << "Calculating adjacency matrix..." << endl;
	MatriceAdj();
	cout << "Done !" << endl;
	
}
*/