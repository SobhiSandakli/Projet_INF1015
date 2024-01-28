#pragma once
#include "Objet.h"
#include "zone.h"
#include <memory>

class ObjetEclairant : public Objet {
public:
    ObjetEclairant(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre, shared_ptr<Zone> zoneCible);

    void regarder() const override;
    void prendre(Game& game) const override;
    void utiliser(Game& game, shared_ptr<Zone> zoneActuelle) override;

private:
    shared_ptr<Zone> zoneCible_; 
};
