//
// Created by etienne on 25/05/18.
//

#ifndef GHOSTBUSTER_PACNODE_H
#define GHOSTBUSTER_PACNODE_H

#include "Node.h"
#include "Directions.h"

class PacNode : public Node
{
private:
    array<Fantome, 4> fantomes; // Les 4 fantomes
    Pacman pac; // Le pacman
    array<array<Objet, Largeur>, Hauteur> niveau; // La matrice du niveau (pour les positions des points
    int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
    Node& parent; // Référence vers le parent, pour lui transmettre les infos
    Direction choix; // La direction choisie par le Pacman, utile uniquement à la racine
    double heuristique; // La meilleure heuristique possible correspondant au "bon choix" de direction
public:
    PacNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
            int pr, Node& pa);
    double next();
    Direction getDir();
};


#endif //GHOSTBUSTER_PACNODE_H
