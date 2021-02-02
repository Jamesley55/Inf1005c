#include <iostream>
#include <string>

float mod_vect(int x, int y, int z)
{
    int Distance = sqrt(x * x + y * y + z * z);
    std::cout << "La distance de ce point à l'origine est:" << std::endl
              << Distance << std::endl;
    return Distance;
}

int Exo4()
{
    int x, y, z;
    std::cout << "Veuillez entrer un point en x :" << std::endl;
    std::cin >> x;
    std::cout << "Veuillez entrer un point en y :" << std::endl;
    std::cin >> y;
    std::cout << "Veuillez entrer un point en z :" << std::endl;
    std::cin >> z;
    float plus_proche_de_lorigine = mod_vect(x, y, z);
    while (plus_proche_de_lorigine != 0)
    {
        std::cout << "Veuillez entrer les coordonnées d'un autre point" << std::endl;
        std::cout << "Veuillez entrer un point en x :" << std::endl;
        std::cin >> x;
        std::cout << "Veuillez entrer un point en y :" << std::endl;
        std::cin >> y;
        std::cout << "Veuillez entrer un point en z :" << std::endl;
        std::cin >> z;
        float dist_nouveau_point = mod_vect(x, y, z);
        if (dist_nouveau_point < plus_proche_de_lorigine)
        {
            std::cout << "Ce point est plus proche de l'rogine que les point precedent" << std::endl;
            plus_proche_de_lorigine = dist_nouveau_point;
        }
    }
    std::cout << "vous avez trouvez le point le plus proche de l'origine" << std::endl;
}
