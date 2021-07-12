//Inclusions C++
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>

//Inclusions perso
#include "traitements.h"

using namespace std;


void afficherTitreAlpha();
void afficherTitreNonAlpha();

int main()
{
    //On demande le nombre de mot a trier
    cout << "Combien de donnees avez-vous ?" << endl;
    int tailleTab;
    while ( ! ( cin >> tailleTab ) )
    {
        //Pour éviter les boucles infinies en cas d'itroduction de caractère par l'utilisateur au lieu de nombre
        if ( cin.eof() )
        {
            // pour windows; Fin du flux d'entree !
            return 0;
        }
        else if ( cin.fail() ) // On cas d'introduction de caracteres au lieu de nombres
        {
            cout << "Saisie incorrecte, recommencez : ";
            cin.clear();
            cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );
        }

    }
    string data = "";
    vector<string> tabValeurs;
    //On recupre les données on les stockons dans un conteneur type vector
    for(int i(0); i< tailleTab; i++)
    {
        cout << "Entrez la chaine " << i+1 << endl;
        cin >> data;
        tabValeurs.push_back(data);
    }


    //On affiche les valeurs du tableau, comme ils etaient entrées par l'utilisateur
    for(int i(0); i<(int)tabValeurs.size(); i++)
    {
        cout << tabValeurs[i] << endl;
    }

    //On demande le choix du tri à réalisé
    int choix = 0;
    cout << "1------alphabetique" << endl;
    cout << "2------alphabetique inverse" << endl;
    cout << "3------les deux" << endl;
    cout << "Choisissez une option de tri ? " ;
    while ( ! ( cin >> choix ) || (choix != 1 && choix != 2 && choix != 3))
    {
        //Pour éviter les boucles infinies en cas d'itroduction de caractère par l'utilisateur au lieu de nombre
        if ( cin.eof() )
        {
            // pour windows; Fin du flux d'entree !
            return 0;
        }
        else if ( cin.fail() ) // On cas d'introduction de caracteres au lieu de nombres
        {
            cout << "Saisie incorrecte, recommencez : ";
            cin.clear();
            cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );
        }
        else // On cas d'introduction de nombres différends de 1,2,3
        {
            cout << "Le chiffre n'est pas valide, recommencez : ";
        }
    }


    //On fait le tri selon l'options choisie
    switch (choix) {
    case 1 : //Tri alphabetique
    {
        afficherTitreAlpha();
        Traitements::TriAlphabetique(tabValeurs);
        Traitements::SuppDoublons(tabValeurs);
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            cout << tabValeurs[i] << " ";
        cout << endl;
        break;
    }

    case 2 : //Tri alphabetique inverse
    {
        afficherTitreNonAlpha();
        Traitements::TriNonAlphabetique(tabValeurs);
        Traitements::SuppDoublons(tabValeurs);
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            cout << tabValeurs[i] << " ";
        cout << endl;

        break;
    }

        //Les deux tri
    case 3 :
    {
        afficherTitreAlpha();
        Traitements::TriAlphabetique(tabValeurs);
        Traitements::SuppDoublons(tabValeurs);
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            cout << tabValeurs[i] << " ";
        cout << endl;

        afficherTitreNonAlpha();
        Traitements::TriNonAlphabetique(tabValeurs);
        Traitements::SuppDoublons(tabValeurs);
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            cout << tabValeurs[i] << " ";
        cout << endl;
        break;
    }

    }
    return 0;
}

//Juste pour afficher les titres
void afficherTitreAlpha()
{
    cout << "******************" << endl;
    cout << "*Tri alphabetique*" << endl;
    cout << "******************" << endl;
}

//Juste pour afficher les titres
void afficherTitreNonAlpha()
{
    cout << "**************************" << endl;
    cout << "*Tri alphabetique inverse*" << endl;
    cout << "**************************" << endl;
}

