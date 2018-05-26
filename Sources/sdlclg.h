#ifndef _SDLCLG_H
#define _SDLCLG_H
///////////////////////////////////////////////////////////////////////////////
// sdlclg.h
// Interface de programmation graphique pour le cours de KA0 utilisation la
// la libraire SDL 1.2.14-VC8
// Joan-S�bastien Morales et St�phane Chass�
// Version 1.0 Cr�ation 25 octobre 2009
// Version 1.1 Modification 27 octobre 2009
//   -- Ajout de messages d'erreurs
//   -- Ajout de la fonction RafraichirFenetre
// Version 1.2 Modification 17 novembre 2009
//   -- Ajout du type ImageId
//   -- Ajout de l'�num�ration Evenement
//   -- Ajout de la fonction AttendreEvenement
// Version 1.21 Modification 24 novembre 2009
//   -- Correction d'un bug avec la fonction AttendreEvenement
// Version 1.22 Modification 12 novembre 2013
//   -- Ajout de la fonction non-bloquante LireEvenement
// Version 1.23 Modification 4 mai 2017
//   -- Correction d'un bug dans LireEvenement d� � SDL_PollEvent
///////////////////////////////////////////////////////////////////////////////
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif
#include "Directions.h"
//#include <windows.h>
//#include <vector>
//#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Type de donn�es utilis� pour conserver les num�ros d'images
///////////////////////////////////////////////////////////////////////////////
typedef int ImageId;

///////////////////////////////////////////////////////////////////////////////
// Liste des �v�nements associ�s au clavier
///////////////////////////////////////////////////////////////////////////////
enum Evenement
{
	EVAucun, EVQuitter,	EVBas, EVHaut, EVGauche, EVDroite
};
///////////////////////////////////////////////////////////////////////////////
// Attendre
// Permet de placer le programme en attente pendant un certain temps
// Intrant: Temps: Nombre de millisecondes
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void Attendre(int Temps);
///////////////////////////////////////////////////////////////////////////////
// InitialiserAffichage
// Fait appara�tre une fen�tre graphique
// Intrant: Titre: Titre de la fen�tre
//			Largeur: Largeur de la fen�tre en pixels
//		    Hauteur: Hauteur de la fen�tre en pixels
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void InitialiserAffichage(string Titre, int Largeur, int Hauteur);
///////////////////////////////////////////////////////////////////////////////
// RemplirFenetre
// Colore toute la fen�tre d'une certaine couleur
// Intrant: Rouge: Composante rouge de la couleur (0-255)
//          Vert : Composante verte de la couleur (0-255)
//          Bleu : Composante bleue de la couleur (0-255)
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void RemplirFenetre(int Rouge, int Vert, int Bleu);
///////////////////////////////////////////////////////////////////////////////
// DessinerRectangle
// Permet de dessiner un rectangle d'une certaine couleur dans la fen�tre
// Intrant: PosX: Position horizontale du rectangle.
//          PosY: Position verticale du rectangle.
//          Le point (0,0) est en haut � gauche
//			Largeur: Largeur du rectangle en pixels
//			Hauteur: Hauteur du rectangle en pixels
//          Rouge: Composante rouge de la couleur (0-255)
//          Vert : Composante verte de la couleur (0-255)
//          Bleu : Composante bleue de la couleur (0-255)
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void DessinerRectangle(int PosX, int PosY, int Largeur, int Hauteur, int Rouge, int Vert, int Bleu);
///////////////////////////////////////////////////////////////////////////////
// ChargerImage
// Permet de charger une image du disque dur vers la m�moire
// Le seul type d'image support� est le bitmap (BMP)
// Intrant: NomFichier: Nom du fichier image. Le fichier doit �tre dans le
//                      m�me r�pertoire que le projet
// Extrant: un num�ro identifiant uniquement l'image
///////////////////////////////////////////////////////////////////////////////
ImageId ChargerImage(string NomFichier);
///////////////////////////////////////////////////////////////////////////////
// AfficherImage
// Permet d'afficher une image � un certain endroit dans le fen�tre graphique
// Intrant: Image: Num�ro de l'image
//			PosX: Position horizontale de l'image
//          PosY: Position verticale de l'image
//          Le point (0,0) est en haut � gauche
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void AfficherImage(ImageId Image, int PosX, int PosY);
///////////////////////////////////////////////////////////////////////////////
// RafraichirFenetre
// Mettre � jour la fen�tre d'affichage pour que les derni�res modifications
// soient visibles
// Intrant: Aucun
// Extrant: Aucun
///////////////////////////////////////////////////////////////////////////////
void RafraichirFenetre();
///////////////////////////////////////////////////////////////////////////////
// QuitterAffichage
// Ferme la fen�tre graphique
///////////////////////////////////////////////////////////////////////////////
void QuitterAffichage();
///////////////////////////////////////////////////////////////////////////////
// AttendreEvenement
// Attend que l'usager appuie sur une touche du clavier
// Cette fonction est bloquante!!
// Intrant: Aucun
// Extrant: L'�v�nement correspondant � la touche du clavier:
//   EVHaut: Fl�che vers le haut
//   EVBas:  Fl�che vers le bas
//   EVDroite: Fl�che vers la droite
//   EVGauche: Fl�che vers la gauche
//   EVQuitter: Esc
///////////////////////////////////////////////////////////////////////////////
Evenement AttendreEvenement();
///////////////////////////////////////////////////////////////////////////////
// LireEvenement
// V�rifie si l'usager a appuy� sur une touche du clavier
// Cette fonction n'est pas bloquante!!
// Intrant: Aucun
// Extrant: L'�v�nement correspondant � la touche du clavier:
//   EVHaut: Fl�che vers le haut
//   EVBas:  Fl�che vers le bas
//   EVDroite: Fl�che vers la droite
//   EVGauche: Fl�che vers la gauche
//   EVQuitter: Esc
///////////////////////////////////////////////////////////////////////////////
Evenement LireEvenement(Direction choix);
///////////////////////////////////////////////////////////////////////////////
// VerifierErreur
// Permet d'afficher un message d'erreur
///////////////////////////////////////////////////////////////////////////////
inline void VerifierErreur(bool Test, string Msg);
#endif //_SDLCLG_H
