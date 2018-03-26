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
	const Node& parent;
	bool ghostNode;
	double proba;
public:
	const Node& getParent() const;
	
};

#endif // NODE_H


