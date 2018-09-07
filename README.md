# Exercices de remise en forme C++

Ce sujet contient une liste de petits exercices visant à se (re)familiariser avec les bases du langage C++.

On veillera à ce que chaque exercice soit écrit dans une ou plusieurs fonctions, qui seront appelées les une après les autres dans la fonction main.

## Exercice 1 : les types primitifs de base

Les types primitifs de base en C+ sont :

- bool : un boolean
- char : un caractère seul
- char*, ou char[] : une chaine de caractère (C-style) si terminé par null
- string : une chaine de caractère (depuis librarie standard)
- int : un entier
- unsigned int : un entier exclusivement positif
- long int (ou long) : un entier long (permettant de stocker de plus grandes valeurs)
- float : nombre à virgule flottante, simple précision
- double : nombre à virgule flottante, double précision

**Question** : à l'aide de l'opérateur `sizeof(*type*)` qui affiche la taille en mémoire du type passé en paramètre, écrire un petit programme qui affiche pour les types char, bool, int, long, float et double la taille mémoire associée. En déduie les valeur maximales et minimales pour les types *int*, *unsigned int*, *long* et *unsigned long*.

## Exercice 2 : manipulation d'entiers

Un nombre premier est un entier naturel qui admet exactement deux diviseurs distincts entiers et positifs, 1 et lui même. Noter que par cette définition, 0 et 1 ne sont pas premiers.

**Question 1** : écrire une fonction *isPrime* qui prend en paramètre un entier et renvoie un boolean, vrai si l'entier passé en paramètre est premier, faux sinon.

**Question 2** : en utilisant la fonction *isPrime*, écrire une fonction qui prend en paramètre un entier et affiche sur la sortie standard tous les nombres premiers inférieurs ou égals à cet entier.

La factorielle d'un entier *n* est le produit de tous les entiers strictement positifs inférieurs ou égal à *n*.

**Question 3** : écrire une fonction *factorial* qui prend en paramètre un entier et renvoie sous la forme d'un entier long la factorielle de cet entier. Faire appel à cette fonction.

## Exercice 3 : algorithmie et boucles imbriquées

On va écrire une fonction *printTriangle* qui prend en paramètre un entier *n* et affiche sur la sortie standard un triangle de hauteur *n*. Par exemple, si *n* = 4, on affichera :

       #
      ###
     #####
    #######

**Question 1** : en fonction de n, et en comptant les lignes de haut en bas à partir de 0, quel est le nombre d'espaces à gauche du premier `#` sur la première ligne ? la deuxième ? la *i-ème* ?

**Question 2** : toujours en indexant les lignes de haut en bas en commençant par 0, quel est le nombre de caractères `#` sur la première ligne ? la deuxième ? la *i-ème* ?

**Question 3** : écrire la fonction *printTriangle*

## Exercice 4 : paramètres : pointeurs et passage par référence

**Question 1** : Ecrire une fonction *swapVariables* qui prend en paramètre deux pointeurs vers int, et qui inverse la valeur des deux variables.

**Question 2** : Ecrire maintenant une fonction **swapVariablesByRef** qui fait la même chose mais qui prend en paramètre non pas des pointeurs vers int mais des int passés par référence.

## Exercice 5 : Pointeurs et tableaux dynamiques

On va écrire une fonction qui crée et renvoie un tableau qui contient tous les nombres pairs entre deux bornes, comprises. La taille du tableau n'étant pas connue à la compilation, on va l'allouer dynamiquement avec l'opérateur `new`. Il va également falloir renvoyer la taille du tableau allouée, et comme on ne peut renvoyer qu'une seule valeur de retour, cette taille sera retournée via un paramètre passé par référence. La signature de la fonction sera donc :

    int* arrayOfEvenNumbers(int min, int max, int& size);

**Question 1** : connaît-on la taille du tableau au moment de la compilation ? Comment devra-t-on l'allouer ?

**Question 2** : étant donnés *min* et *max*, deux entiers pairs, combien y a-t-il d'entiers pairs compris entre ces deux bornes incluses ?

**Question 3** : si maintenant *min* et *max* sont arbitrairement pair ou impair, comment calculer le nombre d'entiers entre ces deux bornes ?

**Question 4** : écrire la fonction *arrayOfEvenNumbers*