#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>

std::vector<int(*)()> listeExercices;

struct Enregistreur {
    Enregistreur(int(*fonction)()) {
        listeExercices.push_back(fonction);
    }
};

/*
1. Débogage d'un programme :
I Ouvrir le projet fourni lors du TP et corriger les erreurs à l'aide des
informations données par le compilateur et le débogueur.
*/

// voir main_Heron_corrected.cpp pour la resolution du premier exerccice

/*
2. Traitement des cotes d'un examen avec un tableau :
I Déclarer un tableau pouvant contenir 10 nombres entiers (les cotes) ;
I Générer aléatoirement et stocker dans le tableau 10 cotes entre 0 et 20 ;
I Acher le tableau des cotes ;
I Acher la meilleure cote, la moins bonne cote et la moyenne ;
I Demander à l'utilisateur une cote entre 0 et 20, acher toutes les cotes
supérieures à cette valeur et indiquer quel pourcentage des résultats cela
représente.
*/

int A() {
    int scores[10];
    std::cout << "Scores : ";
    int min = 21, max = -1, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scores[i] = rand() % 21;
        if (scores[i] < min) min = scores[i];
        if (scores[i] > max) max = scores[i];
        sum += scores[i];
        std::cout << scores[i] << " ";
    }
    std::cout << "\nLa moyenne est de " << sum / 10 << "\nLe minimum est " << min << "\nLe maximum est " << max << std::endl;
    return 0;
}
Enregistreur regA(A);

/*
3. Recherche dans un tableau
I Créer un tableau de 50 éléments de type double ;
I Charger les nombres contenus dans le chier nombres.txt et les
stocker dans le tableau ;
I Acher le tableau ;
I Déterminer l'indice du plus petit élément du tableau ;
I Acher la valeur de cet élément et l'indice correspondant
*/

int B() {
    double nums[50] = { 0 };
    std::ifstream numbers("nombres.txt");
    if (!numbers.is_open()) {
        std::cout << "erreur lors de la lecture du fichier \"nombres.txt\", verifiez qu'il soit bien présent, disponible sur ecampus" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Le fichier contient ";
    int i = 0;
    int imin = 0;
    double nmin = 100000000; //big enough
    while (numbers.good()) {
        int a = 0;
        numbers >> a;
        if (a < nmin) {
            imin = i;
            nmin = a;
        }
        nums[i++] = a;
        std::cout << a << " ";
    }
    numbers.close();
    std::cout << "\nLe minimum est " << nmin << " à la position " << imin + 1 << std::endl;

/*
4. Tri de tableau :
Modier l'exercice précédent pour trier les éléments du tableau du plus petit au
plus grand. Les étapes pour y parvenir sont
I Acher le tableau non trié ;
I Parcourir le tableau à la recherche du plus petit élément ;
I Permuter cet élément avec le premier élément du tableau ;
I Chercher le plus petit élément parmi ceux restants (Remarque : les
éléments restants sont tous les éléments sauf le premier, dont on sait
désormais qu'il est le plus petit de tout le tableau) ;
I Permuter cet élément avec le second du tableau ;
I Poursuivre avec le 3e
, le 4e élément, etc... jusqu'à ce que le tableau soit
trié ;
I Acher le tableau trié.
*/

    std::cout << "\nExercice 4 : Tri du tableau" << std::endl;
    double temp = nmin;
    nums[imin] = nums[0];
    nums[0] = temp;
    std::cout << "Le tableau trié est " << temp;
    for (int i = 1; i < 50; i++)
    {
        imin = i;
        nmin = nums[i];
        for (int j = i + 1; j < 50; j++)
        {
            if (nums[j] < nmin) {
                imin = j;
                nmin = nums[j];
            }
        }
        temp = nmin;
        nums[imin] = nums[i];
        nums[i] = temp;
        std::cout << " " << temp;
    }

    return 0;
}
Enregistreur regB(B);

/*
5. Calcul d'un déterminant :
I Charger le chier matrice.txt contenant une matrice 3 × 3 dans un
tableau de nombres réels ;
I Acher la matrice (sous forme carrée) dans la console ;
I Calculer le déterminant de cette matrice ;
I Acher le résultat du calcul dans la console.
*/

int C()
{
    double matrix[3][3];
    std::ifstream fMatrice("matrice.txt");
    if (!fMatrice.is_open()) {
        std::cout << "Erreur lors du chargement du fichier matrice.txt, verifiez qu'il soit bien présent, dispo sur ecampus" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "La matrice contient :" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (!fMatrice.good()) {
            std::cout << "Vérifiez votre fichier matrice.txt" << std::endl;
            return EXIT_FAILURE;
        }
        fMatrice >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
        std::cout << matrix[i][0] << "\t" << matrix[i][1] << "\t" << matrix[i][2] << std::endl;
    }
    fMatrice.close();
    std::cout << "Le déterminant de la matrice est ";
    // implementation de la formule de Sarus
    double det = 0;
    for (int i = 0; i < 3; i++)
    {
        det += matrix[0][i] * matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3];
    }
    for (int i = 0; i < 3; i++)
    {
        det -= matrix[2][i] * matrix[1][(i + 1) % 3] * matrix[0][(i + 2) % 3];
    }
    std::cout << det << std::endl;

    return 0;
}
Enregistreur regC(C);

/*
6. Calcul de π par une série (formule de Leibniz) :
Soit la série qui converge vers π
[voir pdf, somme alternée des inverses des nombres impaires = π/4]
Ecrire un programme qui calcule les termes de cette série ainsi que la somme des termes.
I Calculer la série jusqu'à ce que le dernier terme soit successivement plus petit que 10−3, 10−6 puis 10−9.
Afficher le nombre de termes contenus
dans chacune de ces sommes, ainsi que la valeur de π que l'on peut en déduire ;
I Ecrire chacun de ces résultats dans un chier approx_pi.txt, ligne par
ligne, sous la forme PI = 3.1415... (avec x termes).
*/
int Dcalcul(double precision, int &termes, double &approx) {
    double lastTerme = 1;
    double sum = 0;
    int n = 0;
    std::cout << "Calcule d'une valeure de π avec une précision de " << precision << std::endl;
    while (abs(lastTerme) > precision) {
        if (n < 0) {
            std::cout << "Overflow" << std::endl;
            return EXIT_FAILURE;
        }
        lastTerme = ((double)(n % 2) * (-2) + 1) / (2 * (double)n + 1);
        sum += lastTerme;
        n++;
    }
    termes = n;
    approx = sum * 4;
}
int Dprint(double pi_approx[], int termes[]) {
    std::cout.precision(15);
    std::cout << "On obtient " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << pi_approx[i] << " avec " << termes[i] << " termes" << std::endl;
    }
    return 0;
}
int Dsave(double pi_approx[], int termes[]) {
    char filename[] = "approx_pi.txt";
    std::cout << "enregistrement de ces données dans " << filename << std::endl;
    std::ofstream approx(filename);
    if (!approx.is_open()) {
        std::cout << "erreur en ouvrant " << filename << std::endl;
        return EXIT_FAILURE;
    }
    approx.precision(15);
    for (int i = 0; i < 3; i++)
    {
        approx << "PI = " << pi_approx[i] << "... (avec " << termes[i] << " termes)" << std::endl;
    }
    approx.close();
    std::cout << "Les données ont été sauvegardées" << std::endl;
    return 0;
}
int D() {
    double precisions[] = { 1e-3, 1e-6, 1e-9 };
    double approximations[3] = { 0 };
    int termes[3] = { 0 };
    int i = 0;
    for  (double precision : precisions)
    {
        Dcalcul(precision, termes[i], approximations[i]);
        i++;
    }
    int r = Dprint(approximations, termes);
    if (r != 0) return r;
    r = Dsave(approximations, termes);
    if (r != 0) return r;
    return 0;
}
Enregistreur regD(D);
/*
7. Calcul de π par dichotomie :
Soit la fonction f (x) = cos(x) considéréé sur l'intervalle [0; 3], le zéro de f (x)
est x = π/2. Calculer le zéro de cos(x) permet donc de déterminer la valeur de
π.
Ecrire un programme qui permet de calculer ce zéro par la méthode de la
dichotomie. Cette méthode consiste à diviser de manière répétée l'intervalle sur
lequel le zéro est recherché (ici, [0; 3]) par 2, déterminer dans lequel des deux se
trouve le zéro, et ainsi de suite jusqu'à obtenir un intervalle de la précision
voulue autour de ce zéro. Pour ce faire, si [a; b] est l'intervalle sur lequel le zéro
est recherché :
7.1 Calculer f (a), f (b) et f (c), avec c = (a + b)/2 ;
I Si f (a) × f (c) < 0, on sait que le zéro se trouve dans [a; c]
I Si f (b) × f (c) < 0, on sait que le zéro se trouve dans [c; b]
7.2 Recommencer l'étape (1) avec le nouvel intervalle à considérer ([a; c] ou
[c; b]) ;
7.3 Procéder ainsi jusqu'à ce que l'intervalle [a; b] soit réduit à la précision
voulue e. Tester avec e = 10−9
;
7.4 En déduire la valeur de π ;
7.5 Ouvrir à nouveau le précédent chier approx_pi.txt et y ajouter une
ligne contenant PI = 3.1415... (dichotomie) à la suite des résultats
précédents.
*/
int E() {
    double a = 0, c = 1.5, b = 3;
    double e = 1e-9;
    std::cout << "Calcul de π par dichotomie" << std::endl;
    while (b - a > e) {
        double fa = cos(a), fc = cos(c); //fb inutile , fb = f(b)
        if (fa * fc < 0) {
            b = c;
            c = (b + a) / 2;
        }
        else {
            a = c;
            c = (b + a) / 2;
        }
    }
    double pi_approx = c * 2;

    std::cout.precision(15);
    std::cout << "On obtient " << c * 2 << std::endl;

    char filename[] = "approx_pi.txt";
    std::cout << "enregistrement de ces données dans " << filename << std::endl;
    std::ofstream approx(filename, std::ios::app);
    if (!approx.is_open()) {
        std::cout << "erreur en ouvrant " << filename << std::endl;
        return EXIT_FAILURE;
    }
    approx.precision(15);
    approx << "PI = " << pi_approx << "... (dichotomie)" << std::endl;
    approx.close();
    std::cout << "Les données ont été sauvegardées" << std::endl;
    return 0;
}
Enregistreur regE(E);
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
