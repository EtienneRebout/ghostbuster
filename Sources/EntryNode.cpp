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
#include "EntryNode.h"
#include <vector>
using namespace std;

EntryNode::EntryNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                 int pr, bool r):
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr),
        root(r)
{
    choix = NONE;
    heuristique = -50000;
}

Direction EntryNode::next()
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
        //cout << "1:" << x << endl;
        if(x > heuristique)
        {
            heuristique = x;
            choix = HAUT;
        }
    }
    if (niveau[pac.GetY()+1][pac.GetX()] != M
        && pac.GetY()+1 != pac.GetOldY()
        && !(pac.GetX() == 9 && pac.GetY() == 7))
    {
        Pacman nextPac(pac);
        nextPac.BougerBas();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,BAS);
        double x = gn.next();
        //cout << "2:" << x << endl;
        if(x > heuristique)
        {
            heuristique = x;
            choix = BAS;
        }
    }
    if (niveau[pac.GetY()][pac.GetX()-1] != M
        && pac.GetX()-1 != pac.GetOldX()
            )
    {
        Pacman nextPac(pac);
        nextPac.BougerGauche();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,GAUCHE);
        double x = gn.next();
        //cout << "3:" << x << endl;
        if(x > heuristique)
        {
            heuristique = x;
            choix = GAUCHE;
        }
    }
    if (niveau[pac.GetY()][pac.GetX()+1] != M
        && pac.GetX()+1 != pac.GetOldX()
            )
    {
        Pacman nextPac(pac);
        nextPac.BougerDroite();
        GhostNode gn = GhostNode(fantomes,nextPac,niveau,profondeur-1,*this,DROITE);
        double x = gn.next();
        //cout << "4:" << x << endl;
        if(x > heuristique)
        {
            heuristique = x;
            choix = DROITE;
        }
    }
    //cout << choix << endl;
    return choix;
}

Direction EntryNode::getDir()
{
    return choix;
}