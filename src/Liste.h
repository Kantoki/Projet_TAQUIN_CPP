#ifndef LISTE_H_
#define LISTE_H_

/**
 * @file Liste.hpp
 * Projet sem06-tp-Cpp3
 * @author l'équipe pédagogique
 * @version 2 - 26/11/16
 * @brief Composant de liste d'Elements
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Chaine.h"

struct Liste {
    Chaine ch;	            // structure de stockage
	unsigned int nb;        // nombre d'éléments dans la liste
	unsigned int index;	    // index correspondant à la position courante dans la chaine
};

/**
 * @brief Initialiser une liste vide
 * la liste est allouée en mémoire dynamique
 * elle est à désallouer (cf. detruire) en fin d’utilisation
 * @param [in,out] l : la liste à créer (vide)
 * @pre aucune (la liste peut déjà être créée ou non)
 * @post l est vide
 */
void initialiser(Liste& l);

/**
 * @brief Désallouer une liste
 * la liste a été créée (cf. initialiser)
 * @param [in,out] l : la liste
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste
 * @param [in] l : la liste
 * @return la longueur
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un élément de liste
 * @param [in] l : la liste
 * @return l'Element lu
 * @pre 0<=i<=longueur(l)
 * @pos la liste est inchnangée
 */
Element lire(Liste& l, unsigned int i);

/**
 * @brief Ecrire un Element dans la liste
 * @param [in,out] l : la liste
 * @param [in] i : position de l'élément à écrire
 * @param [in] it : l'Element
 * @pre 0<=i<=longueur(l)
 * @pos it est en position i,
 *  la longueur de liste est inchangée
 */
void ecrire(Liste& l, unsigned int i, const Element& it);

/**
 * @brief Insérer un élément dans une liste
 * @param [in,out] l : la liste
 * @param [in] i : la position avant laquelle l'élément est inséré
 * @param [in] it : l'élément inséré
 * @pre 0<=i<=longueur(l)+1
 * @pos l'élément it inséré est en position i,
 *  la longueur de liste est incrémentée de 1
 */
void inserer(Liste& l, unsigned int i, const Element& it);

/**
 * @brief Supprimer un élément dans une liste
 * @param [in,out] l : la liste
 * @param [in] i : la position de l'élément à supprimer
 * @pre 0<=i<=longueur(l)
 * @pre 0<=i_s<longueur(l_s) et 0<=i_d<=longueur(l_d)
 * @pos la longueur de liste est diminuée de 1
 */
void supprimer(Liste& l, unsigned int i);

/**
 * @brief Déplacer un élément d'une liste à une autre
 * @param [in-out] l_s: liste source
 * @param [in-out] l_d: liste de destination
 * @param [in] i_s: index de l'élément dans la source
 * @param [in] i_d: index de l'élément dans la destination
*/
void deplacer(Liste& l_s, Liste& l_d, unsigned int i_s, unsigned int i_d);

#endif /*LISTE_H_*/
