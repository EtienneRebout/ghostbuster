//
// Created by etienne on 25/05/18.
//

#include "ai.h"
#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"
#include "GhostNode.h"
#include "PacNode.h"
#include "AleaNode.h"
#include "Node.h"
#include "Directions.h"
#include <vector>
using namespace std;

PacNode::PacNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                 int pr, Node& pa):
        parent(pa),
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr)
{
    choix = NONE;
    heuristique = 0;
    next();
}

void PacNode::next()
{
    // Creates a GN for each possible direction
    // The GN will update the heuristic and direction of this PN using their reference to it
    if (niveau[pac.GetY()-1][pac.GetX()] != M)
    {
        Pacman nextPac(pac);
        nextPac.BougerHaut();
        GhostNode GhostNode(fantomes,pac,niveau,profondeur-1,*this,HAUT);
    }
    if (niveau[pac.GetY()+1][pac.GetX()])
    {
        Pacman nextPac(pac);
        nextPac.BougerBas();
        GhostNode GhostNode(fantomes,pac,niveau,profondeur-1,*this,BAS);
    }
    if (niveau[pac.GetY()][pac.GetX()-1])
    {
        Pacman nextPac(pac);
        nextPac.BougerGauche();
        GhostNode GhostNode(fantomes,pac,niveau,profondeur-1,*this,GAUCHE);
    }
    if (niveau[pac.GetY()][pac.GetX()+1] != M)
    {
        Pacman nextPac(pac);
        nextPac.BougerDroite();
        GhostNode GhostNode(fantomes,pac,niveau,profondeur-1,*this,DROITE);
    }

    // Now the PN transmits its heuristic to its parent (if it's not the root node, i.e. parent = null)
    parent.setH(heuristique);
}

Direction PacNode::getDir()
{
    return choix;
}