#include"Game.h"
#include "ObjetUnlock.h"
#include <memory>

ObjetUnlock::ObjetUnlock(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, typeZoneDir zoneUtiliser, typeZoneDir zoneOuvrir) :
	Objet(nom, descriptionRegarder, descriptionUtiliser, descriptionPrendre),
	zoneOuvrir_(zoneOuvrir), zoneUtiliser_(zoneUtiliser) 
{
	setEstPrenable(true);
}

void ObjetUnlock::prendre(Game& game) const
{ cout << "Vous avez pris " << endl; 
 	Objet::prendre(game);
}

void ObjetUnlock::utiliser(Game& game, shared_ptr<Zone> zoneActuelle) 
{
		Zone::lienEntreZones(zoneUtiliser_, zoneOuvrir_);
		Objet::utiliser(game, zoneActuelle);
}

