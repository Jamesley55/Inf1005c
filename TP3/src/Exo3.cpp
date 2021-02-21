/*-----------------------------
Exo3:            
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 21 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int entreeValide(string chaine, float min, float max)
{
    int entree;
    do
    {
        cout << chaine;
        cin >> entree;
    } while (entree < min || entree > max);
    return entree;
}

int Exo3()
{
    int temps = entreeValide("Entrez le temps total : ", 0, INFINITY);
    int pos1 = entreeValide("Entrez la position initiale du premier train : ", -INFINITY, INFINITY);
    int v1 = entreeValide("Entrez la vitesse du premier train : ", -100, 100);
    int pos2 = entreeValide("Entrez la position initiale du second train : ", -INFINITY, INFINITY);
    int v2 = entreeValide("Entrez la vitesse du second train : ", -100, 100);
    double colision;
    if ((v2 - v1) != 0)
    {
        colision = ((pos1 - pos2) / (v2 - v1));
    }
    for (int i = 1; (i <= colision && i <= temps); i++)
    {
        cout << "Apres " << i << " seconde(s)" << endl;
        cout << "Train 1 : " << (pos1 + v1 * i) << endl;
        cout << "Train 2 : " << (pos2 + v2 * i) << endl;
    }
    colision > 0 && colision <= temps ? cout << "Il y a eu une collision pendant la " << colision << "e seconde !" :
                                      cout << "Il n'y a pas eu de collision !" << endl;;
}