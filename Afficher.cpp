#include "Afficher.h"
#include <sstream>
#include <memory>

using namespace std;

Afficher::Afficher(Game& game) : game_(game)
{
	quitFunction(false);
	initialiserMapSaisir();
}

void Afficher::afficherStep()
{
	cout << game_;
	gestionEntree();

}

void Afficher::afficherSaisir()
{
	changerCouleur(Couleur::BLEU);

	cout << "Comment jouer:" << endl;
	cout << "- \"N/n\" pour " << mapSaisirs_["n"]->nameFonction_ << " nord" << endl;
	cout << "- \"E/e\" pour " << mapSaisirs_["e"]->nameFonction_ << " est" << endl;
	cout << "- \"S/s\" pour "<< mapSaisirs_["s"]->nameFonction_ << " sud" << endl;
	cout << "- \"O/o\" pour " << mapSaisirs_["o"]->nameFonction_ << " ouest" << endl;
	cout << "- \"prendre\" pour "  << mapSaisirs_["prendre"]->nameFonction_ << endl;
	cout << "- \"utiliser\" pour " << mapSaisirs_["utiliser"]->nameFonction_ << endl;
	cout << "- \"regarder\" pour " << mapSaisirs_["regarder"]->nameFonction_ << endl;
	cout << "- \"Q/q\" pour "<< mapSaisirs_["q"]->nameFonction_  << endl;

	changerCouleur(Couleur::DEFAUT);
}

void Afficher::gestionEntree()
{
	string saisirEntree;
	vector<string> vectorSaisirEntree;

	cout << "~";
	getline(cin, saisirEntree);
	vectorSaisirEntree = diviserParMots(saisirEntree);


	if (shared_ptr<Saisir> saisir = mapSaisirs_[vectorSaisirEntree[0]]) {
    changerCouleur(Couleur::VERT);
    saisir->execute(game_, vectorSaisirEntree);
    changerCouleur(Couleur::DEFAUT);
	} else {
	changerCouleur(Couleur::ROUGE);
    cout << "Saisir inconnue\n" << endl;
    gestionEntree();
    changerCouleur(Couleur::DEFAUT);
	}
}

bool estSubstring(const std::string& str1, const std::string& str2) {
    return str2.find(str1) != std::string::npos;
}

shared_ptr<Objet> Afficher::chercherMots(vector<shared_ptr<Objet>>& objets, vector<string>& objetSaisir)
{
    for (const auto& objet : objets) {
        const auto& motsImportants = objet->avoirMotsImportant();
        bool matchFound = any_of(motsImportants.begin(), motsImportants.end(), 
            [&](const string& motImportant) {
                return any_of(objetSaisir.begin(), objetSaisir.end(), 
                    [&](const string& motSaisir) {
                        return estSubstring(motImportant, motSaisir);
                    });
            });

        if (matchFound) {
            return objet;
        }
    }
    return nullptr;
}

vector<string> Afficher::diviserParMots(string saisir) {
    vector<string> mots;
    stringstream ss(saisir);
    string mot;

    while (ss >> mot) {
        mots.push_back(mot);
    }

    if (mots.empty()) {
        mots.push_back(" ");
    }

    return mots;
}

void Afficher::changerCouleur(Couleur couleur)
{
	switch (couleur) {
    case Couleur::ROUGE:
        cout << "\033[91m";
        break;
    case Couleur::BLEU:
        cout << "\033[94m";
        break;
    case Couleur::VERT:
        cout << "\033[92m";
        break;
    case Couleur::DEFAUT:
        cout << "\033[0m";
        break;
}

}

void Afficher::initialiserMapSaisir()
{
	shared_ptr<Afficher> Aff = make_shared<Afficher>(*this);
	shared_ptr<SaisirUtiliser> saisirUtiliser = make_shared<SaisirUtiliser>(*this);
	shared_ptr<SaisirPrendre> saisirPrendre = make_shared<SaisirPrendre>(*this);
	shared_ptr<SaisirRegarder> saisirRegarder = make_shared<SaisirRegarder>(*this);
	shared_ptr<SaisirAllerDirection> saisirDirection = make_shared<SaisirAllerDirection>(*this);
	shared_ptr<SaisirQuiter> saisirQuiter = make_shared<SaisirQuiter>(*this);

	mapSaisirs_["utiliser"] = saisirUtiliser;

	mapSaisirs_["prendre"] = saisirPrendre;

	mapSaisirs_["regarder"] = saisirRegarder;

	mapSaisirs_["N"] = saisirDirection;
	mapSaisirs_["n"] = saisirDirection;

	mapSaisirs_["E"] = saisirDirection;
	mapSaisirs_["e"] = saisirDirection;

	mapSaisirs_["S"] = saisirDirection;
	mapSaisirs_["s"] = saisirDirection;

	mapSaisirs_["O"] = saisirDirection;
	mapSaisirs_["o"] = saisirDirection;

	mapSaisirs_["Q"] = saisirQuiter;
	mapSaisirs_["q"] = saisirQuiter;
}

