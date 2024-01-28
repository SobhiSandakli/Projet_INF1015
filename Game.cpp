#include "Game.h"
#include "ObjetUnlock.h"
#include "ObjetEclairant.h"
#include <memory>

Game::Game()
{
	creationGame();
}

Game::~Game()
{
	for (auto& elem : zones_) {
		elem->supprimerLiens();
	}
}

void Game::creationGame()
{
	shared_ptr<Zone> salon = make_shared<Zone>("Salon", "Un salon lumineux", false);
	shared_ptr<Zone> couloir = make_shared<Zone>("Couloir", "Un couloir étroit", true);
	shared_ptr<Zone> petitChambre = make_shared<Zone>("Petite chambre", "Une petite chambre modeste", true);
	shared_ptr<Zone> cuisine = make_shared<Zone>("Cuisine", "Une cuisine spacieuse", true);
	shared_ptr<Zone> salleR = make_shared<Zone>("Salle R", "Juste une Salle R", true);
	shared_ptr<Zone> entree = make_shared<Zone>("Entree", "Une entrée simple", true);

	zones_.push_back(entree);
	zones_.push_back(salon);
	zones_.push_back(couloir);
	zones_.push_back(petitChambre);
	zones_.push_back(cuisine);
	zones_.push_back(salleR);

	Zone::lienEntreZones({ entree, Direction::Est }, { salon, Direction::Ouest });
	Zone::lienEntreZones({ entree, Direction::Nord }, { couloir, Direction::Sud });
	Zone::lienEntreZones({ couloir, Direction::Nord }, { cuisine, Direction::Sud });
	Zone::lienEntreZones({ couloir, Direction::Ouest }, { petitChambre, Direction::Est });

	shared_ptr<Objet> vase = make_shared<Objet>("Un vase", "Un vase cyan", "Vous avez mis des fleurs dans le vase.", "Vous avez pris le vase.");
	vase->ajouterMots({"Vase" , "vase"});

	shared_ptr<Objet> lampe = make_shared<Objet>("Une lampe", "Une lampe jaune", "Vous avez allumé la lampe.", "Vous avez pris la lampe.");
	lampe->ajouterMots({"Lampe" , "lampe"});

	shared_ptr<Objet> clef = make_shared<ObjetUnlock>("Un bouton", "Un bouton gris", "Vous utilsez le bouton gris.", "", pair(couloir, Direction::Est), pair(salleR, Direction::Ouest));
	clef->ajouterMots({ "Clef", "clef"});

	shared_ptr<Objet> interupteur = make_shared<ObjetEclairant>("Un simple interupteur", "Vous regardez attentivement l'interupteur.", "Vous ne pouvez pas prendre l'interupteur, il est encastré dans le mur.", "",  salon);
	interupteur->ajouterMots({ "interupteur", "Interupteur" });

	entree->retournerObjets().push_back(vase);
	petitChambre->retournerObjets().push_back(lampe);
	salon->retournerObjets().push_back(clef);
	entree->retournerObjets().push_back(interupteur);

	zoneActuelle_ = entree;
}

void Game::prendreObjet(shared_ptr<Objet> objet) {
    vector<shared_ptr<Objet>>& objets = getListeObjetZone();

    auto itEnlever = find_if(objets.begin(), objets.end(), 
                             [&objet](const shared_ptr<Objet>& o) { return o->avoirNom() == objet->avoirNom(); });

    if (itEnlever != objets.end()) {
        objets.erase(itEnlever);
    }

    objets_.push_back(objet);
}

void Game::allerDirection(Direction direction)
{
	zoneActuelle_ = zoneActuelle_->retournerZoneDirection(direction);
}

shared_ptr<Zone> Game::getZoneDirection(Direction direction) const
{
	return zoneActuelle_->retournerZoneDirection(direction);
}

shared_ptr<Zone>& Game::getZoneActuelle()
{
	return zoneActuelle_;
}

vector<shared_ptr<Objet>>& Game::getListeObjetZone()
{
	return zoneActuelle_->retournerObjets();
}

vector<shared_ptr<Objet>>& Game::getListeObjetGame()
{
	return objets_;
}


ostream& operator<<(ostream& o, const Game& game)
{
	o << game.zoneActuelle_;

	if (game.objets_.size() != 0) {
		o << "Vous avez: " << endl;

		for (auto objet : game.objets_)
			o << " " << objet;
	}

	o << endl;

	return o;
}