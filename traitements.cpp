#include "traitements.h"

using namespace std;

//Constructeur
Traitements::Traitements()
{

}

//Destructeur
Traitements::~Traitements()
{

}

//Une fonction qui permet de faire un tri alphabétique
void Traitements::TriAlphabetique(vector<string> &tabValeurs)
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

//Une fonction qui permet de faire un tri alphabétique inverse
void Traitements::TriNonAlphabetique(vector<string> &tabValeurs)
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

//Une fonction qui permet de supprimer les doublons
void Traitements::SuppDoublons(vector<string> &tabValeurs)
{
    tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
}




