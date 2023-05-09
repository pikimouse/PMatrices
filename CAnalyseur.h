#ifndef C_ANALYSEUR_H
#define C_ANALYSEUR_H

#include <iostream>
#include <fstream>
#include <string>
#include "CMatrice.h"
#include "CVecteur.cpp"

template<typename MATT>
class CAnalyseur 
{
public:
    CAnalyseur();
    
    /**
    * @fn ANALireMatriceDepuisFichier
    * @brief Fonction qui permet de parser une matrice depuis un fichier text
    * @param Nom du fichier de type chaine de caractere
    * @return Objet de la classe CMatrice
    */
    CMatrice<MATT> ANALireMatriceDepuisFichier(const std::string& nomFichier);

};

#endif