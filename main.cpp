#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


void tri_alphabetique(vector<string> &tabValeurs);
void tri_non_alphabetique(vector<string> &tabValeurs);
void afficherTitreAlpha();
void afficherTitreNonAlpha();
void suppDoublons(vector<string> &tabValeurs);

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
            return false;
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
            return false;
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
        tri_alphabetique(tabValeurs);
        tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            printf("%s ", tabValeurs[i].c_str());
        printf("\n");
        break;
    }

    case 2 : //Tri alphabetique inverse
    {
        afficherTitreNonAlpha();
        tri_non_alphabetique(tabValeurs);
        tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            printf("%s ", tabValeurs[i].c_str());

        printf("\n");
        break;
    }

        //Les deux tri
    case 3 :
    {
        afficherTitreAlpha();
        tri_alphabetique(tabValeurs);
        tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            printf("%s ", tabValeurs[i].c_str());
        printf("\n");
        afficherTitreNonAlpha();
        tri_non_alphabetique(tabValeurs);
        tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
        for (int i = 0; i < (int)tabValeurs.size(); i++)
            printf("%s ", tabValeurs[i].c_str());
        printf("\n");
        break;
    }

    }
    return 0;
}

void suppDoublons(vector<string> &tabValeurs)
{
    vector<string> temp;
    vector<bool> valASuppr(tabValeurs.size(), false);

    for(int i(0); i < (int)tabValeurs.size(); i++)
    {

        for(int j(i+1); j < (int)tabValeurs.size(); j++)
        {
            if(strcmp(tabValeurs[i].c_str(), tabValeurs[j].c_str()))
            {
                if(!valASuppr[j])
                    valASuppr.push_back(true);
            }
        }
    }
    vector<bool>::iterator it;
    for(int i(0); i<(int)valASuppr.size(); i++)
    {
        if(valASuppr[i])
            temp.push_back(tabValeurs[i]);
    }
    tabValeurs.clear();
    //tabValeurs = temp;
}

//Tri alphabetique
void tri_alphabetique(vector<string> &tabValeurs)
{
    string temp;
    for (unsigned int i = 0; i < tabValeurs.size(); i++)
    {
        for (unsigned int j = 0; j < tabValeurs.size(); j++)
        {
            if (strcmp(tabValeurs[i].c_str(), tabValeurs[j].c_str()) < 0)
            {
                temp = tabValeurs[i];
                tabValeurs[i] = tabValeurs[j];
                tabValeurs[j] = temp;
            }
        }
    }
}

//Tri alphabetique inverse
void tri_non_alphabetique(vector<string> &tabValeurs)
{
    string temp;
    for (unsigned int i = 0; i < tabValeurs.size(); i++)
    {
        for (unsigned int j = 0; j < tabValeurs.size(); j++)
        {
            if (strcmp(tabValeurs[j].c_str(), tabValeurs[i].c_str()) < 0)
            {
                temp = tabValeurs[j];
                tabValeurs[j] = tabValeurs[i];
                tabValeurs[i] = temp;
            }
        }
    }
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
