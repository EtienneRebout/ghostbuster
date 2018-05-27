//
// Created by etienne on 25/05/18.
//

#ifndef GHOSTBUSTER_ENTRYNODE_H
#define GHOSTBUSTER_ENTRYNODE_H

#include "Node.h"
#include "Directions.h"

class EntryNode : public Node
{
private:
    array<Fantome, 4> fantomes; // Les 4 fantomes
    Pacman pac; // Le pacman
    array<array<Objet, Largeur>, Hauteur> niveau; // La matrice du niveau (pour les positions des points
    int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
    Direction choix; // La direction choisie par le Pacman, utile uniquement à la racine
    double heuristique; // La meilleure heuristique possible correspondant au "bon choix" de direction
    bool root; // Indique si c'est le 1er PacNode (qui ne remontera rien)
public:
    EntryNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
            int pr, bool r);
    Direction next();
    Direction getDir();
};


#endif //GHOSTBUSTER_ENTRYNODE_H
