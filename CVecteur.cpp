#include "CVecteur.h"

template<typename T>
inline CVecteur<T>::CVecteur() : elements(nullptr), capacite(0), taille(0) {}

template<typename T>
inline CVecteur<T>::~CVecteur() {
    delete[] elements;
}

template <typename T>
void CVecteur<T>::ajouterElement(const T& element) {
    if (taille == capacite) {
        // Augmenter la capacité du vecteur si nécessaire
        capacite = (capacite == 0) ? 1 : capacite * 2;
        T* nouveauElements = new T[capacite];
        std::copy(elements, elements + taille, nouveauElements);
        delete[] elements;
        elements = nouveauElements;
    }
    elements[taille++] = element;
}

template <typename T>
void CVecteur<T>::ajouterVecteur(const CVecteur<T>& vecteur) {
    for (unsigned long long i = 0; i < vecteur.taille; ++i) {
        ajouterElement(vecteur.elements[i]);
    }
}

template<typename T>
T& CVecteur<T>::operator[](int index)
{
    if (index < 0 || index >= taille) {
        throw std::out_of_range("Index hors limites");
    }
    return elements[index];
}


template<typename T>
int CVecteur<T>::afficherTaille() const
{
    return taille;
}


