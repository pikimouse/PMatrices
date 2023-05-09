#include "CMatrice.h"

using namespace std;

/**
* @brief Constructeur par defaut de la classe CMatrice
* @param
* @return
*/
template<typename MATT>
CMatrice<MATT>::CMatrice() {
	iMATNbColonnes = 0;
	iMATNbLignes = 0;
	oMATDonnees = nullptr;
}

/**
* @brief Constructeur de confort de la classe CMatrice
* @param entier naturel nombre de lignes et nombres de colonnes
* @return
*/
template<typename MATT>
CMatrice<MATT>::CMatrice(int iMATNbLignes, int iMATNbColonnes)
	: iMATNbLignes(iMATNbLignes), iMATNbColonnes(iMATNbColonnes)
{
	oMATDonnees = new MATT * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new MATT[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			oMATDonnees[i][j] = 0;
		}
	}
}

/**
* @brief Constructeur de recopie de la classe CMatrice
* @param MATarg objet de la classe CMatrice
* @return
*/
template<typename MATT>
CMatrice<MATT>::CMatrice(const CMatrice<MATT>& MATarg)
{
	//Copie des dimension
	iMATNbLignes = MATarg.iMATNbLignes;
	iMATNbColonnes = MATarg.iMATNbColonnes;

	oMATDonnees = new MATT * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new MATT[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			//Recopie des elements d'une matrice dans une autres
			oMATDonnees[i][j] = MATarg.oMATDonnees[i][j];
		}
	}
}

/**
* @brief Destructeur de la classe CMatrice : Il a pour charge de desallouer le pointeur oMATDonnees
* @param
* @pre
* @return
*/
template<typename MATT>
CMatrice<MATT>::~CMatrice()
{
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		delete[] oMATDonnees[i];
	}
	delete[] oMATDonnees;
}

/**
* @fn transposer()
* @brief Fonction pour calculer la transposer d'une matrice
* @param
* @return Un objet de la classe CMatrice
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::MATtransposer() const
{
	// Creation de la matrice pour stocker le resultat du transposer des matrices
	CMatrice<MATT> result(iMATNbColonnes, iMATNbLignes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[j][i] = oMATDonnees[i][j];
		}
	}
	return result;
}

/**
* @fn operator=
* @brief Surcharge de l'operateur= qui sert a realiser une affectation entre deux matrices
* @param Objet de la classe CMatrice
* @return Reference de l'objet en cours
*/
template<typename MATT>
CMatrice<MATT>& CMatrice<MATT>::operator=(const CMatrice<MATT>& MATarg)
{
	if (this == &MATarg) // Verification de l'auto-affectation
	{
		return *this;
	}

	// Copie des dimensions
	iMATNbLignes = MATarg.iMATNbLignes;
	iMATNbColonnes = MATarg.iMATNbColonnes;

	// Reallocation et copie des elements
	oMATDonnees = new MATT * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new MATT[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			oMATDonnees[i][j] = MATarg.oMATDonnees[i][j];
		}
	}

	return *this;
}

/**
* @fn operator*
* @brief Surcharge de l'operateur* qui calcul la multiplication de deux matrices
* @param Objet de la classe CMatrice
* @return Le resultat de la multiplication des deux matrices
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::operator*(const CMatrice<MATT>& MATarg) const
{
	if (iMATNbLignes != MATarg.iMATNbColonnes) {
		// exception nombre de lignes different du nombre de colonnes
		throw (CException(nbLignesDiffNbColonnes));
	}
	// Creation de la matrice pour stocker le resultat du produit des matrices
	CMatrice<MATT> result(iMATNbLignes, MATarg.iMATNbColonnes);

	// Boucle sur les lignes de la matrice
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		//Boucle sur les colonnes de la matrice
		for (int j = 0; j < MATarg.iMATNbColonnes; ++j)
		{
			// Initialisation des valeur de la matrice a 0
			result.oMATDonnees[i][j] = 0;
			//Une nouvelle boucle sur les colonnes de la matrice pour realiser la multiplication de deux matrice Ligne * colonne
			for (int k = 0; k < iMATNbColonnes; ++k)
			{
				result.oMATDonnees[i][j] += oMATDonnees[i][k] * MATarg.oMATDonnees[k][j];
			}
		}
	}
	return result;
}

/**
* @fn operator*
* @brief Surcharge de l'operateur* qui calcul le produit d'une matrice avec une constance
* @param Constante reelle
* @return Resultat de la multiplication
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::operator*(const double c) const
{
	CMatrice<MATT> result(iMATNbLignes, iMATNbColonnes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = c * oMATDonnees[i][j];
		}
	}
	return result;
}

/**
* @fn operator+
* @brief Surcharge de l'operateur+ qui sert a additioner de deux matrices
* @param Objet de la classe CMatrice
* @return Resultat de l'addition des des deux matrices
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::operator+(const CMatrice<MATT>& MATarg) const
{
	// Verification des dimensions des deux matrices
	if (iMATNbLignes != MATarg.iMATNbLignes || iMATNbColonnes != MATarg.iMATNbColonnes)
	{
		//Exception : Les matrices ont des dimensions differentes
		throw(CException(dimMatricesIncompatible));
	}

	// Creation d'une nouvelle matrice pour stocker le resultat
	CMatrice<MATT> result(iMATNbLignes, iMATNbColonnes);

	// Addition des elements correspondants des deux matrices
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] + MATarg.oMATDonnees[i][j];
		}
	}

	return result;
}

/**
* @fn operator-
* @brief Surcharge de l'operateur- qui sert a la soustraction de deux matrices
* @param Objet de la classe CMatrice
* @return Resultat de la soustraction des des deux matrices
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::operator-(const CMatrice<MATT>& arg) const
{
	// Verification des dimensions des deux matrices
	if (iMATNbLignes != arg.iMATNbLignes || iMATNbColonnes != arg.iMATNbColonnes)
	{
		//Exception : Les matrices ont des dimensions differentes
		throw(CException(dimMatricesIncompatible));
	}

	// Creation d'une nouvelle matrice pour stocker le resultat
	CMatrice<MATT> result(iMATNbLignes, iMATNbColonnes);

	// Soustraction des elements correspondants des deux matrices
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] - arg.oMATDonnees[i][j];
		}
	}

	return result;
}

/**
* @fn operator/
* @brief Surcharge de l'operateur/ qui sert a divier une matrice par une constante
* @param Constante reelle
* @return Resultat de la division
*/
template<typename MATT>
CMatrice<MATT> CMatrice<MATT>::operator/(const double c) const
{
	// Exception si l'utilisateur saisi la valeur Zero
	if (c == 0)
		throw CException(matriceDiviserParZero);

	// Division de chaque valeur dans la matrice par la constante saisi par l'utilisateur
	CMatrice<MATT> result(iMATNbLignes, iMATNbColonnes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] / c;
		}
	}
	return result;
}

/**
* @fn operator<<
* @brief Surcharge de l'operateur<< qui sert a afficher une matrice
* @param Objet de sortie
* @param Objet de la classe CMatrice
* @return Affiche la matrice en sortie
*/
template<typename MATT>
std::ostream& operator<<(std::ostream& out, const CMatrice<MATT>& MATarg)
{
	for (int i = 0; i < MATarg.iMATNbLignes; i++)
	{
		for (int j = 0; j < MATarg.iMATNbColonnes; j++)
		{
			out << MATarg.oMATDonnees[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

/**
* @fn MATLireNbLignes
* @brief Affichage du nombre de ligne de la matrice
* @param
* @return Nombre de lignes de la matrice
*/
template<typename MATT>
int CMatrice<MATT>::MATLireNbLignes()
{
	return iMATNbLignes;
}

/**
* @fn MATLireNbColonnes
* @brief Affichage du nombre de colonnes de la matrice
* @param
* @return Nombre de colonnes de la matrice
*/
template<typename MATT>
int CMatrice<MATT> ::MATLireNbColonnes()
{
	return iMATNbColonnes;
}

/**
* @fn MATModifierElement
* @brief Modifier la valeur du coefficient d'une matrice
* @param Indice de ligne
* @param Indice de colonne
* @param Nouvelle valeur
* @return
*/
template<typename MATT>
void CMatrice<MATT>::MATModifierElement(int i, int j, MATT val) {
	//// Verification des indices
	if (i < 0) {
		//exception indice ligne negative
		throw(CException(indiceLigneNegatif));
	}
	else if (j < 0) {
		//exception indice colonne negative
		throw(CException(indiceColonneNegatif));
	}
	else if (i > iMATNbLignes) {
		//exception indice ligne superieur aux nombres de lignes existants dans la matrice cree
		throw (CException(indiceLigneSupNbLignes));
	}
	else if (j > iMATNbColonnes) {
		//exception indice coolonne superieur aux nombres de colonnes existants dans la matrice cree
		throw (CException(indiceColonneSupNbColonnes));
	}

	oMATDonnees[i][j] = val;
}

/**
* @fn MATAfficherElement
* @brief Afficher la valeur du coefficient d'une matrice
* @param Indice de ligne
* @param Indice de colonne
* @return Valeur demandee
*/
template <typename MATT>
MATT CMatrice<MATT>::MATAfficherElement(int i, int j) const {
	//// Verification des indices
	if (i < 0) {
		//exception indice ligne negative
		throw(CException(indiceLigneNegatif));
	}
	else if (j < 0) {
		//exception indice colonne negative
		throw(CException(indiceColonneNegatif));
	}
	else if (i > iMATNbLignes) {
		//exception indice ligne superieur aux nombres de lignes existants dans la matrice cree
		throw (CException(indiceLigneSupNbLignes));
	}
	else if (j > iMATNbColonnes) {
		//exception indice coolonne superieur aux nombres de colonnes existants dans la matrice cree
		throw (CException(indiceColonneSupNbColonnes));
	}

	return oMATDonnees[i][j];
}




