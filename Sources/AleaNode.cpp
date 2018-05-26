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
    heuristique = 0;
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
        if(profondeur > 0)
        {
            PacNode PacNode(fantomes, pac, niveau, profondeur, *this, false);
        }
        else
        {
            // Computing heuristic
            int x = pac.GetX();
            int y = pac.GetY();

            for(int i = 0; i < 4; i++)
            {
                heuristique += Mat[x+19*y][fantomes[i].GetX()+19*fantomes[i].GetY()];
                if(niveau[x][y] == P)
                    heuristique += 15;
            }

        }



        possib = 1;
    }

    parent.plusPossib();
    parent.setH(parent.getH() + (heuristique / possib));

}

void AleaNode::plusPossib()
{
    possib ++;
}