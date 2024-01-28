#include <iostream>
#include "Afficher.h"
#include "Game.h"

int main()
{
	Game game;
	Afficher Affichage(game);

	Affichage.afficherSaisir();

	while (true) {
		if (Affichage.quit())
			break;
		Affichage.afficherStep();
	}
}
