/*-----------------------------
Exo3: Sin
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 7 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int main()
{
     srand(unsigned(time(nullptr)));
     double nombreAleatoire = rand() % 100;
     cout << "premier nombre aleratoir" << nombreAleatoire << endl;
     if (nombreAleatoire == 0)
     {
          nombreAleatoire = 0;
     }
     else
     {
          nombreAleatoire = 1 / nombreAleatoire;
     }
     double valeurReel = sin(nombreAleatoire);
     double approximation = nombreAleatoire - (pow(nombreAleatoire, 3) / 6) + (pow(nombreAleatoire, 5) / 120);

     double difference = abs(valeurReel - approximation);

     cout << "la valeur de x est: " << nombreAleatoire
          << " et la difference entre la valeur reel et l'Approximation est: " << difference
          << endl;
     return 0;
}