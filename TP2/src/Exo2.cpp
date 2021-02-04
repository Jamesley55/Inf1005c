#include <iostream>
using namespace std;

int Exo2()
{
     int x, y;
     int a, b, c, d;
     cout << "Veuillez entrer la coordonnées en x du premier vecteur" << endl;
     cin >> x;
     a = x;
     cout << "Veuillez entrer la coordonnées en y du premier vecteur" << endl;
     cin >> y;
     b = y;
     cout << "Veuillez entrer la coordonnées en x du deuxieme vecteur" << endl;
     cin >> x;
     c = x;
     cout << "Veuillez entrer la coordonnées en y du deuxieme vecteur" << endl;
     cin >> y;
     d = y;

     int Produit = (a * c) + (b * d);
     if (Produit == 0)
     {
          cout << "Ces deux vecteurs sont orthogonaux" << endl;
     }
     else
     {
          cout << "Ces deux vecteurs ne sont pas orthogonaux" << endl;
     }
     return 0; 
}
