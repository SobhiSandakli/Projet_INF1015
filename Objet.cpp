#include "Game.h"
#include "Objet.h"

Objet::Objet(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre) :
	nom_(nom), descriptionRegarder_(descriptionRegarder), descriptionUtiliser_(descriptionUtiliser), descriptionPrendre_(descriptionPrendre)
{
	setEstPrenable(false);
}

void Objet::ajouterMots(vector<string> mots)
{
	motsImportants_.insert(motsImportants_.end(), mots.begin(), mots.end());
}

vector<string>& Objet::avoirMotsImportant()
{
	return motsImportants_;
}

string Objet::avoirNom() const
{
	return nom_;
}

void Objet::prendre(Game& game) const
{
	game.prendreObjet(make_shared<Objet>(*this));
	cout << descriptionPrendre_ << "\n" << endl;
}

void Objet::regarder() const
{
	cout << descriptionRegarder_ << "\n" << endl;
}

void Objet::utiliser(Game& game, shared_ptr<Zone> zoneActuelle)
{
	cout << descriptionUtiliser_ << "\n" << endl;
}

ostream& operator<<(ostream& o, const shared_ptr<Objet> ptrObjet)
{
	o << ptrObjet->nom_ << endl;
	return o;
}