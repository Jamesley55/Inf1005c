/*-----------------------------
Exo1:             
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 21 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstring>

using namespace std;

bool isPrime(int n)
{
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n == 1 || n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
int Exo1()
{
    int entier;
    do
    {
        cout << "Entrez un nombre entier : " << endl;
        cin >> entier;
        if (entier % 2 == 0)
        {
            entier++;
        }
        while (!isPrime(entier))
        {
            entier += 2;
        }
        cout << "Le prochain nombre premier est " << entier << "." << endl;
    } while (entier != -1);
}
