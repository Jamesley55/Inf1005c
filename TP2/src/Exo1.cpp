#include <iostream>
#include <cstring>

using namespace std;
int Exo1()
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