//
// Created by etienne on 25/05/18.
//

#ifndef GHOSTBUSTER_GHOSTNODE_H
#define GHOSTBUSTER_GHOSTNODE_H

#include "Node.h"

class GhostNode : public Node
{
private:
    array<Fantome, 4> fantomes; // Les 4 fantomes
    Pacman pac; // Le pacman
    array<array<Objet, Largeur>, Hauteur> niveau; // La matrice du niveau (pour les positions des points
    int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
    Node& parent; // Référence vers le parent, pour lui transmettre les infos
    Direction choix; // La direction choisie par le Pacman, à retransmettre au parent en cas de meilleure heuristique
    double  heuristique;
public:
    GhostNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
              int pr, Node& pa, Direction d);
    void next();
    int getH();
};


#endif //GHOSTBUSTER_GHOSTNODE_H
