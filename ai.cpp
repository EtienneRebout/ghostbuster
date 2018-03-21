#include "sdlclg.h"
#include "Constantes.h"
#include "Personnage.h"
#include "Pacman.h"
#include "Fantome.h"
#include <iostream>
#include <fstream>
using namespace std;


Evenement ChoisirEvenement()
{
	Evenement e = EVAucun;
	
	int profondeur;


	
	return e;
}

void MatriceAdj()
{
	int TableauCopieCopie[Hauteur][Largeur] =
	{
	{ M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M},
	{ M, P, P, P, P, P, P, P, P, M, P, P, P, P, P, P, P, P, M},
	{ M, W, M, M, P, M, M, M, P, M, P, M, M, M, P, M, M, W, M},
	{ M, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, M},
	{ M, P, M, M, P, M, P, M, M, M, M, M, P, M, P, M, M, P, M},
	{ M, P, P, P, P, M, P, P, P, M, P, P, P, M, P, P, P, P, M},
	{ M, M, M, M, P, M, M, M, V, M, V, M, M, M, P, M, M, M, M},
	{ V, V, V, M, P, M, V, V, V, V, V, V, V, M, P, M, V, V, V},
	{ M, M, M, M, P, M, V, M, M, V, M, M, V, M, P, M, M, M, M},
	{ V, V, V, V, P, V, V, M, V, V, V, M, V, V, P, V, V, V, V},
	{ M, M, M, M, P, M, V, M, M, M, M, M, V, M, P, M, M, M, M},
	{ V, V, V, M, P, M, V, V, V, V, V, V, V, M, P, M, V, V, V},
	{ M, M, M, M, P, M, V, M, M, M, M, M, V, M, P, M, M, M, M},
	{ M, P, P, P, P, P, P, P, P, M, P, P, P, P, P, P, P, P, M},
	{ M, P, M, M, P, M, M, M, P, M, P, M, M, M, P, M, M, P, M},
	{ M, W, P, M, P, P, P, P, P, P, P, P, P, P, P, M, P, W, M},
	{ M, M, P, M, P, M, P, M, M, M, M, M, P, M, P, M, P, M, M},
	{ M, P, P, P, P, M, P, P, P, M, P, P, P, M, P, P, P, P, M},
	{ M, P, M, M, M, M, M, M, P, M, P, M, M, M, M, M, M, P, M},
	{ M, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, M},
	{ M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M},
	};
	
	int cpt = 0;
	for(int i = 0; i < Hauteur; i++)
	{
		for(int j = 0; j < Largeur; j++)
		{
			if(Tableau[i][j] != M)
				cpt++;
		}	
	}

	int Mat[cpt+1][cpt+1];

	for(int i = 0; i < cpt+1; i++)
	{
		for(int j = 0; j < cpt+1; j++)
		{
			Mat[i][j] = 9999;
		}	
	}

	cpt = 0;
	for(int i = 0; i < Hauteur; i++)
	{
		for(int j = 0; j < Largeur; j++)
		{
			if(Tableau[i][j] != M)
				TableauCopieCopie[i][j] = ++cpt;
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
					Mat[TableauCopieCopie[i][j]][TableauCopieCopie[i-1][j]] = 1;
					Mat[TableauCopieCopie[i-1][j]][TableauCopieCopie[i][j]] = 1;
				}
				if(Tableau[i+1][j] != M)
				{
					Mat[TableauCopieCopie[i][j]][TableauCopieCopie[i+1][j]] = 1;
					Mat[TableauCopieCopie[i+1][j]][TableauCopieCopie[i][j]] = 1;
				}
				if(Tableau[i][j-1] != M)
				{
					Mat[TableauCopieCopie[i][j]][TableauCopieCopie[i][j-1]] = 1;
					Mat[TableauCopieCopie[i][j-1]][TableauCopieCopie[i][j]] = 1;
				}
				if(Tableau[i][j+1] != M)
				{
					Mat[TableauCopieCopie[i][j]][TableauCopieCopie[i][j+1]] = 1;
					Mat[TableauCopieCopie[i][j+1]][TableauCopieCopie[i][j]] = 1;
				}

			}
		}	
	}


	for(int k = 1; k < cpt; k++)
	{
		for(int i = 1; i < cpt; i++)
		{
			for(int j = 1; j < cpt; j++)
				Mat[i][j] = min(Mat[i][j],Mat[i][k]+Mat[k][j]);
		}	
	}

	ofstream matrice;
	matrice.open("matrice.txt");
	for(int i = 1; i < cpt; i++)
	{
		for(int j = 1; j < cpt; j++)
		{
			matrice << Mat[i][j] << "  ";
		}	
		matrice << endl;
	}
	matrice.close();
}


int main(int argc, char *argv[])
{
	cout << "Starting..." << endl;
	MatriceAdj();
	cout << "Done !" << endl;
	
}
