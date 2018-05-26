#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"

Node::Node(const array<Fantome>& f, const Pacman& p, array<array<Objet>> n, int p, const Node& pa, bool gn, double pr):
		parent(pa),
		fantomes(f),
		pac(p),
		niveau(n),
		profondeur(p),
		ghostNode(gn),
		proba(pr)
{
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
		//heuristique();
	}
	else
	{
		if(ghostNode)
		{
			possib = 0;
			moveG(0, fantomes);
			proba = 1/possib;
		}
		else
		{
			moveP();
		}
	}
}

void moveG(int i, const array<Fantome>& f) {
	if (i == 4) {
		Node noeud(f, pac, niveau, profondeur, this, false);
	} else {
		if (niveau[f[i].getY() - 1][f[i].getX()] != M
			&& f[i].getY() - 1 != f[i].getOldY()) {
			array<Fantome, 4> f2(f);
			f2[i].BougerHaut();
			moveG(i + 1, f2);
			possib++;
		}
		if (niveau[f[i].getY() + 1][f[i].getX()]
			&& f[i].getY() + 1 != f[i].getOldY()) {
			array<Fantome, 4> f2(f);
			f2[i].BougerBas();
			moveG(i + 1, f2);
			possib++;
		}
		if (niveau[f[i].getY()][f[i].getX() - 1]
			&& f[i].getX() - 1 != f[i].getOldX()) {
			array<Fantome, 4> f2(f);
			f2[i].BougerGauche();
			moveG(i + 1, f2);
			possib++;
		}
		if (niveau[f[i].getY()][f[i].getX() + 1] != M
			&& f[i].getX() + 1 != f[i].getOldX()) {
			array<Fantome, 4> f2(f);
			f2[i].BougerDroite();
			moveG(i + 1, f2);
			possib++;
		}
	}
}