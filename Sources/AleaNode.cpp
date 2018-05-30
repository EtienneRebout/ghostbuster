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
#include "Node.h"
#include "AleaNode.h"
#include "global.h"
#include <vector>
#include <math.h>
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
    possib = 0;
    heuristique = 0;
}
double AleaNode::next()
{
    //cout << "A";
    if(ghost < 4)
    {
        if (niveau[fantomes[ghost].GetY()-1][fantomes[ghost].GetX()] != M
            && fantomes[ghost].GetY()-1 != fantomes[ghost].GetOldY())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerHaut();
            AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
            heuristique += an.next();
            possib ++;
        }
        if (niveau[fantomes[ghost].GetY()+1][fantomes[ghost].GetX()]
            && fantomes[ghost].GetY()+1 != fantomes[ghost].GetOldY())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerBas();
            AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
            heuristique += an.next();
            possib ++;
        }
        if (niveau[fantomes[ghost].GetY()][fantomes[ghost].GetX()-1]
            && fantomes[ghost].GetX()-1 != fantomes[ghost].GetOldX())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerGauche();
            AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
            heuristique += an.next();
            possib ++;
        }
        if (niveau[fantomes[ghost].GetY()][fantomes[ghost].GetX()+1] != M
            && fantomes[ghost].GetX()+1 != fantomes[ghost].GetOldX())
        {
            array<Fantome,4> f2(fantomes);
            f2[ghost].BougerDroite();
            AleaNode an = AleaNode(f2,pac,niveau,profondeur,*this,ghost+1);
            heuristique += an.next();
            possib ++;
        }
    }
    else
    {
        if(profondeur > 0)
        {
            PacNode pn = PacNode(fantomes, pac, niveau, profondeur, *this);
            heuristique = pn.next();
        }
        else
        {
            // Computing heuristic
            int x = pac.GetX();
            int y = pac.GetY();
            double distMin = 200;
            heuristique = -2000.0;
            for(int i = 0; i < 4; i++)
            {
                double dist = global::Mat[x+19*y][fantomes[i].GetX()+19*fantomes[i].GetY()];
                distMin = min(dist, distMin);
                //heuristique = max(heuristique, (-5000.0)/sqrt(dist));
            }

            heuristique = -500.0/sqrt(distMin);

            /*if (distMin < 2)
                heuristique = -10000.0;
            if (distMin > 15)
                heuristique = 2000.0;*/

            if(niveau[x][y] == P)
                heuristique += POINT;

        }

        possib = 1;
    }
    heuristique = heuristique / possib;

    return heuristique;
}

void AleaNode::plusPossib()
{
    possib ++;
    //cout << "coucou" << endl;
}
