//
// Created by etienne on 25/05/18.
//

#ifndef GHOSTBUSTER_ALEANODE_H
#define GHOSTBUSTER_ALEANODE_H

#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"
#include "GhostNode.h"
#include "PacNode.h"
#include "Node.h"

#include <vector>

class AleaNode : public Node
{
private:
    array<Fantome, 4> fantomes; // Les 4 fantomes
    Pacman pac; // Le pacman
    array<array<Objet, Largeur>, Hauteur> niveau; // La matrice du niveau (pour les positions des points
    int profondeur; // La profondeur de l'arbre (décroissante, feuille -> 0)
    Node& parent; // Référence vers le parent, pour lui transmettre les infos
    Direction choix; // La direction choisie par le Pacman, à retransmettre au parent en cas de meilleure heuristique
    int heuristique;
    int ghost; // Pour savoir à quel ghost du tableau on est (et quand s'arrêter)
    double proba; // Proba de cette branche
    double possib; // Nombre de possibilités pour le fantôme en cours
public:
    AleaNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
             int pr, Node& pa, int g);
    void next();
    void plusPossib();
};


#endif //GHOSTBUSTER_ALEANODE_H
