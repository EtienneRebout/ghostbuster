#ifndef NODE_H
#define NODE_H

#include "Pacman.h"
#include "Personnage.h"
#include <vector>

using namespace std;

class Node
{
private:
	array<Fantome> fantomes; // Les 4 fantomes
	Pacman pac; // Le pacman
	array<array<Objet>> niveau; // La matrice du niveau (pour les positions des points
	int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
	const Node& parent; // Référence vers le parent, pour lui transmettre les infos
	bool ghostNode; // Indique si on est sur une ghostNode ou une pacNode
	double proba; // Probabilité de cette node (pour GN)
	double possib; // Nombre de possibilités pour cette node (pour GN)
public:
	const Node& getParent() const;
	
};

#endif // NODE_H


