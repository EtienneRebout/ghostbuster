#ifndef NODE_H
#define NODE_H

#include "Pacman.h"
#include "Personnage.h"
#include <vector>

using namespace std;

class Node
{
private:
	array<Fantome> fantomes;
	Pacman pac;
	array<array<Objet>> niveau;
	int profondeur;
	bool hasParent;
	Node parent;
public:
	
};

#endif // NODE_H


