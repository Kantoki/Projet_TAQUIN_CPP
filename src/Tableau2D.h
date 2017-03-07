#ifndef TABLEAU2D_H_INCLUDED
#define TABLEAU2D_H_INCLUDED

/**
 * @file Tableau2D.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 26/12/2015
 * @brief Composant des fonctions et structures d'un Tableau 2D
 */

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <iomanip>

typedef int Item ;

struct Tableau2D
{
    unsigned int lignes, colonnes;
    Item **damier;
};

/* -------------------------------------------------- */
/* -------------------- SPRINT 1 -------------------- */
/* -------------------------------------------------- */

/**
 * @brief initialiser, initialiser un damier de n lignes et p colonnes
 * @param [in-out] t, tableau à 2 dimensions à initialiser(Tableau2D)
 * @param [in] n, nombre de lignes
 * @param [in] p, nombre de lignes
*/
void initialiser(Tableau2D& t, int n, int p);

/**
 * @brief detruire, détruit un Tableau2D
 * @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Tableau2D& t);

/**
 * @brief lire,
 * @param [in-out] t, tableau à 2 dimensions à lire (Tableau2D)
*/
void lire(Tableau2D& t);

/**
 * @brief afficher, affiche le tableau 2D
 * @param [in] t, tableau 2D à afficher
*/
void afficher(const Tableau2D& t);

#endif // TABLEAU2D_H_INCLUDED
