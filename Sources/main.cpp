//Copyright (C) 2013-2017  Alexandre-Xavier Labonté-Lamoureux
//main.cpp
//Affaires principales du jeu

#include "sdlclg.h"	//Intéressant: habilité de screenshot et message d'erreur
#include "Constantes.h"
#include "Personnage.h"
#include "Pacman.h"
#include "Fantome.h"
#include "ai.h"
#include <ctime>
#include <cstdlib>
#ifdef _WIN32
#include <SDL_mixer.h>
#include <Windows.h>
#else
#include <SDL/SDL_mixer.h>
#endif
#include "ai.h"
#include "Node.h"
#include "Directions.h"
#include "PacNode.h"
#include "EntryNode.h"
using namespace std;

int main(int argc, char *argv[])
{
	//Initialisation du générateur de nombres aléatoires
	srand(static_cast<unsigned int>(time(0)));

	//Créer une fenêtre graphique de la bonne taille
	InitialiserAffichage("PacMan", Largeur*NbPixelsParCase, Hauteur*NbPixelsParCase);

	//Initialiser SDL_mixer
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	//Pour que la musique soit jouée, il faut la loader.
	Mix_Music *musique = Mix_LoadMUS("music/Africa.mid");;

	//Message d'erreur si on la trouve pas
	if(!musique) {
		printf("Mix_LoadMUS(\"level.mid\"): %s\n", Mix_GetError());
	}	//Si la musique joue pas, ben on la joue!
	else if(!Mix_PlayingMusic())
	{
		//Jouer la musque!
		Mix_PlayMusic(musique, -1);
	}

	//Identification des images
	int ImagePac;
	string pacman = "icon32/doge.bmp";
	int ImagePacM;
	string pacmanm = "icon32/doge2.bmp";		//Image miroir de PacMan
	int ImageBash;
	string bashful = "icon32/bashful.bmp";
	int ImagePok;
	string pokey = "icon32/pokey.bmp";
	int ImageShadow;
	string shadow = "icon32/shadow.bmp";
	int ImageSpeedy;
	string speedy = "icon32/speedy.bmp";
	int ImageMur;
	string mur = "icon32/mur.bmp";
	int ImagePoint;
	string point = "icon32/point.bmp";
	int ImagePower;
	string power = "icon32/power.bmp";
	int ImagePeur;
	string peur = "icon32/peur.bmp";
	int ImageGagne;
	string gagne = "icon/gagne.bmp";
	int ImagePerdu;
	string perdu = "icon/perdu.bmp";

	//Charger les images
	ImagePac = ChargerImage(pacman);
	ImagePacM = ChargerImage(pacmanm);
	ImageBash = ChargerImage(bashful);
	ImagePok = ChargerImage(pokey);
	ImageShadow = ChargerImage(shadow);
	ImageSpeedy = ChargerImage(speedy);
	ImageMur = ChargerImage(mur);
	ImagePoint = ChargerImage(point);
	ImagePower = ChargerImage(power);
	ImagePeur = ChargerImage(peur);
	ImageGagne = ChargerImage(gagne);
	ImagePerdu = ChargerImage(perdu);

	//Initialiser Pac-Man et les fantômes
	Pacman PacMan = Pacman(9, 15);
	Fantome Bashful = Fantome(8, 9, &PacMan);
	Fantome Pokey = Fantome(10, 9, &PacMan);
	Fantome Shadow = Fantome(9, 8, &PacMan);
	Fantome Speedy = Fantome (9, 9, &PacMan);

	//Les variables
	bool Bouger = false;
	int CompteurFantome = 0;
	int e = EVAucun;  //Faut l'initialiser à rien
	int Fuite = 0;
	bool Miroir = false;
	bool Mort = false;
	int NbPoints = 1;
	bool Quitter = false;
	int Random;

    // Matrice d'adjacence
    MatriceAdj();

    double victoires = 0;
    double defaites = 0;
    int score = 0;
    int scoreT = 0;
    int nbGames = 0;


	//Boucle principale: jouer tant que l'usager n'a pas demandé de quitter
	while(!Quitter)
	{
        //cout << "Profondeur : " << prof << endl;
        //Boucle secondaire: jouer tant qu'il reste des points et que Pac Man est en vie
        while (NbPoints != 0 && !Mort && !Quitter)
        {
            //Bouger Pac Man selon la touche appuyée
            array<Fantome, 4> ghosts = {Bashful, Pokey, Shadow, Speedy};
            //cout << "1turn" << endl;
            EntryNode choose(ghosts, PacMan, Tableau, 8, true);
            e = LireEvenement(choose.next());

            //cout << "X = " << PacMan.GetX() << "; Y = " << PacMan.GetY() << endl;

            if(e == EVQuitter)
            {
                Quitter = true;
            }
            else if (e == EVHaut || e == EVBas || e == EVGauche || e == EVDroite)
            {
                Miroir = PacMan.Bouger(e, Miroir);
            }
            else
            {
                e = EVAucun;
            }

            //Manger des points si on est dessus
            if (Tableau[PacMan.GetY()][PacMan.GetX()] == P)
            {
                Tableau[PacMan.GetY()][PacMan.GetX()] = V;
                score ++;
            }

            //Mettre les fantomes en mode fuite
            if (Tableau[PacMan.GetY()][PacMan.GetX()] == W)
            {
                Tableau[PacMan.GetY()][PacMan.GetX()] = V;
                Fuite = TEMPS_FUITE;
            }
            //Dure 150 tours de boucle
            if (Fuite > 0)
            {
                Fuite--;
            }

            //Bouger les fantômes un tour sur 10 (à l'aide d'un compteur qui est remis à 0 une fois que les fantômes ont bougé)
            CompteurFantome++;		//Ajuster ce délais augmente la difficulté
            if (CompteurFantome >= VitesseFantome)
            {
                CompteurFantome = 0;
            }

            if (CompteurFantome == 0)
            {
                Bouger = 0;
                while (Bouger == 0)
                {
                    Random = rand() % 4;
                    if (Fuite == 0)
                    {
                        Bouger =  Pokey.BougerRandom(Random);
                    }
                    else
                    {
                        Bouger = Pokey.BougerFuite(Random);
                    }
                }

                Bouger=0;
                while (Bouger == 0)
                {
                    Random = rand() % 4;
                    if (Fuite == 0)
                    {
                        Bouger =  Bashful.BougerRandom(Random);
                    }
                    else
                    {
                        Bouger = Bashful.BougerFuite(Random);
                    }
                }

                Bouger=0;
                while (Bouger == 0)
                {
                    Random = rand() % 4;
                    if (Fuite == 0)
                    {
                        Bouger =  Shadow.BougerRandom(Random);
                    }
                    else
                    {
                        Bouger = Shadow.BougerFuite(Random);
                    }
                }

                Bouger=0;
                while (Bouger == 0)
                {
                    Random = rand() % 4;
                    if (Fuite == 0)
                    {
                        Bouger = Speedy.BougerRandom(Random);
                    }
                    else
                    {
                        Bouger = Speedy.BougerFuite(Random);
                    }
                }
            }

            //Vérifier si Pac Man a été mangé
            if (!Fuite)
            {
                if (PacMan.GetX() == Pokey.GetX() && PacMan.GetY() == Pokey.GetY())
                {
                    Mort = true;
                }
                else if (PacMan.GetX() == Bashful.GetX() && PacMan.GetY() == Bashful.GetY())
                {
                    Mort = true;
                }
                else if (PacMan.GetX() == Shadow.GetX() && PacMan.GetY() == Shadow.GetY())
                {
                    Mort = true;
                }
                else if (PacMan.GetX() == Speedy.GetX() && PacMan.GetY() == Speedy.GetY())
                {
                    Mort = true;
                }
            }
            else
            {
                if (PacMan.GetX() == Pokey.GetX() && PacMan.GetY() == Pokey.GetY())
                {
                    Pokey.SetX(9);
                    Pokey.SetY(9);
                }
                if (PacMan.GetX() == Bashful.GetX() && PacMan.GetY() == Bashful.GetY())
                {
                    Bashful.SetX(9);
                    Bashful.SetY(9);
                }
                if (PacMan.GetX() == Shadow.GetX() && PacMan.GetY() == Shadow.GetY())
                {
                    Shadow.SetX(9);
                    Shadow.SetY(9);
                }
                if (PacMan.GetX() == Speedy.GetX() && PacMan.GetY() == Speedy.GetY())
                {
                    Speedy.SetX(9);
                    Speedy.SetY(9);
                }
            }

            //Remplir la fenêtre de noir
            RemplirFenetre(0, 0, 0);

            //Dessiner les murs blancs (petites barrières ou genre de téléporteur)
            DessinerRectangle(0, NbPixelsParCase*9, MurMince, NbPixelsParCase, 255, 255, 255);
            DessinerRectangle(NbPixelsParCase*Largeur-MurMince, NbPixelsParCase*9, MurMince, NbPixelsParCase, 255, 255, 255);
            DessinerRectangle(NbPixelsParCase*9, NbPixelsParCase*8+MurMince, NbPixelsParCase, MurMince, 255, 255, 255);

            //Afficher le labyrinthe (murs et points)
            NbPoints = 0;
            for (int i = 0; i < Largeur; i++)
            {
                for (int j = 0; j < Hauteur; j++)
                {
                    if (Tableau[j][i] == M)  //Tableau[y][x]
                    {
                        AfficherImage(ImageMur, i*NbPixelsParCase, j*NbPixelsParCase);
                    }
                    else if (Tableau[j][i] == P)
                    {
                        AfficherImage(ImagePoint, i*NbPixelsParCase, j*NbPixelsParCase);
                        NbPoints++;
                    }
                    else if (Tableau[j][i] == W)
                    {
                        AfficherImage(ImagePower, i*NbPixelsParCase, j*NbPixelsParCase);
                    }
                    //Sinon il y a juste rien là et alors on affiche rien
                }
            }

            //Afficher Pac Man. Deux directions seulement, car il a l'oeil est tout le temps en haut.
            if (!Miroir)
            {
                AfficherImage(ImagePac, PacMan.GetX()*NbPixelsParCase, PacMan.GetY()*NbPixelsParCase);
            }
            else
            {
                AfficherImage(ImagePacM, PacMan.GetX()*NbPixelsParCase, PacMan.GetY()*NbPixelsParCase);
            }

            //Afficher les fantômes
            if (Fuite == 0 || Fuite == 4 || Fuite == 5 || Fuite == 8 || Fuite == 9 || Fuite == 12 || Fuite == 13 || Fuite == 16 || Fuite == 17)
            {   //On les fait flacher avant de redevenir normal (pour pas avoir de surprise, c'est chien)
                AfficherImage(ImageBash, Bashful.GetX()*NbPixelsParCase, Bashful.GetY()*NbPixelsParCase);
                AfficherImage(ImagePok, Pokey.GetX()*NbPixelsParCase, Pokey.GetY()*NbPixelsParCase);
                AfficherImage(ImageShadow, Shadow.GetX()*NbPixelsParCase, Shadow.GetY()*NbPixelsParCase);
                AfficherImage(ImageSpeedy, Speedy.GetX()*NbPixelsParCase, Speedy.GetY()*NbPixelsParCase);
            }
            else
            {
                AfficherImage(ImagePeur, Bashful.GetX()*NbPixelsParCase, Bashful.GetY()*NbPixelsParCase);
                AfficherImage(ImagePeur, Pokey.GetX()*NbPixelsParCase, Pokey.GetY()*NbPixelsParCase);
                AfficherImage(ImagePeur, Shadow.GetX()*NbPixelsParCase, Shadow.GetY()*NbPixelsParCase);
                AfficherImage(ImagePeur, Speedy.GetX()*NbPixelsParCase, Speedy.GetY()*NbPixelsParCase);
            }

            //Rafraichir la fenêtre
            RafraichirFenetre();
            //Attendre 30 ms pour ralentir le jeu
            SDL_Delay(20);
        }

        //Afficher le bon message de fin de partie
        if (!Quitter)
        {
            if (NbPoints == 0)
            {
                AfficherImage(ImageGagne, 60, 280);
                victoires++;
            }
            else
            {
                AfficherImage(ImagePerdu, 60, 280);
                defaites++;
            }
            //Attendre un peu
            RafraichirFenetre();
            SDL_Delay(200);

            for (int i = 0; i < Largeur; i++)
            {
                for (int j = 0; j < Hauteur; j++)
                {
                    Tableau[j][i] = TableauCopie[j][i];
                }
            }

            //Réinitialiser Pac-Man et les fantômes
            PacMan.SetX(9);     PacMan.SetY(15);
            Bashful.SetX(8);    Bashful.SetY(9);
            Pokey.SetX(10);     Pokey.SetY(9);
            Shadow.SetX(9);     Shadow.SetY(8);
            Speedy.SetX(9);     Speedy.SetY(9);

            Mort = Miroir = false;
            Fuite = 0;
	    nbGames++;

            // Flusher les événements qui peuvent s'avoir cumulés durant SDL_Delay
            /*for (int i = 0; i < 100; i++)
            {
                e = LireEvenement();
            }*/
            e = EVAucun;
		
	    cout << "===========================" << endl;
	    cout << "Partie #" << nbGames << " ........." << ((NbPoints == 0) ? " VICTOIRE" : " DEFAITE") << endl;
	    cout << "Score: " << score << endl;
            cout << (victoires / nbGames) * 100.0 <<  "% de victoires" << endl;
            scoreT += score;
            cout << "Score moyen : " << scoreT/nbGames << endl;
            score = 0;

	    NbPoints = 1;

        }
	}

	//Fermer la fenêtre
	Mix_FreeMusic(musique);
	QuitterAffichage();
	return 0;
}

