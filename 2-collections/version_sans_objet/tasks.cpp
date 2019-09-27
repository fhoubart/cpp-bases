#include <vector>
#include <iostream>

using namespace std;

void ajouterTache(string tache) {
    cout << "Ajout de la tache " << tache << endl;
    cout << "NOT YET IMPLEMENTED" << endl;
}

void supprimerTache(int n) {
    cout << "Suppression de la tache " << n << endl;
    cout << "NOT YET IMPLEMENTED" << endl;
}

void afficherTaches() {
    cout << "Voici la liste des taches:" << endl;
    cout << "NOT YET IMPLEMENTED" << endl;
}

int main(int argc, char** argv) {
    string input, input2;

    do {
        afficherTaches();
        cout << "[ADD|DONE|EXIT] > ";
        cin >> input;
        if(input == "ADD") {
            cout << "Entrer la description de la tache :" << endl;
            cin >> input2;
            ajouterTache(input2);
        }
        if(input == "DONE") {
            cout << "Entrer le numero de la tache effectuee : ";
            int n;
            cin >> n;
            supprimerTache(n); 
        }
    } while(input != "EXIT");

    return 0;
}