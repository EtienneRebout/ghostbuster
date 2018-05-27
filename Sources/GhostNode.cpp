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
#include <vector>
using namespace std;

GhostNode::GhostNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                     int pr, Node& pa, Direction d):
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr),
        parent(pa),
        choix(d)
{
    heuristique = 0;
}

double GhostNode::next()
{
    for(int i = 0; i < 4; i ++)
    {
        if (fantomes[i].GetX() == pac.GetX() && fantomes[i].GetY() == pac.GetY())
            return -100000;
    }
    if (niveau[fantomes[0].GetY()-1][fantomes[0].GetX()] != M
        && fantomes[0].GetY()-1 != fantomes[0].GetOldY())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerHaut();
        AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,1);
        heuristique += an.next();
    }
    if (niveau[fantomes[0].GetY()+1][fantomes[0].GetX()]
        && fantomes[0].GetY()+1 != fantomes[0].GetOldY())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerBas();
        AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,1);
        heuristique += an.next();
    }
    if (niveau[fantomes[0].GetY()][fantomes[0].GetX()-1]
        && fantomes[0].GetX()-1 != fantomes[0].GetOldX())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerGauche();
        AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,1);
        heuristique += an.next();
    }
    if (niveau[fantomes[0].GetY()][fantomes[0].GetX()+1] != M
        && fantomes[0].GetX()+1 != fantomes[0].GetOldX())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerDroite();
        AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,1);
        heuristique += an.next();
    }

    /*if(heuristique > parent.getH())
    {
        parent.setH(heuristique);
        parent.setDir(choix);
    }*/
    return heuristique;
}