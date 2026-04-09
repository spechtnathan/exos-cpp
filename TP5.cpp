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
 * Exercice : Simple manipulation of strings
 * ============================================================================
 * * Description :
 * ============================================================================
 */
int Exercice1() {
    std::string str = "";
    std::getline(std::cin, str); // flush cin

    while (str.empty()) {
        std::cout << "Enter a string : ";
        std::getline(std::cin, str);
    }
    int length = str.length();
    std::cout << std::endl << "You wrote : \"" << str << "\" that is " << length << " characters" << std::endl;
    std::string mstr = str;
    if (96 < str[0] && str[0] < 123)
    {
        std::cout << "You forgot to capitalize the first letter." << std::endl;
        mstr[0] -= 32;
    }
    if (mstr[length - 1] != '.') {
        std::cout << "You forgot to end your text with a dot." << std::endl;
        mstr += '.';
    }
    if (mstr != str) {
        std::cout << "Here is your corrected text : " << std::endl;
        std::cout << mstr;
    }
    std::cout << "\nEnter a word to search in your text: ";
    std::string word;
    std::cin >> word;

    std::vector<size_t> occurrences; // Changed to size_t to match string indices
    size_t last = str.find(word);    // Perform the first search outside the loop

    // std::string::npos is the proper way to check if a string wasn't found
    while (last != std::string::npos) {
        occurrences.push_back(last);
        std::cout << last << ", ";

        // Advance 'last' by the word's length so we don't keep finding the same word
        last = str.find(word, last + word.length());
    }
    return 0;
}
Enregistreur reg1(Exercice1);

/**
 * ============================================================================
 * Exercice 2 : string and files
 * ============================================================================
 * * Description :
 * ============================================================================
 */
std::string formattage(std::string nom, std::string prenom) {
    prenom = prenom[0];
    return prenom + ". " + nom;
}
int Exercice2() {
    std::ifstream users("users.txt");
    if (!users.is_open()) {
        std::cout << "Error"; return 0;
    }
    std::string names[10];
    int i = 0;
    while (users.good()) {
        std::getline(users, names[i++]);
    }
    users.close();

    for (auto name : names) {
        std::string nom = name.substr(0, name.find(" "));
        std::string prenom = name.substr(name.find(" ") + 1);
        std::cout << formattage(nom, prenom) << std::endl;
    }
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
    std::ifstream presence("presence.txt");
    if (!presence.is_open()) {
        std::cout << "Error 0"; return 0;
    }
    std::string names[200];
    int i = 0;
    while (presence.good() && i < 200) {
        std::getline(presence, names[i++]);
    }
    presence.close();

    bool sorted = false;
    while (!sorted) {

        sorted = true;
        for (int i = 1; i < 200; i++)
        {
            if (names[i - 1] > names[i]) {
                std::string tmp = names[i];
                names[i] = names[i - 1];
                names[i - 1] = tmp;
                sorted = false;
            }
        }
    }
    std::ofstream save("presence_trie.txt");
    if (!save.is_open()) {
        std::cout << "Error 1"; return 0;
    }

    for (auto name : names) {
        save << name << std::endl;
    }

    save.close();

    std::string query;
    getline(std::cin, query);

    std::ofstream verif("verification_presence.txt");
    while (true)
    {
        std::cout << "\n-------------------\nSearch a name (empty or \"quitter\" to quit) : ";
        getline(std::cin, query);
        if (query.empty()) break;
        for (int i = 0; i < query.length(); i++)
            query[i] = toupper(query[i]);

        std::vector<std::string> founded;
        for (int i = 0; i < 200; i++)
        {
            if (names[i].find(query) != -1)
                founded.push_back(names[i]);
        }
        std::cout << "Que voulez-vous enrigistrer ? (saisir nombre) \n 0 - Ne pas enregister \n 1 - " << query << " est absent\n ";

        for (int i = 0; i < founded.size(); i++)
        {
            std::cout << i + 2 << " - " << founded[i] << " est présent\n ";
        }
        int respons;
        std::cin >> respons;

        std::cin.ignore(INT_MAX, '\n');

        if (respons == 1)
            verif << query << " est absent" << std::endl;
        else if (respons > 1 && respons < founded.size() + 2)
            verif << founded[respons - 2] << " est présent" << std::endl;
    }
    verif.close();

    return 0;
}
Enregistreur reg3(Exercice3);
/**
 * ============================================================================
 * Exercice 4 : code de César
 * ============================================================================
 * Description :
 * ============================================================================
 */
std::string chiffrement(std::string input, int key) {
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = (input[i] + key - 32) % 95 + 32;
    }
    return input;
}
int Exercice4() {
    std::string input = "";
    for (char i = 32; i < 127; i++)
    {
        input += i;
    }

    int key = 3;

    std::cout << input << std::endl;
    std::cout << chiffrement(input, key) << std::endl;

    std::ifstream message("message.txt");
    getline(message, input);
    message.close();

    std::cout << input << std::endl;
    std::cout << "key : ";
    std::string password;
    std::cin >> password;
    key = 0;
    for (auto passletter : password)
    {
        key += passletter;
    }
    std::string chiffre = chiffrement(input, key);
    std::cout << chiffre << std::endl;
    std::ofstream message_code("message_code.txt");
    message_code << chiffre;
    message_code.close();

    return 0;
}
Enregistreur reg4(Exercice4);
/**
 * ============================================================================
 * Exercice 5 : decode
 * ============================================================================
 * Description :
 * ============================================================================
 */
int Exercice5() {
    std::string input = "";

    int key = 0;

    std::ifstream message_code("message_code.txt");
    getline(message_code, input);
    std::cout << input << std::endl;
    message_code.close();
    
    int maxOccurences = 0;
    char mostPresentChar = 0;

    for (char i = 32; i < 127; i++)
    {
        size_t last = input.find(i);
        int occurence = 0;
        while (last != std::string::npos) {
            last = input.find(i, last + 1);
            occurence++;
        }
        if (occurence > maxOccurences) {
            maxOccurences = occurence;
            mostPresentChar = i;
        }

    }
    
    key = 127 - mostPresentChar;

    std::string chiffre = chiffrement(input, key);
    std::cout << chiffre << std::endl;
    std::ofstream message_decode("message_decode.txt");
    message_decode << chiffre;
    message_decode.close();

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
