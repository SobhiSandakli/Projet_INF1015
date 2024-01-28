
#include "Saisir.h"
#include "Afficher.h"
#include <memory>

void SaisirPrendre::execute(Game& game, vector<string>& saisir)
{
	if (saisir.size()>1){
		vector<shared_ptr<Objet>>& objets = game.getListeObjetZone();
		if (shared_ptr<Objet> objet = Aff_.chercherMots(objets, saisir)) {
			objet->prendre(game);
		}
		else { cout << "Aucun objet nomme comme ca dans la zone! \n" << endl; }
	}
	else { cout << "Vous devez entrer un objet a prendre! \n" << endl; }

}

void SaisirUtiliser::execute(Game& game, vector<string>& saisir)
{
	if (saisir.size() > 1) {
		vector<shared_ptr<Objet>>& objetsGame = game.getListeObjetGame();
		vector<shared_ptr<Objet>>& objetsZone = game.getListeObjetZone();

		if (shared_ptr<Objet> objet = Aff_.chercherMots(objetsZone, saisir)) {
			if (objet->estPrenable()) { cout << "Vous devez avoir l'objet sur vous pour l'utiliser \n" << endl; }
			else
				objet->utiliser(game, game.getZoneActuelle());
		}
		else if (shared_ptr<Objet> objet = Aff_.chercherMots(objetsGame, saisir)) {
			objet->utiliser(game, game.getZoneActuelle());
		}
		else { cout << "Aucun objet nomme comme ca! \n" << endl; }
	}
	else {cout << "Vous devez entrer un objet a utiliser! \n" << endl;}

}

void SaisirRegarder::execute(Game& game, vector<string>& saisir)
{
	vector<shared_ptr<Objet>>& objetsZone = game.getListeObjetZone();
	if (saisir.size()>1){
		if (shared_ptr<Objet> objet = Aff_.chercherMots(objetsZone, saisir)) {
			objet->regarder();
		}
		else { cout << "Aucun objet nomme comme ca! \n" << endl; }
	}
}

void SaisirQuiter::execute(Game& game, vector<string>& saisir)
{
	cout << "Game done " << endl;
	Aff_.quitFunction(true);
}

void SaisirAllerDirection::execute(Game& game, vector<string>& saisir)
{
	Direction direction = static_cast<Direction>(toupper(saisir[0][0]));

	if (game.getZoneDirection(direction) != nullptr) {
		game.allerDirection(direction);
		cout << "Aller " << Zone::retournerDescriptionNom()[direction] << endl;
	}
	else {
		cout << "Vous ne pouvez pas aller la!\n" << endl;
	}
}
