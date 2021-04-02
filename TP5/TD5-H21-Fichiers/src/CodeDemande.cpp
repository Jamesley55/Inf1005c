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

EnteteDib lireEnteteFichier ( fstream& fichier )
{
	// TODO: Lire l'entête DIB du fichier donné.
	EnteteBmp enteteBmp;
	EnteteDib enteteDib;
	fichier.read((char*)&enteteBmp, sizeof(enteteBmp));
	fichier.read((char*)&enteteDib, sizeof(enteteDib));
	return enteteDib;
}

void lireDonneesImage ( fstream& fichier, Image& image )
{
	int padding;
	if(image.largeur%4 ==0) calculerTaillePadding(image);

	// TODO: Se positionner au début du tableau de pixels dans le fichier.
	fichier.seekp(sizeof(EnteteDib) + sizeof(EnteteBmp), ios::beg);

	// TODO: Pour chaque ligne de l'image, lire la ligne et sauter le padding.
	for (int i = image.hauteur-1; i >= 0; i--)
	{
		for (int j = 0; j < image.largeur; j++)
			fichier.read((char*)&image.pixels[i][j], sizeof(image.pixels[i][j]));
		fichier.seekp(padding, ios::cur);
	}
}

void ecrireDonneesImage ( fstream& fichier, const Image& image )
{
	// TODO: Se positionner au début du tableau de pixels dans le fichier (après
	//       les entêtes).
	fichier.seekp(sizeof(EnteteBmp) + sizeof(EnteteDib), ios::beg);

	// TODO: Pour chaque ligne de l'image, écrire la ligne puis écrire des bytes
	//       à zéro pour le padding.
		for (int i = image.hauteur-1; i >= 0; i--)
			for (int j = 0; j < image.largeur; j++)
				fichier.write((char*)&image.pixels[i][j], sizeof(image.pixels[i][j]));
				fichier.write("0", calculerTaillePadding(image));
	
}

void ecrireImage ( const string& nomFichier, const Image& image, bool& ok )
{
	// TODO: Ouvrir un fichier en écriture binaire.
	fstream fichierEcrire(nomFichier, ios::binary | ios::out);

	if (fichierEcrire.fail())
		ok = false;
	else{
		// Si l'ouverture n'a pas échouée :
		ok = true;
		// TODO: Construire les entêtes à partir de l'image.
		EnteteBmp Bmp = construireEnteteBmp(image);
		EnteteDib Dib = construireEnteteDib(image);
		// TODO: Écrire les entêtes dans le fichier.
		fichierEcrire.write((char*)&Bmp, sizeof(Bmp));
		fichierEcrire.write((char*)&Dib, sizeof(Dib));
		
		// TODO: Écrire les données (pixels) de l'image dans le fichier.
		ecrireDonneesImage(fichierEcrire, image);
	}
}

Image allouerImage ( unsigned largeur, unsigned hauteur )
{
	Image image;
	Pixel pixel = { 0, 0, 0 };
	// Si la largeur ET la hauteur ne sont pas nulles :
	if (largeur != 0 && hauteur != 0)
		// TODO: Affecter les dimensions à l'image.
		image.hauteur = hauteur;
		image.largeur = largeur;
		// TODO: Allouer un tableau dynamique de pixels pour l'image.
		//       On veut Image::hauteur de lignes qui ont chacune
		//       Image::largeur de pixels.
		image.pixels = new Pixel* [hauteur];
		for (int ligne : range(hauteur))
		{
			image.pixels[ligne] = new Pixel[largeur];
			for (int colonne : range(largeur))
				image.pixels[ligne][colonne] = pixel;
			
		}

}


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

Image lireImage ( const string& nomFichier, bool& ok )
{
	Image image = { 0, 0, 0 };
	// TODO: Ouvrir le fichier en lecture binaire.
		fstream fichier(nomFichier, ios::in | ios::binary);

	if (!fichier.fail()){
	// Si l'ouverture n'a pas échouée :
		ok = true;

		EnteteDib enteteDib;
		// TODO: Lire l'entête DIB.
		enteteDib = lireEnteteFichier(fichier);

		// TODO: Allouer une image selon le contenu du DIB.
		image = allouerImage(enteteDib.largeurImage, enteteDib.hauteurImage);

		// TODO: Lire les pixels du fichier.
		lireDonneesImage(fichier, image);
	}
	else
		ok = false;
	return image;

}

Image extraireMorceau ( const Image& image, const int x, const int y, const int hauteur, const int largeur)
{
	// TODO: Allouer une image de la taille du morceau à extraire
	Image copie = allouerImage(largeur, hauteur);
	
	// TODO: Copier les pixels du morceau dans l'image.
	copie.pixels = image.pixels;
	return copie;
}

ImageDecomposee decomposerImage(const Image& image, const int hauteurMorceaux, const int largeurMorceaux)
{
	ImageDecomposee imageDecomposee;

	// TODO: Spécifier le nombre de morceaux en x et en y contenus dans l'image

	// TODO: Allouer morceaux en fonction du nombre de morceaux en y

	for (int i : range(imageDecomposee.nMorceauxY)) {
		// TODO: Allouer la ligne de morceaux courante en fonction du nombre de morceaux en x

		for (int j : range(imageDecomposee.nMorceauxX)) {
			// TODO: Utiliser extraireMorceau pour obtenir une image pour chaque morceau de chaque ligne

		}
	}

	return imageDecomposee;
}

ImageDecomposee melangerImage(ImageDecomposee imageDecomposee) 
{

	for (int i : range(imageDecomposee.nMorceauxY)) {
		for (int j : range(imageDecomposee.nMorceauxX)) {
			// TODO: Échanger le morceau courant avec un morceau choisi au hasard

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
Image recomposerImage(const ImageDecomposee imageDecomposee) 
{
	Image image;
	int largeurMorceau = imageDecomposee.morceaux[0][0].largeur;
	int hauteurMorceau = imageDecomposee.morceaux[0][0].hauteur;

	// TODO: Allouer l'image
	
	for (int i : range(image.hauteur)) {
		for (int j : range(image.largeur)) {
			// TODO: Copier le pixel correspondant du morceau dans l'image
		}
	}

	return image;
}

#pragma endregion //}

#pragma endregion //}

