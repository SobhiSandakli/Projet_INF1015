#pragma once
#include <iostream>
#include <vector>

class Game;
class Zone; 

using namespace std;

class Objet
{
public:
	Objet(string nom, string descriptionRegarder, string descriptionUtiliser, string descriptionPrendre);
	virtual ~Objet() = default;
	

	void ajouterMots(vector<string> mots);
	
	vector<string>& avoirMotsImportant();
	string avoirNom() const;

	virtual void prendre(Game& game) const;
	virtual void regarder() const;
	virtual void utiliser(Game& game, shared_ptr<Zone> zoneActuelle);
	void setEstPrenable(bool estPrenable) { estPrenable_ = estPrenable; }
	bool estPrenable() const{ return estPrenable_; } 
	friend ostream& operator<< (ostream& o, const shared_ptr<Objet> ptrObjet);
private:

	string nom_;
	string descriptionRegarder_;
	string descriptionUtiliser_;
	string descriptionPrendre_;
	vector<string> motsImportants_;
	bool estPrenable_;
};