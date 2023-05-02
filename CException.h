#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H
#include <iostream>

#define exceptionParDefaut 0

// les valeurs definit pour les exceptions levees par la classe CMatrice
#define indiceLigneNegatif 1
#define indiceColonneNegatif 2
#define indiceLigneSupNbLignes 3
#define indiceColonneSupNbColonnes 4
#define dimMatricesIncompatible 5
#define nbLignesDiffNbColonnes 6
#define typeValDiffTypeValMatrice 8
#define matriceDiviserParZero 9

// les valeurs definit pour les exceptions levees par la classe CAnalyseur
#define typeFichierIncompatible 20
#define baliseTypeMatriceIntrouvable 21
#define baliseNBLignesIntrouvable 22
#define baliseNBColonnesIntrouvable 23
#define baliseDebutMatriceIntrouvable 24
#define baliseFinMatriceIntrouvable 25
#define typeMatricePASTypeDouble 26
#define matriceFichierInvalid 27
#define impossibleOuvrirFichier 28
#define lignesInferieurOuEgalZero 29
#define colonnesInferieurOuEgalZero 30

#define nbArgumentsInfADeux 31

//Les messages definit pour les exceptions levees par la classe CMatrice
#define erreur_Par_Defaut "Erreur Par Defaut"
#define indice_Ligne_Negatif "L'indice ligne saisi est negatif"
#define indice_Colonne_Negatif "L'indice colonne saisi est negatif"
#define indice_Ligne_Sup_NbLignes "L'indice ligne saisi pour est superieur au nombre de lignes de la matrice"
#define indice_Colonne_Sup_NbColonnes "L'indice colonne saisi est superieur au nombre de colonnes de la matrice"
#define dim_Matrices_Incompatible "Les dimensions des matrices ne sont pas les memes"
#define nbLignes_Diff_NbColonnes "Le nombre de lignes saisi est different du nombre de lignes de la matrice"
#define type_Valeur_Different_Type_Val_Matrice "Le type de la valeur est different de celle a modifier"
#define matrice_Diviser_Par_Zero "Impossible de diviser une matrice par zero"

//Les messages definit pour les exceptions levees par la classe CAnalyseur
#define type_Fichier_Incompatible "L'un des fichiers saisi n'est pas un fichier texte"
#define balise_Type_Matrice_Introuvable "La balise 'TypeMatrice=' est introuvable dans l'un des fichiers saisi"
#define balise_NBLignes_Introuvable "La balise NBLignes= est introuvable dans l'un des fichiers saisi"
#define balise_NBColonnes_Introuvable "La balise NBColonnes= est introuvable dans l'un des fichiers saisi"
#define balise_Debut_Matrice_Introuvable "La balise '[' est introuvable dans l'un des fichiers saisi"
#define balise_Fin_Matrice_Introuvable "La balise ']' est introuvable dans l'un des fichiers saisi"
#define matrice_Fichier_Invalid "La matrice de l'un des fichiers saisi est invalid"
#define impossible_Ouvrir_Fichier "Impossible d'ouvrir l'un des fichiers saisi"
#define lignes_Inferieur_Egal_Zero "Le nombre de lignes saisi dans l'un des fichiers est inferieur ou egal a zero"
#define colonnes_Inferieur_Egal_Zero "Le nombre de colonnes saisi dans l'un des fichiers est inferieur ou egal a zero"
#define type_Matrice_PAS_Type_double "Le type definit dans l'un des fichiers saisi n'est pas de type double"

#define nb_Arguments_Inf_A_Deux " Veuillez saisir au moins deux noms de fichiers pour pouvoir faire des calcul"

using namespace std;

class CException
{
private :
	unsigned int uEXCException;

public :
	CException();

	CException(unsigned int uErreur);

	int EXCLireException(void) const;

	void EXCModifierException(unsigned int uErreur);

	void EXCAfficherException() const;

};

#endif