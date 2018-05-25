//
// Created by etienne on 26/05/18.
//

#include "Node.h"

void Node::setH(int h)
{
    heuristique = h;
}

int Node::getH()
{
    return heuristique;
}

void Node::plusPossib() {}