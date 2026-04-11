#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

std::vector<int(*)()> listeExercices; // sujet de ce TP

struct Enregistreur { // on n'a pas vu le struct mais aussi non c'est juste une fonction qui ajoute des pointers de fonctions à une liste
    Enregistreur(int(*fonction)()) {
        listeExercices.push_back(fonction);
    }
};

/**
 * ============================================================================
 * Exercice 1 : 
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice1() {
    int n;

    // 1. Demander la taille
    std::cout << "Entrez la taille de la matrice carree (N) : ";
    std::cin >> n;

    // 2. Déclarer le vecteur 1D qui servira de tableau 2D (taille totale = n * n)
    std::vector<int> M(n * n);

    // 3. Saisir les éléments avec conversion des indices
    std::cout << "Veuillez saisir les elements de la matrice :" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "M[" << i << "][" << j << "] = ";

            // L'indice 1D est calculé par : i * nombre_de_colonnes + j
            std::cin >> M[i * n + j];
        }
    }

    std::cout << "La matrice est : " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << M[i * n + j] << "\t";
        }
        std::cout << std::endl;
    }
    
    std::cout << "La matrice transposée est : " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << M[j * n + i] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
Enregistreur reg1(Exercice1);

/**
 * ============================================================================
 * Exercice 2 : random dice sum
 * ============================================================================
 * * Description :
 * ============================================================================
 */
void role_dice(int sums[]) {
    sums[rand() % 6 + rand() % 6]++;
}
int Exercice2() {
    int sums[11] = { 0 };
    int n = 0;

    int ninit = 100000000;

    clock_t start = clock(); // pour calculer lance / sec
    for (int i = 0; i < ninit; i++)
    {
        role_dice(sums);
        n++;
    }
    clock_t end = clock();
    double temps = (double)(end - start) / CLOCKS_PER_SEC;
    double lps = (double)ninit / temps; // lance par secondes

    int max = 0;
    int maxi = 0;

    std::cout << "après " << n << " lancés (en " << temps << " s, lps=" << lps << ")" << std::endl;
    for (int i = 0; i < 11; i++)
    {
        std::cout << i + 2 << " : " << sums[i] << std::endl;
        if (sums[i] > max) {
            max = sums[i];
            maxi = i;
        }
    }

    std::cout << "Le nombre le plus probable est " << maxi + 2 << std::endl;

    for (int i = 0; i < 11; i++)
    {
        std::cout << i + 2 << " : ";
        for (int j = 0; j < (double)sums[i] / max * 70; j++)
        {            std::cout << "=";
        }
        std::cout << std::endl;
        
    }

    return 0;
}
Enregistreur reg2(Exercice2);

/**
 * ============================================================================
 * Exercice 3 : Tensor product
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice3() {
    int n, m;
    std::cout << "Entrez la taille des vecteurs (m et n) : "; std::cin >> m; std::cin >> n;

    int tmp;
    std::vector<int> u, v;

    std::cout << "Entrez les valeurs des composantes du u : " << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cout << "u[" << i << "] = "; std::cin >> tmp;
        u.push_back(tmp);
    }
    
    std::cout << "Entrez les valeurs des composantes du v : " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "v[" << i << "] = "; std::cin >> tmp;
        v.push_back(tmp);
    }
    std::cout << "Produit tensoriel : " << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << u.at(i) * v.at(j) << "\t";
        }
        std::cout << std::endl;
    }

    // enregistrer dans un fichier
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

double alpha_n(double x, int n) {
    return ((n - 1) % 2 == 1 ? -1 : 1) * pow(x, n) / n;
}
int Exercice4() {
    double x = -1;
    while(x <= -1 || x > 1)
    {
        std::cout << "Enter a value of x in ] -1, 1] : "; std::cin >> x;
    }
    double ep = 1;
    while (ep <= 0 || ep >= 1)
    {
        std::cout << "Enter a value for epsillon in ] 0, 1[ : "; std::cin >> ep;
    }
    double sum = 0;
    double last = 1;
    int n = 1;
    while (abs(last) > ep)
    {
        last = alpha_n(x, n++);
        sum += last;
    }
    std::cout << "Calculated " << sum << " after " << n << " steps" << std::endl;
    double lg = log(1 + x);
    std::cout << "log(1+x) gives " << lg << " which is a difference of " << abs(sum - lg) << std::endl;

    sum = 0;
    last = 1;
    double lastlast = 0;
    n = 1;
    while (abs(sum - lg) > 1e-6)
    {
        lastlast = last;
        last = alpha_n(x, n++);
        sum += last;
    }

    std::cout << "For a difference less then 10-6 we need epsilon to be less than " << abs(lastlast) << std::endl;

    return 0;
}
Enregistreur reg4(Exercice4);
/**
 * ============================================================================
 * Exercice 5 : Crible d'Eratosthène
 * ============================================================================
 * Description :
 * ============================================================================
 */
std::vector<int> Erastoshene(int N) {
    std::vector<int> Nombres(N + 1);
    for (int i = 0; i <= N; i++)
    {
        Nombres[i] = i;
    }

    if (N >= 1) { Nombres[1] = 0; }

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (Nombres[i] != 0) { // i est premier
            for (int j = i * i; j <= N; j += i)
                // le premier nombre a enlevé est i*i car les multiples de i (2i, 3i, ...) ont été enlevé quand i = 2, 3, ...
            {
                Nombres[j] = 0;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= N; i++)
    {
        if (Nombres[i] != 0) {
            primes.push_back(Nombres[i]);
        }
    }
    return primes;
}

std::vector<int> EratostheneUltime(int N) {
    // Gestion des cas de base pour éviter les erreurs
    if (N < 2) return {};
    if (N == 2) return { 2 };

    // OPTIMISATION 1 : On ne stocke que les nombres impairs.
    // L'indice 0 représente 3, l'indice 1 représente 5, l'indice 2 représente 7, etc.
    // La formule est : Nombre = 2 * Indice + 3
    int half_size = (N - 1) / 2;

    // OPTIMISATION 2 : uint8_t au lieu de int. 
    // Prend 4x moins de place qu'un 'int', rentre parfaitement dans le cache L1/L2.
    // On initialise à 0 (qui signifie ici "est premier") car c'est plus rapide.
    std::vector<uint8_t> is_composite(half_size, 0);

    int limit = (std::sqrt(N) - 1) / 2;

    for (int i = 0; i <= limit; i++) {
        if (is_composite[i] == 0) {
            // Retrouver la vraie valeur du nombre premier
            int p = 2 * i + 3;

            // On commence à p^2. 
            // L'indice correspondant à p^2 est : 2*i^2 + 6*i + 3
            // On fait des bonds de 'p' (ce qui correspond à bondir de 2p en vraie valeur)
            for (int j = 2 * i * i + 6 * i + 3; j < half_size; j += p) {
                is_composite[j] = 1; // 1 = composé (rayé)
            }
        }
    }

    // OPTIMISATION 3 : Compter les nombres premiers avant de remplir le tableau final
    int prime_count = 1; // On compte déjà le '2'
    for (int i = 0; i < half_size; i++) {
        if (is_composite[i] == 0) prime_count++;
    }

    // OPTIMISATION 4 : Pré-allocation (reserve)
    std::vector<int> primes;
    primes.reserve(prime_count);

    primes.push_back(2); // On ajoute le seul nombre pair

    // Remplissage final
    for (int i = 0; i < half_size; i++) {
        if (is_composite[i] == 0) {
            primes.push_back(2 * i + 3);
        }
    }

    return primes;
}
int Exercice5() {

    std::vector<int> primes;
    int N = 100000000;
    std::cout << "All primes less then " << N << std::endl;

    clock_t start = clock();
    clock_t end = clock();

    start = clock();
    primes = Erastoshene(N);
    end = clock();

    std::cout << "A took " << (end - start) * 1000.0 / CLOCKS_PER_SEC << " ms" << std::endl;

    start = clock();
    primes = EratostheneUltime(N);
    end = clock();

    std::cout << "B took " << (end - start) * 1000.0 / CLOCKS_PER_SEC << " ms" << std::endl;

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
