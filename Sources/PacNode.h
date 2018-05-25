//
// Created by etienne on 25/05/18.
//

#ifndef GHOSTBUSTER_PACNODE_H
#define GHOSTBUSTER_PACNODE_H

#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"
#include "GhostNode.h"
#include "AleaNode.h"
#include "Node.h"

#include <vector>

class PacNode : public Node
{
private:
    array<Fantome, 4> fantomes; // Les 4 fantomes
    Pacman pac; // Le pacman
    array<array<Objet, Largeur>, Hauteur> niveau; // La matrice du niveau (pour les positions des points
    int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
    Node& parent; // Référence vers le parent, pour lui transmettre les infos
    Direction choix; // La direction choisie par le Pacman, utile uniquement à la racine
    int heuristique; // La meilleure heuristique possible correspondant au "bon choix" de direction
    bool root; // Indique si c'est le 1er PacNode (qui ne remontera rien)
public:
    PacNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
            int pr, Node& pa, bool r);
    void next();
    void setH(int h);
    int getH();
};


#endif //GHOSTBUSTER_PACNODE_H