/*-----------------------------
Exo4:             
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 21 fevrier 2021
------------------------------*/
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    const int size = 10;
    int tableau[size];

    cout << "Entrez dix nombres entiers : ";
    int temp;
    for (int i = 0; i < size; i++)
    {
        cin >> tableau[i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tableau[j] < tableau[i])
            {
                temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
    cout << "Voici le tableau trie : ";
    for (int i = 0; i < size; i++)
    {
        cout << tableau[i] << " ";
    }
    cout << endl;
}