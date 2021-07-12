#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>

class Traitements
{
public:
    //Constructeur
    Traitements();
    //Destructeur
    ~Traitements();

    //Une fonction qui permet de faire un tri alphabétique
    static void TriAlphabetique(std::vector<std::string> &tabValeurs);
    //Une fonction qui permet de faire un tri alphabétique inverse
    static void TriNonAlphabetique(std::vector<std::string> &tabValeurs);
    //Une fonction qui permet de supprimer les doublons
    static void SuppDoublons(std::vector<std::string> &tabValeurs);
};

#endif // TRAITEMENTS_H
