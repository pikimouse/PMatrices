#include "CAnalyseur.h"

/**
* @brief Constructeur par defaut de la classe CAnalyseur
* @param
* @return
*/
template<typename MATT>
CAnalyseur<MATT>::CAnalyseur() 
{}

/**
* @fn ANALireMatriceDepuisFichier
* @brief Fonction qui permet de parser une matrice depuis un fichier text
* @param Nom du fichier de type chaine de caractere
* @return Objet de la classe CAnalyseur
*/
template <typename MATT>
CMatrice<MATT> CAnalyseur<MATT>::ANALireMatriceDepuisFichier(const std::string& nomFichier) {
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
    CVecteur<CVecteur<MATT>> oMATDonnees;

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
        // Lecture des lignes de la matrice
        else if (debutMatriceTrouve) {
            //Creation d un vecteur pour stocker les valeurs d une ligne de la matrice.
            CVecteur<MATT> ligneMatrice;
            //Initialisation des variables debut et fin pour marquer les positions de debut et de fin de la sous-chaine a extraire.
            size_t debut = 0, fin = 0;
            //Declaration d'une variable pour stocker la valeur extraite de la sous-chaine.
            MATT valeur;
            //Une boucle pour extraire les valeurs de la ligne de la matrice
            while (fin != std::string::npos) {
                //Recherche de l indice de la prochaine occurrence d'un espace a partir de la position debut dans la ligne.
                fin = ligne.find(' ', debut);
                //Extrait de la sous-chaine entre debut et fin et la convertit en valeur numerique de type T a l aide de std::stod.
                valeur = std::stod(ligne.substr(debut, fin - debut));
                //Ajoute la valeur extraite au vecteur ligneMatrice.
                ligneMatrice.ajouterElement(valeur);
                //Mise a jour de la position de debut pour rechercher la prochaine valeur.
                debut = fin + 1;
            }
            if (ligneMatrice.afficherTaille() != nbColonnes) {
                throw CException(matriceFichierInvalid);
            }
            //Ajoute du vecteur ligneMatrice au vecteur oMATDonnees, qui stocke toutes les lignes de la matrice
            oMATDonnees.ajouterElement(ligneMatrice);

            if (oMATDonnees.afficherTaille() > nbLignes) {
                throw CException(matriceFichierInvalid);
            }
            if (oMATDonnees.afficherTaille() == nbLignes) {
                break; // Fin de la lecture
            }
        }
    }

    // Verification du nombre de lignes
    if (oMATDonnees.afficherTaille() != nbLignes) {
        throw CException(matriceFichierInvalid);
    }

    // Creation de l'objet matrice
    CMatrice<MATT> matrice(nbLignes, nbColonnes);
    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            matrice.MATModifierElement(i, j, oMATDonnees[i][j]);
        }
    }

    return matrice;
}
