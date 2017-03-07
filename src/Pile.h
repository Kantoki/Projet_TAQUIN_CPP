#ifndef _PILE_
#define _PILE_

/**
 * @file Pile.hpp
 * Projet sem04-cours-Cpp2
 * @author l'�quipe p�dagogique
 * @version 1 - 23/12/05
 * @brief Composant de pile avec capacit� donn�e
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <cassert>
#include <iostream>

#include "Liste.h"
#include "Tableau2D.h"
#include "Etat.h"

using namespace std;

struct Pile {
	unsigned int capacite;  // capacit� de la pile
	Element* tab;				// tableau m�morisant les �l�ments de pile
	int sommet;				// indice, de sommet de pile, dans tab
};

/**
 * @brief Initialiser une pile vide
 * la pile est allou�e en m�moire dynamique
 * elle est � d�sallouer (cf. detruire) en fin d�utilisation
 * @param[in,out] p : la pile � initialiser (� vide)
 * @param[in] c : capacit� de la pile (nb maximum d�Elements stock�s)
 * @pre aucune (la pile peut d�j� �tre cr�e ou non)
 * @post p est vide
 */
void initialiser(Pile& p, unsigned int c);

/**
 * @brief D�sallouer une pile
 * la pile a �t� cr��e (cf. initialiser)
 * @param[in,out] p : la pile concern�e
 */
void detruire(Pile& p);

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile test�e
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p);

/**
 * @brief Test de pile vide
 * @param[in] p : la pile test�e
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p);

/**
 * @brief Empiler un Element sur la pile
 * @param[in,out] p : la pile concern�e
 * @param[in] it : l'Element � empiler
 * @pre p n�est pas pleine
 * @post p n�est pas vide, it est le sommet de p
 */
void empiler(Pile& p, const Element& it);

/**
 * @brief Lire l'Element au sommet de la pile
 * @param[in] p : la pile concern�e
 * @return la valeur de l'Element au sommet de pile
 * @pre la pile n�est pas vide
 */
Element sommet(const Pile& p);

/**
 * @brief D�piler l�Element sommet de pile
 * @param[in,out] p : la pile concern�e
 * @pre p n�est pas vide
 */
void depiler(Pile& p);

#endif


