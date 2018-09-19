#include <iostream>
#include <vector>

#include "../include/Task.h"
#include "../include/TaskList.h"

using namespace std;

/**
 * Affiche sur la sortie standard la liste des commandes disponibles.
 */
void printCommands() {
    cout << "Entrez la commande souhaitée:" << endl;
    cout << "  - add: ajoute une nouvelle tâche à la liste" << endl;
    cout << "  - delete: supprime une tâche de la liste" << endl;
    cout << "  - done: marque une tâche comme réalisée" << endl;
    cout << "  - quit: sortir du programme" << endl;
}

int main(int argc, char** argv) {

    string input; // Contient la saisie utilisateur

    TaskList taskList; // La liste de tâche

    do {
        taskList.printTasks();
        cout << endl;
        printCommands();
        cout << ">";
        cin >> input;
        if(input == "add") taskList.addFromStdin();
        else if(input == "delete") taskList.deleteFromStdin();
        else if(input == "done") taskList.doneFromStdin();
        else if(input != "quit") cout << "Je ne comprend pas votre commande, veuillez réessayer" << endl;

    } while(input != "quit");
}