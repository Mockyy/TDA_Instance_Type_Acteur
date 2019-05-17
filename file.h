#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "defineform.h"

typedef struct tElement {
    struct tActor *donnee;
    struct tElement *suivant;
}tElement;


typedef struct tFile {
    tElement *debut;
    tElement *fin;
    int taille;
}tFile;


///PROTOTYPES

//Initialisation
extern void initialisation(tFile *suite);

//Insertion
extern int enFiler(tFile *suite, tElement *courant, tActor *donnee);

//Suppression
extern int deFiler (tFile *suite);

//Affichage
extern void afficher(tFile *suite, SDL_Renderer *renderer);

#endif // FILE_H_INCLUDED
