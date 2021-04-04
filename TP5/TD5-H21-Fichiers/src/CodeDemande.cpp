////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
////////////////////////////////////////////////////////////////////////////////

#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <fstream>
#include <string>

#include "CodeFourni.hpp"

using namespace std;

#pragma endregion //}

#pragma region "Globaux" //{

#pragma region "Fonctions" //{

//Good
EnteteDib lireEnteteFichier(fstream &fichier)
{
	// TODO: Lire l'entête DIB du fichier donné.
	EnteteBmp enteteBmp;
	EnteteDib enteteDib;
	fichier.read((char *)&enteteBmp, sizeof(enteteBmp));
	fichier.read((char *)&enteteDib, sizeof(enteteDib));
	return enteteDib;
}

//Good
void lireDonneesImage(fstream &fichier, Image &image)
{
	// TODO: Se positionner au début du tableau de pixels dans le fichier.
	EnteteDib enteteDib ;
	EnteteBmp enteteBmp ;
	fichier.seekg(sizeof(enteteBmp) + sizeof(enteteDib), ios::beg);
	// TODO: Pour chaque ligne de l'image, lire la ligne et sauter le padding.
	unsigned padding = calculerTaillePadding(image);
	for (int hauteur : range(image.hauteur))
	{
		for (int largeur : range(image.largeur))
		{
			Pixel pixel;
			fichier.read((char *)&pixel, sizeof(pixel));
			image.pixels[hauteur][largeur] = pixel;
		}
		fichier.seekg(padding, ios::cur);
	}
}
//Good
void ecrireDonneesImage(fstream &fichier, const Image &image)
{

	// TODO: Se positionner au début du tableau de pixels dans le fichier (après
	//       les entêtes).
	EnteteDib enteteDib ;
	EnteteBmp enteteBmp ;
	fichier.seekg(sizeof(enteteBmp) + sizeof(enteteDib), ios::beg);
	// TODO: Pour chaque ligne de l'image, écrire la ligne puis écrire des bytes
	//       à zéro pour le padding.
	int zero = 0;
	unsigned padding = calculerTaillePadding(image);
	for (int hauteur : range(image.hauteur)) {
		for (int largeur : range(image.largeur)) {
			Pixel pixel = image.pixels[hauteur][largeur];
			fichier.write((char*)&pixel, sizeof(pixel));
		}
		fichier.write((char*)&zero, padding);
	}
}

//Good
void ecrireImage(const string &nomFichier, const Image &image, bool &ok)
{
		// TODO: Ouvrir un fichier en écriture binaire.
	fstream fichier(nomFichier, ios::out | ios::binary);
	// Si l'ouverture n'a pas échouée :
	ok = !fichier.fail();
	if (ok) {
		fichier.seekp(0, ios::beg);
		// TODO: Construire les entêtes à partir de l'image.
		EnteteBmp enteteBmp = construireEnteteBmp(image);
		EnteteDib enteteDib = construireEnteteDib(image);
		// TODO: Écrire les entêtes dans le fichier.
		fichier.write((char*)&enteteBmp, sizeof(enteteBmp));
		fichier.write((char*)&enteteDib, sizeof(enteteDib));
		// TODO: Écrire les données (pixels) de l'image dans le fichier.
		ecrireDonneesImage(fichier, image);
	}
	
}

//Good
Image allouerImage(unsigned largeur, unsigned hauteur)
{
	Image image;
	// Si la largeur ET la hauteur ne sont pas nulles :
	if (largeur != 0 && hauteur != 0) {
		// TODO: Affecter les dimensions à l'image.
		image.hauteur = hauteur;
		image.largeur = largeur;
		// TODO: Allouer un tableau dynamique de pixels pour l'image.
		//       On veut Image::hauteur de lignes qui ont chacune
		//       Image::largeur de pixels.
		image.pixels = new Pixel * [hauteur];
		for (int i : range(hauteur)) {
			image.pixels[i] = new Pixel[largeur];
		}
	}
	return image;
}

//Good
void desallouerImage ( Image& image )
{
	// Si le tableau dynamique de l'image n'est pas nul :
		// TODO: Désallouer le tableau 2D.
	if (image.largeur != 0 && image.hauteur != 0 && image.pixels != 0)
	{
		for (int ligne : range(image.hauteur))
			delete[] image.pixels[ligne];
		delete[] image.pixels;
		image.pixels = 0;
	}
}

//Good
Image lireImage(const string &nomFichier, bool &ok)
{
	
	Image image = {};
	// TODO: Ouvrir le fichier en lecture binaire.
	fstream fichier(nomFichier, ios::in | ios::binary);

	if (!fichier.fail())
	{
		// Si l'ouverture n'a pas échouée :
		ok = true;

		EnteteDib enteteDib;
		// TODO: Lire l'entête DIB.
		enteteDib = lireEnteteFichier(fichier);

		// TODO: Allouer une image selon le contenu du DIB.
		image = allouerImage(enteteDib.largeurImage, enteteDib.hauteurImage);

		// TODO: Lire les pixels du fichier.
		lireDonneesImage(fichier, image);
		return image;
	}
	else
		ok = false;
	return image;
	
}

//Good
Image extraireMorceau(const Image &image, const int x, const int y, const int hauteur, const int largeur)
{
// TODO: Allouer une image de la taille du morceau à extraire
	Image morceau = allouerImage(largeur, hauteur);
	// TODO: Copier les pixels du morceau dans l'image.
	for (int i : range(hauteur)) {
		for (int j : range(largeur)) {
			morceau.pixels[i][j] = image.pixels[y + i][x + j];
		}
	}
	return morceau;
}

//Good
ImageDecomposee decomposerImage(const Image &image, const int hauteurMorceaux, const int largeurMorceaux)
{
	ImageDecomposee imageDecomposee;
	// TODO: Spécifier le nombre de morceaux en x et en y contenus dans l'image
	imageDecomposee.nMorceauxX = image.largeur / largeurMorceaux;
	imageDecomposee.nMorceauxY = image.hauteur / hauteurMorceaux;
	// TODO: Allouer morceaux en fonction du nombre de morceaux en y
	imageDecomposee.morceaux = new Image * [imageDecomposee.nMorceauxY];
	for (int i : range(imageDecomposee.nMorceauxY)) {
		// TODO: Allouer la ligne de morceaux courante en fonction du nombre de morceaux en x
		imageDecomposee.morceaux[i] = new Image[imageDecomposee.nMorceauxX];
		for (int j : range(imageDecomposee.nMorceauxX)) {
			// TODO: Utiliser extraireMorceau pour obtenir une image pour chaque morceau de chaque ligne
			int y =  j * largeurMorceaux;
			int x = i * hauteurMorceaux;
			imageDecomposee.morceaux[i][j] = extraireMorceau(image, y,
				x, hauteurMorceaux, largeurMorceaux);
		}
	}
	return imageDecomposee;
}

//Good
ImageDecomposee melangerImage(ImageDecomposee imageDecomposee)
{

	Image morceauTemp;
	int x, y;
	for (int i : range(imageDecomposee.nMorceauxY)) {
		for (int j : range(imageDecomposee.nMorceauxX)) {
			// Inverser le morceau courant avec un morceau choisi au hasard
			morceauTemp = imageDecomposee.morceaux[i][j];
			x = rand() % imageDecomposee.nMorceauxX;
			y = rand() % imageDecomposee.nMorceauxY;
			imageDecomposee.morceaux[i][j] = imageDecomposee.morceaux[y][x];
			imageDecomposee.morceaux[y][x] = morceauTemp;
		}
	}
	return imageDecomposee;
}

/**
 * Crée une image à partir d'une image décomposée
 *
 * \param [in] imageDecomposee		L'image de départ
 *
 * \return l'image recomposée
 */
// Checker demain
Image recomposerImage(const ImageDecomposee imageDecomposee)
{
	Image image;
	int largeurMorceau = imageDecomposee.morceaux[0][0].largeur;
	int hauteurMorceau = imageDecomposee.morceaux[0][0].hauteur;
	int blocX, blocY, y, x;
	// TODO: Allouer l'image
	image = allouerImage(largeurMorceau * imageDecomposee.nMorceauxX,
		hauteurMorceau * imageDecomposee.nMorceauxY);
	for (int i : range(image.hauteur)) {
		blocY = i / hauteurMorceau;
		y = i - blocY * hauteurMorceau;
		for (int j : range(image.largeur)) {
			// TODO: Copier le pixel correspondant du morceau dans l'image
			blocX = j / largeurMorceau;
			x = j - blocX * largeurMorceau;
			image.pixels[i][j] = imageDecomposee.morceaux[blocY][blocX].pixels[y][x];
		}
	}
	return image;
}

#pragma endregion //}

#pragma endregion //}
