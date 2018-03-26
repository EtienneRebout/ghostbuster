#include "sdlclg.h"
#include "Constantes.h"
#include "Pacman.h"
#include "Personnage.h"
#include "Fantome.h"

Node::Node(Fantome* f, Pacman p, Objet** n, int p, bool hp)
{
	fantomes = f;
	pac = p;
	niveau = n;
	profondeur = p;
	hasParents = hp
}
