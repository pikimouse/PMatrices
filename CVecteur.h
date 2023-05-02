#include "CException.h"

#include <iostream>

template <typename T>
class CVecteur {
private:
    T* elements;
    int taille;
    int capacite;

public:
    CVecteur();
    ~CVecteur();

    int afficherTaille() const;
    void ajouterElement(const T& element);
    void ajouterVecteur(const CVecteur<T>& vecteur);
    T& operator[](int index);

    
};
