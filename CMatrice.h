#ifndef C_MATRICE_H
#define C_MATRICE_H

#include "CException.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>

template<typename T>
class CMatrice
{

//Attributs
private:
    T** oMATDonnees;
    int iMATNbLignes;
    int iMATNbColonnes;

public:
    CMatrice();
    CMatrice(int iMATNbLignes, int iMATNbColonnes);
    CMatrice(const CMatrice& other);
    ~CMatrice();
    CMatrice transposer() const;
    CMatrice& operator=(const CMatrice& MATarg);
    CMatrice operator+(const CMatrice& MATarg) const;
    CMatrice operator-(const CMatrice& MATarg) const;
    CMatrice operator*(const CMatrice& MATarg) const;
    CMatrice operator*(const T& c) const;
    CMatrice operator/(const T& c) const;
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const CMatrice<T>& MAT);

    int MATLireNbLignes();
    int MATLireNbColonnes();
    // Fonctions de modification et d'affichage d'un element
    void MATModifierElement(int i, int j, T val);
    T MATAfficherElement(int i, int j) const;


};


#endif