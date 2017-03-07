/**
 * @file Etat.cpp
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 02/01/2016
 * @brief Composant des fonctions et structures liées à un état d'un taquin
 */

#include "Etat.h"

using namespace std;

/**
 * @brief Donne f d'un état
 * @param [in] état
 * @return f de l'état (g+h)
*/
unsigned int f(const Etat& e)
{
    return e.g+e.h;
}

/**
 * @brief Renvoie true si les deux états sont semblables, false sinon
 * @param [in] e1
 * @param [in] e2
 * @return bool;
*/
bool isSame(const Etat& e1, const Etat& e2)
{
    bool tmp = true;
    for(unsigned int i = 0; i < e1.d.lignes; i++)
    {
        for(unsigned int j = 0; j < e1.d.colonnes; j++)
        {
            if(e1.d.damier[i][j] != e2.d.damier[i][j])
            {
                tmp = false;
            }
        }
    }
    return tmp;
}

/**
 * @brief afficher, affiche un mouvement
 * @param [in] mouvement e à afficher
*/
void afficher(Mouvement mv)
{
    switch(mv)
    {
        case NORD:
            cout << "NORD" << endl;
            break;
        case OUEST:
            cout << "OUEST" << endl;
            break;
        case SUD:
            cout << "SUD" << endl;
            break;
        case EST:
            cout << "EST" << endl;
            break;
        case FIXE:
            cout << "FIXE" << endl;
            break;
    }
}

/**
 * @brief retourne l'heuristique, c-à-d, le nombre de case mal placé
 * @return h, l'heuristique
 * @param [in] état e
*/
unsigned int heuristique(Etat& e)
{
    unsigned int h = 0;
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

    for(unsigned int i = 0; i < eFinal.d.lignes; i++)
    {
        for(unsigned int j = 0; j < eFinal.d.colonnes; j++)
        {
            if((e.d.damier[i][j] != eFinal.d.damier[i][j]) && (e.d.damier[i][j] != 0))
            {
                h++;
            }
        }
    }

    return h;
}

/**
 * @brief afficher, affiche un état du Taquin
 * @param [in] état e à afficher
*/
void afficher(const Etat& e)
{
    // On affiche le dernier mouvement seulement s'il y en a eu au moins 1
    if(e.g > 0)
    {
        afficher(e.m);
    }

    // On affiche maintenant le damier résultant (fonction afficher(Tableau2D&))
    afficher(e.d);
}
