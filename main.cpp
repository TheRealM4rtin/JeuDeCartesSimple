#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

class Carte{
public:
        //Carte();
        Carte(std::string couleur, std::string rang) : couleur(couleur), rang(rang) {}

        std::string getRang() const{
            return this->rang;
        }
        std::string getCouleur() const{
            return this->couleur;
        }
        void afficher() const{
                std::cout << "La carte est de couleur " << getCouleur() << " et de rang " << getRang() << std::endl;
        }
    private:
        std::string rang;
        std::string couleur;
};

class Paquet{
public:
    std::vector<Carte> cartes;
    //std::vector<Paquet> deck;
    Paquet() {

        std::vector<std::string> couleurs = {"coeur", "carreau", "pique", "trefle"};
        std::vector<std::string> rangs = {"as", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};

        for (auto couleur:couleurs) {
            for (auto rang : rangs) {
                cartes.push_back(Carte(couleur, rang));
            }
        }
    }
    void melanger(){
        auto rng = std::default_random_engine {};
        std::shuffle(cartes.begin(), cartes.end(), rng);
    }

    void piocher(std::vector<Carte> &Paquet){
        if (!Paquet.empty()) {
            Carte piocher = Paquet.back();
            cartes.push_back(piocher);
            Paquet.pop_back();
        } else {
            std::cout << "Le paquet est vide !" << std::endl;
        }
    }

    void PiocherNCartes(std::vector<Carte> &Paquet, int n){
        for (int i = 0; i < n; ++i) {
            piocher(Paquet);
        }
    }

    void afficher(){
        for (auto carte:cartes) {
            carte.afficher();
        }
    }

    std::vector<std::string>::size_type cartesrestantes(){
        return cartes.size();
    }

};


int main() {
    int n;
    Paquet p;
    Paquet deck;
    p.melanger();
    std::cout<< "Combien de cartes souhaitez-vous piocher ?" << std::endl; std::cin >> n;

    deck.PiocherNCartes(p.cartes, 5);
    std::cout << "Il reste " << p.cartesrestantes() << " cartes dans le paquet" << std::endl;

    return 0;
}