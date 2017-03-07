#ifndef _PILE_
#define _PILE_

/**
 * @file Pile.hpp
 * Projet sem04-cours-Cpp2
 * @author l'équipe pédagogique
 * @version 1 - 23/12/05
 * @brief Composant de pile avec capacité donnée
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <cassert>
#include <iostream>

#include "Liste.h"
#include "Tableau2D.h"
#include "Etat.h"

using namespace std;

struct Pile {
	unsigned int capacite;  // capacité de la pile
	Element* tab;				// tableau mémorisant les éléments de pile
	int sommet;				// indice, de sommet de pile, dans tab
};

/**
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * elle est à désallouer (cf. detruire) en fin d’utilisation
 * @param[in,out] p : la pile à initialiser (à vide)
 * @param[in] c : capacité de la pile (nb maximum d‘Elements stockés)
 * @pre aucune (la pile peut déjà être crée ou non)
 * @post p est vide
 */
void initialiser(Pile& p, unsigned int c);

/**
 * @brief Désallouer une pile
 * la pile a été créée (cf. initialiser)
 * @param[in,out] p : la pile concernée
 */
void detruire(Pile& p);

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testée
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p);

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p);

/**
 * @brief Empiler un Element sur la pile
 * @param[in,out] p : la pile concernée
 * @param[in] it : l'Element à empiler
 * @pre p n’est pas pleine
 * @post p n’est pas vide, it est le sommet de p
 */
void empiler(Pile& p, const Element& it);

/**
 * @brief Lire l'Element au sommet de la pile
 * @param[in] p : la pile concernée
 * @return la valeur de l'Element au sommet de pile
 * @pre la pile n’est pas vide
 */
Element sommet(const Pile& p);

/**
 * @brief Dépiler l’Element sommet de pile
 * @param[in,out] p : la pile concernée
 * @pre p n’est pas vide
 */
void depiler(Pile& p);

#endif


