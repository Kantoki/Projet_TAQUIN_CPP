#ifndef TAQUIN_H_INCLUDED
#define TAQUIN_H_INCLUDED

/**
 * @file Taquin.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions et structures liées à un jeu de Taquin
 */

#include "Liste.h"
#include "Pile.h"
#include "Etat.h"

using namespace std;

struct Taquin {
    Liste lee; // Liste des états explorés
    Liste leae; // Liste des états à explorer
    unsigned int lignes, colonnes; // Nombre de lignes et de colonnes du tableau considéré
};

/**
 * @brief initialiser, crée un jeu de taquin avec l'état initial
 * @param [in-out] t, Taquin à initialiser
*/
void initialiser(Taquin& t);

/**
 * @brief Deplace le # dans le damier, retourne l'état résultant
 * @param [in] mv, Direction dans laquelle doit bouger le #
 * @param [in] e, Etat depuis lequel le mouvement doit être effectué
 * @return er, etat résultant du mouvement
*/
Etat deplacement(Mouvement mv, const Etat& e);

/**
 * @brief Affiche le contenu des listes lee et leae
 * @param [in] Taquin t, le taquin à afficher
*/
void afficher(Taquin& t);

/**
 * @brief renvoie vrai si l'état existe déjà dans le taquin
 * @param [in] ef, état dont on doit vérifier l'existence
 * @param [in-out] t, taquin dans lequel la vérification se fait
 * @return res
*/
bool appartient(const Etat& ef, Taquin& t);


/**
 * @brief Renvoie vrai s’il s’agir de l’état final, faux sinon
 * @param [in] e
 * @return bool
*/
bool but(const Etat& e);

/**
 * @brief Indique si un unique état est de valeur f minimale dans leae
 * @param [in] t
 * @param [in] i, indice dans leae de l'état
 * @return true si unique valeur de f minimale dans leae, false sinon
*/
bool f_min(Taquin& t, unsigned int i);

/**
 * @brief Indique si parmi les états de LEAE de même valeur f minimale, l'état de LEAE est de valeur h minimale
 * @param [in] t
 * @param [in] i, indice dans leae de l'état
 * @return true si oui, false sinon
*/
bool h_min(Taquin& t, unsigned int i);

/**
 * @brief Retourne l’état le plus récemment inséré dans LEAE parmi les états de LEAE de même valeur f minimale et de même valeur h minimale)
 * @param [in] t
 * @return l'indice de l'état dans leae
*/
unsigned int h_min_rec(Taquin& t);

/**
 * @brief jouer, pour faire une itération de l'algorithme de recherche
 * @param [in-out] Taquin t, le taquin à résoudre
 * @return true si solution trouvée, false sinon
*/
bool jouer(Taquin& t);

/**
 * @brief Afficher la solution du taquin
 * @param [in-out] Taquin t, le taquin à résoudre
*/
void afficherSolution(Taquin& t);

#endif // TAQUIN_H_INCLUDED
