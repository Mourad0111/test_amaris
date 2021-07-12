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

//Tri alphabetique
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

//Tri alphabetique inverse
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

void Traitements::SuppDoublons(vector<string> &tabValeurs)
{
    tabValeurs.erase( unique( tabValeurs.begin(), tabValeurs.end() ), tabValeurs.end() );
}
/*
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
*/



