#ifndef TAQUIN_H_INCLUDED
#define TAQUIN_H_INCLUDED

/**
 * @file Taquin.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions et structures li�es � un jeu de Taquin
 */

#include "Liste.h"
#include "Pile.h"
#include "Etat.h"

using namespace std;

struct Taquin {
    Liste lee; // Liste des �tats explor�s
    Liste leae; // Liste des �tats � explorer
    unsigned int lignes, colonnes; // Nombre de lignes et de colonnes du tableau consid�r�
};

/**
 * @brief initialiser, cr�e un jeu de taquin avec l'�tat initial
 * @param [in-out] t, Taquin � initialiser
*/
void initialiser(Taquin& t);

/**
 * @brief Deplace le # dans le damier, retourne l'�tat r�sultant
 * @param [in] mv, Direction dans laquelle doit bouger le #
 * @param [in] e, Etat depuis lequel le mouvement doit �tre effectu�
 * @return er, etat r�sultant du mouvement
*/
Etat deplacement(Mouvement mv, const Etat& e);

/**
 * @brief Affiche le contenu des listes lee et leae
 * @param [in] Taquin t, le taquin � afficher
*/
void afficher(Taquin& t);

/**
 * @brief renvoie vrai si l'�tat existe d�j� dans le taquin
 * @param [in] ef, �tat dont on doit v�rifier l'existence
 * @param [in-out] t, taquin dans lequel la v�rification se fait
 * @return res
*/
bool appartient(const Etat& ef, Taquin& t);


/**
 * @brief Renvoie vrai s�il s�agir de l��tat final, faux sinon
 * @param [in] e
 * @return bool
*/
bool but(const Etat& e);

/**
 * @brief Indique si un unique �tat est de valeur f minimale dans leae
 * @param [in] t
 * @param [in] i, indice dans leae de l'�tat
 * @return true si unique valeur de f minimale dans leae, false sinon
*/
bool f_min(Taquin& t, unsigned int i);

/**
 * @brief Indique si parmi les �tats de LEAE de m�me valeur f minimale, l'�tat de LEAE est de valeur h minimale
 * @param [in] t
 * @param [in] i, indice dans leae de l'�tat
 * @return true si oui, false sinon
*/
bool h_min(Taquin& t, unsigned int i);

/**
 * @brief Retourne l��tat le plus r�cemment ins�r� dans LEAE parmi les �tats de LEAE de m�me valeur f minimale et de m�me valeur h minimale)
 * @param [in] t
 * @return l'indice de l'�tat dans leae
*/
unsigned int h_min_rec(Taquin& t);

/**
 * @brief jouer, pour faire une it�ration de l'algorithme de recherche
 * @param [in-out] Taquin t, le taquin � r�soudre
 * @return true si solution trouv�e, false sinon
*/
bool jouer(Taquin& t);

/**
 * @brief Afficher la solution du taquin
 * @param [in-out] Taquin t, le taquin � r�soudre
*/
void afficherSolution(Taquin& t);

#endif // TAQUIN_H_INCLUDED
