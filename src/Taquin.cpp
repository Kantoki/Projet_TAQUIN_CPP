/**
 * @file Taquin.h
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions liées à un jeu de Taquin
 */

#include "Taquin.h"

/**
 * @brief initialiser, crée un jeu de taquin avec l'état initial
 * @param [in-out] t, Taquin à initialiser
*/
void initialiser(Taquin& t)
{
    // Déclaration et initialisation de lee - Liste de Etats Explorés)
    Liste lee;
    initialiser(lee);

    // Déclaration et initialisation de leae - Liste de Etats A Explorer)
    Liste leae;
    initialiser(leae);

    // Demande du nbre de colonnes et de lignes à partir du flot d'entrée standard
    unsigned int lignes, colonnes;
    cin >> lignes;
    cin >> colonnes;

    Etat e_init; // Déclaration de l'état initial
    e_init.d.lignes = lignes;
    e_init.d.colonnes = colonnes;

    // Initialisation du damier initial
    initialiser(e_init.d, lignes, colonnes);

    // Lecture du damier initial
    lire(e_init.d);

    // On définit le mouvement initial à FIXE puisqu'il n'y en a pas encore eu,
    // ainsi que g, le nombre de mouvements à 0
    e_init.m = FIXE;
    e_init.g = 0;
    e_init.h = heuristique(e_init);

    // On cherche le # dans le damier (qui vaut 0) pour obtenir ses coordonnées
    for(unsigned int i = 0; i < lignes; i++)
    {
        for(unsigned int j = 0; j < colonnes; j++)
        {
            if(e_init.d.damier[i][j] == 0)
            {
                // Obtention des coordonnées du 0
                e_init.x = i;
                e_init.y = j;
            }
        }
    }

    // On copie les liste dans t.leae et t.lee
    t.leae = leae;
    t.lee = lee;

    // On détruit les deux listes devenues obsolètes
    detruire(leae);
    detruire(lee);

    // On insère dans leae l'état initial que nous venons de créer
    inserer(t.leae, 0, e_init);

    // On affiche le nombre de lignes et de colonnes du taquin
    cout << "Damier : " << lignes << " lignes, " << colonnes << " colonnes" << endl;
}


/**
 * @brief Deplace le # dans le damier, retourne l'état résultant
 * @param [in] mv, Direction dans laquelle doit bouger le #
 * @param [in] e, Etat depuis lequel le mouvement doit être effectué
 * @return er, etat résultant du mouvement
*/
Etat deplacement(Mouvement mv, const Etat& e)
{
    Etat er;
    initialiser(er.d, e.d.lignes, e.d.colonnes);
    for(unsigned int i = 0; i < er.d.lignes; i++)
    {
        for(unsigned int j = 0; j < er.d.colonnes; j++)
        {
            er.d.damier[i][j] = e.d.damier[i][j];
        }
    }
    er.x = e.x;
    er.y = e.y;
    er.m = mv;
    er.g = e.g + 1;

    switch(mv)
    {
        case NORD:
            er.d.damier[er.x][er.y] = er.d.damier[er.x-1][er.y];
            er.d.damier[er.x-1][er.y] = 0;
            er.x--;
            break;
        case OUEST:
            er.d.damier[er.x][e.y] = er.d.damier[er.x][er.y-1];
            er.d.damier[er.x][er.y-1] = 0;
            er.y--;
            break;
        case SUD:
            er.d.damier[er.x][er.y] = er.d.damier[er.x+1][er.y];
            er.d.damier[er.x+1][er.y] = 0;
            er.x++;
            break;
        case EST:
            er.d.damier[er.x][er.y] = er.d.damier[er.x][er.y+1];
            er.d.damier[er.x][er.y+1] = 0;
            er.y++;
            break;
        case FIXE:
            return er;
    }
    er.h = heuristique(er);

    return er;
}

/**
 * @brief Affiche le contenu des listes lee et leae
 * @param [in] Taquin t, le taquin à afficher
*/
void afficher(Taquin& t)
{
    cout << endl << "*** LEAE - long : " << longueur(t.leae) << endl;
    for(unsigned int i = 0; i < longueur(t.leae); i++)
    {
        afficher(lire(t.leae, i));
    }
}

/**
 * @brief renvoie vrai si l'état existe déjà dans le taquin
 * @param [in] ef, état dont on doit vérifier l'existence
 * @param [in-out] t, taquin dans lequel la vérification se fait
 * @return res
*/
bool appartient(const Etat& ef, Taquin& t)
{
    for(unsigned int i = 0; i < longueur(t.lee); i++)
    {
        if(isSame(lire(t.lee, i), ef))
        {
            return true;
        }
    }
    for(unsigned int i = 0; i < longueur(t.leae); i++)
    {
        if(isSame(lire(t.leae, i), ef))
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Renvoie vrai s’il s’agir de l’état final, faux sinon
 * @param [in] e
 * @return bool
*/
bool but(const Etat& e)
{
    // On crée l'état final
    Etat eFinal;
    initialiser(eFinal.d, e.d.lignes, e.d.colonnes);
    unsigned int cpt = 1;
    for(unsigned int i = 0; i < eFinal.d.lignes; i++)
    {
        for(unsigned int j = 0; j < eFinal.d.colonnes; j++)
        {
            if(cpt == eFinal.d.lignes*eFinal.d.colonnes)
            {
                eFinal.d.damier[i][j] = 0;
            }
            else
            {
                eFinal.d.damier[i][j] = cpt;
                cpt++;
            }
        }
    }

    return isSame(eFinal, e);
}

/**
 * @brief Indique si un unique état est de valeur f minimale dans leae
 * @param [in-out] t
 * @param [in] i, indice dans leae de l'état
 * @return true si unique valeur de f minimale dans leae, false sinon
*/
bool f_min(Taquin& t, unsigned int i)
{
    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if(f(lire(t.leae, j)) <= f(lire(t.leae, i)))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Indique si parmi les états de LEAE de même valeur f minimale, l'état de LEAE est de valeur h minimale
 * @param [in] t
 * @param [in] i, indice dans leae de l'état
 * @return true si oui, false sinon
*/
bool h_min(Taquin& t, unsigned int i)
{
    unsigned int fmin = f(lire(t.lee, 0));
    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if(f(lire(t.leae, j)) < fmin)
        {
            fmin = f(lire(t.leae, j));
        }
    }
    if(f(lire(t.leae, i)) != fmin)
    {
        return false;
    }
    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if(f(lire(t.leae, j)) == fmin)
        {
            if(lire(t.leae, i).h >= lire(t.leae, j).h)
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Retourne l’état le plus récemment inséré dans LEAE parmi les états de LEAE de même valeur f minimale et de même valeur h minimale)
 * @param [in] t
 * @return l'indice de l'état dans leae
*/
unsigned int h_min_rec(Taquin& t)
{
    unsigned int indice = 0;
    unsigned int fmin = f(lire(t.leae, 0)), hmin = lire(t.leae, 0).h;
    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if(f(lire(t.leae, j)) < fmin)
        {
            fmin = f(lire(t.leae, j));
            hmin = lire(t.leae, j).h;
        }
    }
    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if(f(lire(t.leae, j)) == fmin)
        {
            fmin = f(lire(t.leae, j));
            if(hmin > lire(t.leae, j).h)
            {
                hmin = lire(t.leae, j).h;
            }
        }
    }

    for(unsigned int j = 0; j < longueur(t.leae); j++)
    {
        if((f(lire(t.leae, j)) == fmin) && (hmin == lire(t.leae, j).h))
        {
            return j;
        }
    }
    return indice;
}

/**
 * @brief jouer, pour faire une itération de l'algorithme de recherche
 * @param [in-out] Taquin t, le taquin à résoudre
 * @return true si solution trouvée, false sinon
*/
bool jouer(Taquin& t)
{
    Etat courant;
    // Indice
    unsigned int iCourant;
    if(longueur(t.leae) == 1)
    {
        iCourant = 0;
    }
    else
    {
        for(unsigned int i = 0; i < longueur(t.leae); i++)
        {
            if(f_min(t, i))
            {
                iCourant = i;
            }
            else if(h_min(t, i))
            {
                iCourant = i;
            }
            else
            {
                iCourant = h_min_rec(t);
            }
        }
    }

    courant = lire(t.leae, iCourant);

    if(but(courant))
    {
        return true;
    }

    // Déplacement du dernier état ajouté dans leae dans lee
    // NB: A modifier quand l'heuristque sera à traiter
    deplacer(t.leae, t.lee, iCourant, longueur(t.lee));

    Etat temp;

    // Si c'est possible, on insère dans leae les états qui découlent du dernier état entré dans lee
    if(courant.x > 0)
    {
        if(!appartient(deplacement(NORD, courant), t))
        {
            temp = deplacement(NORD, courant);
            temp.dp = longueur(t.lee)-1;
            inserer(t.leae, 0, temp);
        }
    }
    if(courant.y > 0)
    {
        if(!appartient(deplacement(OUEST, courant), t))
        {
            temp = deplacement(OUEST, courant);
            temp.dp = longueur(t.lee)-1;
            inserer(t.leae, 0, temp);
        }
    }
    if(courant.x < courant.d.lignes-1)
    {
        if(!appartient(deplacement(SUD, courant), t))
        {
            temp = deplacement(SUD, courant);
            temp.dp = longueur(t.lee)-1;
            inserer(t.leae, 0, temp);
        }
    }
    if(courant.y < courant.d.colonnes-1)
    {
        if(!appartient(deplacement(EST, courant), t))
        {
            temp = deplacement(EST, courant);
            temp.dp = longueur(t.lee)-1;
            inserer(t.leae, 0, temp);
        }
    }

    return false;
}

/**
 * @brief Afficher la solution du taquin
 * @param [in-out] Taquin t, le taquin à résoudre
*/
void afficherSolution(Taquin& t)
{
    Etat solution;
    for(unsigned int i = 0; i < longueur(t.leae); i++)
    {
        if(but(lire(t.leae, i)))
        {
            solution = lire(t.leae, i);
        }
    }
    cout << "Solution en " << solution.g << " mouvements" << endl;
    Pile arbre_solution;
    initialiser(arbre_solution, solution.g+1);
    empiler(arbre_solution, solution);
    for(unsigned int i = 1; i < solution.g+1; i++)
    {
        empiler(arbre_solution, lire(t.lee, sommet(arbre_solution).dp));
    }

    do
    {
        afficher(sommet(arbre_solution));
        depiler(arbre_solution);
    }
    while(!estVide(arbre_solution));
}
