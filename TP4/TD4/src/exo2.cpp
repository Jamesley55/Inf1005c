	
/**
* Exercice 2 – Tableaux de nombres
* \file   exo2.cpp
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

using namespace std;

const int NB_MAX_COLONNE = 8;

struct Comparateur
{
	int nbPlusPetit;
	int nbEgaux;
	int nbPlusGrand;
};

/**
* cherche un valeur aleatoire entre un borne minimal et maximal.
*  \param       minimun  la borne minimale
*  \param 		maximum  la borne maximal
*  \return  	Valeur aleatoire comprise dans l'intervale.
*/
int valeurAleatoire(int minimum, int maximum)
{
	int valeurAleatoire = 0;
	valeurAleatoire = rand() % (maximum + 1 - minimum) + minimum;
	return valeurAleatoire;
}

/**
*  cree  un tableau a une dimensions de valeurs aleatoires comprises entre 2 bornes predefini.
*  \param       minimun  	la borne minimale
*  \param 		maximum  	la borne maximal
*  \param	    tableau		Tableau a une dimensions.
*  \param       taille		la taille du tableau 
*/
void tableauAleatoire(int minimum, int maximum, int tableau[], int taille)
{
	int i = 0;
	while (i < taille)
		tableau[i++] = valeurAleatoire(minimum, maximum);
}

/**
*  cree  un tableau a deux dimensions de valeurs aleatoires comprises entre 2 bornes predefini.
*  \param       minimun  	la borne minimale
*  \param 		maximum  	la borne maximal
*  \param	    tableau		Tableau a deux dimensions.
*  \param       taille		la taille du tableau 
*/
void tableauDeuxDimensionsAleatoire(int minimum, int maximum, int tableau[][NB_MAX_COLONNE], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < NB_MAX_COLONNE; j++)
		{
			tableau[i][j] = valeurAleatoire(minimum, maximum);
		}
	}
}

/**
*  Compare une entree avec les donner dun tableau a deux dimensions
*  \param       entier		entier a comparer .
*  \param       taille		la taille du tableau 
*  \param       tableau		Tableau a deux dimensions.
*  \return		Comparateur	structeur contenant le nombre delement plus petit, plus grand et egal a l'entier a comparer
*/
Comparateur trouverNombre(int entier, int taille, int tableau[][NB_MAX_COLONNE])
{

	int nbPlusPetit = 0;
	int nbEgaux = 0;
	int nbPlusGrand = 0;
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < NB_MAX_COLONNE; j++)
		{
			if (tableau[i][j] < entier)
				nbPlusPetit++;
			else if (tableau[i][j] == entier)
				nbEgaux++;
			else
				nbPlusGrand++;
		}
	}

	Comparateur nombres;
	nombres.nbPlusPetit = nbPlusPetit;
	nombres.nbEgaux = nbEgaux;
	nombres.nbPlusGrand = nbPlusGrand;
	return nombres;
}

/**
*  Verifie si un tableau A est inclut dans un tableau B
*  \param       tableauA				Premier tableau a une dimension.
*  \param       tailleTableauA			taille du tableau A
*  \param		tableauB				Deuxieme tableau a une dimension.
*  \param       tailleB					taille du tableau B.
*  \return		indice					retourne l'indice a partir duquel  le tableau A est inclut dans B sinon retourne -1
*/
int bIncludeA(int tableauA[], int tailleTableauA, int tableauB[], int tailleTableauB)
{
	int indice = -1;
	bool isInclude = true;
	for (int i = 0; i < tailleTableauB; i++)
	{
		for (int j = 0; j < tailleTableauA; j++)
		{
			if (tableauB[i + j] != tableauA[j])
			{
				isInclude = false;
			}
		}
		if (isInclude == true)
		{
			indice = i;
		}
		isInclude = true;
	}

	return indice;
}
int Exo2()
{

	srand(time(0));
	int minimum;
	cout << "Veuillez entrer un minimum \n";
	cin >> minimum;
	int maximum;
	cout << "Veuillez entrer un maximum \n";
	cin >> maximum;

	int aleatoire = valeurAleatoire(minimum, maximum);
	cout << "le nombre aleatoire entre la borne mimumum et maximum trouve est : " << aleatoire << "\n\n";
	int tableauUneDimension[aleatoire];
	tableauAleatoire(minimum, maximum, tableauUneDimension, aleatoire);
	cout << "le donnes du tableau a une dimension et au valeur aletoire sont:  \n";
	for (int i = 0; i < aleatoire; i++)
		cout << tableauUneDimension[i] << " ";
	cout << "\n\n";

	int tableauDeuxDimension[aleatoire][NB_MAX_COLONNE];
	tableauDeuxDimensionsAleatoire(minimum, maximum, tableauDeuxDimension, aleatoire);
	cout << "le donnes du tableau a deux dimension et au valeur aletoire sont:  \n";
	for (int i = 0; i < aleatoire; i++)
	{
		for (int j = 0; j < NB_MAX_COLONNE; j++)
			cout << tableauDeuxDimension[i][j] << " ";
		cout << "\n";
	}

	cout << "Veuillez choisir le nombre entier a comparer"
		 << "\n";
	int entier;
	cin >> entier;
	Comparateur nombres = trouverNombre(entier, aleatoire, tableauDeuxDimension);
	cout << nombres.nbPlusGrand << " nombres  sont superieurs a " << entier << "\n";
	cout << nombres.nbPlusPetit << " nombres sont inferieurs a " << entier << "\n";
	cout << nombres.nbEgaux << "  nombres sont egaux a " << entier << "\n";

	int tailleTableauA = valeurAleatoire(minimum, maximum);
	int tailleTableauB = valeurAleatoire(minimum, maximum);
	int tableauA[tailleTableauA];
	int tableauB[tailleTableauB];
	tableauAleatoire(minimum, maximum, tableauA, tailleTableauA);
	tableauAleatoire(minimum, maximum, tableauB, tailleTableauB);

	cout << "tableau A :  \n";
	for (int i = 0; i < tailleTableauA; i++)
		cout << tableauA[i] << " ";
	cout << "\n";

	cout << "tableau B:  \n";
	for (int i = 0; i < tailleTableauB; i++)
		cout << tableauB[i] << " ";
	cout << "\n";

	int indice = bIncludeA(tableauA, tailleTableauA, tableauB, tailleTableauB);
	indice != -1 ? cout << "Le tableau A est inclut dans le tableau B a partir de l'indice " << indice << "\n" : cout << "Le tableau A n'est pas inclut dans le tableau B \n";
	return 0;
}