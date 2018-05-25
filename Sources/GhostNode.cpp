//
// Created by etienne on 25/05/18.
//

#include "GhostNode.h"

GhostNode::GhostNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                     int pr, Node& pa, Direction d):
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr),
        parent(pa),
        choix(d)
{
    next();
}

void GhostNode::next()
{
    if (niveau[fantomes[0].GetY()-1][fantomes[0].GetX()] != M
        && fantomes[0].GetY()-1 != fantomes[0].GetOldY())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerHaut();
        AleaNode AleaNode(f2,pac,niveau,profondeur,*this,1);
    }
    if (niveau[fantomes[0].GetY()+1][fantomes[0].GetX()]
        && fantomes[0].GetY()+1 != fantomes[0].GetOldY())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerBas();
        AleaNode AleaNode(f2,pac,niveau,profondeur,*this,1);
    }
    if (niveau[fantomes[0].GetY()][fantomes[0].GetX()-1]
        && fantomes[0].GetX()-1 != fantomes[0].GetOldX())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerGauche();
        AleaNode AleaNode(f2,pac,niveau,profondeur,*this,1);
    }
    if (niveau[fantomes[0].GetY()][fantomes[0].GetX()+1] != M
        && fantomes[0].GetX()+1 != fantomes[0].GetOldX())
    {
        array<Fantome,4> f2(fantomes);
        f2[0].BougerDroite();
        AleaNode AleaNode(f2,pac,niveau,profondeur,*this,1);
    }
}