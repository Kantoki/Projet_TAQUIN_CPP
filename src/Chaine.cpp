/**
 * @file Chaine.cpp
 * Projet sem06-tp-Cpp1
 * @author l'équipe pédagogique
 * @version 2 26/11/15
 * @brief Composant de chaine
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "Chaine.h"

/**
 * brief Initialisation d'une chaîne
 * la chaîne est allouée en mémoire dynamique
 * la désallouer en fin d'utilisation (cf. detruire)
 * @param[in,out] c : la chaîne
 * @pos la chaîne est vide
 */
void initialiser(Chaine& c) {
	c.tete = c.queue = c.courant = NULL;
}

/**
 * @brief Destruction d'une chaîne
 * la chaîne a été créée (cf. initialiserC)
 * @param [in,out] c : la chaîne
 * @pos la mémoire de chaîne est désallouée
 */
void detruire(Chaine& c) {
	debut(c);
	while (!estVide(c))
	supprimer(c);
}

/**
 * @brief Test de chaîne vide
 * @param [in] c : la chaîne testée
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c) {
	return (c.tete == NULL);
}

/**
 * @brief Insertion d'un élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 * @param [in] elem : l'élément inséré
 */
void inserer(Chaine& c, const Element& elem) {
	Maillon* m = new Maillon;
	m->elem = elem;
	m->suiv = c.courant;

	// ajout en tête de chaîne
	if (c.courant == c.tete) {
		m->prec = NULL;
		if (c.tete != NULL)
			c.tete->prec = m;
		else c.queue = m;
		c.courant = c.tete = m;
	}

	// ajout en queue de chaine
	if (c.courant == NULL) {
		m->prec = c.queue;
		c.queue->suiv = m;
		c.courant = c.queue = m;
	}

	// ajout ni en tête ni en queue de chaine
    if ((c.courant != c.tete) && (c.courant != c.queue)) {
		m->prec = c.courant->prec;
		c.courant->prec->suiv = m;
		c.courant->prec = m;
		c.courant = m;
	}
}

/**
 * @brief Suppression de l'élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 * @pre le maillon courant est dans la chaîne
 */
void supprimer(Chaine& c) {
	assert(c.courant != NULL);

	Maillon* m = c.courant;

	// suppression d'un maillon en début de chaine
	if (c.courant == c.tete) {
		c.courant = c.tete = c.tete->suiv;
		if (estVide(c)) c.queue = NULL;
		else c.tete->prec = NULL;
		delete m;
		return;
	}

	// suppression d'un maillon en queue de chaine
	if (c.courant == c.queue) {
		c.queue = c.queue->prec;
		c.courant = c.queue->suiv = NULL;
		delete m;
		return;
	}

	// suppression d'un maillon ni en tête ni en queue de chaine
  	if ((c.courant != c.tete) && (c.courant != c.queue)) {
  		c.courant->prec->suiv = c.courant->suiv;
		c.courant->suiv->prec = c.courant->prec;
		c.courant = c.courant->suiv;
		delete m;
	}

}

/**
 * @brief Ecriture d'un élément à l'emplacement courant de la chaîne
 * @param [in,out] c : la chaîne
 * @param [in] elem : l'élément à écrire
 * @pre le maillon courant est dans la chaîne
 */
void ecrire(Chaine& c, const Element& elem) {
	assert(c.courant != NULL);
	c.courant->elem = elem;
}

/**
 * @brief Lecture d'un élément à l'emplacement courant de la chaîne
 * @param [in] c : la chaîne
 * @return l'élément lu
 * @pre le maillon courant est dans la chaîne
 */
Element lire(const Chaine& c) {
	assert(c.courant != NULL);
	return c.courant->elem;
}

/**
 * @brief Positionnement du maillon courant en début de chaîne
 * @param [in,out] c : la chaîne
 */
void debut(Chaine& c) {
	c.courant = c.tete;
}

/**
 * @brief Test de debut de chaine
 * @param [in] c : la chaîne testée
 * @return true si le maillon courant est le début de chaîne, false sinon
 */
bool estDebut(const Chaine& c) {
	return (c.courant == c.tete);
}

/**
 * @brief Positionnement du maillon courant en fin de chaîne
 * @param [in,out] c : la chaîne
 */
void fin(Chaine& c) {
	c.courant = NULL;
}

/**
 * @brief Test de fin de chaîne
 * @param [in] c : la chaîne testée
 * @return true si le maillon courant est la fin de chaîne, false sinon
 */
bool estFin(const Chaine& c) {
	return (c.courant == NULL);
}

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param [in,out] c : la chaîne
 * @pre le maillon courant est dans la chaîne
 */
void suivant(Chaine& c) {
	assert(c.courant != NULL);
	c.courant = c.courant->suiv;
}

/**
 * @brief Positionnement du maillon courant au maillon précédent
 * @param [in,out] c : la chaîne
 * @pre le maillon courant n'est pas le début de chaîne
 */
void precedent(Chaine& c) {
	assert(c.courant != c.tete);
	if (c.courant == NULL)
		c.courant = c.queue;
	else c.courant = c.courant->prec;
}
