
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Voyageur
{
    string nom;
    string numeroDePassport;
    string numeroDePlace;
};
struct Vol
{
    string numeroDeVol;
    string aeroportDeDepart;
    string heureDeDepart;
    string aeroportArrive;
    string heureDarriver;
};

int main(){
    #question1 
    //char a = 'B'; int b =67; string c = "ABC";
    //cout << a;
    //cout << int(a) << "*"<< bool(a) << "*"<< c.length() << "*" << char(b) << "*" << char(a+2) << "*" << 'b' << "*" << (a-1) << "*" << double(c[1]);

    #question 2:
    /* int vec[] ={8,1,17};
    for(int i=0; i < 3; i++){
        for( int j =i+1; j <= 3; j++){
            if(vec[j] >= vec[i]){
                int temps =vec[i]; 
                vec[i] = vec[j]; 
                vec[j] = temps;
            }
        }
    } 
    cout << vec[0] <<"-" << vec[1] << "-" <<vec[2] << endl;
    */

    #question4 
    /* srand((time(nullptr))); // Initialisation du générateur aléatoire
    const int dim = 5;
    int mat[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            int interval = 100;
            int nombreAleatoire = rand() % interval + 0;
            mat[i][j] = nombreAleatoire;
        }
    }
    int somme = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {

            if (i = j)
            {
                somme += mat[i][j];
            }
        }
    }
    cout << "la somme est de: " << somme << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {

            if (i != j && mat[i][j] != 0)
            {
                cout << "cette matrice n'est pas diagonale" << endl;
                return 0;
            }
        }
    }
    */

   
   #question5 
   /*  static const int nMaxPlaces = 550;
    struct Point
    {
        string aeroport, heure;
    };
    Voyageur voyageurs[nMaxPlaces];
    Vol vol;
    const std::string path = "DetailsVol.txt";
    ifstream ficLire(path, ios::in);
    ofstream ficEcrire(path, ios::app);
    int nPlace = 0;
    if (ficLire.fail())
    {
        cout << "Ne peut pas ouvrir ce fichier!";
        return 0;
    }
    else
    {
        ficLire >> vol.numeroDeVol >> vol.aeroportDeDepart >> vol.heureDeDepart >> vol.aeroportArrive >> vol.heureDarriver;
        while (!ws(ficLire).eof())
        {
            ficLire >> voyageurs[nPlace].nom >> voyageurs[nPlace].numeroDePassport >> voyageurs[nPlace].numeroDePlace;
            nPlace += 1;
        }
    }
    cout << "saisir un numéro de place sous la forme de AXXX ou BXXX " << setw(5) << "le nombre XXX apres les identifiant A et B represente le numero de la place que vous voulez" << endl;
    string numerodePlaceEntree;
    cin >> numerodePlaceEntree;
    bool isFree = true;
    for (Voyageur voyageur : voyageurs)
    {
        if (voyageur.numeroDePlace == numerodePlaceEntree)
        {
            isFree = false;
        }
    }
    isFree ? cout << "votre place a ete enregistre" << endl : cout << "la place entree est deja prise" << endl;
    if (isFree)
    {
        cout << "entre votre nom ";
        string nom;
        cin >> nom;
        cout << "entree votre numero de pasport ";
        string numeroDePassport;
        cin >> numeroDePassport;
        ficEcrire << "\n" << nom << " " << numeroDePassport << " " << numerodePlaceEntree << endl;
    }
    */
}