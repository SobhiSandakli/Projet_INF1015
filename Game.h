#pragma once
#include <iostream>
#include <vector>
#include "zone.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void allerDirection(Direction direction);
	void prendreObjet(shared_ptr<Objet> objet);
	shared_ptr<Zone>& getZoneActuelle();

	shared_ptr<Zone> getZoneDirection(Direction direction) const;
	vector<shared_ptr<Objet>>& getListeObjetGame();
	vector<shared_ptr<Objet>>& getListeObjetZone();

	friend ostream& operator<< (ostream& o, const Game& ptrGame);

private:
	void creationGame();

	shared_ptr<Zone> zoneActuelle_;
	vector<shared_ptr<Zone>> zones_;
	vector<shared_ptr<Objet>> objets_;
};