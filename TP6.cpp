#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

std::vector<int(*)()> listeExercices; // Les vecteurs sont vu dans ce TP, mais pas les pointeurs de fonctions.

struct Enregistreur { // on a pas vu ceci mais c'est un truc de C++ pour faire du code plus propre, on peut s'en passer
    Enregistreur(int(*fonction)()) {
        listeExercices.push_back(fonction);
    }
};

/**
 * ============================================================================
 * Exercice : Operations on pointers
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice1() {
    int a = 2;
    int *b, *c, *d;
    b = c = d = &a;
    std::cout << a << std::endl;
    a *= (*b);
    std::cout << a << std::endl;
    a *= (*c);
    std::cout << a << std::endl;
    a *= (*d);
    std::cout << a << std::endl;
        
    return 0;
}
Enregistreur reg1(Exercice1);

/**
 * ============================================================================
 * Exercice 2 : Manipulations of pointers
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice2() {
    int tint[10];
    double tdouble[10];
    char tchar[10];

    for (int i = 0; i < 10; i++)
    {
        std::cout << (long long)&tint[i] << "\t" << (long long)&tdouble[i] << "\t" << (long long)&tchar[i] << std::endl;
    }
    return 0;
}
Enregistreur reg2(Exercice2);

/**
 * ============================================================================
 * Exercice 3 : Operation on a unknown number of data
 * ============================================================================
 * Description :
 * ============================================================================
 */
std::vector<double> maxv(const std::vector<double> &A, const std::vector<double> &B) {
    std::vector<double> R;
    for (int i = 0; i < B.size(); i++)
    {
        double a = A.at(i);
        double b = B.at(i);
        R.push_back(a < b ? b : a);
    }
    return R;
}

int Exercice3() {
    std::vector<double> a, b;
    std::cout << "Enter two series of data (leave blank when finished)\n";
    std::cout << "A\tB\t\tR\n";

    std::string ina;
    std::getline(std::cin, ina);

    while (true)
    {
        // 1. Get first number (A) 
        std::getline(std::cin, ina);
        if (ina.empty()) break;
        double current_a = std::stod(ina);
        a.push_back(current_a);

        // Move cursor UP one line and clear the line so we can overwrite their input.
        // We print 'A' and a tab so it stays on screen while they type 'B'.
        std::cout << "\033[A\033[2K" << current_a << "\t";

        // 2. Get second number (B)
        std::getline(std::cin, ina);
        if (ina.empty()) break; // Safeguard in case they quit halfway through a pair
        double current_b = std::stod(ina);
        b.push_back(current_b);

        // Move cursor UP one line, clear the line, and print the ENTIRE final row at once.
        std::cout << "\033[A\033[2K"
            << current_a << "\t" << current_b << "\t\t"
            << ((current_a < current_b) ? current_b : current_a) << std::endl;
    }
    auto r = maxv(a, b);
    for (int i = 0; i < r.size(); i++)
    {
        std::cout << r.at(i) << ", ";
    }
    return 0;
}
Enregistreur reg3(Exercice3);
/**
 * ============================================================================
 * Exercice 4 : args by reference/address
 * ============================================================================
 * Description :
 * ============================================================================
 */
int fourthRootP(double* x) {
    if (*x < 0)
        return 1;
    *x = pow(*x, 0.25);
    return 0;
}
int fourthRootR(double& x) {
    if (x < 0)
        return 1;
    x = pow(x, 0.25);
    return 0;
}
int Exercice4() {
    double x = 65536;
    (fourthRootP(&x) == 0 ? std::cout << x : std::cout << "failed") << std::endl;
    (fourthRootR(x) == 0 ? std::cout << x : std::cout << "failed") << std::endl;

    return 0;
}
Enregistreur reg4(Exercice4);
/**
 * ============================================================================
 * Exercice 5 : translate in morse code
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice5() {
    std::vector<std::string> latin, morse, words;

    std::ifstream morseDic("alphabet_militaire.txt");

    std::string text;
    while (morseDic.good()) {
        morseDic >> text;
        latin.push_back(text);
        morseDic >> text;
        morse.push_back(text);
        std::cout << latin.back() << " --> " << morse.back() << std::endl;
    }
    morseDic.close();

    while (true)
    {
        std::cin >> text;

        for (int i = 0; i < text.length(); i++)
            text[i] = toupper(text[i]);

        if (text == "STOP") break;

        words.push_back(text);
    }

    for(auto word : words){
        std::string trWord;
        for (int i = 0; i < word.length(); i++)
        {
            for (int j = 0; j < latin.size(); j++)
            {
                if (word[i] == latin[j][0])
                {
                    trWord += morse.at(j) + " ";
                }
            }
        }
        std::cout << trWord << " / ";
        //save in a file
    }

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
