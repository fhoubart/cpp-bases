#include <iostream>
#include <math.h>

using namespace std;

#define TAILLE 10
#define MAX 100

class Joueur {
    public:

    int* grille;
    int score;

    // Initialisation
    Joueur() {
        this->grille = new int[TAILLE];
        for(int i = 0; i < TAILLE; i++) {
            this->grille[i] = rand() % MAX + 1;
        }
        this->score = 0;
    }

    // Cocher un jeton
    void cocher(int jeton) {
        for(int i = 0; i < TAILLE; i++) {
            if(this->grille[i] == jeton) {
                this->score += jeton;
            }
        }
    }

    // Donner son score
    int getScore() {
        return this->score;
    }
};

class TireurJeton {
    public:
    int tirer() {
        return rand()%MAX + 1;
    }
};

int main(int argc, char** argv) {
    int nombreJoueurs = 0;
    cout << "Combien de joueurs ?" << endl;
    cin >> nombreJoueurs;

    Joueur *joueurs = new Joueur[nombreJoueurs];
    

    TireurJeton tireur;

    for(int i = 0; i < 20; i++) {
        int jeton = tireur.tirer();
        for(int j = 0; j < nombreJoueurs; j++) {
            joueurs[j].cocher(jeton);
        }
    }

    for(int j = 0; j < nombreJoueurs; j++) {
        cout << "Score du joueur " << (j+1) << ": " << joueurs[j].getScore() << endl;
    }
}