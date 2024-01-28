#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Objet.h"

using namespace std;

enum class Direction
{
	Nord = 'N',
	Est = 'E',
	Sud = 'S',
	Ouest = 'O',
};

class Zone
{
public:
	Zone(string nom, string description, bool estEclaire = true);
	~Zone() = default;

	shared_ptr<Zone> retournerZoneDirection(Direction direction) const;
	vector<shared_ptr<Objet>>& retournerObjets(); 

	void supprimerLiens();

	friend ostream& operator<< (ostream& o, const shared_ptr<Zone>& ptrZone);

	static void lienEntreZones(pair<shared_ptr<Zone>, Direction> zone1, pair<shared_ptr<Zone>, Direction> zone2);
	static map<Direction, string>& retournerDescriptionNom();
	void switchEclairage();
    bool estEclaire() const; 
	string retournerNom() const;

private:
	void fixerZoneAdjacente(Direction direction, const shared_ptr<Zone> zoneAdjacente);
	static map<Direction, string> directionNom_;

    bool estEclaire_ = true;; 
	string nom_;
	string description_;
	map<Direction, shared_ptr<Zone>> zonesConnectes_;
	vector<shared_ptr<Objet>> objets_;
};