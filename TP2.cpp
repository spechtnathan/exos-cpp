#include <iostream>
#include <cmath>
#include <iostream>
#include <map>
#include <functional>
#include <windows.h>
#include <cstdlib>

void A() {
    char c;
    std::cout << "Saisissez un charactère : ";
    std::cin >> c;

    switch (c)
    {
    case 'a':
        std::cout << "Première lettre de l'alphabet" << std::endl;
        std::cout << "c'est une voyelle" << std::endl;
        break;
    case 'z':
        std::cout << "Dernière lettre de l'alphabet" << std::endl;
        std::cout << "c'est une consonne" << std::endl;
        break;
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        std::cout << "c'est une voyelle" << std::endl;
        break;
    default:
        std::cout << "c'est une consonne" << std::endl;
        break;
    }
}

void B() {
    for (int i = 32; i < 127; i++)
    {
        std::cout << (char)i << "(" << i << ")" << std::endl;
    }

}

void C() {
    int n = -1;
    do {
        std::cout << "Saisissez le nombre de nombres aléatoires à générer : ";
        std::cin >> n;
    } while (n <= 0 || n > 100000000);

    int sum = 0;

    for (int i = 0; i < n; i++)
    { 
        sum += std::rand() % 1000;
    }

    std::cout << "La moyenne des nombres générés est " << (float)sum / n << std::endl;
}

void D()
{
    float a = 10.0f/3.0f;
    float b = a - 3.0f;
    float c = b * 3.0f;
    float d = c - 1.0f;

    std::cout << d << std::endl; // different de 0
}
void E() {
    int i = 0;
    while (i <= 100) {
        std::cout << i++ << std::endl;
    }
    i = 0;
    do {
        std::cout << i++ << std::endl;
    } while (i <= 100);
    
    for (i = 0; i <= 100; i++)
    {
        std::cout << i << std::endl;
    }
    float f = -0.1f;
    while ((f += 0.1f) <= 1.1f) { //il y a une erreur d'approximation et la première valeur est 10e-9 != 0
        std::cout << f << std::endl;
    }
    f = 0.0f;
    do {
        std::cout << f << std::endl;
    } while ((f += 0.1f) <= 1.1f);
    for (f = 0.0f; f <= 1.1f; f += 0.1f) {
        std::cout << f << std::endl;
    }
}
void F() {
    // attention : 10e30 dépasse la plage d'un int ; conserver la logique originale
    int a = (int)10e3; // ajustement pour éviter UB (valeur symbolique)
    int b = -(int)10e3;
    int c = 1;

    std::cout << (a + b) + c << std::endl;
    std::cout << a + (b + c) << std::endl;
}
void G() {
    double e;
    std::cout << "Calcul du nombre d'or via la formule de Fibonacci,\nSaisissez la precision : " << std::endl;
    std::cin >> e;
	int a = 1, b = 1;
    double oldPhi = 0;
    while (std::fabs(oldPhi - ((double)a / b)) > e) {
        oldPhi = (double)a / b;
        int temp = b;
        b = a;
        a += temp;
    }
    std::cout << (double)a / b << std::endl;
}
void H() {
    int p = 100 + std::rand() % 100000; //Prix aléatoire entre 1€00 et 1000€00
    std::cout << "Devinez le juste prix entre 1 et 1000 (10 essais) : " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        int g = -1;
        do {
            float f;
            std::cout << "Essai " << (i + 1) << ": ";
            std::cin >> f;
			g = (int)std::round(f * 100); // Convertit l'entrée en centimes pour éviter les problèmes d'approximation
		} while (g < 100 || g > 100000);
        if(g == p) {
            std::cout << "Bravo ! Vous avez trouvé le juste prix." << std::endl;
            return;
        }
        else if (g < p) {
            std::cout << "C'est plus cher." << std::endl;
        }
        else {
            std::cout << "C'est moins cher." << std::endl;
		}
    }
}
void I() {
    std::cout << "Bienvenu dans le MASTERMIND !!" << std::endl;
    std::cout << "Vous connaissez bien evidement les règles, je vais maintenant choisir une combinaison" << std::endl;
    char comb[4];
    for (int i = 0; i < 4; i++)
    {
        comb[i] = 48 + std::rand() % 10;
    }
    
    std::cout << "C'est bon, j'ai choisi" << std::endl; //ça :" << comb << std::endl;
    char game[10][6];
    char prop[4];
    for (int j = 0; j < 10; j++)
    {
        std::cout << "\nQue proposez vous ?" << std::endl;
        std::cin >> prop[0] >> prop[1] >> prop[2] >> prop[3]; // ╔ ═ ╦ ╗ ╠ ╬ ╣ ╚ ╩ ╝ ║     ┌ ─ ┐ │ └ ┘ ├ ┼ ┤ ┬ ┴

        // Game logic
        
	    int c = 0, m = 0;

        for (int i = 0; i < 4; i++)
        {
            if (prop[i] == comb[i]) {
                c++;
            }
            else {
                for (int j = 0; j < 4; j++)
                {
                    if (prop[i] == comb[j]) {
                        m++;
                        break;
                    }
                }
            }
        }

        // Render
        game[j][0] = prop[0];
        game[j][1] = prop[1];
        game[j][2] = prop[2];
        game[j][3] = prop[3];
        game[j][4] = 48 + c;
        game[j][5] = 48 + m;

        std::cout << std::endl;
        std::cout << "╔════╦═════════╦═══════════╦════════════╗" << std::endl;
        std::cout << "║ ## ║ # # # # ║ Correctes ║ Mal places ║" << std::endl;
        std::cout << "╠════╬═════════╬═══════════╬════════════╣" << std::endl;
        for (int i = 9; i > -1; i--)
        {
            char number[3] = "10";
            if (i != 9) {
                number[0] = ' '; number[1] = (char)(49 + i);
            }
            if (i <= j) {
                std::cout << "║ " 
                    << number << " ║ " 
                    << game[i][0] << " " 
                    << game[i][1] << " " 
                    << game[i][2] << " " 
                    << game[i][3] << " ║         "
                    << game[i][4] << " ║          "
                    << game[i][5] << " ║" << std::endl;
            }
            else std::cout << "║ " << number << " ║         ║           ║            ║" << std::endl;

            if (i == 0) break;
            std::cout << "╠────╬─────────╬───────────╬────────────╣" << std::endl;
        }
        std::cout << "╚════╩═════════╩═══════════╩════════════╝" << std::endl;
        if (c == 4) break;
    }
    if (prop == comb) {
        std::cout << "Quoi ? Vous avez gagne ? La reponse était effectivement " << comb[0] << comb[1] << comb[2] << comb[3] << " !!" << std::endl;
    }
    else
    {
        std::cout << "Dommage -Big flop et au lit !" << std::endl;
    }
}
int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);


    // 1. Création du tableau de pointeurs de fonctions
    // La syntaxe "void (*nom[])()" signifie "tableau de pointeurs vers des fonctions retournant void et ne prenant aucun argument"
    void (*exercices[])() = { A, B, C, D, E, F, G, H, I };

    // Calcul automatique du nombre d'exercices disponibles
    int nbExercices = sizeof(exercices) / sizeof(exercices[0]);

    while (true) {
        int choix = 0;
        std::cout << "\n\nChoisissez un exercice (1-" << nbExercices << ", 0 to quit) : ";
        std::cin >> choix;

        if (choix == 0) return 0;

        // 2. Vérification que le choix est dans les limites du tableau
        if (choix >= 1 && choix <= nbExercices) {
            std::cout << "Exercice " << choix << "\n\n" << std::endl;

            // 3. Appel de la fonction
            // On fait "choix - 1" car les tableaux commencent à l'index 0 en C++
            exercices[choix - 1]();
        }
        else {
            std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}