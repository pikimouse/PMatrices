#ifndef C_VECTEUR_H
#define C_VECTEUR_H

#include "CException.h"

template<typename MATT>
class CVecteur {
private:
    MATT* elements;
    int capacite;
    int taille;

public:
    /**
    * @brief Constructeur par defaut de la classe CVecteur
    * @param
    * @return
    */
    CVecteur();

    /**
    * @brief Constructeur de recopie de la classe CVecteur
    * @param VECarg objet de la classe CVecteur
    * @return
    */
    CVecteur(const CVecteur<MATT>& VECarg);

    /**
    * @brief Destructeur de la classe CVecteur : Il a pour charge de desallouer le pointeur elements
    * @param
    * @pre
    * @return
    */
    ~CVecteur();

    /**
    * @fn ajouterElement
    * @brief Ajoute un element a la fin du vecteur
    * @param
    * @return
    */
    void ajouterElement(const MATT& VECelement);

    /**
    * @fn afficherTaille
    * @brief affiche la taille du vecteur
    * @param
    * @return le nombre d'elements dans le vecteur
    */
    int afficherTaille() const;

    /**
    * @fn operator=
    * @brief Operateur d'assignation par copie
    * @param
    * @return Un objet de la classe CVecteur
    */
    CVecteur<MATT>& operator=(const CVecteur<MATT>& VECarg);

    /**
    * @fn operator[]
    * @brief Operateur d'indexation en ecriture
    * @param
    * @return Un objet de type MATT
    */
    MATT& operator[](int VECindex);
};


#endif