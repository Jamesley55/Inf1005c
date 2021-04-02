////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
////////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <fstream>
#include <string>

#include "CodeFourni.hpp"


using namespace std;

#pragma endregion //}




#pragma region "Déclarations" //{

#pragma region "Globaux" //{

Image lireImage ( const string& nomFichier, bool& ok );
ImageDecomposee decomposerImage(const Image& image, const int hauteurMorceaux, const int largeurMorceaux);
ImageDecomposee melangerImage(ImageDecomposee imageDecomposee) ;
void desallouerImage ( Image& image );
Image recomposerImage(const ImageDecomposee imageDecomposee);
void ecrireImage ( const string& nomFichier, const Image& image, bool& ok );
#pragma endregion //}

#pragma endregion //}

