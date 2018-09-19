#include "../include/TaskList.h"

#include <string>
#include <iostream>
#include <limits>

using namespace std;

TaskList::TaskList() {
}

void TaskList::printTasks() {
    cout << "+---------------------------+" << endl;
    cout << "|     Liste des tâches      | " << endl;
    cout << "+---------------------------+" << endl;

    if(list.size() == 0) {
        cout << "votre liste de tâches est vide" << endl;
    } else {
        for(int i = 0; i < list.size(); i++) {
            cout << "[" << i << "] " << list[i]->getTitle();
            if(list[i]->isDone()) cout << " (DONE)";
            cout << endl;
        }
    }
}

int TaskList::getItemIndexFromStdin() {
    int number = -1;
    cout << "Indiquer le numero de la tache: ";

    while(!(cin >> number && number >= 0 && number < list.size())) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Entrée invalide, veuillez réessayer: ";
    }

    return number;
}

void TaskList::addFromStdin() {
    string title;
    string description;

    cout << "Veuillez indiquer le titre de la tâche: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,title);
    cout << endl;

    Task* t = new Task(title);
    list.push_back(t);
}

void TaskList::deleteFromStdin() {
    if(list.size() == 0) return;

    int number = this->getItemIndexFromStdin();
    

    // Set an iterator on the item to delete
    vector<Task*>::iterator it = list.begin();
    for(int i=0; i<number; i++) { it++; }

    // Get a pointer to the item to delete it
    Task* taskToDelete = *it;

    // Remove the item from the list
    list.erase(it);

    // Delete the item from memory
    delete taskToDelete;

}

void TaskList::doneFromStdin() {
    if(list.size() == 0) return;
    
    int number = this->getItemIndexFromStdin();
    list[number]->done();

}