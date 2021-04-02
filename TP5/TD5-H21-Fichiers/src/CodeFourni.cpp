////////////////////////////////////////////////////////////////////////////////
/// \file    CodeFourni.cpp
/// \author  Charles Hosson et François-R Boyer
/// \version Dernière entrée : 2021/03/23
///
/// L'implémentation du code fourni aux élèves.
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <algorithm>

#include "CodeFourni.hpp"


using namespace std;

#pragma endregion //}




#pragma region "Globaux" //{

#pragma region "Fonctions" //{


/**
 * Construit un entête BMP avec les informations spécifiques au TD, mais en
 * laissant vide la taille du fichier.
 * 
 * \return Un \c EnteteBmp valide et vide.
 */
EnteteBmp construireBmpVide ( )
{
	EnteteBmp resultat = {};

	resultat.id = BMP_ID;
	resultat.positionTableau = sizeof(EnteteBmp) + sizeof(EnteteDib);
	
	return resultat;
}


/**
 * Construit un entête DIB avec les informations spécifiques au TD, mais en
 * laissant vide les dimensions de l'image et du tableau de pixels.
 * 
 * \return Un \c EnteteDib valide et vide.
 */
EnteteDib construireDibVide ( )
{
	EnteteDib resultat = {};
	
	resultat.tailleEntete = sizeof(EnteteDib);
	resultat.nbPlansCouleur = 1;
	resultat.bpp = sizeof(Pixel) * 8;
	resultat.compression = COMPRESSION_BI_RGB;
	resultat.resolutionImpression[0] = RESOLUTION_IMPRESSION;
	resultat.resolutionImpression[1] = RESOLUTION_IMPRESSION;
	
	return resultat;
}


/**
 * Calcule le nombre d'octets de \e padding nécessaire pour chaque ligne
 * de pixels dans une image.
 * 
 * \param [in] image
 *        L'image à traiter.
 * 
 * \return Le nombre d'octet de padding.
 */
unsigned calculerTaillePadding ( const Image& image )
{
	unsigned tailleBruteLigne = image.largeur * sizeof(Pixel);
	
	return (ALIGNEMENT_PIXELS - (tailleBruteLigne % ALIGNEMENT_PIXELS)) %
	       ALIGNEMENT_PIXELS;
}


/**
 * Calcule la taille de la séquence de pixels dans le fichier bitmap, en
 * incluant le padding nécessaire.
 * 
 * \param [in] image
 *        L'image à traiter.
 * 
 * \return Le nombre d'octet du tableau dans le fichier.
 */
unsigned calculerTailleTableau ( const Image& image )
{
	unsigned padding = calculerTaillePadding(image);
	unsigned tailleLigne = image.largeur * sizeof(Pixel) + padding;
	
	return tailleLigne * image.hauteur;
}


/**
 * Construit un entête BMP à partir des dimensions d'une image.
 * 
 * \param [in] image
 *        L'image à traiter.
 * 
 * \return Un \c EnteteBmp complet.
 */
EnteteBmp construireEnteteBmp ( const Image& image )
{
	EnteteBmp resultat = construireBmpVide();
	
	resultat.tailleFichier = sizeof(EnteteBmp) + sizeof(EnteteDib) +
	                         calculerTailleTableau(image);
	
	return resultat;
}


/**
 * Construit un entête DIB à partir des dimensions d'une image.
 * 
 * \param [in] image
 *        L'image à traiter.
 * 
 * \return Un \c EnteteDib complet.
 */
EnteteDib construireEnteteDib ( const Image& image )
{
	EnteteDib resultat = construireDibVide();
	
	resultat.largeurImage = image.largeur;
	resultat.hauteurImage = image.hauteur;
	resultat.tailleTableau = calculerTailleTableau(image);
	
	return resultat;
}

#pragma endregion //}

#pragma endregion //}

