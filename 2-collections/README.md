# Exercice sur les collections C++

## Rappel sur les types de collections

- Vector : liste dynamique, ne permet d'ajouter des éléments qu'en fin de tableau
- Deque : *Double Ended Queue*, comme un Vector mais permet également d'ajouter des éléments au début
- Stack : une pile, *Last In, First Out*
- Queue : une file, *First In, First Out*

### Utilisation d'un vector

Les fonctions principales sur un Vector de type `T` (déclaré comme ` std::vector<T>`) sont :

- `operator[x]` : accès à l'élément en position x (comme dans un tableau)
- `void push_back(const T& elt)` : ajout de *elt* à la fin du tableau
- `void pop_back()` : suppression de l’élément de fin
- `T front()` : renvoie le premier élément
- `T back()` : renvoie le dernier élément
- `size_t size() const` : nombre d’éléments dans le tableau

Exemple :

```c++
#include <vector>

std::vector<int> v;
v.push_back(1); // v = [ 1 ]
v.push_back(2); // v = [ 1, 2 ]
v.push_back(3); // v = [ 1, 2, 3 ]
int i = v[0]; // i = 1
int j = v[1]; // j = 2
i = v.front(); // i = 1
j = v.back(); // j = 3
int i = v.size(); // n = 3
v.pop_back(); // v = [ 1, 2 ]
```

### Utilisation d'un deque

Les fonctions disponibles sur les `Deque` sont les mêmes que pour les `Vector` avec en plus les méthodes d'accès en tête du tableau :

- `void push_front(const T& elt)` : ajout de *elt* au début
- `void pop_front()` : suppression de l’élément de début

Exemple :

```c++
#include <deque>

std::deque<int> d;
d.push_back(1); // d = [ 1 ]
d.push_back(2); // d = [ 1, 2 ]
d.push_front(3); // d = [ 3, 1, 2 ]
int i = d[0]; // i = 3
int j = d[1]; // j = 2
i = d.front(); // i = 3
j = d.back(); // j = 2
int i = d.size(); // n = 3
d.pop_back(); // d = [ 3, 1 ]
d.pop_front(); // d = [ 1 ]
```

### Utilisation d'une stack

Les méthodes disponibles sur une `stack` ne permettent que d'accéder à la tête de la pile :

- `void push(const T& elt)` : ajout de *elt* en haut de la pile
- `void pop()` : supprime l’élément en haut de la pile
- `T top()` : renvoie l’élément en haut de la pile
- `size_t size() const` : nombre d’éléments dans la pile
- `bool empty() const` : vérifie si la pile est vide

Exemple :

```c++
#include <stack>

std::stack<int> s;
s.push(1); // d = haut->[ 1 ]
s.push(2); // d = haut->[ 2, 1 ]
s.push(3); // d = haut->[ 3, 2, 1 ]
int i = d.top(); // i = 3
int j = d.top(); // j = 3
s.pop(); // d = haut->[ 2, 1 ]
j = s.top(); // j = 2
int n = s.size(); // n = 2
```

### Utilisation d'une queue

Les méthodes disponibles sur une `queue` permettent d'ajouter à la fin de la queue et de sortir par le début :

- `void push(const T& elt)` : ajout de *elt* en haut de la pile
- `void pop()` : supprime l’élément à la tête de la file
- `T front()` : renvoie l’élément à la tête de la file (le prochain à sortir)
- `T back()` : renvoie l’élément à la queue de la file (le dernier ajouté)
- `size_t size() const` : nombre d’éléments dans la pile
- `bool empty() const` : vérifie si la pile est vide

Exemple :

```c++
#include <queue>

std::queue<int> q;
q.push(1); // d = <-[ 1 ]<-
q.push(2); // d = <-[ 1, 2 ]<-
q.push(3); // d = <-[ 1, 2, 3 ]<-
int i = q.front(); // i = 1
int j = q.back(); // j = 3
q.pop(); // d = <-[ 2, 1 ]<-
j = q.front(); // j = 2
int n = q.size(); // n = 2
```

## Exercice : construction d'une TODO List

Le but de l'exercice est de contruire une gestion de TODO List, via l'invite de commandes. Une Tâche est définie par un titre, et peut être terminée ou non. L'utilisateur pourra, via la ligne de commande, ajouter des tâches, les marquer comme terminées, et éventuellement les supprimer.

Voici un exemple de déroulement du programme :

```
+---------------------------+
|     Liste des tâches      | 
+---------------------------+
votre liste de tâches est vide

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>add
Veuillez indiquer le titre de la tâche: Faire les courses

+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>add
Veuillez indiquer le titre de la tâche: Passer le balai

+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses
[1] Passer le balai

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>add
Veuillez indiquer le titre de la tâche: Faire son TP de C++

+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses
[1] Passer le balai
[2] Faire son TP de C++

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>add                   
Veuillez indiquer le titre de la tâche: Révision les collections

+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses
[1] Passer le balai
[2] Faire son TP de C++
[3] Révision les collections

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>done
Indiquer le numero de la tache: 2
+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses
[1] Passer le balai
[2] Faire son TP de C++ (DONE)
[3] Révision les collections

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>done
Indiquer le numero de la tache: 0
+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses (DONE)
[1] Passer le balai
[2] Faire son TP de C++ (DONE)
[3] Révision les collections

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>delete
Indiquer le numero de la tache: 1
+---------------------------+
|     Liste des tâches      | 
+---------------------------+
[0] Faire les courses (DONE)
[1] Faire son TP de C++ (DONE)
[2] Révision les collections

Entrez la commande souhaitée:
  - add: ajoute une nouvelle tâche à la liste
  - delete: supprime une tâche de la liste
  - done: marque une tâche comme réalisée
  - quit: sortir du programme
>quit
```


1/ Ecrire une classe `Task` qui aura la définition suivante :

```c++
class Task {

    public:
        /**
         * Create a new Task
         */
        Task(string title);

        /**
         * Get the title of the Task
         */
        string getTitle();


        /**
         * Check if the Task is done or not.
         **/
        bool isDone();

        /**
         * Mark this task as done.
         */
        void done();

    private:
        string _title;
        bool _done;
};
```

2/ Une TODO List est une liste de tâche, que l'on encapsulera dans un `vector`. La classe `TaskList` fournira également les méthodes utilitaire pour gérer l'ajout, la suppression et le marquage comme terminé des tâches de la list. Implémenter la classe `TaskList` qui aura la définition suivante :

```c++
class TaskList {

    private:
        vector<Task*> list;
        int getItemIndexFromStdin();

    public:
        /**
         * Constructor, create an empty TaskList
         */
        TaskList();

        /**
         * Print to stdout the list of all tasks
         */
        void printTasks();

        /**
         * Ask the user to provide a title from stdin, create a Task and add it to the list
         */
        void addFromStdin();

        /**
         * Ask the user to provide the index of the task from stdin in the list and delete it.
         */
        void deleteFromStdin();

        /**
         * Ask the user to provide the index of the task from stdin and mark it as done.
         */
        void doneFromStdin();

};
```

3 / Ecrire une fonction main qui va demander à l'utilisateur ce qu'il veut faire (ajouter, supprimer, marquer comme terminé, ou quitter) et en fonction de son entrée va exécuter les méthodes correspondantes sur la classe `TaskList`.
