#include "sdlclg.h"
#include "Constantes.h"
#include "Personnage.h"
#include "Pacman.h"
#include "Fantome.h"

Evenement ChoisirEvenement()
{
	Evenement e = EVAucun;
	
	e = decide();
	
	return e;
}
