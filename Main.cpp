#include "CMatrice.cpp"
#include "CAnalyseur.cpp"

void main(int argc, char* argv[])
{
    try {
        // Verification du nombre d'arguments
        if (argc < 2) {
            throw CException(nbArgumentsInfADeux);
        }

        // Creation de l'analyseur
        CAnalyseur<double> analyseur;
        // Demande de la valeur c
        double c;
        std::cout << "Veuillez saisir la valeur de c : ";
        std::cin >> c;

        CMatrice<double> premiereMatrice = analyseur.ANALireMatriceDepuisFichier(argv[1]);
        CMatrice<double> matriceAddition, matriceSoustraction, matriceProduit;

        // Lecture et traitement de chaque fichier
        for (int i = 1; i < argc; i++) {
            std::string nomFichier(argv[i]);
            CMatrice<double> matrice = analyseur.ANALireMatriceDepuisFichier(nomFichier);

            // Affichage des resultats des operations
            std::cout << "Matrice " << nomFichier << " multipliee par " << c << " : " << std::endl << matrice * c << std::endl;
            std::cout << "Matrice " << nomFichier << " divisee par " << c << " : " << std::endl << matrice / c << std::endl;
        }
        // Addition des matrices
        matriceAddition = premiereMatrice;
        matriceProduit = premiereMatrice;
        matriceSoustraction = premiereMatrice;
        for (int j = 2; j < argc; j++) {
            CMatrice<double> matriceJ = analyseur.ANALireMatriceDepuisFichier(argv[j]);
            matriceAddition = matriceAddition + matriceJ;

            // Soustraction et addition alternees

            bool soustraction = true;
            if (soustraction) {
                matriceSoustraction = matriceSoustraction - matriceJ;
            }
            else {
                matriceSoustraction = matriceSoustraction + matriceJ;
            }
            soustraction = !soustraction;

            // Produit des matrices
            matriceProduit = matriceProduit * matriceJ;
        }
        std::cout << "Addition des matrices : " << std::endl << matriceAddition << std::endl;
        std::cout << "Soustraction et addition alternees : " << std::endl << matriceSoustraction << std::endl;
        std::cout << "Produit des matrices : " << std::endl << matriceProduit << std::endl;
    }
    catch (const CException& e) {
        std::cerr << "Erreur : " << e.EXCLireException() << std::endl;
        e.EXCAfficherException();
    }
}
