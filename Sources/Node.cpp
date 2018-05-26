//
// Created by etienne on 26/05/18.
//

#include "Node.h"
#include "Directions.h"

using namespace std;

void Node::setH(int h)
{
    heuristique = h;
}

int Node::getH()
{
    return heuristique;
}

void Node::plusPossib() {}

void Node::setDir(Direction d) { choix = d; }
