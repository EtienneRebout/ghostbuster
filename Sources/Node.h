//
// Created by etienne on 26/05/18.
//

#ifndef GHOSTBUSTER_NODE_H
#define GHOSTBUSTER_NODE_H

#include "Directions.h"

class Node {
private:
    double heuristique;
    Direction choix;
public:
    void setH(int h);
    int getH();
    void plusPossib();
    void setDir(Direction d);
};

#endif //GHOSTBUSTER_NODE_H
