#include <iostream>
#include <fstream>

using namespace std;
static const int MAX_NOMBRE_VALEURS = 80;

struct ValueArray
{
    int tableauDeValeur[MAX_NOMBRE_VALEURS];
    int nbValeurs = 0;
    void pushBack(int value)
    {
        tableauDeValeur[nbValeurs] = value;
        nbValeurs++;
    }
};
int comparateur(int entree, ValueArray &valueArray)
{
    int divisible = 0;
    for (int i = 0; i < valueArray.nbValeurs; i++)
    {
        if (valueArray.tableauDeValeur[i] % entree == 0)
        {
            divisible++;
        }
    }
    return divisible;
}
int quiz2()
{

    ifstream fichier("fichierQuiz2.txt");
    ValueArray valueArray;
    string chaine = "";
    if (fichier.fail())
    {
        cout << "Ne peut pas ouvrir ce fichier!";
    }
    else
    {
        getline(fichier, chaine);
        while (chaine.find(' ') != string::npos)
        {
            valueArray.pushBack(atoi(chaine.substr(0, chaine.find(' ')).c_str()));
            chaine.erase(0, chaine.find(' ') + 1);
        }
    }
    cout << "saisissez une valeur dont vous voulez trouver le nombre de valeur divisible : \n";
    int entree; 
    cin >> entree;
    cout << "le nombre = " << comparateur(entree, valueArray)  <<'\n';
}
