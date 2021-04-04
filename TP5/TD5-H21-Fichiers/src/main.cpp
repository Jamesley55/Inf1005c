////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <iomanip>
#include <iostream>
#include <string>

#include "CodeDemande.hpp"
#include "CodeFourni.hpp"


using namespace std;

#pragma endregion //}


/**
 * Lit une dimension des morceaux et s'assure qu'elle est valide
 *
 * \param [in] message				Le texte à afficher
 * \param [in] dimensionTotale		La dimension de l'image
 *
 * \return la dimension d'un morceau
 */
int lireDimension(string message, int dimensionTotale) {
	int dimension = 80;
	cout << message <<endl;
	// cin >> dimension;
	while (dimensionTotale % dimension) {
		cout << "La taille de l'image, " << dimensionTotale << ", n'est pas divisible par " << dimension << endl;
		cout << message << endl;
		cin >> dimension;
	} 
	return dimension;
}

/**
 * Lit, modifie et écrit une image bitmap dans un fichier
 *
 */
int main ( )
{
	srand(unsigned(time(nullptr)));
	cout << boolalpha;
	cout << "Veuillez entrer le nom de l'image a lire: ";
	string fichierLire = "image.bmp";
	// cin >> fichierLire;
	bool ok;
	Image image = lireImage(fichierLire, ok);
	if (not ok) {
		cout << "Erreur de lecture de l'image" << endl;
		return -1;
	}
	int dimensionX = lireDimension("Veuillez indiquer la dimension des morceaux en X", image.largeur);
	int dimensionY = lireDimension("Veuillez indiquer la dimension des morceaux en Y", image.hauteur);
	ImageDecomposee imageDecomposee = decomposerImage(image, dimensionY, dimensionX);
	imageDecomposee = melangerImage(imageDecomposee);
	desallouerImage(image);

	image = recomposerImage(imageDecomposee);
	cout << "Veuillez entrer le nom du fichier a ecrire : ";
	string fichierEcrire = "fichier.bmp";
	cin >> fichierEcrire;

	ecrireImage(fichierEcrire, image, ok);
	if (ok) {
		cout << "L'image a ete ecrite dans le fichier" << endl;
	}
}
