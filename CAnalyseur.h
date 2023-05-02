#ifndef C_ANALYSEUR_H
#define C_ANALYSEUR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CMatrice.h"
//#include "CVecteur.cpp"

using namespace std;

template<typename T>
class CAnalyseur : public CMatrice<T>
{
public:
    CAnalyseur();

    virtual ~CAnalyseur();
    
    /**
    * @fn ANALireMatriceDepuisFichier
    * @brief Fonction qui permet de parser une matrice depuis un fichier text
    * @param Nom du fichier de type chaine de caractere
    * @return Objet de la classe CMatrice
    */
    CMatrice<T> ANALireMatriceDepuisFichier(const std::string& nomFichier);

};

#endif