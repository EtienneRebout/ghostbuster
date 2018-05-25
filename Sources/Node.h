//
// Created by etienne on 26/05/18.
//

#ifndef GHOSTBUSTER_NODE_H
#define GHOSTBUSTER_NODE_H


class Node {
private:
    int heuristique;
public:
    void setH(int h);
    int getH();
    void plusPossib();
};


#endif //GHOSTBUSTER_NODE_H
