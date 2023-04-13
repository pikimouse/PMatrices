#include "CException.h"
#include <iostream>


	CException::CException() {
		uEXCErreur = 0;
	}

	CException::CException(unsigned int uErreur) {
		uEXCErreur = uErreur;
	}

	CException::~CException() {}
		// à supprimer 

	unsigned int CException::EXCLireErreur(void) {
		return uEXCErreur;
	}

	void CException::EXCModifierErreur(unsigned int uErreur) {
		uEXCErreur = uErreur;
	}

	void  CException::EXCAfficherErreur(unsigned int uErreur){
		Chaines chaines;
		switch (uErreur) {

			case exception_Par_Defaut:
				cout << chaines.sEXCErreur_Par_Defaut;
				break;

			case exception_Ligne_InferieurOuEgal_Zero:
				cout << chaines.sEXCLigne_InferieurOuEgal_Zero;
				break;

			case exception_Colonne_InferieurOuEgal_Zero:
				cout << chaines.sEXCColonne_InferieurOuEgal_Zero;
				break;

			case exception_Dimension_Incompatible:
				cout << chaines.sEXCDimension_Incompatible;
				break;
			
			case exception_Chemin_Vide:
				cout << chaines.sEXCChemin_Vide;
				break;

			case exception_Type_Fichier_Incompatible:
				cout << chaines.sEXCType_Fichier_Incompatible;
				break;

			case exception_Structure_Fichier_Invalid:
				cout << chaines.sEXCStructure_Fichier_Invalid;
				break;

			case exception_Syntaxe_TypeMatrice_Invalid:
				cout << chaines.sEXCSyntaxe_TypeMatrice_Invalid;
				break;

			case exception_Syntaxe_NBLignes_Invalid:
				cout << chaines.sEXCSyntaxe_NBLignes_Invalid;
				break;

			case exception_Syntaxe_NBColonnes_Invalid:
				cout << chaines.sEXCSyntaxe_NBColonnes_Invalid;
				break;

			case exception_Structure_Matrice_Invalid:
				cout << chaines.sEXCStructure_Matrice_Invalid;
				break;

			case exception_Type_Matrice_Icompatible:
				cout << chaines.sEXCType_Matrice_Icompatible;
				break;

			case exception_Dimension_NBLignes_Icompatible:
				cout << chaines.sEXCDimension_NBLignes_Icompatible;
				break;

			case exception_Dimension_NBColonnes_Icompatible:
				cout << chaines.sEXCDimension_NBColonnes_Icompatible;
				break;

		

		}
	}
