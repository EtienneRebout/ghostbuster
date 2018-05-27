//Copyright (C) 2013-2017  Alexandre-Xavier Labonté-Lamoureux
//Constantes.h
//Initialisation des fonctions, des constantes, etc.

#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <array>

using namespace std;

//Déclarations de constantes requises pour le jeu
constexpr int Largeur = 19;
constexpr int Hauteur = 21;
constexpr int NbPixelsParCase = 32;
//Ajoutez vos propres constantes ici...
constexpr int VitesseFantome = 4; // Bougent à tous les 10 tours
constexpr int MurMince = 4;

const int TEMPS_FUITE = 150;

//Énumération pour représenter une case du labyrinthe
//V=Vide, M=Mur, P=Point
enum Objet {M, V, P, W};

//Tableau de la carte
static array<Objet,Largeur> ligne1 =
{ M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M};
static array<array<Objet,Largeur>,Hauteur> Tableau =
{
	ligne1,
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

static array<array<Objet,Largeur>,Hauteur> TableauCopie(Tableau);
//std::copy(std::begin(src), std::end(src), std::begin(dest));

#endif // CONSTANTES_H


