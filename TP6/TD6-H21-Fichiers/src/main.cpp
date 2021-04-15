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

const bool doitFaireTestsAutomatises = false;
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

	// TODO: Inverser le masque pour avoir uniquement des bits à 1 sauf pour les nBits à écrire.

	// TODO: Appliquer le masque pour que la sonnerie garde le même contenu sauf pour les nBits à écrire qui sont maintenant à 0.

	// TODO: Décaler les bits à écrire pour qu'ils soient à la bonne position dans la sonnerie.

	// TODO: Combiner les bits à la sonnerie pour les ajouter.
}

uint64_t obtenirBitsDeSonnerie(uint64_t sonnerie, uint64_t position, uint64_t nBits) {
	// TODO: Créer un masque contenant uniquement des bits à 0 sauf pour les nBits à extraire (en tenant compte aussi de leur position).

	// TODO: Appliquer un masque pour extraire les bits.

	// TODO: Décaler les bits obtenus pour les ramener à droite (en fonction de leur position initiale).
	return {};
}

uint64_t convertirSerieDeNotesEnSonnerie(span<uint64_t> notes) {
	uint64_t sonnerie = 0;
	// TODO: Ajouter la durée (nombre de notes) au début de la sonnerie.

	// TODO: Ajouter chaque note dans la sonnerie.
	return {};
}

uint64_t creerNouvelleSonnerie() {
	// TODO: Demande/lit de l'usager la durée de la sonnerie.

	// TODO: Allouer le tableau dynamique de notes.

	// TODO: Demande/lit les notes de l'usager et les conserver dans le tableau.

	// TODO: Convertir les notes en une sonnerie (un entier).
	return {};
}

void ajouterNote(uint64_t& sonnerie) {
	// TODO: Si le nombre maximal de notes n'est pas atteint:
	// TODO: Modifier la durée de la sonnerie.
	// TODO: Demander/lire un note de l'usager et l'ajouter à la fin de la sonnerie.

	// TODO: Sinon, afficher un message d'erreur.
}

void enleverNote(uint64_t& sonnerie) {
	// TODO: Si la sonnerie n'est pas vide:
	// TODO: Enlever la dernière note de la sonnerie.

	// TODO: Sinon, afficher un message d'erreur.
}

void modifierNote(uint64_t& sonnerie) {
	// TODO: Si la sonnerie n'est pas vide:
	// TODO: Demander/lire la position et la nouvelle valeur de la note à modifier.
	// TODO: Modifier la note dans la sonnerie.

	// TODO: Sinon, afficher un message d'erreur.
}

Portee initialiserPortee(uint64_t nColonnes) {
	// TODO: Créer une nouvelle portée ayant nColonnes. Le nombre de lignes de la portée est de taillePortee.
	// TODO: Allouer le tableau dynamique de la portée.
	// TODO: Initialiser une ligne sur deux à des - et les autres lignes à des ' '. La portée doit contenir 5 lignes de - et 4 lignes de ' '.
	return {};
}

Portee construirePortee(uint64_t sonnerie) {
	// TODO: Initialiser la portée en fonction de la durée de la sonnerie.
	// TODO: Extraire chaque note de la sonnerie.
	// TODO: Si la note n'est pas 0 (silence), ajouter le caractère 'o' dans la portée à la ligne correspondant à la note et à la colonne correspondant à la position de la note dans la sonnerie.
	// NOTE: La note 1 va sur la ligne du bas de la portée et 9 sur la ligne du haut.
	return {};
}

void afficherPortee(Portee portee) {
	// TODO: Afficher toutes les cases de la portée.
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
		cin.set_rdbuf(entree.rdbuf());
	}

	// TODO: Créer une nouvelle sonnerie.
	// TODO: Afficher le menu jusqu'à ce que l'option de quitter soit choisie, et appeler la (les) bonne(s) fonction(s) pour chaque option.
}
