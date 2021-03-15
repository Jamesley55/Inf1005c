/*-----------------------------
Exo5:             
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 21 fevrier 2021
------------------------------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const int nombreDaliment = 10;

using namespace std;
struct Aliment
{
    std::string aliment;
    std::string type;
    int quantite;
    double prix;
};
int main()
{
    Aliment inventaire[nombreDaliment];
    int alimentId = 0;
    const std::string path = "inventaire.txt";
    ifstream fichier(path, std::ios::in);
    if (fichier)
    {
        while (!ws(fichier).eof())
        {
            getline(fichier, inventaire[alimentId].aliment, '\t');
            getline(fichier, inventaire[alimentId].type, '\t');
            fichier >> inventaire[alimentId].quantite >> inventaire[alimentId].prix;
            alimentId += 1;
        }
        int i = 0;
        for (int j = 1; j < alimentId; j++)
        {
            if (inventaire[i].prix < inventaire[j].prix)
            {
                i = j;
            }
        }
        cout << inventaire[i].quantite
             << " " << inventaire[i].aliment
             << " (" << inventaire[i].type << ")"
             << " a " << std::setprecision(2) << std::fixed << inventaire[i].prix << "$ chacun";
    }
    else
    {
        cout << "Ne peut pas ouvrir ce fichier!" << endl;
        return 0;
    }
}