//
// Created by etienne on 25/05/18.
//

#include "PacNode.h"

PacNode::PacNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                 int pr, Node& pa, bool r):
        parent(pa),
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr),
        root(r)
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
    if(!root)
        parent.setH(heuristique);
}