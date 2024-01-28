#pragma once
#include <iostream>
#include "Objet.h"
#include "zone.h"

using namespace std;
using typeZoneDir = pair<shared_ptr<Zone>, Direction>;

class ObjetUnlock :public Objet
{
public:
	ObjetUnlock(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, typeZoneDir zoneUtiliser, typeZoneDir zoneOuvrir);

	void prendre(Game& game) const override;
	void utiliser(Game& game,shared_ptr<Zone> zoneActuelle) override;

private:
	typeZoneDir zoneUtiliser_, zoneOuvrir_;
};