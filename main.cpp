#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Carte{
public:
        //Carte();
        Carte(string couleur, string rang) : couleur(std::move(couleur)), rang(std::move(rang)) {}

        string getRang() const{
            return this->rang;
        }
        string getCouleur() const{
            return this->couleur;
        }
        void afficher() const{
                cout << "La carte est de couleur " << getCouleur() << " et de rang " << getRang() << endl;
        }
    private:
        string rang;
        string couleur;
};

class Paquet{
public:
    vector<Carte> cartes;
    //std::vector<Paquet> deck;
    Paquet() {

        vector<std::string> couleurs = {"coeur", "carreau", "pique", "trefle"};
        vector<std::string> rangs = {"as", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};

        for (auto couleur:couleurs) {
            for (auto rang : rangs) {
                cartes.push_back(Carte(couleur, rang));
            }
        }
    }
    void melanger(){
        auto rng = default_random_engine {};
        shuffle(cartes.begin(), cartes.end(), rng);
    }

    void piocher(std::vector<Carte> &Paquet){
        if (!Paquet.empty()) {
            Carte piocher = Paquet.back();
            cartes.push_back(piocher);
            Paquet.pop_back();
        } else {
            cout << "Le paquet est vide !" << endl;
        }
    }

    void PiocherNCartes(vector<Carte> &Paquet, int n) {
        for (int i = 0; i < n; ++i) {
            piocher(Paquet);
        }
    }

    void afficher() const{
        for (auto carte:cartes) {
            carte.afficher();
        }
    }

    vector<string>::size_type cartesrestantes() const{
        return cartes.size();
    }

};


int main() {
    int n;
    Paquet p;
    Paquet deck;
    p.melanger();
    cout<< "Combien de cartes souhaitez-vous piocher ?" << endl; cin >> n;

    deck.PiocherNCartes(p.cartes, 5);
    cout << "Il reste " << p.cartesrestantes() << " cartes dans le paquet" << endl;
    return 0;
}