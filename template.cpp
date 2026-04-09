#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>

std::vector<int(*)()> listeExercices; // Les vecteurs sont vu dans ce TP, mais pas les pointeurs de fonctions.

struct Enregistreur { // on a pas vu ceci mais c'est un truc de C++ pour faire du code plus propre, on peut s'en passer
    Enregistreur(int(*fonction)()) {
        listeExercices.push_back(fonction);
    }
};

/**
 * ============================================================================
 * Exercice :
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice1() {
    return 0;
}
Enregistreur reg1(Exercice1);

/**
 * ============================================================================
 * Exercice 2 :
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice2() {
    return 0;
}
Enregistreur reg2(Exercice2);

/**
 * ============================================================================
 * Exercice 3 :
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice3() {
    return 0;
}
Enregistreur reg3(Exercice3);
/**
 * ============================================================================
 * Exercice 4 :
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice4() {
    return 0;
}
Enregistreur reg4(Exercice4);
/**
 * ============================================================================
 * Exercice 5 :
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice5() {
    return 0;
}
Enregistreur reg5(Exercice5);

int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);


    // Les instructions suivantes permettent d'exécuter un exercice au choix au lancement
    // Ce n'est pas à faire dans le cadre du TP
    int nbExercices = listeExercices.size();

    while (true) {
        int choix = 0;
        std::cout << "\n\nChoisissez un exercice (1-" << nbExercices << ", 0 to quit) : ";
        std::cin >> choix;

        if (choix == 0) return 0;

        if (choix >= 1 && choix <= nbExercices) {
            std::cout << "Exercice " << choix << "\n\n" << std::endl;
            int r = listeExercices[choix - 1]();
            if (r != 0) return r;
        }
        else {
            std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}
