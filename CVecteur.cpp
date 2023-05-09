#include "CVecteur.h"

/**
* @brief Constructeur par defaut de la classe CVecteur
* @param
* @return
*/
template<typename MATT>
inline CVecteur<MATT>::CVecteur() : elements(nullptr), capacite(0), taille(0) {}

/**
* @brief Constructeur de recopie de la classe CVecteur
* @param VECarg objet de la classe CVecteur
* @return
*/
template<typename MATT>
CVecteur<MATT>::CVecteur(const CVecteur<MATT>& VECarg) : elements(nullptr), capacite(0), taille(0) {
    *this = VECarg;
}

/**
* @brief Destructeur de la classe CVecteur : Il a pour charge de desallouer le pointeur elements
* @param
* @pre
* @return
*/
template<typename MATT>
CVecteur<MATT>::~CVecteur()
{
    delete[] elements;
}

/**
* @fn ajouterElement
* @brief Ajoute un element a la fin du vecteur
* @param
* @return
*/
template<typename MATT>
void CVecteur<MATT>::ajouterElement(const MATT& element)
{
    // Ajoute un element a la fin du vecteur
    if (taille == capacite) {
        capacite = (capacite == 0) ? 1 : capacite * 2;
        MATT* nouveauElements = new MATT[capacite];
        for (int i = 0; i < taille; ++i) {
            nouveauElements[i] = elements[i];
        }
        delete[] elements;
        elements = nouveauElements;
    }
    elements[taille++] = element;
}


/**
* @fn afficherTaille
* @brief affiche la taille du vecteur
* @param
* @return le nombre d'elements dans le vecteur
*/
template<typename MATT>
int CVecteur<MATT>::afficherTaille() const
{
    return taille;
}

/**
* @fn operator=
* @brief Operateur d'assignation par copie
* @param
* @return Un objet de la classe CVecteur
*/
template<typename MATT>
CVecteur<MATT>& CVecteur<MATT>::operator=(const CVecteur<MATT>& VECarg)
{
    if (this != &VECarg) {
        if (capacite < VECarg.capacite) {
            delete[] elements;
            elements = new MATT[VECarg.capacite];
            capacite = VECarg.capacite;
        }
        taille = VECarg.taille;
        for (int i = 0; i < taille; ++i) {
            elements[i] = VECarg.elements[i];
        }
    }
    return *this;
}

/**
* @fn operator[]
* @brief Operateur d'indexation en ecriture
* @param
* @return Un objet de type MATT
*/
template<typename MATT>
MATT& CVecteur<MATT>::operator[](int index)
{
    if (index < 0 || index >= taille) {
        throw CException(indiceHorsPlage);
    }
    return elements[index];
}




