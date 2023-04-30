#include "CAnalyseur.h"

template<typename T>
CAnalyseur<T>::CAnalyseur() : CMatrice<T>()
{}

template<typename T>
CAnalyseur<T>::~CAnalyseur()
{}


template <typename T>
CMatrice<T> CAnalyseur<T>::ANALireMatriceDepuisFichier(const std::string& nomFichier) {
    // Verification du type de fichier
    /*std::string extension = nomFichier.substr(nomFichier.find_last_of(".") + 1);
    if (extension._Equal("txt")) {
        throw CException(typeFichierIncompatible);
    }*/

    // Ouverture du fichier
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        throw (CException(impossibleOuvrirFichier));
    }

    // Lecture des informations de la matrice
    std::string ligne;
    std::string typeMatrice;
    int nbLignes = -1;
    int nbColonnes = -1;
    bool debutMatriceTrouve = false;
    std::vector<std::vector<T>> oMATDonnees;

    while (std::getline(fichier, ligne)) {
        // Recherche des informations de la matrice dans les balises
        if (ligne.find("TypeMatrice=") == 0) {
            typeMatrice = ligne.substr(strlen("TypeMatrice="));
            if (typeMatrice.empty() || !typeMatrice._Equal("double")) {
                throw (CException(typeMatricePASTypeDouble));
            }
        }
        else if (ligne.find("NBLignes=") == 0) {
            nbLignes = std::stoi(ligne.substr(strlen("NBLignes=")));
            if (nbLignes <= 0) {
                throw (CException(lignesInferieurOuEgalZero));
            }
        }
        else if (ligne.find("NBColonnes=") == 0) {
            nbColonnes = std::stoi(ligne.substr(strlen("NBColonnes=")));
            if (nbColonnes <= 0) {
                throw CException(colonnesInferieurOuEgalZero);
            }
        }
        else if (ligne.find("Matrice=[") == 0) {
            debutMatriceTrouve = true;
        }
        else if (debutMatriceTrouve) {
            // Lecture des lignes de la matrice
            std::vector<T> ligneMatrice;
            size_t debut = 0, fin = 0;
            T valeur;
            while (fin != std::string::npos) {
                fin = ligne.find(' ', debut);
                valeur = std::stod(ligne.substr(debut, fin - debut));
                ligneMatrice.push_back(valeur);
                debut = fin + 1;
            }
            if (ligneMatrice.size() != nbColonnes) {
                throw CException(matriceFichierInvalid);
            }
            oMATDonnees.push_back(ligneMatrice);
            if (oMATDonnees.size() > nbLignes) {
                throw CException(matriceFichierInvalid);
            }
            if (oMATDonnees.size() == nbLignes) {
                break; // Fin de la lecture
            }
        }
    }

    // Verification du nombre de lignes
    if (oMATDonnees.size() != nbLignes) {
        throw CException(matriceFichierInvalid);
    }

    // Creation de l'objet matrice
    CMatrice<T> matrice(nbLignes, nbColonnes);
    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            matrice.MATModifierElement(i, j, oMATDonnees[i][j]);
        }
    }

    return matrice;
}

template class CAnalyseur<double>;