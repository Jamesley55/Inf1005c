/*-----------------------------
Exo1:            Premier prénom
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 7 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
     cout << "Veuillez entrer un prénom composé" << endl;
     string prenomCompose;
     cin >> prenomCompose;

     int posUnion = prenomCompose.find("-");
     string prenom;
     prenom = prenomCompose.substr(0, posUnion);
     string lettreEnMajuscule;
     lettreEnMajuscule = char(toupper(prenom[0]));
     prenom.replace(0, 1, lettreEnMajuscule);
     cout << "Bonjour " << prenom << endl;
     return 0;
}