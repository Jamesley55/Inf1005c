////////////////////////////////////////////////////////////////////////////////
// \title 	TD6
/// \file   main.cpp
/// \author Jamesley Joseph 1990552
/// \date   18 Avril 2021
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <cassert>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include "debogageMemoire.hpp"
#include <bitset>

using namespace std;
using namespace iter;
using namespace gsl;

const bool doitFaireTestsAutomatises = true;
const uint64_t nBitsDuree = 4;
const uint64_t nBitsNote = 4;
const uint64_t nNotes = 9;
const uint64_t dureeMax = 15;
const uint64_t taillePortee = 9;
const uint64_t nBitsParOctet = 8;

struct Portee
{
	uint64_t nColonnes;
	char **portee;
};

/// Affiche un texte et lit une valuer située dans l'intervalle défini
///
/// \param [in] texte  Le texte à afficher
/// \param [in] max    La valeur maximale acceptée
///
/// \return La valeur lue
uint64_t lireValeurValide(const string &texte, uint64_t max)
{
	while (true)
	{
		cout << texte << " (0-" << max << "): ";
		uint64_t valeur;
		cin >> valeur;
		if (doitFaireTestsAutomatises)
		{
			if (cin.fail())
				cout << "?" << endl;
			else
				cout << valeur << endl;
		}
		if (!cin.fail() && (valeur >= 0 && valeur <= max))
		{
			return valeur;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.eof())
		{
			// Ces lignes dans cette condition n'ont pas à être couvertes par les tests.
			cout << "Erreur sur cin irrecuperable, il a ete interrompu.\n";
			exit(1);
		}
		cout << "Erreur! ";
	}
}

/**
 * ajoute des bits a la fin de la  une sonnerie
 *
 * \param [in out] sonnerie	    La sonnerie 
 * \param [in] position		La position où ajouter les bits
 * \param [in] bits	        Les bits à ajouter
 * \param [in] nBits		Nombre de bits de la note ou durée
 *
 * \return La sonnerie contenant des nouveaux bits de donnee
 */
void ajouterBitsDansSonnerie(uint64_t &sonnerie, uint64_t position, uint64_t bits, uint64_t nBits)
{
	// TODO: Créer un masque contenant uniquement des bits à 0 sauf pour les nBits à écrire (en tenant compte aussi de leur position).
	uint64_t masque = pow(2, nBits) - 1;
	masque = masque << ((64 - nBits) - (position * nBits));
	// TODO: Inverser le masque pour avoir uniquement des bits à 1 sauf pour les nBits à écrire.
	masque = ~masque;
	// TODO: Appliquer le masque pour que la sonnerie garde le même contenu sauf pour les nBits à écrire qui sont maintenant à 0.
	sonnerie = sonnerie & masque;
	// TODO: Décaler les bits à écrire pour qu'ils soient à la bonne position dans la sonnerie.
	bits = bits << ((64 - nBits) - (position * nBits));
	// TODO: Combiner les bits à la sonnerie pour les ajouter.
	sonnerie += bits;
}

/**
 * Retourne un nombre de bits de donne a partir d'une position donner
 *
 * \param [in] sonnerie	    La sonnerie 
 * \param [in] position		La position a partir duquelle il faut extraire les bits
 * \param [in] nBits		Nombre de bits a retournee
 *
 * \return Les bits extrait de la sonnerie
 */

uint64_t obtenirBitsDeSonnerie(uint64_t sonnerie, uint64_t position, uint64_t nBits)
{
	// TODO: Créer un masque contenant uniquement des bits à 0 sauf pour les nBits à extraire (en tenant compte aussi de leur position).
	std::bitset<64> sonerieBinaire;
	uint64_t masque = sonerieBinaire.set().to_ullong() << (64 - nBits);
	masque = masque >> (position * nBits);
	// TODO: Appliquer un masque pour extraire les bits.
	sonnerie = sonnerie & masque;
	// TODO: Décaler les bits obtenus pour les ramener à droite (en fonction de leur position initiale).
	sonnerie = sonnerie >> (64 - ((position + 1) * nBits));
	return sonnerie;
}

/**
 * transforme un tableau de donne en des donnee binaire 
 *
 * \param [in] notes		Le tableau de notes
 *
 * \return La sonnerie sous 64 bits
 */
uint64_t convertirSerieDeNotesEnSonnerie(span<uint64_t> notes)
{
	uint64_t sonnerie = 0;
	// TODO: Ajouter la durée (nombre de notes) au début de la sonnerie.
	uint64_t duree = 0;
	for (uint64_t i : range(notes.size()))
	{
		duree +=  notes[i] > 9 ? 0 : 1;
	}
	sonnerie += duree << (64 - nBitsDuree);
	// TODO: Ajouter chaque note dans la sonnerie.
	for (uint64_t i : range(duree))
	{
		sonnerie += notes[i] << ((64 - nBitsNote) - ((i + 1) * nBitsNote));
	}
	return sonnerie;
}
/**
 * cree la sonnerie a partir des entree de l'utlisateur
 *
 * \return La sonnerie cree
 */
uint64_t creerNouvelleSonnerie()
{
	// TODO: Demande/lit de l'usager la durée de la sonnerie.
	uint64_t duree = lireValeurValide("quelle est la duree desirer de votre sonerie? ", dureeMax);

	// TODO: Allouer le tableau dynamique de notes.
	uint64_t notes[nNotes];

	// TODO: Demande/lit les notes de l'usager et les conserver dans le tableau.
	for (uint64_t i : range(duree))
	{
		notes[i] = lireValeurValide("Veuillez entrer la note desirer ", nNotes);
	}
	// TODO: Convertir les notes en une sonnerie (un entier).

	return convertirSerieDeNotesEnSonnerie(notes);
}

/**
 * Ajoute une note entree par l'utilisateur a la fin de la sonnerie
 *
 * \param [in out] sonnerie	 la sonnerie a mettre  a jour
 */

void ajouterNote(uint64_t &sonnerie)
{
	// TODO: Si le nombre maximal de notes n'est pas atteint:
	std::bitset<64> sonerieBinaire;
	sonerieBinaire = sonerieBinaire.set().to_ullong() << (64-nBitsDuree);
	if (sonnerie < sonerieBinaire.to_ullong())
	{
		// TODO: Modifier la durée de la sonnerie.
		uint64_t duree = sonnerie >> (64-nBitsDuree);
		duree += 1; 
		sonnerie += sonerieBinaire.reset().set(nBitsDuree * dureeMax, 1).to_ullong();
		// TODO: Demander/lire un note de l'usager et l'ajouter à la fin de la sonnerie.
		uint64_t note = lireValeurValide("veuillier entre la note que vous voulez rajouter: ", nNotes);
		ajouterBitsDansSonnerie(sonnerie, duree, note, nBitsNote);
	}
	else
	{
		// TODO: Sinon, afficher un message d'erreur.
		cerr << "la sonnerie a atteint la duree  maximale "
			 << "\n";
	}
}

/**
 * Retire la dernière note d'une sonnerie
 *
 * \param [in out] sonnerie	 la sonnerie a mettre a jour
 */
void enleverNote(uint64_t &sonnerie)
{
	// TODO: Si la sonnerie n'est pas vide:
	std::bitset<64> sonerieBinaire;
	if (sonnerie >= sonerieBinaire.set(nBitsDuree * dureeMax, 1).to_ullong())
	{
		// TODO: Enlever la dernière note de la sonnerie.
		uint64_t duree = obtenirBitsDeSonnerie(sonnerie, 0, nBitsDuree);
		sonnerie -= sonerieBinaire.to_ullong();
		uint64_t masque = pow(2, nBitsNote) - 1;
		masque = masque << ((64-nBitsNote)-(duree*nBitsNote));
		sonerieBinaire.reset().set();
		masque = masque ^ sonerieBinaire.to_ullong();
        sonnerie = sonnerie & masque;
	}
	else
	{
		// TODO: Sinon, afficher un message d'erreur.
		cerr << "presentement il n'y a pas de sonerie disponible "
			 << "\n";
	}
}

/**
 * modifie une note  de la sonnerie à une position choisie par l'utilisateur
 *
 * \param [in out] sonnerie	  la sonnerie a mettre a jour
 */

void modifierNote(uint64_t &sonnerie)
{
	// TODO: Si la sonnerie n'est pas vide:
	std::bitset<64> sonerieBinaire;
	if (sonnerie >= sonerieBinaire.set(nBitsDuree * dureeMax, 1).to_ullong())
	{
		// TODO: Demander/lire la position et la nouvelle valeur de la note à modifier.
		uint64_t duree = obtenirBitsDeSonnerie(sonnerie, 0, nBitsDuree);
		uint64_t position = lireValeurValide("Veuillez entrez la position a modifier", duree);
		uint64_t note = lireValeurValide("Veuillez entrer la note", nNotes);
		// TODO: Modifier la note dans la sonnerie.
		ajouterBitsDansSonnerie(sonnerie, position, note, nBitsNote);
	}
	else
	{
		// TODO: Sinon, afficher un message d'erreur.
		cerr << "La sonnerie ne possede pas de note a modifier."
			 << "\n";
	}
}

/**
 * Initialise une portee
 *
 * \param [in] nColonnes   La durée de la sonnerie 
 *
 * \return La portee initialisé
 */

Portee initialiserPortee(uint64_t nColonnes)
{
	// TODO: Créer une nouvelle portée ayant nColonnes. Le nombre de lignes de la portée est de taillePortee.
	Portee portee;
	portee.nColonnes = nColonnes;
	// TODO: Allouer le tableau dynamique de la portée.
	portee.portee = new char *[nColonnes];
	// TODO: Initialiser une ligne sur deux à des - et les autres lignes à des ' '. La portée doit contenir 5 lignes de - et 4 lignes de ' '.
	for (uint64_t i : range(nColonnes))
	{
		portee.portee[i] = new char[taillePortee];
		for (uint64_t j : range(taillePortee))
		{
			if (j % 2)
				portee.portee[i][j] = ' ';
			else
				portee.portee[i][j] = '-';
		}
	}
	return portee;
}
/**
 * Retourne la portée d'une sonnerie
 *
 * \param [in] sonnerie	   La sonnerie 
 *
 * \return La portée de la sonnerie
 */

Portee construirePortee(uint64_t sonnerie)
{
	// TODO: Initialiser la portée en fonction de la durée de la sonnerie.
	uint64_t duree = obtenirBitsDeSonnerie(sonnerie, 0, nBitsDuree);
	Portee portee = initialiserPortee(duree);

	// TODO: Extraire chaque note de la sonnerie.
	uint64_t note = 0;
	for (uint64_t i : range(duree))
	{
		note = obtenirBitsDeSonnerie(sonnerie, i + 1, nBitsNote);
		// TODO: Si la note n'est pas 0 (silence), ajouter le caractère 'o' dans la portée à la ligne correspondant à la note et à la colonne correspondant à la position de la note dans la sonnerie.
		// NOTE: La note 1 va sur la ligne du bas de la portée et 9 sur la ligne du haut.
		if (note != 0)
		{
			portee.portee[i][nNotes - (note)] = 'o';
		}
	}
	return portee;
}
/**
 * Affiche la portée a l'ecran
 *
 * \param [in] portee	 La portee a afficher
 */
void afficherPortee(Portee portee)
{
	// TODO: Afficher toutes les cases de la portée.
	for (uint64_t i : range(taillePortee))
	{
		for (uint64_t j : range(portee.nColonnes))
		{
			cout << portee.portee[j][i];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	initDebogageMemoire();
	ifstream entree;
	if (doitFaireTestsAutomatises)
	{
		entree.open("tests.txt");
		if (entree.fail())
		{
			// Ces lignes dans cette condition n'ont pas à être couvertes par les tests.
			cout << "N'a pu ouvrir le fichier tests.txt\n";
			return 1;
		}
		// Remplace cin par l'entrée du fichier.
		cin.set_rdbuf(entree.rdbuf());
	}

	// TODO: Créer une nouvelle sonnerie.
	// TODO: Afficher le menu jusqu'à ce que l'option de quitter soit choisie, et appeler la (les) bonne(s) fonction(s) pour chaque option.
	uint64_t sonnerie = creerNouvelleSonnerie();
	int option = -1;
	do
	{

		cout << "Veuillez choisir une option"
			 << "\n\n"
			 << "Menu"
			 << "\n"
			 << "1. Ajouter une note a la fin"
			 << "\n"
			 << "2. Enlever une note a la fin"
			 << "\n"
			 << "3. Modifier note"
			 << "\n"
			 << "4. Creer nouvelle sonnerie"
			 << "\n"
			 << "5. Afficher la portee"
			 << "\n"
			 << "0. Quitter"
			 << "\n";
		cin >> option;
		if (option == 1)
			ajouterNote(sonnerie);
		else if (option == 2)
			enleverNote(sonnerie);
		else if (option == 3)
			modifierNote(sonnerie);
		else if (option == 4)
			creerNouvelleSonnerie();
		else if (option == 5)
			afficherPortee(construirePortee(sonnerie));
	} while (option != 0);
}
