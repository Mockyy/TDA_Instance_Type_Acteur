#include "defineform.h"

/************************
Principe : initialise la file

Entrée : la file

Sortie :

Note :
***********************/
void initialisation(tFile *suite)
{
    suite->debut = NULL;
    suite->fin = NULL;
    suite->taille = 0;
}


/************************
Principe : ajoute un élément à la file

Entrée : la file, la fin de la file, et un élément

Sortie :

Note :
***********************/
int enFiler(tFile *suite, tElement *courant, tActor *donnee)
{
    tElement *nouvel_element;

    if((nouvel_element = malloc(sizeof(tElement))) == NULL)
        return -1;
    if((nouvel_element->donnee = malloc(sizeof(tActor))) == NULL)
        return -1;

    nouvel_element->donnee = donnee;

    if(courant == NULL && suite->taille == 0)
    {
        suite->fin = nouvel_element;
        nouvel_element->suivant = suite->debut;
        suite->debut = nouvel_element;
    }
    else
    {
        if(courant->suivant == NULL)
        {
            suite->fin = nouvel_element;
            nouvel_element->suivant = courant->suivant;
            courant->suivant = nouvel_element;
        }
    }

    suite->taille++;

    return 0;
}


/************************
Principe : enlève un élément de la file

Entrée : la file

Sortie :

Note : trouver un moyen de supprimer la texture du renderer après sa copie
***********************/
int deFiler(tFile *suite)
{
    tElement *supp_element;

    if(suite->taille == 0)
        return -1;

    supp_element = suite->debut;
    suite->debut = suite->debut->suivant;

    SDL_DestroyTexture(supp_element->donnee->textActor);
    free(supp_element->donnee);

    suite->taille--;

    return 0;
}


/************************
Principe : affiche les éléments contenus dans la file

Entrée : la file, le renderer

Sortie :

Note :
***********************/
void afficher(tFile *suite, SDL_Renderer *renderer)
{
    tElement *courant;
    int i = 0;

    courant = suite->debut;

    for(i=0;i<suite->taille;++i)
    {
        Copy(courant->donnee, renderer, i); //Copie de la texture sur le renderer
        courant = courant->suivant;
    }
}
