# Pacman
Projet de fin de session à ma première session de CEGEP. Un simple Pacman en C++. 

Je l'ai codé en décembre 2013 comme projet de fin de session. Onze mois après, en 2014, je l'ai porté vers Linux. Quelques années plus tard, en 2017, j'ai réécrit le code en C++ orienté objet. 

Vous pouvez utiliser Visual Studio 2012 pour compiler ce projet. Si vous utilisez Linux, vous pouvez le compiler à partir du terminal avec les commandes suivantes: 
`g++ -o Pacman main.cpp Fantome.cpp Pacman.cpp Personnage.cpp sdlclg.cpp -lSDL -lSDL_mixer`

Note: Vous devez vous assurer que les paquets suivants sont installés: `g++ libsdl1.2-dev libsdl-mixer1.2-dev` et aussi les paquets correspondants pour l'exécution du programme. 

![screenshot at 2016-09-23 11_04_50](https://cloud.githubusercontent.com/assets/6194072/18793261/e78e80c2-8187-11e6-8595-bf63733eac18.png)


# Projet IA
Projet du module IA à l'INSA de Rennes par Daniel Haus et Etienne Rebout. Le projet a été fait à partir du code développé par cet étudiant à la CEGEP (cf paragraphes ci-dessus).

Le moteur de l'IA utilise un algorithme Expectimax, semblable à l'algorithme A*. Pour le lancer depuis Linux, il faut se placer sur le répertoire du projet (ghostbuster) et lancer la commande dans commandline.txt.

Pour changer la musique, il faut simplesment changer le path dans Sources/main.cpp. Pareil pour les icônes.
