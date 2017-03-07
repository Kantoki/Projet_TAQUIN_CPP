/**
 * @file main.cpp
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 31/12/2015
 * @brief Fonction principale du programme pour résoudre un jeu de taquin
 */

#include "Taquin.h"

using namespace std;

/* ---------- POUR LE DEBUGGAGE ---------- */
bool LOGGING_ON = false;
void log(const char* msg)
{
    if(LOGGING_ON)
    {
        cout << msg << endl;
    }
}
/* ---------------------------------------- */

int main()
{
    Taquin t;

    initialiser(t);

    do{} while(!jouer(t));
    afficherSolution(t);

    return 0;
}
