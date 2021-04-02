#include <iostream>
#include <math.h> /* exp */

using namespace std;

// le f(x) que tu cherche dans ce cas j'ai mis la fonction exponentielle
double f(double x)
{
    return exp(x);
}

// fonction de la somation  avec les borne superieur et inferieur
double somation(int borneSuperieur, double x0, double h)
{
    double valeurSommation = 0;
    for (int i = 1; i <= borneSuperieur; i++)
    {
        // la X(i) comme on la mis dans les remarques
        // tu dois changer cette ligne si la valeur demander est X(i+1/2) ou X(2i)
        double xi = x0 + i * h;
        valeurSommation += f(xi);
    }
    return valeurSommation;
}
int main()
{

    // lis les bornes
    cout << "entrer les bornes \n ";
    double x0, xn;
    cin >> x0 >> xn;

    // j;'ai rajouter tout les valeur de n possible dans un tableau comme ca en fonction de ce qu'on te demande tu peut choisir la valeur de n que tu veut
    // n[0] = 6 , n[1] = 12,  n[2] = 18 etc..
    int n[5] = {6, 12, 18, 24, 30};

    //calcul le h
    double h = (xn - x0) / n[0];
    double trapezoidalRule = h * ((f(x0) + f(xn)) / 2 + somation((n[0] - 1), x0, h));
    cout << "Valeur approximee est de : " << trapezoidalRule << "\n";
}
