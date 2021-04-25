#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <cassert>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <bitset>

using namespace std;
using namespace iter;
using namespace gsl;
#include <typeinfo>

int Exo1()
{
}

void f1(int &x, int y, int c[])
{
	int v[] = {21, 2, 6};
	x = 4;
	y = 5;
	cout << y << " " << c[1] << " " << x << endl;
	c[1] = ++v[1];
}
int Exo2()
{
}
int Exo3()
{
}

int Exo4()
{
}

int Exo5()
{
}

/*
int main(int argc, char *argv[])
{
	/*std::cout << "Hello world!" << std::endl;
	Exo1();
	Exo2();
	Exo3();
	Exo4();
	Exo5();
	Exo1();
  fstream fichier("entier.bin", ios::in|ios::out|ios::binary);
  // Modifier la troisième valeur du fichier.
   int valeur =33;  
   fichier.seekp(2*sizeof(valeur), ios::beg);
   // Positionnement. 
    fichier.write((char*)&valeur,sizeof(valeur));
	// Écriture.   
	fichier.close();
	cout << "La valeur actuell est :" << valeur << endl;
*/
/*int x=1; 
int y = x+1; 
int v[] ={10,10,20}; 
f1(x, y, v);
cout << v[1] << " " << y << " " << x << endl;
}
*/

/* struct Format
{
    int tab[3];
	int x =23;
};

void f2(int& x, Format c)
{
    c.tab[0]=10;
    x = 4;
    cout << x << " " << c.tab[0] << endl;
    c.tab[0] = 22;
}

int main() {
	int x =1;
    Format f;
	f.tab[0] = 111;   
    f2(f.x, f);
    cout << f.tab[0] << " " << x << endl;
}
*/

/* struct A {double a; string b; int** c;}; 
struct B {B* a; A** b; A c; short d;}; 
struct C {char a; float* b; B** c;}; 
B* a(int x){

};
B c;
C b;

int main (){
	float d = b.b[0];
	B* f =a(5); 
	A g = c.a->b[0][0];
	A* h = c.a->b[0];
	string* i =&(c.b[0]->b);
	B j= *(a(3));
	A k = a(1)->a->c; 
	string* m = new string; 
	B n = **(b.c);
	
cout << typeid(b.b[0]).name() << endl;

//cout << typeid(c.b->c).name() << endl;  X
cout << typeid(a(5)).name() << endl;
cout << typeid(c.a->b[0][0]).name() << endl;
cout << typeid(c.a->b[0]).name() << endl;
cout << typeid(&(c.b[0]->b)).name() << endl;
cout << typeid(*(a(3))).name() << endl;
cout << typeid(a(1)->a->c).name() << endl;
cout << typeid(new string).name() << endl;
cout << typeid(**(b.c)).name() << endl;
}
*/

/*int main(){
	short s = 0b1111111110101011; 
	cout << s << endl;
}
*/
const int NB_PLACE_LIBRE = 500;

struct Voyageur
{
	string nom;
	string numeroDePassport;
	int numeroDeBiliet;
};
struct VoyageurBin
{
	char nom[81]; char numeroDePassport[100]; 
	int numeroDeBiliet;
};

struct Avion
{
	Voyageur *voyageur;
	VoyageurBin *voyageurBin;
	int nPlace = 0;
};

void afficherAvion(const Avion &avion)
{

	for (int i = 0; i < avion.nPlace; i++)
	{
		cout << "le nom du passager est: " << avion.voyageur->nom << "\n"
			 << "son numero de passeport est: " << avion.voyageur->numeroDePassport << "\n"
			 << "son numero de billet est: " << avion.voyageur->numeroDeBiliet << "\n";
	}
}

int trouverVoyageur(const string &numeroDePassport, const Avion &avion)
{
	for (int i = 0; i < avion.nPlace; i++)
	{
		if (avion.voyageur->numeroDePassport == numeroDePassport)
		{
			return avion.voyageur->numeroDeBiliet;
		}
	}
	return -1;
}

void ajouterVoyageurDuFichier(istream& fichier, Avion& avion){

	fichier.read((char*)&avion.voyageurBin->nom, sizeof(avion.voyageurBin->nom));
	fichier.read((char*)&avion.voyageurBin->numeroDePassport, sizeof(avion.voyageurBin->numeroDePassport));
	fichier.read((char*)&avion.voyageurBin->numeroDeBiliet, sizeof(avion.voyageurBin->numeroDeBiliet));
}

int main(){
	std::string binary = std::bitset<32>(38).to_string(); //to binary
    std::cout<<binary<<"\n";	
}