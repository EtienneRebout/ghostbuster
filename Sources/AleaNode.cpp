//
// Created by etienne on 25/05/18.
//

#include "AleaNode.h"

AleaNode::AleaNode(const array<Fantome, 4>& f, const Pacman& p, array<array<Objet, Largeur>, Hauteur> n,
                   int pr, Node& pa, int g):
        parent(pa),
        fantomes(f),
        pac(p),
        niveau(n),
        profondeur(pr),
        ghost(g)
{
    next();
    possib = 0;
}

void AleaNode::next()
{
    if(ghost < 4)
    {
        if (niveau[fantomes[ghost].GetY()-1][fantomes[ghost].GetX()] != M
            && fantomes[ghost].GetY()-1 != fantomes[ghost].GetOldY())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerHaut();
            AleaNode AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
        }
        if (niveau[fantomes[ghost].GetY()+1][fantomes[ghost].GetX()]
            && fantomes[ghost].GetY()+1 != fantomes[ghost].GetOldY())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerBas();
            AleaNode AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
        }
        if (niveau[fantomes[ghost].GetY()][fantomes[ghost].GetX()-1]
            && fantomes[ghost].GetX()-1 != fantomes[ghost].GetOldX())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerGauche();
            AleaNode AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
        }
        if (niveau[fantomes[ghost].GetY()][fantomes[ghost].GetX()+1] != M
            && fantomes[ghost].GetX()+1 != fantomes[ghost].GetOldX())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerDroite();
            AleaNode AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
        }
    }
    else
    {
        // Computing heuristic


        possib = 1;
    }

    parent.plusPossib();
    parent.setH(parent.getH() + (heuristique / possib));

}

void AleaNode::plusPossib()
{
    possib ++;
}