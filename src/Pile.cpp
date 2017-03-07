/**
 * @file Pile.cpp
 * Projet sem04-cours-Cpp2
 * @author l'équipe pédagogique
 * @version 2 - 26/11/15
 * @brief Composant de pile avec capacité
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Pile.h"

/**
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * elle est é désallouer (cf. detruire) en fin déutilisation
 * @param[in,out] p : la pile à initialiser (à vide)
 * @param[in] c : capacité de la pile (nb maximum déElements stockés)
 * @pre aucune (la pile peut déjé étre crée ou non)
 * @post p est vide
 */
void initialiser(Pile& p, unsigned int c) {
	p.tab = new Element[c];
	p.sommet = -1;
	p.capacite = c;
}

/**
 * @brief Désallouer une pile
 * la pile a été initialisée (cf. creer)
 * @param[in,out] p : la pile concernée
 */
void detruire(Pile& p) {
	delete [] p.tab;
	p.tab = NULL;
}

/**
 * @brief Test de pile pleine
 * la pile a été créée (cf. creer)
 * @param[in] p : la pile testée
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p) {
	return (p.sommet == (p.capacite-1));
}

/**
 * @brief Test de pile vide
 * la pile a été créée (cf. creer)
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'Element au sommet de la pile
 * @param[in] p : la pile concernée
 * @return la valeur de l'Element au sommet de pile
 * @pre la pile néest pas vide
 */
Element sommet(const Pile& p) {
	assert(!estVide(p));
	return p.tab[p.sommet];
}

/**
 * @brief Empiler un Element sur la pile
 * la pile a été créée (cf. creer)
 * @param[in,out] p : la pile concernée
 * @param[in] it : l'Element à empiler
 * @pre p néest pas pleine
 * @post p n'est pas vide, it est le sommet de p
 */
void empiler(Pile& p, const Element& it) {
	assert(!estPleine(p));
	p.sommet++;
	p.tab[p.sommet] = it;
}

/**
 * @brief Dépiler léElement sommet de pile
 * la pile a été créée (cf. creer)
 * @param[in,out] p : la pile concernée
 * @pre p n'est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
