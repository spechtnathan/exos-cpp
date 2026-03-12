#include <iostream>

int main() {
	// Construire un projet “Hello World !”, le compiler et l’exécuter;

	std::cout << "Hello World !" << std::endl;

	/*
	Construire un programme affichant les premi`eres d´ecimales du
		nombre d’or Φ = 1.618033988749894848204586..., avec
		successivement
		I la pr´ecision par d´efaut de cout;
		I 15 chiffres significatifs;
		I 10 chiffres significatifs.
	*/
	double phi = 1.618033988749894848204586;

	std::cout << phi << std::endl;
	std::cout.precision(15);
	std::cout << phi << std::endl;
	std::cout.precision(10);
	std::cout << phi << std::endl;

	/*
	Construire un programme affichant `a l’´ecran un dessin de
		votre choix `a l’aide de caract`eres tels que *, +, , -, etc...
		^__^
		(oo)\_______
		(__)\       )\/\
		   ||----w |
		   ||     ||
	*/

	std::cout << "^__^\n(oo)\\_______\n(__)\\       )\\ / \\\n   || ----w |\n   ||      ||" << std::endl;
}
