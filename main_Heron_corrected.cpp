#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
    Calcul de la racine carree par la methode de Heron

    Soit a le nombre dont on veut extraire la racine carree:

    La suite definie par recurrence x' = (x + a/x)/2,
    ou x' est le terme suivant x dans la suite, converge de maniere quadratique
    vers la racine carree de a.

    Le programme ci-dessous demande un nombre a et une certaine precision au-delà
    de laquelle il cesse de calculer la série. Cette precision correspond a la difference
    entre deux termes successifs de la serie en-dessous de laquelle on arrete de calculer.

*/

int main()
{
    double a; // contient la valeur a dont on veut calculer sqrt(a)
    double x = 0; // contient x
    double x2 = 0; // contient le terme suivant x dans la suite
    double precision = 0; // difference entre deux termes successifs au-dessus de laquelle on continue a calculer
    int iterateur = 0; // Compteur du nombre d'itérations

    do
    {
        cout << "Quel est le nombre dont vous voulez calculer la racine carree ? " << endl;
        cin >> a;
    } while (a < 0);  // On ne peut calculer la racine carree que d'un nombre positif

    cout << "Quel precision voulez - vous choisir ? ";
    cin >> precision;

    cout.precision(15);

    cout << "Debut du calcul de la racine de " << a << " avec une precision de " << precision << endl;

    x2 = a; // valeur estimee initiale choisie: a

    do
    {
        x = x2; // on conserve l'ancienne valeur de x2
        x2 = (x + a / x) / 2.;

        iterateur++; // on incrémente la valeur de l'itérateur à chaque passage dans la boucle

    } while (fabs(x2 - x) > precision);  // on calcule tant que la difference est plus grande que la precision

    cout << "sqrt(" << a << ") = " << x2 << " (apres " << iterateur << " iterations)" << endl;

    return 0;
}
