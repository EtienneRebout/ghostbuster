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
    heuristique = -50000;
}

double PacNode::next()
{
    // Creates a GN for each possible direction
    // The GN will update the heuristic and direction of this PN using their reference to it
    if (niveau[pac.GetY()-1][pac.GetX()] != M
        && pac.GetY()-1 != pac.GetOldY()
            )
    {
        Pacman nextPac(pac);
        nextPac.BougerHaut();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,HAUT);
        double x = gn.next();
        if (niveau[pac.GetY()-1][pac.GetX()] == P)
            x += POINT;

        heuristique = max(x, heuristique);
    }
    if (niveau[pac.GetY()+1][pac.GetX()] != M
        && pac.GetY()+1 != pac.GetOldY()
        && !(pac.GetX() == 9 && pac.GetY() == 7))
    {
        Pacman nextPac(pac);
        nextPac.BougerBas();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,BAS);
        double x = gn.next();
        if (niveau[pac.GetY()+1][pac.GetX()] == P)
            x += POINT;
        heuristique = max(x, heuristique);
    }
    if (niveau[pac.GetY()][pac.GetX()-1] != M
        && pac.GetX()-1 != pac.GetOldX()
            )
    {
        Pacman nextPac(pac);
        nextPac.BougerGauche();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,GAUCHE);
        double x = gn.next();
        if (niveau[pac.GetY()][pac.GetX()-1] == P)
            x += POINT;
        heuristique = max(x, heuristique);
    }
    if (niveau[pac.GetY()][pac.GetX()+1] != M
        && pac.GetX()+1 != pac.GetOldX()
            )
    {
        Pacman nextPac(pac);
        nextPac.BougerDroite();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,DROITE);
        double x = gn.next();
        if (niveau[pac.GetY()][pac.GetX()+1] == P)
            x += POINT;
        if (niveau[pac.GetY()][pac.GetX()+1] == W)
            x += CERISE;
	
        heuristique = max(x, heuristique);
    }

    // Now the PN transmits its heuristic to its parent (if it's not the root node, i.e. parent = null)
    return heuristique;
}

Direction PacNode::getDir()
{
    return choix;
}
