#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

/**
 * @file Etat.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions et structures li�es � un �tat d'un taquin
 */

#include "Tableau2D.h"

enum Mouvement { NORD, SUD, EST, OUEST, FIXE };

/**
 * @brief afficher, affiche un mouvement
 * @param [in] mouvement e � afficher
*/
void afficher(Mouvement mv);

struct Etat {
    Tableau2D d; // Damier r�sultant
    Mouvement m; // Dernier mouvement de #
    unsigned int dp; // Index dans lee du damier pr�c�dent
    unsigned int g; // Nombre de coups
    unsigned int h; // Heuristique de e
    unsigned int x, y; // Coordonn�es dans le damier r�sultant
};

/**
 * @brief Donne f d'un �tat
 * @param [in] �tat
 * @return f de l'�tat (g+h)
*/
unsigned int f(const Etat& e);

/**
 * @brief Renvoie true si les deux �tats sont semblables, false sinon
 * @param [in] e1
 * @param [in] e2
 * @return res
*/
bool isSame(const Etat& e1, const Etat& e2);

/**
 * @brief retourne l'heuristique, c-�-d, le nombre de case mal plac�
 * @return h, l'heuristique
 * @param [in] �tat e
*/
unsigned int heuristique(Etat& e);

/**
 * @brief afficher, affiche un �tat du Taquin
 * @param [in] �tat e � afficher
*/
void afficher(const Etat& e);

#endif // ETAT_H_INCLUDED
