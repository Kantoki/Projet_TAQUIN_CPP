/**
 * @file Tableau2D.cpp
 * Projet SDA
 * @author Kilian CHOLLET, Abdulmajid NASSER
 * @version 1 - 26/12/2015
 * @brief Composant des fonctions d'un Tableau 2D
 */

#include "tableau2D.h"

using namespace std;

/* -------------------------------------------------- */
/* -------------------- SPRINT 1 -------------------- */
/* -------------------------------------------------- */

/**
 * @brief initialiser, initialiser un damier de n lignes et p colonnes
 * @param [in-out] t, tableau à 2 dimensions à initialiser(Tableau2D)
 * @param [in] n, nombre de lignes
 * @param [in] p, nombre de lignes
*/
void initialiser(Tableau2D& t, int n, int p)
{
    t.lignes = n;
    t.colonnes = p;

    // On définit le tableau qui contient les adresses vers les colonnes du damier
    t.damier = new(nothrow) Item*[t.lignes];
    if(t.damier == NULL)
    {
        cerr << "Allocation en memoire impossible." << endl;
        exit(1);
    }

    for(unsigned int i = 0; i < t.lignes; i++)
    {
        // On alloue dynamiquement chaque colonne du damier
        t.damier[i] = new(nothrow) Item[t.colonnes];
        if(t.damier[i] == NULL)
        {
            cerr << "Allocation en memoire impossible." << endl;
            exit(1);
        }
    }
}

/**
 * @brief detruire, détruit un Tableau2D
 * @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Tableau2D& t)
{
    for(unsigned int i = 0; i < t.lignes; i++)
    {
        delete[] t.damier[i];
    }
    delete[] t.damier;
    t.damier = NULL;
}

/**
 * @brief lire,
 * @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void lire(Tableau2D& t)
{
    // On définit une variable contenant le nombre de chiffres à entrer
    int taille = t.lignes*t.colonnes;

    // On crée un tableau qui répertoriera toutes les entrées de l'utilisateur, pour vérifier plus tard que chaque chiffre a été entré une fois.
    Item* entrees = new Item[taille];

    // Variable qui récupérera l'entrée de l'utilisateur
    string entree;

    // Variable qui contera le nombre de valeurs entrées
    int nbValeurs = 0;

    // On demande les entrées (d'abord des types Item), que l'on transforme en int par la suite (# = 0)
    // Note : pour convertir string str en int, on utilise : atoi( str.c_str() )
    for(int i = 0; i < taille; i++)
    {
        cin >> entree;

        for(int j = 0; j < nbValeurs; j++)
        {
            if(atoi(entree.c_str()) == entrees[j] && entree != "#")
            {
                cout << "Erreur : une nombre a ete entre 2 fois." << endl;
                exit(1);
            }
        }

        // Transformation des string en int, le # qui se transforme en 0 (on l'affichera cependant sous forme de #)
        if(entree != "#")
        {
            // Vérifiation de la validité de l'entrée (comprise en 0 et taille)
            assert(atoi(entree.c_str()) < taille && atoi(entree.c_str()) > 0);
            entrees[i] = atoi(entree.c_str());
        }
        else
        {
            entrees[i] = 0;
        }

        nbValeurs++;
    }

    // Nous avons maintenant un tableau contenant toutes les entrées.
    // Il faut maintenant les mettre dans le damier...

    // On réinitialise nbValeurs pour compter le nobre de valeurs entrées dans le damier
    nbValeurs = 0;

    // Insertion des valeurs de entrees dans le damier
    for(unsigned int i = 0; i < t.lignes; i++)
    {
        for(unsigned int j = 0; j < t.colonnes; j++)
        {
            t.damier[i][j] = entrees[nbValeurs];
            nbValeurs++;
        }
    }

}

/**
 * @brief afficher, affiche le tableau 2D
 * @param [in] t, tableau 2D à afficher
*/
void afficher(const Tableau2D& t)
{
    for(unsigned int i = 0; i < t.lignes; i++)
    {
        for(unsigned int j = 0; j < t.colonnes; j++)
        {
            // On affiche le # à la place du 0
            if(t.damier[i][j] != 0)
            {
                cout << setw(3) << t.damier[i][j];
            }
            else
            {
                cout << setw(3) << "#";
            }
        }
        cout << endl;
    }
}




