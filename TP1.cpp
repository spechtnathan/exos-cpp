
#include <iostream>
#include <cmath>
using namespace std;

void Un() {
    int a;
    float b;
    double c;

    cout << "Saisissez un entier : ";
    cin >> a;
    cout << "Saisissez une float : ";
    cin >> b;
    cout << "Saisissez un double : ";
    cin >> c;
	cout.precision(15);
	cout << "Vous avez saisi : \nentier :" << a << " \nfloat : " << b << " \ndouble : " << c << endl;
}

void Deux() {
    int i1, i2;
    double d1, d2;

	cout << "Saisissez un entier : ";
    cin >> i1;
    cout << "Saisissez un entier : ";
    cin >> i2;
    cout << "Saisissez un double : ";
    cin >> d1;
    cout << "Saisissez un double : ";
	cin >> d2;

	cout << "Somme\n\tentiers : " << i1 + i2 << "\n\tdoubles : " << d1 + d2 << endl;
	cout << "Soustraction\n\tentiers : " << i1 - i2 << "\n\tdoubles : " << d1 - d2 << endl;
	cout << "Multiplication\n\tentiers : " << i1 * i2 << "\n\tdoubles : " << d1 * d2 << endl;
	cout << "Division\n\tentiers : " << i1 << "/" << i2 << " = " << i1 / i2 << " + " << i1 % i2 << " / " << i2 << " = " << (float)i1 / i2 << "\n\tdoubles : " << d1 / d2 << endl; // pour le modulo on peut utiliser fmod(i1,i2)

    cout << "a = " << i1 << " et b = " << i2 << ", on echange les deux variables" << endl;
	int temp = i1;
	i1 = i2;
	i2 = temp;
    cout << "a = " << i1 << " et b = " << i2 << endl;
}

void Troix() {
    float a;
	cout << "Saisissez un nombre reel : ";
    cin >> a;

    int b = (int)a;
    cout << a << " = " << b << " + " << a - b << endl;

    long long int c;
    cout << "Saisissez un numero de compte bancaire : ";
    cin >> c;

    long long int d = c / 100;
    int e = c % 100;
    int f = d % 97;
    if (e == f) {
		cout << "Le numero de compte bancaire est valide" << endl;
    }
    else {
		cout << "Le numero de compte bancaire n'est pas valide" << endl;
    }
}

void Quatre()
{
    float h, v, a;
    cout << "Saisissez les parametres :\n\t La hauteur du panier (default 3.05m) [m] : ";
    cin >> h;
    if (h == 0) {
        h = 3.05f;
    }
    cout << "\t La vitesse de tir [m/s] : ";
    cin >> v;
    cout << "\t L'augle de tir [degree] : ";
    cin >> a;
    float aRad = a * 0.0174532925;
    if (pow(v * sin(aRad), 2) < 2 * 9.81 * h) {
        cout << "Le tir est impossible" << endl;
        return;
    }
    else {
        float d = v * cos(aRad) / 9.81 * (v * sin(aRad) + sqrt(pow(v * sin(aRad), 2) - 2 * 9.81 * h));
        cout << "La distance de tir est " << d << " m" << endl;
    }

    int b;
	cout << "Saisir un nombre entier : ";
    cin >> b;
    for (int i = 2; i < 11; i++)
    {
        cout << "Le nombre " << (b % i == 0 ? "est" : "n'est pas") << " divisible par " << i << endl;
    }
    if(b > 0 && sqrt((double)b) == (int)sqrt((double)b)) {
        cout << "Le nombre " << b << " est un carre parfait" << endl;
    }
    else {
        cout << "Le nombre " << b << " n'est pas un carre parfait" << endl;
	}
}
void Cinq() {
    int s;
	cout << "Entrez un nombre de secondes : ";
    cin >> s;
    int h = s / 3600;
    int m = (s % 3600) / 60;
    int sec = s % 60;
    cout << "Cette duree correspond a ";
    if (h > 0) {
        cout << h << " heures ";
    }
    if (m > 0) {
        cout << m << " minutes ";
    }
    if (sec > 0) {
        cout << sec << " secondes";
    }
    cout << endl;
}
void Six() {
    float x, y, z;
    cout << "Saisir les composantes d'un vecteur : \n\tx : ";
    cin >> x;
    cout << "\ty : ";
    cin >> y;
    cout << "\tz : ";
    cin >> z;

    cout << "Le vecteur est (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "La norme est " << sqrt(x * x + y * y + z * z) << endl;
    cout << "Les angles polaires sont " << atan(y / x) << " rad et " << atan2(sqrt(x * x + y * y) / z) << " rad" << endl;
}
int main()
{
    while (true) {
        int choix = 3;
        cout << "\n\nChoisissez un exercice (1-6, 0 to quit) : ";
        cin >> choix;
        if (choix == 0) return 0;
        cout << "Exercice " << choix << "\n\n" << endl;
        switch (choix)
        {
        default:
            break;
        case 1:
            Un();
            break;
        case 2:
            Deux();
            break;
        case 3:
            Troix();
            break;
        case 4:
            Quatre();
            break;
        case 5:
            Cinq();
            break;
        case 6:
            Six();
            break;
        }
    }
}

