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
    /**
    * @brief Constructeur par defaut de la classe CMatrice
    * @param
    * @return
    */
    CMatrice();

    /**
    * @brief Constructeur de confort de la classe CMatrice
    * @param entier naturel nombre de lignes et nombres de colonnes
    * @return
    */
    CMatrice(int iMATNbLignes, int iMATNbColonnes);

    /**
    * @brief Constructeur de recopie de la classe CMatrice
    * @param MATarg objet de la classe CMatrice
    * @return
    */
    CMatrice(const CMatrice& other);

    /**
    * @brief Destructeur de la classe CMatrice : Il a pour charge de desallouer le pointeur oMATDonnees
    * @param
    * @pre
    * @return
    */
    ~CMatrice();

    /**
    * @fn transposer()
    * @brief Fonction pour calculer la transposer d'une matrice
    * @param
    * @return Un objet de la classe CMatrice
    */
    CMatrice transposer() const;

    /**
    * @fn operator=
    * @brief Surcharge de l'operateur= qui sert a réaliser une affectation entre deux matrices
    * @param Objet de la classe CMatrice
    * @return Reference de l'objet en cours
    */
    CMatrice& operator=(const CMatrice& MATarg);

    /**
    * @fn operator+
    * @brief Surcharge de l'operateur+ qui sert a additioner de deux matrices
    * @param Objet de la classe CMatrice
    * @return Resultat de l'addition des des deux matrices
    */
    CMatrice operator*(const CMatrice& MATarg) const;

    /**
    * @fn operator*
    * @brief Surcharge de l'operateur* qui calcul le produit d'une matrice avec une constance
    * @param Constante reelle
    * @return Resultat de la multiplication
    */
    CMatrice operator*(const double c) const;

    /**
    * @fn operator+
    * @brief Surcharge de l'operateur+ qui sert a additioner de deux matrices
    * @param Objet de la classe CMatrice
    * @return Resultat de l'addition des des deux matrices
    */
    CMatrice operator+(const CMatrice& MATarg) const;

    /**
    * @fn operator-
    * @brief Surcharge de l'operateur- qui sert a la soustraction de deux matrices
    * @param Objet de la classe CMatrice
    * @return Resultat de la soustraction des des deux matrices
    */
    CMatrice operator-(const CMatrice& MATarg) const;

    /**
    * @fn operator/
    * @brief Surcharge de l'operateur/ qui sert a divier une matrice par une constante
    * @param Constante reelle
    * @return Resultat de la division
    */
    CMatrice operator/(const double c) const;

    /**
    * @fn operator<<
    * @brief Surcharge de l'operateur<< qui sert a afficher une matrice
    * @param Objet de sortie
    * @param Objet de la classe CMatrice
    * @return Resultat l'affichage en sortie
    */
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const CMatrice<T>& MAT);


    /**
    * @fn MATLireNbLignes
    * @brief Affichage du nombre de ligne de la matrice
    * @param
    * @return Nombre de lignes de la matrice
    */
    int MATLireNbLignes();

    /**
    * @fn MATLireNbColonnes
    * @brief Affichage du nombre de colonnes de la matrice
    * @param
    * @return Nombre de colonnes de la matrice
    */
    int MATLireNbColonnes();

    /**
    * @fn MATModifierElement
    * @brief Modifier la valeur du coefficient d'une matrice
    * @param Indice de ligne
    * @param Indice de colonne
    * @param Nouvelle valeur
    * @return
    */
    void MATModifierElement(int i, int j, T val);

    /**
    * @fn MATAfficherElement
    * @brief Afficher la valeur du coefficient d'une matrice
    * @param Indice de ligne
    * @param Indice de colonne
    * @return Valeur demandée
    */
    T MATAfficherElement(int i, int j) const;


};

#endif