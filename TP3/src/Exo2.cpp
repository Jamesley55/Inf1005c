/*-----------------------------
Exo2:             
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 21 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstring>

using namespace std;

int entreeValide(string chaine, float min, float max)
{
    float entree;
    do
    {
        cout << chaine;
        cin >> entree;
    } while (entree < min || entree > max);
    return (int)entree;
}

int Exo2()
{
    int interval = 1000;
    srand(time(NULL));
    int nombreAleatoire = rand() % interval + 0;
    int nombreDeTentative = 0;
    int valeurEntree;
    do
    {
        valeurEntree = entreeValide("Entrez un nombre entier : ", 0, interval);
        valeurEntree < nombreAleatoire ? cout << "Trop bas." << endl : cout << "Trop haut." << endl;
        ;
        nombreDeTentative++;
    } while (valeurEntree != nombreAleatoire);
    cout << "Bravo! Vous avez reussi! en " << nombreDeTentative << " tentatives!" << endl;
}