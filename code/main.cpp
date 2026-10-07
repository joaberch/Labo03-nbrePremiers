#include <iostream>
#include <limits>
#include <iomanip>

/*
  ------------------------------------------------------------------------------
  Fichier     : main.cpp
  Auteur(s)   : Joachim Berchel
  Date        : 07.10.2026

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/

int main() {
    char restart = 'A';
    const short int n_col = 5;
    short int nbrPrime = 0;

    do {
        short int input = -1;
        do {
            std::cout << "entrer une valeur [2-1000] : ";
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (input <2||input >1000);

        std::cout << "Voici la liste des nombres premiers" << std::endl;

        for (short int i = 2; i <= input; i++) {
            bool isPrime = true;
            for (short int j = 2; j <= i-1; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                std::cout << std::setw(10) << i;
                ++nbrPrime;
                if (nbrPrime % n_col==0) {
                    std::cout << std::endl;
                }
            }
        }

        do {
            std::cout << "\nVoulez-vous recommencer [O/N] : ";
            std::cin >> restart;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (restart!='O'&&restart!='N');

    } while (restart=='O');
}
