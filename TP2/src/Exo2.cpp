#include <iostream>

int Exo2()
{
     int x, y;
     int a, b, c, d;
     std::cout << "Veuillez entrer la coordonnées en x du premier vecteur" << std::endl;
     std::cin >> x;
     a = x;
     std::cout << "Veuillez entrer la coordonnées en y du premier vecteur" << std::endl;
     std::cin >> y;
     b = y;
     std::cout << "Veuillez entrer la coordonnées en x du deuxieme vecteur" << std::endl;
     std::cin >> x;
     c = x;
     std::cout << "Veuillez entrer la coordonnées en y du deuxieme vecteur" << std::endl;
     std::cin >> y;
     d = y;

     int Produit = (a * c) + (b * d);
     if (Produit == 0)
     {
          std::cout << "Ces deux vecteurs sont orthogonaux" << std::endl;
     }
     else
     {
          std::cout << "Ces deux vecteurs ne sont pas orthogonaux" << std::endl;
     }
}
