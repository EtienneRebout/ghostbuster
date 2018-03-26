#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"

Node::Node(const array<Fantome>& f, const Pacman& p, array<array<Objet>> n, int p, const Node& pa, bool gn, double pr): parent(pa),fantomes(f),pac(p),
{
	fantomes = f;
	pac = p;
	niveau = n;
	profondeur = p;
	parent = pa;
	ghostNode = gn;
	proba = pr
	this.next();
}

const Node& Node::getParent() const
{
	return parent;
}

void next()
{
	if(profondeur == 0)
	{
		
	}
	else
	{
		if(ghostNode)
		{
			proba = 1;
			moveG(0, fantomes);
		}
		else
		{
			moveP();
		}
	}
}

void moveG(int i, const array<Fantome>& f)
{
	if(i==4)
	{
		Node noeud(f, pac, niveau, profondeur, this, false);
	}
	else
	{
		if (niveau[f[i].getY()-1][f[i].getX()] != M)
		{
			if (f[i].getY()-1 != f[i].getOldY())
			{
				array<Fantome,4> f2(f);// = {f2[0].clone(),f2[1].clone(),f2[2].clone(),f2[3].clone()} ;
				f2[i].BougerHaut();
				moveG(i+1, bougerF(f, i, 0);
			}
		}
		else if (niveau[f[i].getY()+1][f[i].getX()])
		{
			if(f[i].getY()+1 != f[i].getOldY())
			{
				array<Fantome,4> f2 = {f2[0].clone(),f2[1].clone(),f2[2].clone(),f2[3].clone()} ;
				f2[i].BougerBas();
				moveG(i+1, bougerF(f, i, 1);
			}
		}
		else if (niveau[f[i].getY()][f[i].getX()-1])
		{
			if (f[i].getX()-1 != f[i].getOldX())
			{
				array<Fantome,4> f2 = {f2[0].clone(),f2[1].clone(),f2[2].clone(),f2[3].clone()} ;
				f2[i].BougerGauche();
				moveG(i+1, bougerF(f, i, 2);
			}
		}
		else if (niveau[f[i].getY()][f[i].getX()+1] != M)
		{
			if(f[i].getX()+1 != f[i].getOldX())
			{
				array<Fantome,4> f2 = {f2[0].clone(),f2[1].clone(),f2[2].clone(),f2[3].clone()} ;
				f2[i].BougerDroite();
				moveG(i+1, bougerF(f, i, 3);
			}
		}
}
