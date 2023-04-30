#include "CMatrice.h"

using namespace std;

template<typename T>
CMatrice<T>::CMatrice() {
	iMATNbColonnes = 0;
	iMATNbLignes = 0;
	oMATDonnees = NULL;
}

template<typename T>
CMatrice<T>::CMatrice(int iMATNbLignes, int iMATNbColonnes)
	: iMATNbLignes(iMATNbLignes), iMATNbColonnes(iMATNbColonnes)
{
	oMATDonnees = new T * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new T[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			oMATDonnees[i][j] = 0;
		}
	}
}

template<typename T>
CMatrice<T>::CMatrice(const CMatrice<T>& other)
{
	iMATNbLignes = other.iMATNbLignes;
	iMATNbColonnes = other.iMATNbColonnes;

	oMATDonnees = new T * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new T[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			oMATDonnees[i][j] = other.oMATDonnees[i][j];
		}
	}
}

template<typename T>
CMatrice<T>::~CMatrice()
{
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		delete[] oMATDonnees[i];
	}
	delete[] oMATDonnees;
}

template<typename T>
CMatrice<T> CMatrice<T>::transposer() const
{
	CMatrice<T> result(iMATNbColonnes, iMATNbLignes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[j][i] = oMATDonnees[i][j];
		}
	}
	return result;
}

template<typename T>
CMatrice<T>& CMatrice<T>::operator=(const CMatrice<T>& arg)
{
	if (this == &arg) // Verification de l'auto-affectation
	{
		return *this;
	}

	// Copie des dimensions
	iMATNbLignes = arg.iMATNbLignes;
	iMATNbColonnes = arg.iMATNbColonnes;

	// Reallocation et copie des elements
	oMATDonnees = new T * [iMATNbLignes];
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		oMATDonnees[i] = new T[iMATNbColonnes];
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			oMATDonnees[i][j] = arg.oMATDonnees[i][j];
		}
	}

	return *this;
}


template<typename T>
CMatrice<T> CMatrice<T>::operator*(const CMatrice<T>& MATarg) const
{
	if (iMATNbLignes != MATarg.iMATNbColonnes) {
		// exception nombre de lignes different du nombre de colonnes
		throw (CException(nbLignesDiffNbColonnes));
	}
	// Creation de la matrice pour stocker le resultat du produit des matrices
	CMatrice<T> result(iMATNbLignes, MATarg.iMATNbColonnes);

	//
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < MATarg.iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = 0;
			for (int k = 0; k < iMATNbColonnes; ++k)
			{
				result.oMATDonnees[i][j] += oMATDonnees[i][k] * MATarg.oMATDonnees[k][j];
			}
		}
	}
	return result;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator*(const T& c) const
{
	CMatrice<T> result(iMATNbLignes, iMATNbColonnes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = c * oMATDonnees[i][j];
		}
	}
	return result;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator+(const CMatrice<T>& arg) const
{
	// Verification des dimensions des deux matrices
	if (iMATNbLignes != arg.iMATNbLignes || iMATNbColonnes != arg.iMATNbColonnes)
	{
		//Les matrices ont des dimensions differentes
		throw(CException(dimMatricesIncompatible));
	}

	// Creation d'une nouvelle matrice pour stocker le resultat
	CMatrice<T> result(iMATNbLignes, iMATNbColonnes);

	// Addition des elements correspondants des deux matrices
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] + arg.oMATDonnees[i][j];
		}
	}

	return result;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator-(const CMatrice<T>& arg) const
{
	// Verification des dimensions des deux matrices
	if (iMATNbLignes != arg.iMATNbLignes || iMATNbColonnes != arg.iMATNbColonnes)
	{
		//Les matrices ont des dimensions differentes
		throw(CException(dimMatricesIncompatible));
	}

	// Creation d'une nouvelle matrice pour stocker le resultat
	CMatrice<T> result(iMATNbLignes, iMATNbColonnes);

	// Addition des elements correspondants des deux matrices
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] - arg.oMATDonnees[i][j];
		}
	}

	return result;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator/(const T& c) const
{
	if (c == 0)
		throw CException(matriceDiviserParZero);
	CMatrice<T> result(iMATNbLignes, iMATNbColonnes);
	for (int i = 0; i < iMATNbLignes; ++i)
	{
		for (int j = 0; j < iMATNbColonnes; ++j)
		{
			result.oMATDonnees[i][j] = oMATDonnees[i][j] / c;
		}
	}
	return result;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const CMatrice<T>& MAT)
{
	for (int i = 0; i < MAT.iMATNbLignes; i++)
	{
		for (int j = 0; j < MAT.iMATNbColonnes; j++)
		{
			out << MAT.oMATDonnees[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

template<typename T>
int CMatrice<T> :: MATLireNbLignes()
{
	return iMATNbLignes;
}

template<typename T>
int CMatrice<T> :: MATLireNbColonnes()
{
	return CMatrice<T>::iMATNbColonnes;
}

// Definition de la fonction modifierElement
template<typename T>
void CMatrice<T>::MATModifierElement(int i, int j, T val) {
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
	else if(j > iMATNbColonnes) {
		//exception indice coolonne superieur aux nombres de colonnes existants dans la matrice cree
		throw (CException(indiceColonneSupNbColonnes));
	}
	//else if (!is_same_v<double, decltype(donnees[i][j])>) {
	//	//exception le type de la valeur modifie est different de celui de la matrice
	//	throw (CException(typeValDiffTypeValMatrice));
	//}
	oMATDonnees[i][j] = val;
}

// Definition de la fonction afficherElement
template <typename T>
T CMatrice<T>::MATAfficherElement(int i, int j) const {
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

template class CMatrice<double>;



