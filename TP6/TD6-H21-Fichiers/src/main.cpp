////////////////////////////////////////////////////////////////////////////////
///     ENTETE
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

struct Portee {
	uint64_t nColonnes;
	char** portee;
};

/// Affiche un texte et lit une valuer située dans l'intervalle défini
///
/// \param [in] texte  Le texte à afficher
/// \param [in] max    La valeur maximale acceptée
///
/// \return La valeur lue
uint64_t lireValeurValide(const string& texte, uint64_t max) {
	while (true) {
		cout << texte << " (0-" << max << "): ";
		uint64_t valeur;
		cin >> valeur;
		if (doitFaireTestsAutomatises) {
			if (cin.fail())
				cout << "?" << endl;
			else
				cout << valeur << endl;
		}
		if (!cin.fail() && (valeur >= 0 && valeur <= max)) {
			return valeur;
		}
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.eof()) {
			// Ces lignes dans cette condition n'ont pas à être couvertes par les tests.
			cout << "Erreur sur cin irrecuperable, il a ete interrompu.\n";
			exit(1);
		}
		cout << "Erreur! ";
	}
}



void ajouterBitsDansSonnerie(uint64_t& sonnerie, uint64_t position, uint64_t bits, uint64_t nBits) {
	// TODO: Créer un masque contenant uniquement des bits à 0 sauf pour les nBits à écrire (en tenant compte aussi de leur position).
	uint64_t masque = pow(2, nBits) - 1;
	masque = masque << ((64 - nBits) - (position * nBits));
	// TODO: Inverser le masque pour avoir uniquement des bits à 1 sauf pour les nBits à écrire.
	masque = masque ^ 0xffffffffffffffff;
	// TODO: Appliquer le masque pour que la sonnerie garde le même contenu sauf pour les nBits à écrire qui sont maintenant à 0.
	sonnerie = sonnerie & masque;
	// TODO: Décaler les bits à écrire pour qu'ils soient à la bonne position dans la sonnerie.
	bits = bits << ((64 - nBits) - (position * nBits));
	// TODO: Combiner les bits à la sonnerie pour les ajouter.
	sonnerie += bits;
}

uint64_t obtenirBitsDeSonnerie(uint64_t sonnerie, uint64_t position, uint64_t nBits) {
	// TODO: Créer un masque contenant uniquement des bits à 0 sauf pour les nBits à extraire (en tenant compte aussi de leur position).
	uint64_t masque = 0xfffffffffffffff << (64 - nBits);
	masque = masque >> (position * nBits);
	// TODO: Appliquer un masque pour extraire les bits.
	sonnerie = sonnerie & masque;
	// TODO: Décaler les bits obtenus pour les ramener à droite (en fonction de leur position initiale).
	return sonnerie = sonnerie >> (64 - ((position + 1) * nBits));
}

uint64_t convertirSerieDeNotesEnSonnerie(span<uint64_t> notes) {
	uint64_t sonnerie = 0;
	// TODO: Ajouter la durée (nombre de notes) au début de la sonnerie.
	sonnerie += dureeMax << ((64 - nBitsDuree) - (0 * nBitsDuree));
	// TODO: Ajouter chaque note dans la sonnerie.
	for (uint64_t i : range(notes.size())) {
		sonnerie += notes[i] << ((64 - nBitsNote) - (i+1 * nBitsNote));
	}
	return sonnerie;
}

uint64_t creerNouvelleSonnerie() {
	// TODO: Demande/lit de l'usager la durée de la sonnerie.
	uint64_t duree = lireValeurValide("a modififier", dureeMax);

	// TODO: Allouer le tableau dynamique de notes.
	uint64_t notes[dureeMax];

	// TODO: Demande/lit les notes de l'usager et les conserver dans le tableau.
	for (uint64_t i : range(duree)) {
		notes[i] = lireValeurValide("Veuillez entrer la note", nNotes);
	}
	// TODO: Convertir les notes en une sonnerie (un entier).
	return convertirSerieDeNotesEnSonnerie(notes);
}

void ajouterNote(uint64_t& sonnerie) {
	// TODO: Si le nombre maximal de notes n'est pas atteint:
	if (sonnerie < 0xf00000000000000) {
		// TODO: Modifier la durée de la sonnerie.
		uint64_t duree = sonnerie >> nNotes * nBitsNote;
		sonnerie += 0x100000000000000;
		// TODO: Demander/lire un note de l'usager et l'ajouter à la fin de la sonnerie.
		uint64_t note = lireValeurValide("a modifier", nNotes);

	}
	else {
		// TODO: Sinon, afficher un message d'erreur.
	}

}

void enleverNote(uint64_t& sonnerie) {
	// TODO: Si la sonnerie n'est pas vide:
	if (sonnerie >= 0x1000000000000000) {

		// TODO: Enlever la dernière note de la sonnerie.
	}
	else{
	// TODO: Sinon, afficher un message d'erreur.
	}
}

void modifierNote(uint64_t& sonnerie) {
	// TODO: Si la sonnerie n'est pas vide:
	if (sonnerie >= 0x100000000000000) {
		// TODO: Demander/lire la position et la nouvelle valeur de la note à modifier.
		uint64_t duree = obtenirBitsDeSonnerie(sonnerie, 0, nBitsDuree);
		uint64_t position = lireValeurValide("Veuillez entrez la position a modifier", duree);
		uint64_t note = lireValeurValide("Veuillez entrer la note", nNotes);
		// TODO: Modifier la note dans la sonnerie.
		ajouterBitsDansSonnerie(sonnerie, position, note, nBitsNote);
	}
	else {
		// TODO: Sinon, afficher un message d'erreur.
		cerr << "La sonnerie ne possede pas de note a modifier." << endl;

	}
}

Portee initialiserPortee(uint64_t nColonnes) {
	// TODO: Créer une nouvelle portée ayant nColonnes. Le nombre de lignes de la portée est de taillePortee.
	Portee portee;
	portee.nColonnes = nColonnes;
	// TODO: Allouer le tableau dynamique de la portée.
	portee.portee = new char* [nColonnes];
	// TODO: Initialiser une ligne sur deux à des - et les autres lignes à des ' '. La portée doit contenir 5 lignes de - et 4 lignes de ' '.
	for (uint64_t i : range(nColonnes)) {
		portee.portee[i] = new char[taillePortee];
		for (uint64_t j : range(taillePortee)) {
			if (j % 2)
				portee.portee[i][j] = ' ';
			else
				portee.portee[i][j] = '-';
		}
	}
	return portee;
}

Portee construirePortee(uint64_t sonnerie) {
	// TODO: Initialiser la portée en fonction de la durée de la sonnerie.
	uint64_t duree = obtenirBitsDeSonnerie(sonnerie, 0, nBitsDuree);
	Portee portee = initialiserPortee(duree);

	// TODO: Extraire chaque note de la sonnerie.
	uint64_t note = 0;
	for (uint64_t i : range(duree)) {
		note = obtenirBitsDeSonnerie(sonnerie, i + 1, nBitsNote);
		// TODO: Si la note n'est pas 0 (silence), ajouter le caractère 'o' dans la portée à la ligne correspondant à la note et à la colonne correspondant à la position de la note dans la sonnerie.
		// NOTE: La note 1 va sur la ligne du bas de la portée et 9 sur la ligne du haut.
		if (note != 0) {
			portee.portee[i][nNotes - (note)] = 'o';
		}
	}
	return portee;
}

void afficherPortee(Portee portee) {
	// TODO: Afficher toutes les cases de la portée.
	for (uint64_t i : range(taillePortee)) {
		for (uint64_t j : range(portee.nColonnes)) {
			cout << portee.portee[j][i];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	initDebogageMemoire();
	ifstream entree;
	if (doitFaireTestsAutomatises) {
		entree.open("tests.txt");
		if (entree.fail()) {
			// Ces lignes dans cette condition n'ont pas à être couvertes par les tests.
			cout << "N'a pu ouvrir le fichier tests.txt\n";
			return 1;
		}
		// Remplace cin par l'entrée du fichier.
		entree.set_rdbuf(entree.rdbuf());
	}

	// TODO: Créer une nouvelle sonnerie.
	// TODO: Afficher le menu jusqu'à ce que l'option de quitter soit choisie, et appeler la (les) bonne(s) fonction(s) pour chaque option.
	uint64_t sonnerie = creerNouvelleSonnerie();
	int option = 0;
	do {
		cout << "Veuillez choisir une option" << endl
			<< "1. Ajouter une note a la fin" << endl
			<< "2. Enlever une note a la fin" << endl
			<< "3. Modifier note" << endl
			<< "4. Creer nouvelle sonnerie" << endl
			<< "5. Afficher la portee" << endl;
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
	} while (option != -1);
}
