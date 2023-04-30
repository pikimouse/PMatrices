#include "CMatrice.cpp"
#include "CAnalyseur.cpp"
#include "CException.cpp"

int main(int argc, char** argv) {
    try {

        
        /*CMatrice<double> M1(2, 2), M2(2, 2);

        M1.modifierElement(0, 0, 1.0);
        M1.modifierElement(0, 1, 2.0);
        M1.modifierElement(1, 0, 3.0);
        M1.modifierElement(1, 1, 4.0);

        M2.modifierElement(0, 0, 1.0);
        M2.modifierElement(0, 1, 0.0);
        M2.modifierElement(1, 0, 0.0);
        M2.modifierElement(1, 1, 1.0);
        M2.modifierElement(1, 1, 1);

        CMatrice<double> M3 = M1 + M2;
        CMatrice<double> M4 = M2 + M1;
        CMatrice<double> M5 = M1 - M2;
        CMatrice<double> M6 = M2 - M1;
        CMatrice<double> M7 = M1 * M2;
        CMatrice<double> M8 = M2 * M1;
        CMatrice<double> M9 = M1 * 2.0;
        CMatrice<double> M10 = 2.0 * M1;
        CMatrice<double> M11 = M1 / 2.0;
        CMatrice<double> M12 = M1.transposer();

        std::cout << "M1 : " << std::endl << M1 << std::endl;
        std::cout << "M2 : " << std::endl << M2 << std::endl;
        std::cout << "M3 = M1 + M2 : " << std::endl << M3 << std::endl;
        std::cout << "M4 = M1 + M2: " << std::endl << M4 << std::endl;
        std::cout << "M5 = M1 - M2 : " << std::endl << M5 << std::endl;
        std::cout << "M6 = M2 - M1 : " << std::endl << M6 << std::endl;
        std::cout << "M7 = M1 * M2 : " << std::endl << M7 << std::endl;
        std::cout << "M8 = M2 * M1 : " << std::endl << M8 << std::endl;
        std::cout << "M6 = M1 * 2.0 : " << std::endl << M9 << std::endl;
        std::cout << "M66 = 2.0 * M1 : " << std::endl << M10 << std::endl;
        std::cout << "M8 = M1 / 2.0 : " << std::endl << M11 << std::endl;
        std::cout << "transposer de M1 : " << std::endl << M12 << std::endl;

        CAnalyseur<double> analyseur;
        CMatrice<double> matrice = analyseur.lireMatriceDepuisFichier("test1.txt");
        std::cout << "Matrice lue depuis le fichier :\n" << matrice << std::endl;*/
        
    }
    catch (CException& e) {
        std::cerr << "Erreur : " << e.EXCLireErreur() << std::endl;
        e.EXCAfficherErreur(e.EXCLireErreur());
    }



    try {
        // Verification du nombre d'arguments
        if (argc < 2) {
            throw (CException(nbArgumentsInfADeux));
        }
        // Demande de la valeur c
        double c;
        std::cout << "Veuillez saisir la valeur de c : ";
        std::cin >> c;

        // Creation de l'analyseur
        CAnalyseur<double> analyseur;
        CMatrice<double> premiereMatrice, matriceAddition, matriceSoustraction, matriceProduit;

        // Lecture et traitement de chaque fichier
        for (int i = 1; i < argc; i++) {
            std::string nomFichier(argv[i]);
            CMatrice<double> matrice = analyseur.lireMatriceDepuisFichier(nomFichier);

            // Affichage des resultats des operations
            std::cout << "Matrice " << nomFichier << " multipliee par " << c << " : " << std::endl << matrice * c << std::endl;
            std::cout << "Matrice " << nomFichier << " divisee par " << c << " : " << std::endl << matrice / c << std::endl;
        }
            // Addition des matrices
            premiereMatrice = analyseur.lireMatriceDepuisFichier(argv[1]);
            matriceAddition = premiereMatrice;
            matriceSoustraction = premiereMatrice;
            matriceProduit = premiereMatrice;
            bool soustraction = true;
            for (int j = 2; j < argc; j++) {
                CMatrice<double> matriceJ = analyseur.lireMatriceDepuisFichier(argv[j]);
                matriceAddition = matriceAddition + matriceJ;

                if (soustraction) {
                    matriceSoustraction = matriceSoustraction - matriceJ;
                }
                else {
                    matriceSoustraction = matriceSoustraction + matriceJ;
                }
                soustraction = !soustraction;

                matriceProduit = matriceProduit * matriceJ;
            }
        std::cout << "Addition des matrices : " << std::endl << matriceAddition << std::endl;
        std::cout << "Soustraction et addition alternees : " << std::endl << matriceSoustraction << std::endl;
        std::cout << "Produit des matrices : " << std::endl << matriceProduit << std::endl;
    }
    catch (CException& e) {
        std::cerr << "Erreur : " << e.EXCLireErreur() << std::endl;
        e.EXCAfficherErreur(e.EXCLireErreur());
    }

    return 0;
}
    




