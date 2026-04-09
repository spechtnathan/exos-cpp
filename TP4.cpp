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
 * Exercice : Cinématique simple - Rebonds d'une balle
 * ============================================================================
 * * Description :
 * Simule les rebonds successifs d'une balle lâchée depuis une hauteur
 * initiale. À chaque rebond, la nouvelle hauteur est atténuée par le carré
 * du coefficient de restitution (epsilon) du sol.
 * * Fonctions à implémenter :
 * - h_rebond  : Calcule la hauteur atteinte après un seul rebond.
 * - h_final   : Calcule la hauteur atteinte après n rebonds successifs.
 * - n_rebonds : Détermine le nombre de rebonds nécessaires pour que la
 * hauteur de la balle passe sous un seuil donné (h_end).
 * * Cas d'application (Tests à réaliser) :
 * Hauteur initiale = 10 m, Coefficient epsilon = 0.85.
 * 1. Afficher la hauteur après 4 rebonds.
 * 2. Afficher le nombre de rebonds avant que la hauteur soit inférieure à 1 cm.
 * 3. Sauvegarder dans un fichier les hauteurs des 10 premiers rebonds.
 * ============================================================================
 */

// Calcule la hauteur atteinte après un seul rebons
double h_rebond(double h_start, double epsilon)
{
    return h_start * epsilon * epsilon; // formule obtenue après simplification
}

// Calcule la hauteur après n rebonds
double h_final(double h_start, int n, double epsilon)
{
    while(n-->0)
    {
        h_start = h_rebond(h_start, epsilon);
    }
    return h_start;
}

// Calcule le nombre de rebond pour atteindre une hauteur
double n_rebonds(double h_start, double h_end, double epsilon)
{
    int n = 0;
    while (h_start > h_end)
    {
        n++;
        h_start = h_rebond(h_start, epsilon);
    }
    return n;
}

int Exercice1()
{
    double h = 10; double epsilon = 0.85;
    std::cout << "Une balle tombe de " << h << " mètres et rebondis avec un coefficient de restitution de " << epsilon << std::endl;
    std::cout << "Après 4 rebonds, la balle a une hauteur de " << h_final(h, 4, epsilon) << " mètres" << std::endl;
    std::cout << "La balle rebondira à 1 cm après " << n_rebonds(h, 0.01, epsilon) << " rebonds" << std::endl;


    // Enregistrer les dix premiers rebonds
    std::ofstream data("rebonds.txt");
    if (!data.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier";
        return EXIT_FAILURE;
    }
    std::cout << h << std::endl;
    for (int i = 0; i < 10; i++)
    {
        data << (h = h_rebond(h, epsilon)) << std::endl;
    }
    data.close();

    return 0;
}
Enregistreur reg1(Exercice1);

/**
 * ============================================================================
 * Exercice 2 : Calcul de Pi - Formule de Leibniz
 * ============================================================================
 * * Description :
 * Modification du programme précédent pour isoler le calcul du n-ième terme
 * de la série de Leibniz.
 * * Fonction à implémenter :
 * - double terme_Leibniz(int n) : Retourne la valeur du n-ième terme.
 */

double terme_Leibniz(int n) {
    return ((double)(n % 2) * (-2) + 1) / (2 * (double)n + 1);
} // Je vous laisse le soin de l'implémenter avec le TP précédent

int Exercice2() {
    std::cout << "Voir code" << std::endl;
    return 0;
}
Enregistreur reg2(Exercice2);

/**
 * ============================================================================
 * Exercice 3 : Calculs avec des vecteurs (Base orthonormée)
 * ============================================================================
 * * Description :
 * Implémentation d'opérations géométriques sur des vecteurs 3D.
 * * Fonctions à implémenter :
 * - produit_scalaire  : Calcule le produit scalaire à partir des 6 composantes
 * (x, y, z) de deux vecteurs passées individuellement.
 * - produit_vectoriel : Calcule le produit vectoriel de deux vecteurs (passés
 * sous forme de tableaux) et stocke le résultat dans un troisième tableau.
 * * Cas d'application (Tests à réaliser) :
 * Calculer et afficher les produits scalaires et vectoriels des vecteurs
 * (10, 5, 5), (-2, 2, 2) et (3, 6, 1) pris deux à deux.
 */

double produit_scalaire(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return x1 * x2 + y1 * y2 + z1 * z2;
}
double produit_scalaire(double v1[3],double v2[3])
{
    return produit_scalaire(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
}
// produit vectoriel, le résultat est stocké dans le troisième paramètre
void produit_vectoriel(double vecteur1[3], double vecteur2[3], double vecteur[3]) {
    vecteur[0] = vecteur1[1] * vecteur2[2] - vecteur1[2] * vecteur2[1];
    vecteur[1] = vecteur1[2] * vecteur2[0] - vecteur1[0] * vecteur2[2];
    vecteur[2] = vecteur1[0] * vecteur2[1] - vecteur1[1] * vecteur2[0];
}

int Exercice3() {
    double v1[] = { 10, 5, 5 };
    double v2[] = { -2, 2, 2 };
    double v3[] = {  3, 6, 1 };
    double* couples[][2] = { {v1,v2},{v1,v3},{v2,v3} };
    for (auto& v : couples) {
        std::cout << produit_scalaire(v[0], v[1]) << std::endl;
        double result[3] = { 0 };
        produit_vectoriel(v[0], v[1], result);
        std::cout << result[0] << ", " << result[1] << ", " << result[2] << std::endl;
    }
    return 0;
}
Enregistreur reg3(Exercice3);

/**
 * ============================================================================
 * Exercice 4 : Évaluation de polynômes P(x)
 * ============================================================================
 * * Description :
 * Outil d'évaluation polynomiale et exportation de données pour tracé graphique.
 * * Fonction à implémenter :
 * - Une fonction évaluant P(x) recevant en paramètres un tableau contenant
 * les coefficients du polynôme et une valeur x.
 * * Cas d'application (Tests à réaliser) :
 * Évaluer le polynôme P(x) = 2x^4 - 3x^2 + x - 2 sur l'intervalle [-3, 3]
 * avec un pas de progression de 0.001 (10^-3).
 * Sauvegarder les couples de valeurs (x, P(x)) dans un fichier de sortie.
 * ============================================================================
 */
double evaluate(double p[], int size, double x) {
    double sum = 0;
    double xterm = 1;

    for (int i = 0; i < size; ++i) {
        sum += p[i] * xterm;
        xterm *= x;
    }
    return sum;
}

int Exercice4() {
    double p1[] = { -2, 1, 0, -3, 2 };
    char filename[] = "ex4.txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier";
        return EXIT_FAILURE;
    }
    for (double i = -3; i < 3; i += 0.001)
    {
        file << i << ", " << evaluate(p1, 5, i) << std::endl;
    }
    file.close();
    return 0;
}
Enregistreur reg4(Exercice4);


/**
 * ============================================================================
 * Exercice 5 : Calcul d'intégrale numérique
 * ============================================================================
 * * Description :
 * Approximation numérique d'intégrales au sens de Riemann (méthode des
 * rectangles au point milieu). L'aire sous la courbe est calculée en sommant
 * l'aire de rectangles de largeur uniforme epsilon.
 * * Fonctions à implémenter :
 * - Intégrale de cos(2x) : Calcule l'intégrale de la fonction cos(2x) sur
 * un intervalle [a, b] avec une largeur epsilon paramétrable.
 * - Évaluation polynomiale efficace : Calcule P(x) à partir d'un tableau de
 * coefficients, du degré n, et de la valeur x (ex: méthode de Horner).
 * - Intégrale de polynôme : Calcule l'intégrale numérique d'un polynôme de
 * degré n sur un intervalle [a, b] avec une largeur epsilon paramétrable.
 * * Cas d'application (Tests à réaliser) :
 * 1. Intégrer cos(2x) sur [0, pi/4] pour epsilon = 10^-1, 10^-2, ..., 10^-5.
 * 2. Intégrer P(x) = 7x^5 + 3x^4 + 2x^2 + 5x + 7 sur [0, 10] avec epsilon = 0.001.
 * 3. Comparer ce résultat numérique avec le calcul analytique exact utilisant
 * la primitive de ce polynôme.
 * 4. Calculer I(t) = intégrale de 0 à t de P(x)dx pour t allant de 0 à 10
 * par pas de 0.01.
 * 5. Sauvegarder les résultats de I(t) dans un fichier de sortie.
 * ============================================================================
 */

double Riemann(double(*f)(double x), double a, double b, double epsilon) {
    if (epsilon <= 0) return 0;
    bool sign = 1; // positive 1, negative 0
    if ((b - a) < 0) {
        sign = 0;
        double tmp = a;
        a = b;
        b = tmp;
    }

    double sum = 0;
    for (double i = a; i < b; i += epsilon)
    {
        sum += epsilon * f(i + epsilon / 2);
    }
    return sum * (sign * 2 - 1);
}

double f(double x) {
    return cos(x);
}
double g(double x) {
    return cos(2 * x);
}

int Exercice5() {
    double a = 0;
    double b = 3.141592653589793238462643383279 / 4;

    double epsilon = 1;
    for (int i = 1; i < 7; i++)
    {
        epsilon *= 0.1;
        std::cout << "int de f avec epsilon " << epsilon << " : " << Riemann(f, a, b, epsilon) << std::endl;;
        std::cout << "int de g avec epsilon " << epsilon << " : " << Riemann(g, a, b, epsilon) << std::endl;;
    }
    epsilon = 1e-3;
    a = 0, b = 10;
    std::cout << "int de P(x) avec epsilon " << epsilon << " : " << Riemann([](double x) {double p1[] = { 7, 3, 0, 2, 5, 7 }; return evaluate(p1, 6, x);}, a, b, epsilon) << std::endl;
    //ecrire dans un fichier
    return 0;
}
Enregistreur reg5(Exercice5);
/**
 * ======================================
 *  Exercice 6 : Fibo par récurrence
 * ======================================
 */

int fibo(int n);
int fibo(int n) {
    if (n < 3) {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int Exercice6() {
    for (int i = 1; i < 20; i++)
    {
        std::cout << fibo(i) << std::endl;
    }
    return 0;
}
Enregistreur reg6(Exercice6);

/**
 * =========================================
 * Exercice 7 : Chargement de données et distribution
 * =========================================
 * La manière dont l'exercice est demandé m'a l'air nul
 */
void distribute(int nbrOfClasses, double midValues[], double classLength, double distribution[])
{
    std::ifstream data("data.txt");
    if (!data.is_open()) {
        std::cout << "Error"; return;
    }
    while (data.good()) {
        double n;
        data >> n;
        if (n < midValues[0] - classLength / 2) {
            continue;
        }
        for (int i = 0; i < nbrOfClasses; i++)
        {
            if (n < midValues[i] + classLength / 2) {
                distribution[i]++;
                break;
            }
        }
    }
    data.close();
}
void graphDistribution(int nbrOfClasses, double distribution[], double midValues[]) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < nbrOfClasses; i++)
    {
        if (max < distribution[i])
        {
            max = distribution[i];
        }
        sum += distribution[i];
    }
    double charPerValue = 70.0f / max;
    std::cout << "Il y a " << sum << " données réparties en " << nbrOfClasses << " classes\n    ^" << std::endl;
    std::cout.precision(2);
    for (int i = 0; i < nbrOfClasses; i++)
    {
        double m = midValues[i];
        if (m >= 0) std::cout << " ";
        if ((int)m == m) std::cout << "  ";
        std::cout << m << "|";
        int nbrOfEquals = charPerValue * distribution[i];
        while (nbrOfEquals --> -1) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
    std::cout << "    --------------------------------------------------------------------->" << std::endl;
    std::cout.precision(9);
    std::cout << "One character equals " << 1 / charPerValue;

}

int Exercice7() {
    const int nbrOfClasses = 15;
    double a = -4.5;
    double b = 4.5;
    double midValues[nbrOfClasses] = { 0 };

    double classLength = (b - a) / nbrOfClasses;
    midValues[0] = a + classLength / 2;
    for (int i = 1; i < nbrOfClasses; i++)
    {
        midValues[i] = round((midValues[i - 1] + classLength) * 10) / 10;
    }

    double distribution[nbrOfClasses] = { 0 };
    distribute(nbrOfClasses, midValues, classLength, distribution);
    graphDistribution(nbrOfClasses, distribution, midValues);
    return 0;
}
Enregistreur reg7(Exercice7);

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
