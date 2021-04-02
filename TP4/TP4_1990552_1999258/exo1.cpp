/**
* Exercice 1 – Course automobile 
* \file   exo1.cpp
* \author Jamesley Joseph 1990552 
* \author et Théophile GUEI 1999258
* \date   14 mars 2021
*/

#include <utility>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <clocale>

using namespace std;

const int NB_ANNEE = 15;
const int NB_MAX_PILOTE = 15;
const int NB_MAX_CONSTRUCTEUR = 15;

struct Contructeur
{
	string constructeur[NB_MAX_CONSTRUCTEUR];
	int nbConstructeur;
	void clear()
	{
		for (int i = 0; i < NB_ANNEE; i++)
		{
			constructeur[i] = "";
		}
		nbConstructeur = 0;
	}
};
struct AnneeChampion
{
	int anneeChampion[NB_ANNEE];
	int nbAnnee;

	void clear()
	{
		for (int i = 0; i < NB_ANNEE; i++)
		{
			anneeChampion[i] = 0;
		}
		nbAnnee = 0;
	}
};
struct Pilote
{
	string nom;
	string pays;
	int nbCourse;
	int nbVictoire;
	AnneeChampion anneesChampions;
	Contructeur constructeurs;

	void clear()
	{
		nom = "";
		pays = "";
		nbCourse = 0;
		nbVictoire = 0;
		constructeurs.clear();
		anneesChampions.clear();
	}
};

struct PiloteArray
{
	Pilote pilotes[NB_MAX_PILOTE];
	int nbPilote = 0;
	void pushBack(Pilote pilote)
	{
		pilotes[nbPilote] = pilote;
		nbPilote++;
	}
};

/**
*	Lit le fichier champion.txt et met les donner dans pilote dans un tableau de pilote 
*  \return  un struct definissant un tableau de pilote \p pilotes.
*/
PiloteArray lireFichier()
{
	PiloteArray pilotes;
	Pilote pilote;
	string chaine = "";
	stringstream anneVictoire;
	ifstream fichier("champions.txt");

	if (fichier.fail())
	{
		cout << "Ne peut pas ouvrir ce fichier!";
	}
	else
	{
		while (getline(fichier, chaine))
		{

			pilote.nom = chaine;
			getline(fichier, chaine);
			pilote.pays = chaine.substr(0, chaine.find(';'));
			chaine.erase(0, chaine.find(' ') + 1);
			pilote.nbCourse = atoi(chaine.substr(0, chaine.find(' ')).c_str());
			chaine.erase(0, chaine.find(' ') + 1);
			pilote.nbVictoire = atoi(chaine.c_str());
			getline(fichier, chaine);
			anneVictoire << chaine;

			int i = 0;
			while (anneVictoire >> pilote.anneesChampions.anneeChampion[i++])
				;
			pilote.anneesChampions.nbAnnee = i - 1;
			getline(fichier, chaine);
			int j = 0;
			for (; chaine.find(';') != string::npos; j++)
			{
				pilote.constructeurs.constructeur[j] = chaine.substr(0, chaine.find(';'));
				chaine.erase(0, chaine.find(';') + 1);
			}
			pilote.constructeurs.nbConstructeur = j;
			pilotes.pushBack(pilote);
			anneVictoire.clear();
			pilote.clear();
		}
	}
	return pilotes;
}
/**
*	Afficher la liste des champions
*  \param       pilotes  le tableau de pilote
*/
void afficherListeChampions(PiloteArray pilotes)
{

	for (int i = 0; i < pilotes.nbPilote; i++)
	{
		cout << "nom : " << pilotes.pilotes[i].nom << "\n"
			 << "Pays : " << pilotes.pilotes[i].pays << "\n"
			 << "Nombre de courses : " << pilotes.pilotes[i].nbCourse << "\n"
			 << "Nombre de victoires : " << pilotes.pilotes[i].nbVictoire << "\n";

		cout << "champion du monde en : ";
		for (int j = 0; j < pilotes.pilotes[i].anneesChampions.nbAnnee; j++)
			cout << pilotes.pilotes[i].anneesChampions.anneeChampion[j++] << ", ";
		cout << "\n";

		for (int k = 0; k < pilotes.pilotes[i].constructeurs.nbConstructeur; k++)
			cout << "Constructeurs avec lesquels il a été champion du monde : "
				 << pilotes.pilotes[i].constructeurs.constructeur[k++] << ", ";
		cout << "\n\n\n";
	}
}

/**
*	recherche les pilote pour un pays entrer en parametre  a partir d'une liste de pilotes
*  \param       pilotes			liste des pilotes
*  \param       pays			le pays des pilotes
*  \param       nbVictoire		le nombre de victoire du pays
*  \return  un tableau de pilote se trouvant dans ce pays \p nationalPilotes.
*  \return  le nombre de victoire du pays \p nbVictoirePays.
*/
PiloteArray listePilotesPays(Pilote pilotes[], string pays, int &nbVictoire)
{
	PiloteArray nationalPilote;
	int nbVictoirePays = 0;

	nationalPilote.nbPilote = 0;
	for (int i = 0; i < NB_MAX_PILOTE; i++)
	{
		if (pilotes[i].pays == pays)
		{
			nationalPilote.pushBack(pilotes[i]);
			nbVictoirePays += pilotes[i].nbVictoire;
		}
	}
	nbVictoire = nbVictoirePays;
	return nationalPilote;
}

/**
*	recherche le meilleur pilote de une liste de pilote fourni
*  \param       pilotes			La liste des pilotes
*  \return  Le nom du meilleur pilote
*/
string meilleurPilote(PiloteArray pilotes)
{
	Pilote pilote = pilotes.pilotes[1];
	for (int i = 0; i < pilotes.nbPilote; i++)
	{
		if (pilote.nbVictoire < pilotes.pilotes[i].nbVictoire)
			pilote = pilotes.pilotes[i];
	}
	return pilotes.pilotes->nom;
}

int main()
{
	setlocale(LC_ALL, "");
	int option = 0;
	do
	{
		cout << "choisisez parmis les trois option suivant "
			 << "\n\n"
			 << "1 : Afficher la liste des champions "
			 << "\n"
			 << "2 : Afficher la liste de pilotes par pays"
			 << "\n"
			 << "3 : Afficher le meilleur pilote"
			 << "\n";
		cin >> option;
	} while (option < 1 || option > 3);

	string pays = "";
	Pilote pilote[NB_MAX_PILOTE];
	PiloteArray pilotes = lireFichier();
	int nbVictoire = 0;
	switch (option)
	{
	case 1:
		afficherListeChampions(pilotes);
		break;
	case 2:
		cout << "Ecrivez le nom du pays "
			 << "\n\n";
		cin >> pays;
		cout << "\n";
		afficherListeChampions(pilotes);
		pilotes = listePilotesPays(pilotes.pilotes, pays, nbVictoire);
		cout << pays << " a " << nbVictoire << " victoires"
			 << "\n";
		break;
	case 3:
		cout << "Le meilleur pilote est: " << meilleurPilote(pilotes) << "\n";
		break;
	}
	return 0;
}