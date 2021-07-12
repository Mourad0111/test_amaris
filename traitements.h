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

    void tri_alphabetique(std::vector<std::string> &tabValeurs);
    void tri_non_alphabetique(std::vector<std::string> &tabValeurs);
    void afficherTitreAlpha();
    void afficherTitreNonAlpha();
    void suppDoublons(std::vector<std::string> &tabValeurs);
};

#endif // TRAITEMENTS_H
