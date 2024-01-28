#pragma once
#include <iostream>
#include <map>
#include "Game.h"

class Afficher;

using namespace std;

class Saisir {
public:
	Saisir(Afficher& Aff) :Aff_(Aff) {};
	virtual void execute(Game& game, vector<string>& saisir) = 0;
	string nameFonction_;

protected:
	Afficher& Aff_;
};

class SaisirPrendre : public Saisir {
public:
	SaisirPrendre(Afficher& Aff) : Saisir(Aff) { nameFonction_ = "Prendre objet"; };
	void execute(Game& game, vector<string>& saisir) override;
};

class SaisirUtiliser : public Saisir {
public:
	SaisirUtiliser(Afficher& Aff) : Saisir(Aff) { nameFonction_ = "Utiliser objet"; };
	void execute(Game& game, vector<string>& saisir) override;
};

class SaisirRegarder : public Saisir {
public:
	SaisirRegarder(Afficher& Aff) : Saisir(Aff) { nameFonction_ = "Regarder objet"; };
	void execute(Game& game, vector<string>& saisir) override;
};

class SaisirQuiter : public Saisir {
public:
	SaisirQuiter(Afficher& Aff) : Saisir(Aff) { nameFonction_ = "Quitter game"; };
	void execute(Game& game, vector<string>& saisir) override;
};

class SaisirAllerDirection : public Saisir {
public:
	SaisirAllerDirection(Afficher& Aff) : Saisir(Aff) { nameFonction_ = "Aller direction"; };
	void execute(Game& game, vector<string>& saisir) override;
};