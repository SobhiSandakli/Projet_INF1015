#include "ObjetEclairant.h"
#include "Game.h"

ObjetEclairant::ObjetEclairant(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, shared_ptr<Zone> zoneCible) :
    Objet(nom, descriptionRegarder, descriptionUtiliser, descriptionPrendre), 
    zoneCible_(zoneCible) 
{
    setEstPrenable(false);
}


void ObjetEclairant::prendre(Game& game) const {
    Objet::prendre(game);
}

void ObjetEclairant::regarder() const {
    Objet::regarder();
}

void ObjetEclairant::utiliser(Game& game, shared_ptr<Zone> zoneActuelle) {
    zoneCible_->switchEclairage();
    cout << endl;
    cout << "Vous utilisez " << avoirNom() << ". " << endl;

    cout << "La zone " << zoneCible_->retournerNom() << (zoneCible_->estEclaire() ? " est maintenant éclairée." : " est maintenant sombre.") << endl;
}
