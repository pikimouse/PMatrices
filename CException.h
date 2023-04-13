#pragma once

#include <string>
#include "Chaines.h"
using namespace std;

#define exception_Par_Defaut 0
#define exception_Ligne_InferieurOuEgal_Zero 1
#define exception_Colonne_InferieurOuEgal_Zero 2
#define exception_Dimension_Incompatible 3
#define exception_Chemin_Vide 4
#define exception_Type_Fichier_Incompatible 5
#define exception_Structure_Fichier_Invalid 6
#define exception_Syntaxe_TypeMatrice_Invalid 7
#define exception_Syntaxe_NBLignes_Invalid 8
#define exception_Syntaxe_NBColonnes_Invalid 9
#define exception_Structure_Matrice_Invalid 10
#define exception_Type_Matrice_Icompatible 11
#define exception_Dimension_NBLignes_Icompatible 12
#define exception_Dimension_NBColonnes_Icompatible 13

class CException
{
private :
	unsigned int uEXCErreur;
	string sEXCMessage;

public :
	CException();

	CException(unsigned int uErreur);

	~CException();

	unsigned int EXCLireErreur(void);

	void EXCModifierErreur(unsigned int uErreur);

	void EXCAfficherErreur(unsigned int uErreur);

};

