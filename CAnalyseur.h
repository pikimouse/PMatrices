#ifndef C_ANALYSEUR_H
#define C_ANALYSEUR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CMatrice.h"

using namespace std;

template<typename T>
class CAnalyseur : public CMatrice<T>
{
public:
    CAnalyseur();

    virtual ~CAnalyseur();
    
    CMatrice<T> ANALireMatriceDepuisFichier(const std::string& nomFichier);

private:
    // Ajouter des membres prives si necessaire
};

#endif