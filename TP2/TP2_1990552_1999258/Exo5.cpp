/*-----------------------------
Exo5: Pokémon
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 7 fevrier 2021
------------------------------*/
#include <iostream>
#include <fstream>

using namespace std;

int calculerDomage(int lvl, int atk, int pwr, int def)
{
     return ((2 * lvl / 5 + 2) * pwr * atk / def) / 50 + 2;
};

int main()
{
     ifstream ficLire("machamp.txt");
     if (ficLire.fail())
     {
          cout << "Ne peut pas ouvrir ce fichier!";
          return 0;
     }
     else
     {
          ofstream ficEcrire("moves.txt");
          string firstLine;
          int lvl, atk, strenght, superPower, def, dammage1, dammage2;
          cout << "quelle est la defense de votre pokemon?";
          cin >> def;
          getline(ficLire, firstLine);
          string espace1, espace2, placeholderStrength, placeholderSuperPower;
          ficLire >> espace1 >> lvl >> espace2 >> atk >> placeholderStrength >> strenght >> placeholderSuperPower >> superPower;

          dammage1 = calculerDomage(lvl, atk, strenght, def);
          dammage2 = calculerDomage(lvl, atk, superPower, def);
          firstLine.pop_back();
          ficEcrire << firstLine << " contre DEF=" << def << endl
                    << endl;
          ficEcrire << placeholderStrength << " " << dammage1 << endl;
          ficEcrire << placeholderSuperPower << " " << dammage2 << endl;
     }
}