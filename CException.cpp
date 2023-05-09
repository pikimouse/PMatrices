#include "CException.h"

	/**
	* @brief Constructeur par defaut de la classe CException
	* @param
	* @return
	*/
	CException::CException() {
		uEXCException = 0;
	}

	/**
	* @brief Constructeur propre de la classe CException
	* @param
	* @return
	*/
	CException::CException(unsigned int uException) {
		uEXCException = uException;
	}

	/**
	* @fn EXCLireException
	* @brief Lit l'identifiant de l'exception levée
	* @param
	* @return l'identifiant de l'exception levée
	*/
	int CException::EXCLireException(void) const {
		return uEXCException;
	}

	/**
	* @fn EXCModifierException
	* @brief modifie l'identifiant de l'exception levée
	* @param
	* @return
	*/
	void CException::EXCModifierException(unsigned int uException) {
		uEXCException = uException;
	}

	/**
	* @fn EXCAfficherException
	* @brief affiche le message de l'exception levée
	* @param
	* @return
	*/
	void  CException::EXCAfficherException() const{
		switch (uEXCException) {
			//exception_Division_Par_Zero a ajouter
			case exceptionParDefaut:
				cerr << erreur_Par_Defaut;
				break;

			case indiceLigneNegatif:
				cerr << indice_Ligne_Negatif;
				break;

			case indiceColonneNegatif:
				cerr << indice_Colonne_Negatif;
				break;

			case indiceLigneSupNbLignes:
				cerr << indice_Ligne_Sup_NbLignes;
				break;

			case indiceColonneSupNbColonnes:
				cerr << indice_Colonne_Sup_NbColonnes;
				break;
			
			case dimMatricesIncompatible:
				cerr << dim_Matrices_Incompatible;
				break;

			case nbLignesDiffNbColonnes:
				cerr << nbLignes_Diff_NbColonnes;
				break;

			case typeValDiffTypeValMatrice:
				cerr << type_Valeur_Different_Type_Val_Matrice;
				break;

			case matriceDiviserParZero:
				cerr << matrice_Diviser_Par_Zero;
				break;

			//Exception pour la classe CAnalyseur
			case typeFichierIncompatible:
				cerr << type_Fichier_Incompatible;
				break;

			case baliseTypeMatriceIntrouvable:
				cerr << balise_Type_Matrice_Introuvable;
				break;

			case baliseNBLignesIntrouvable:
				cerr << balise_NBLignes_Introuvable;
				break;

			case baliseNBColonnesIntrouvable:
				cerr << balise_NBColonnes_Introuvable;
				break;

			case baliseDebutMatriceIntrouvable:
				cerr << balise_Debut_Matrice_Introuvable;
				break;

			case baliseFinMatriceIntrouvable:
				cerr << balise_Fin_Matrice_Introuvable;
				break;

			case typeMatricePASTypeDouble:
				cerr << type_Matrice_PAS_Type_double;
				break;

			case matriceFichierInvalid:
				cerr << matrice_Fichier_Invalid;
				break;

			case impossibleOuvrirFichier:
				cerr << impossible_Ouvrir_Fichier;
				break;

			case lignesInferieurOuEgalZero:
				cerr << lignes_Inferieur_Egal_Zero;
				break;

			case colonnesInferieurOuEgalZero:
				cerr << colonnes_Inferieur_Egal_Zero;
				break;

			case nbArgumentsInfADeux:
				cerr << nb_Arguments_Inf_A_Deux;
				break;

			case indiceHorsPlage:
				cerr << indice_hors_plage;
				break;
		}
	}
