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
 * @param [in-out] t, tableau � 2 dimensions � initialiser(Tableau2D)
 * @param [in] n, nombre de lignes
 * @param [in] p, nombre de lignes
*/
void initialiser(Tableau2D& t, int n, int p)
{
    t.lignes = n;
    t.colonnes = p;

    // On d�finit le tableau qui contient les adresses vers les colonnes du damier
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
 * @brief detruire, d�truit un Tableau2D
 * @param [in-out] t, tableau � 2 dimensions � d�truire (Tableau2D)
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
 * @param [in-out] t, tableau � 2 dimensions � d�truire (Tableau2D)
*/
void lire(Tableau2D& t)
{
    // On d�finit une variable contenant le nombre de chiffres � entrer
    int taille = t.lignes*t.colonnes;

    // On cr�e un tableau qui r�pertoriera toutes les entr�es de l'utilisateur, pour v�rifier plus tard que chaque chiffre a �t� entr� une fois.
    Item* entrees = new Item[taille];

    // Variable qui r�cup�rera l'entr�e de l'utilisateur
    string entree;

    // Variable qui contera le nombre de valeurs entr�es
    int nbValeurs = 0;

    // On demande les entr�es (d'abord des types Item), que l'on transforme en int par la suite (# = 0)
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
            // V�rifiation de la validit� de l'entr�e (comprise en 0 et taille)
            assert(atoi(entree.c_str()) < taille && atoi(entree.c_str()) > 0);
            entrees[i] = atoi(entree.c_str());
        }
        else
        {
            entrees[i] = 0;
        }

        nbValeurs++;
    }

    // Nous avons maintenant un tableau contenant toutes les entr�es.
    // Il faut maintenant les mettre dans le damier...

    // On r�initialise nbValeurs pour compter le nobre de valeurs entr�es dans le damier
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
 * @param [in] t, tableau 2D � afficher
*/
void afficher(const Tableau2D& t)
{
    for(unsigned int i = 0; i < t.lignes; i++)
    {
        for(unsigned int j = 0; j < t.colonnes; j++)
        {
            // On affiche le # � la place du 0
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




