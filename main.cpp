#include <cstdlib>
#include <iostream>

using namespace std;


///////// EXERCICE 1 - types primitifs ////////////////////

/**
 * Affiche sur la sortie standard la taille en mémoire des
 * principaux types primitifs
 */
void printSizeOfTypes() {
    cout << "La taille des types primitifs est: " << endl;
    cout << " - char: " << sizeof(char) << endl;
    cout << " - int: " << sizeof(int) << endl;
    cout << " - long: " << sizeof(long) << endl;
    cout << " - bool: " << sizeof(bool) << endl;
    cout << " - float: " << sizeof(float) << endl;
    cout << " - double: " << sizeof(double) << endl;
}


///////// EXERCICE 2 - nombre premiers ////////////////////

/**
 * Vérifie si un nombre entier est premier ou non 
 * @param nb : le nombre à controler
 * @return True si le paramètre est premier, false sinon
 */
bool isPrime(int nb) {
    for(int i = 2; i < nb; i++) {
        if(nb % i == 0) return false;
    }
    return true;
}

void printPrimeNumbers(int max) {
    cout << "Les nombres premiers inférieurs ou égals à " << max << "sont :" << endl;
    for(int i=0; i<=max; i++) {
        if(isPrime(i)) cout << i << " ";
    }
    cout << endl;
}

///////// EXERCICE 2 - factorielles ////////////////////

/**
 * Calcule la factorielle d'un entier donnée. La factorielle de n est : n*(n-1)*(n-2)*...*3*2*1.
 * @param n L'entier dont on veut calculer la factorielle
 * @return La factorielle de n
 * */
long factorial(int n) {
    long r = 1;
    for(int i=2; i<=n; i++) {
        r *= i;
    }
    return r;
}

///////// EXERCICE 3 - Algorithmie et boucles imbriquées ////////////////////


void printTriangle(int size) {
    // Chaque ligne du triangle possède à gauche et à droite un caractère de moins que la ligne précédente
    // Si le triange à 'size' lignes, alors le nombre de blanc à la première ligne en haut est donc de 'size -1'
    // Partant de ce constat, on affiche le triangle en diminuant à chaque ligne le nombre d'espace et en ajoutant
    // deux caractères supplémentaires (un à gauche et un à droite) sur chaque nouvelle ligne.
    for(int i=0; i<size; i++) {
        // Affichage du nombre d'espace nécessaires
        for(int j=0; j<size-i-1; j++) {
            cout << " ";
        }
        // Affichage du nombre de caractères
        for(int j=0; j<i*2+1; j++) {
            cout << "#";
        }
        cout << endl;
    }
}

///////// EXERCICE 4 - Pointeurs de base ////////////////////

/**
 * Echange le contenu de deux variables, en utilisant des pointeurs
 */
void swapVariables(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Echange le contenu de deux variables, en utilisant des passage par référence
 */
void swapVariablesByRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

///////// EXERCICE 5 - Pointeurs et tableaux ////////////////////


/**
 * Crée un tableau de tous les nombres pairs compris entre deux bornes (comprises).
 * @param min La borne inférieure
 * @param max La borne superieure
 * @param size La taille du tableau renvoyé, **passé par référence**
 * @return un tableau d'entiers
 */
int* arrayOfEvenNumbers(int min, int max, int& size) {
    // On s'assure d'abord de prendre les bornes incluses dans le tableau. Si min ou max
    // sont impair, on les modifie (pas d'effet de bord puisque passage par valeur)
    if(min % 2 > 0) min++;
    if(max % 2 > 0) max--;
    // Puis on vérifie que l'on aura bien au moins un élément dans le tableau
    if(max < min) {
        size = 0;
        return NULL;
    }
    // Calcul de la taille du tableau
    size = (max-min)/2+1;
    // Allocation du tableau
    int* tab = new int[size];
    // Remplissage du tableau
    for(int i=0; i<size; i++) {
        tab[i]=min+i*2;
    }
    return tab;
}

int main(int argc, char** argv) {

    cout << endl << "----- EXERCICE 1 ----- " << endl << endl;

    printSizeOfTypes();

    cout << endl << "----- EXERCICE 2 ----- " << endl << endl;

    printPrimeNumbers(20);

    cout << "Factorielle de 5: " << factorial(5) << endl;

    cout << endl << "----- EXERCICE 3 ----- " << endl << endl;

    printTriangle(5);

    cout << endl << "----- EXERCICE 4 ----- " << endl << endl;
    
    int a(3), b(5);
    cout << "Au début : a = " << a << ", b = " << b << endl;
    swapVariables(&a, &b);
    cout << "Après swapVariables: a = " << a << ", b = " << b << endl;
    swapVariablesByRef(a, b);
    cout << "Après swapVariablesByRef: a = " << a << ", b = " << b << endl;
    

    cout << endl << "----- EXERCICE 5 ----- " << endl << endl;

    int size;
    int* tab = arrayOfEvenNumbers(4,12,size); // Attention au passage par référence, size va être modifié
    for(int i=0; i<size; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}
