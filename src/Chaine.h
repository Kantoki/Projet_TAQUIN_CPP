#ifndef CHAINE_H_
#define CHAINE_H_

/**
 * @file Chaine.h
 * Projet sem06-tp-Cpp1
 * @author l'équipe pédagogique
 * @version 2 26/11/15
 * @brief Composant de chaine
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Tableau2D.h"
#include "Etat.h"

// Elements qui constitueront la liste chainée
// NB: On a remplacé Item par Element, car Item est utilisé ailleurs (Tableau2D.h)
typedef Etat Element;

/** Type Maillon avec le principe du double chaînage
 *  (maillon suivant et maillon précedent)
 */
struct Maillon {
    Element elem;			// Elément (du maillon) de la liste chaînée
    Maillon* suiv;		// Pointeur sur le maillon suivant
    Maillon* prec;		// Pointeur sur le maillon précédent
};

/** Type Chaine
 *  Repères de début et de fin de chaîne
 *  Repère de l'élément courant
 */
 struct Chaine {
    Maillon* tete;		//Pointeur sur le maillon de tête
    Maillon* queue;		//Pointeur sur le maillon de queue
    Maillon* courant; 	//Pointeur sur le maillon courant
};

/**
 * brief Initialisation d'une chaîne
 * la chaîne est allouée en mémoire dynamique
 * la désallouer en fin d'utilisation (cf. detruire)
 * @param [in,out] c : la chaîne
 * @pos la chaîne est vide
 */
void initialiser(Chaine& c);

/**
 * brief Destruction d'une chaîne
 * la chaîne a été initialisée (cf. initialiserC)
 * @param [in,out] c : la chaîne
 * @pos la mémoire de chaîne est désallouée
 */
 void detruire(Chaine& c);

/**
 * @brief Test de chaîne vide
 * @param [in] c : la chaîne testée
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c);

/**
 * @brief Insertion d'un élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 * @param [in] elem : l'élément inséré
 */
 void inserer(Chaine& c, const Element& elem);

/**
 * @brief Suppression de l'élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 */
void supprimer(Chaine& c);

/**
 * @brief Ecriture d'un élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 * @param [in] elem : l'élément à écrire
 * @pre le maillon courant est dans la chaîne
 */
 void ecrire(Chaine& c, const Element& elem);

/**
 * @brief Lecture d'un élément à l'emplacement courant de la chaîne
 * @param [in] c : la chaîne
 * @return l'élément lu
 * @pre le maillon courant est dans la chaîne
 */
Element lire(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en début de chaîne
 * @param [in,out] c : la chaîne
 * @pre le maillon courant est dans la chaîne
 */
void debut(Chaine& c);

/**
 * @brief Test de debut de chaine
 * @param [in] c : la chaîne testée
 * @return true si le maillon courant est le début de chaîne, false sinon
 */
bool estDebut(const Chaine& c);

/**
 * @brief Positionnement du maillon courant en fin de chaîne
 * @param [in,out] c : la chaîne
 */
void fin(Chaine& c);

/**
 * @brief Test de fin de chaîne
 * @param [in] c : la chaîne testée
 * @return true si le maillon courant est la fin de chaîne, false sinon
 */
 bool estFin(const Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param [in,out] c : la chaîne
 * @pre le maillon courant est dans la chaîne
 */
void suivant(Chaine& c);

/**
 * @brief Positionnement du maillon courant au maillon précédent
 * @param [in,out] c : la chaîne
 * @pre le maillon courant n'est pas le début de chaîne
 */
void precedent(Chaine& c);

#endif /*CHAINE_H_*/
