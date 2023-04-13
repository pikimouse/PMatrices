#pragma once
#include <string>

using namespace std;
class Chaines
{
public:
	/* CMatrice */

	const string sEXCErreur_Par_Defaut = "Erreur Par Défaut";
	const string sEXCLigne_InferieurOuEgal_Zero = "La matrice doit avoir au moins une ligne";
	const string sEXCColonne_InferieurOuEgal_Zero = "La matrice doit avoir au moins une colonne";
	const string sEXCDimension_Incompatible = "La dimension des matrices saisie est incompatible. Impossible d'utiliser des opérateurs entre ces matrices";

	/* CParser */
	const string sEXCChemin_Vide = "Le chemin des fichiers contenant les matrices est nécessaire pour charger les matrices";
	const string sEXCType_Fichier_Incompatible = "Les fichiers saisies ne correspondent pas aux types de fichiers compatible au programme (.txt)";
	const string sEXCStructure_Fichier_Invalid = "La structure du fichier insérer n'est pas celle attendue";
	const string sEXCSyntaxe_TypeMatrice_Invalid = "Le type de la matrice saisie dans le fichier est invalid";
	const string sEXCSyntaxe_NBLignes_Invalid = "Le nombre de ligne saisie dans le fichier est invalid";
	const string sEXCSyntaxe_NBColonnes_Invalid = "Le nombre de colonne saisie dans le fichier est invalid";
	const string sEXCStructure_Matrice_Invalid = "La structure de la matrice insérer n'est pas celle attendue";
	const string sEXCType_Matrice_Icompatible = "Le type des valeurs saisies dans la matrice n'est pas compatible avec le type de la matrice déclaré";
	const string sEXCDimension_NBLignes_Icompatible = "Le nombre de ligne saisies dans la matrice n'est pas compatible avec le nombre de ligne déclaré";
	const string sEXCDimension_NBColonnes_Icompatible = "Le nombre de ligne saisies dans la matrice n'est pas compatible avec le nombre de ligne déclaré";
};

