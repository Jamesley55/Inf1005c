#include <iostream>
#include <cstring>

using namespace std; 
int Exo1() {
     cout << "Veuillez entrer un prénom composé" << endl;
     string prenomCompose;
	cin >> prenomCompose;
   
     int posUnion = prenomCompose.find("-");
     string prenomNonCompose; 
     prenomNonCompose = prenomCompose.substr(0,posUnion); 
     cout << "Bonjour: " << char(toupper(prenomCompose[0])) << endl;

     
}