/*-----------------------------
Exo4: Distance à l’origine en 3D
Author: Jamesley Joseph 1990552
         Théophile GUEI 1999258

Date: 7 fevrier 2021
------------------------------*/
#include <iostream>
#include <string>

using namespace std;

float mod_vect(int x, int y, int z)
{
    int Distance = sqrt(x * x + y * y + z * z);
    cout << "La distance de ce point à l'origine est:" << endl
         << Distance << endl;
    return Distance;
}

int main()
{
    int x, y, z;
    cout << "Veuillez entrer un point en x :" << endl;
    cin >> x;
    cout << "Veuillez entrer un point en y :" << endl;
    cin >> y;
    cout << "Veuillez entrer un point en z :" << endl;
    cin >> z;
    float plus_proche_de_lorigine = mod_vect(x, y, z);
    while (plus_proche_de_lorigine != 0)
    {
        cout << "Veuillez entrer les coordonnées d'un autre point" << endl;
        cout << "Veuillez entrer un point en x :" << endl;
        cin >> x;
        cout << "Veuillez entrer un point en y :" << endl;
        cin >> y;
        cout << "Veuillez entrer un point en z :" << endl;
        cin >> z;
        float dist_nouveau_point = mod_vect(x, y, z);
        if (dist_nouveau_point < plus_proche_de_lorigine)
        {
            cout << "Ce point est plus proche de l'rogine que les point precedent" << endl;
            plus_proche_de_lorigine = dist_nouveau_point;
        }
    }
    cout << "vous avez trouvez le point le plus proche de l'origine" << endl;
}
