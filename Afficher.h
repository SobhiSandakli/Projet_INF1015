#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include "Game.h"
#include "Saisir.h"

enum Couleur {
	ROUGE,
	BLEU,
	VERT,
	DEFAUT
};

class Afficher
{
public:
	Afficher(Game& game);

	void afficherStep();
	void afficherSaisir();
	void gestionEntree();
	
	shared_ptr<Objet> chercherMots(vector<shared_ptr<Objet>>& objets, vector<string>& objetSaisir);
	
	void quitFunction(bool quit) { quit_ = quit; };
	bool quit() { return quit_; };

private:
	vector<string> diviserParMots(string objetSaisir);
	void changerCouleur(Couleur couleur);
	void initialiserMapSaisir();

	Game& game_;
	bool quit_;
	map<string, shared_ptr<Saisir>> mapSaisirs_;
};
