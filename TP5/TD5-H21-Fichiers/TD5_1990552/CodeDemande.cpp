////////////////////////////////////////////////////////////////////////////////
// \title 	TD5
/// \file   CodeDemande.cpp
/// \author Jamesley Joseph 1990552
/// \date   4 Avril mars 2021
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

/**
 * Lit les entêtes d’un fichier bitmap et en extrait l’entête DIB
 * \param [in] fichier	un fichier valide ouvert en lecture binaire
 * \return l'entete Dib du fichier
 */
EnteteDib lireEnteteFichier(fstream &fichier)
{
	// TODO: Lire l'entête DIB du fichier donné.
	EnteteBmp enteteBmp;
	EnteteDib enteteDib;
	fichier.read((char *)&enteteBmp, sizeof(enteteBmp));
	fichier.read((char *)&enteteDib, sizeof(enteteDib));
	return enteteDib;
}

/**
 * Lit les pixels d’une image à partir d’un fichier
 * \param [in] fichier			le fichier ouvert en lecture binaire dans laquelel on va cherche les pixels
 * \param [in, out] image		l'image dans lequel on va mettre les pixels
 */
void lireDonneesImage(fstream &fichier, Image &image)
{
	// TODO: Se positionner au début du tableau de pixels dans le fichier.
	EnteteDib enteteDib;
	EnteteBmp enteteBmp;
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

/**
 * Écrit les pixels d’une image dans un fichier contenant déjà les entêtes
 * \param [out] fichier			Le fichier dans lequelle on va ecrire les pixels d'une image
 * \param [in] image		    L'image dans lequelle va receuillir les pixel 
 */
void ecrireDonneesImage(fstream &fichier, const Image &image)
{

	// TODO: Se positionner au début du tableau de pixels dans le fichier (après
	//       les entêtes).
	EnteteDib enteteDib;
	EnteteBmp enteteBmp;
	fichier.seekg(sizeof(enteteBmp) + sizeof(enteteDib), ios::beg);

	// TODO: Pour chaque ligne de l'image, écrire la ligne puis écrire des bytes
	//       à zéro pour le padding.
	unsigned padding = calculerTaillePadding(image);
	for (int hauteur : range(image.hauteur))
	{
		for (int largeur : range(image.largeur))
		{
			fichier.write((char *)&image.pixels[hauteur][largeur], sizeof(image.pixels[hauteur][largeur]));
		}
		int zero = 0;
		fichier.write((char *)&zero, padding);
	}
}

/**
 * Crée un fichier bitmap à partir d’une Image
 * \param [out] nomFichier		Le nom du fichier image à ouvrir en écriture binaire
 * \param [in] image		    L'image à écrire
 * \param [out] ok              Un bool représentant le succès de l'opération
 */
void ecrireImage(const string &nomFichier, const Image &image, bool &ok)
{
	// TODO: Ouvrir un fichier en écriture binaire.
	fstream fichier(nomFichier, ios::out | ios::binary);

	// Si l'ouverture n'a pas échouée :
	ok = !fichier.fail();
	if (ok)
	{
		fichier.seekp(0, ios::beg);

		// TODO: Construire les entêtes à partir de l'image.
		EnteteBmp enteteBmp = construireEnteteBmp(image);
		EnteteDib enteteDib = construireEnteteDib(image);

		// TODO: Écrire les entêtes dans le fichier.
		fichier.write((char *)&enteteBmp, sizeof(enteteBmp));
		fichier.write((char *)&enteteDib, sizeof(enteteDib));

		// TODO: Écrire les données (pixels) de l'image dans le fichier.
		ecrireDonneesImage(fichier, image);
	}
}

/**
 * Alloue le tableau de pixels pour une image donnée
 * \param [in] largeur			Largeur de l'image
 * \param [in] hauteur          Hauteur de l'image
 * \return une Image allouée ou une Image vide en cas d’échec
 */
Image allouerImage(unsigned largeur, unsigned hauteur)
{
	Image image;
	// Si la largeur ET la hauteur ne sont pas nulles :
	if (largeur != NULL && hauteur != NULL)
	{

		// TODO: Affecter les dimensions à l'image.
		image.hauteur = hauteur;
		image.largeur = largeur;

		// TODO: Allouer un tableau dynamique de pixels pour l'image.
		//       On veut Image::hauteur de lignes qui ont chacune
		//       Image::largeur de pixels.
		image.pixels = new Pixel *[hauteur];
		for (int i : range(hauteur))
		{
			image.pixels[i] = new Pixel[largeur];
		}
	}
	return image;
}

/**
 * Désalloue le tableau de pixels pour une image donnée
 * \param [out] image	L'image à désallouer
 */
void desallouerImage(Image &image)
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

/**
 * Lit un fichier bitmap et crée une Image contenant les dimensions et les pixels
 * \param [in] nomFichier	Le nom du fichier image à ouvrir en lecture binaire
 * \param [out] ok          Un bool représentant la réussite (ou non) de l'ouverture
 * \return L'image prelevee du fichier
 */
Image lireImage(const string &nomFichier, bool &ok)
{
	Image image;
	// TODO: Ouvrir le fichier en lecture binaire.
	fstream fichier(nomFichier, ios::in | ios::binary);

	// Si l'ouverture n'a pas échouée :
	ok = !fichier.fail();

	if (ok)
	{
		// TODO: Lire l'entête DIB.
		EnteteDib enteteDib = lireEnteteFichier(fichier);

		// TODO: Allouer une image selon le contenu du DIB.
		image = allouerImage(enteteDib.largeurImage, enteteDib.hauteurImage);

		// TODO: Lire les pixels du fichier.
		lireDonneesImage(fichier, image);
	}
	return image;
}

/**
 * Extrait un morceau rectangulaire d’une image en créant une plus petite image qui contient les pixels extraits de la zone donnée
 * \param [in] image				L'image à extraire un morceau
 * \param [in] x            		La position en x du coin haut gauche du morceau
 * \param [in] y            		La position en y du coin haut gauche du morceau
 * \param [in] hauteur      		La hauteur du morceau
 * \param [in] largeur      		La largeur du morceau
 * \return un morceau de l'image
 */
Image extraireMorceau(const Image &image, const int x, const int y, const int hauteur, const int largeur)
{
	// TODO: Allouer une image de la taille du morceau à extraire
	Image morceau = allouerImage(largeur, hauteur);

	// TODO: Copier les pixels du morceau dans l'image.
	for (int i : range(hauteur))
	{
		for (int j : range(largeur))
		{
			morceau.pixels[i][j] = image.pixels[y + i][x + j];
		}
	}
	return morceau;
}

/**
 * Découpe une image en la séparant en plusieurs morceaux de même dimension
 * \param [in] image				L'image à décomposer
 * \param [in] hauteurMorceaux		La hauteur de chaque morceau
 * \param [in] largeurMorceaux		La largeur de chaque morceau
 * \return L'image décomposée en morceaux
 */
ImageDecomposee decomposerImage(const Image &image, const int hauteurMorceaux, const int largeurMorceaux)
{
	ImageDecomposee imageDecomposee;
	// TODO: Spécifier le nombre de morceaux en x et en y contenus dans l'image
	imageDecomposee.nMorceauxX = image.largeur / largeurMorceaux;
	imageDecomposee.nMorceauxY = image.hauteur / hauteurMorceaux;

	// TODO: Allouer morceaux en fonction du nombre de morceaux en y
	imageDecomposee.morceaux = new Image *[imageDecomposee.nMorceauxY];

	for (int i : range(imageDecomposee.nMorceauxY))
	{
		// TODO: Allouer la ligne de morceaux courante en fonction du nombre de morceaux en x
		imageDecomposee.morceaux[i] = new Image[imageDecomposee.nMorceauxX];

		for (int j : range(imageDecomposee.nMorceauxX))
		{
			// TODO: Utiliser extraireMorceau pour obtenir une image pour chaque morceau de chaque ligne
			imageDecomposee.morceaux[i][j] = extraireMorceau(image, j * largeurMorceaux, i * hauteurMorceaux, hauteurMorceaux, largeurMorceaux);
		}
	}
	return imageDecomposee;
}

/**
 * Mélange les morceaux en échangeant chaque morceau par un morceau choisi aléatoirement
 *
 * \param [in,out] imageDecomposee	Les morceaux à mélanger
 *
 * \return Les morceaux mélangés
 */
ImageDecomposee melangerImage(ImageDecomposee imageDecomposee)
{

	for (int i : range(imageDecomposee.nMorceauxY))
	{
		for (int j : range(imageDecomposee.nMorceauxX))
		{
			// Inverser le morceau courant avec un morceau choisi au hasard
			Image morceauTemp = imageDecomposee.morceaux[i][j];
			int x = rand() % imageDecomposee.nMorceauxX;
			int y = rand() % imageDecomposee.nMorceauxY;
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
Image recomposerImage(const ImageDecomposee imageDecomposee)
{
	int largeurMorceau = imageDecomposee.morceaux[0][0].largeur;
	int hauteurMorceau = imageDecomposee.morceaux[0][0].hauteur;
	// TODO: Allouer l'image
	Image image = allouerImage(largeurMorceau * imageDecomposee.nMorceauxX, hauteurMorceau * imageDecomposee.nMorceauxY);
	for (int i : range(image.hauteur))
	{
		for (int j : range(image.largeur))
		{
			// TODO: Copier le pixel correspondant du morceau dans l'image
			image.pixels[i][j] = imageDecomposee
									 .morceaux[i / hauteurMorceau][j / largeurMorceau]
									 .pixels[i - (i / hauteurMorceau) * hauteurMorceau][j - (j / largeurMorceau) * hauteurMorceau];
		}
	}
	return image;
}

#pragma endregion //}

#pragma endregion //}
