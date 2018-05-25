#include "sdlclg.h"
#include "Constantes.h"
#include "Personnage.h"
#include "Pacman.h"
#include "Fantome.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


Evenement ChoisirEvenement()
{
	Evenement e = EVAucun;
	
	
	
	//Node root = new Node(
	
	return e;
}




void ChoisirRec(Objet** Tab, int profondeur)
{
	
}

void MatriceAdj()
{
	array<array<int, Largeur>, Hauteur> map;
	
	int cpt = Hauteur * Largeur;

	array<array<int, 399>, 399> Mat;
	vector<int> tmp;

	for(int i = 0; i < cpt; i++)
	{
		for(int j = 0; j < cpt; j++)
		{
			Mat[i][j] = 99;
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
					Mat[map[i][j]][map[i-1][j]] = 1;
					Mat[map[i-1][j]][map[i][j]] = 1;
				}
				if(Tableau[i+1][j] != M)
				{
					Mat[map[i][j]][map[i+1][j]] = 1;
					Mat[map[i+1][j]][map[i][j]] = 1;
				}
				if(Tableau[i][j-1] != M)
				{
					Mat[map[i][j]][map[i][j-1]] = 1;
					Mat[map[i][j-1]][map[i][j]] = 1;
				}
				if(Tableau[i][j+1] != M)
				{
					Mat[map[i][j]][map[i][j+1]] = 1;
					Mat[map[i][j+1]][map[i][j]] = 1;
				}

			}
		}	
	}
	Mat[190][208] = 1;
	Mat[208][190] = 1;

	for(int k = 0; k < cpt; k++)
	{
		for(int i = 0; i < cpt; i++)
		{
			for(int j = 0; j < cpt; j++)
				Mat[i][j] = min(Mat[i][j],Mat[i][k]+Mat[k][j]);
		}	
	}

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

int heuristique()
{

}

int main(int argc, char *argv[])
{
	cout << "Calculating adjacency matrix..." << endl;
	MatriceAdj();
	cout << "Done !" << endl;
	
}
