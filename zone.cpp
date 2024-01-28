#include "zone.h"
#include <memory>

map<Direction, string> Zone::directionNom_ = { { Direction::Nord, "au nord (N)" },
											   { Direction::Est, "a l'est (E)" },
											   { Direction::Sud, "au sud (S)" },
											   { Direction::Ouest, "a l'ouest (O)" } };


Zone::Zone(string nom, string description, bool estEclaire) : nom_(nom), description_(description), estEclaire_(estEclaire)
{
	zonesConnectes_.insert({ Direction::Nord, nullptr });
	zonesConnectes_.insert({ Direction::Est, nullptr });
	zonesConnectes_.insert({ Direction::Sud, nullptr });
	zonesConnectes_.insert({ Direction::Ouest, nullptr });
}


void Zone::fixerZoneAdjacente(Direction direction, const shared_ptr<Zone> zoneAdjacente)
{
	zonesConnectes_[direction] = zoneAdjacente;
}


shared_ptr<Zone> Zone::retournerZoneDirection(Direction direction) const
{
	return zonesConnectes_.find(direction)->second;
}

vector<shared_ptr<Objet>>& Zone::retournerObjets()
{
	return objets_;
}

map<Direction, string>& Zone::retournerDescriptionNom()
{
	return directionNom_;
}

string Zone::retournerNom() const
{
	return nom_;
}

void Zone::supprimerLiens()
{
	for (auto& elem : zonesConnectes_) {
		elem.second = nullptr;
	}
}


void Zone::lienEntreZones(pair<shared_ptr<Zone>, Direction> zone1, pair<shared_ptr<Zone>, Direction> zone2)
{
	zone1.first->fixerZoneAdjacente(zone1.second, zone2.first);
	zone2.first->fixerZoneAdjacente(zone2.second, zone1.first);
}

void Zone::switchEclairage() {
    estEclaire_ = !estEclaire_; 
}

bool Zone::estEclaire() const {
    return estEclaire_;
}

ostream& operator<<(ostream& o, const shared_ptr<Zone>& ptrZone)
{
	o << endl;
	o << "--" << ptrZone->nom_ << "--" << endl << endl;

	!ptrZone->estEclaire() ?  o << "La zone est sombre." << endl << endl : o << ptrZone->description_ << endl << endl;
	
	if (ptrZone->objets_.size() != 0 && ptrZone->estEclaire()) {
		o << "Vous pouvez voir: " << endl;

		for (auto objet : ptrZone->objets_)
			o <<"  " << objet;
			
		o << endl;
	}

	o << "Les zones connectées: " << endl;
	for (auto& zoneAdjacente : ptrZone->zonesConnectes_)
	{
		if (zoneAdjacente.second != nullptr)
			o << "  " << zoneAdjacente.second->nom_ << " est "
			<< Zone::directionNom_[zoneAdjacente.first] << endl;
	}
	return o;
}