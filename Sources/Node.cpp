//
// Created by etienne on 26/05/18.
//

#include "Node.h"
#include <iostream>
#include "Directions.h"

using namespace std;

void Node::setH(int h)
{
    heuristique = h;
    //cout << h << "->" << heuristique <<endl;
}

int Node::getH()
{
    return heuristique;
}

void Node::plusPossib()
{
    possib ++;
}

void Node::setDir(Direction d) { choix = d; }
