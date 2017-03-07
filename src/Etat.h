#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

/**
 * @file Etat.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions et structures liées à un état d'un taquin
 */

#include "Tableau2D.h"

enum Mouvement { NORD, SUD, EST, OUEST, FIXE };

/**
 * @brief afficher, affiche un mouvement
 * @param [in] mouvement e à afficher
*/
void afficher(Mouvement mv);

struct Etat {
    Tableau2D d; // Damier résultant
    Mouvement m; // Dernier mouvement de #
    unsigned int dp; // Index dans lee du damier précédent
    unsigned int g; // Nombre de coups
    unsigned int h; // Heuristique de e
    unsigned int x, y; // Coordonnées dans le damier résultant
};

/**
 * @brief Donne f d'un état
 * @param [in] état
 * @return f de l'état (g+h)
*/
unsigned int f(const Etat& e);

/**
 * @brief Renvoie true si les deux états sont semblables, false sinon
 * @param [in] e1
 * @param [in] e2
 * @return res
*/
bool isSame(const Etat& e1, const Etat& e2);

/**
 * @brief retourne l'heuristique, c-à-d, le nombre de case mal placé
 * @return h, l'heuristique
 * @param [in] état e
*/
unsigned int heuristique(Etat& e);

/**
 * @brief afficher, affiche un état du Taquin
 * @param [in] état e à afficher
*/
void afficher(const Etat& e);

#endif // ETAT_H_INCLUDED
