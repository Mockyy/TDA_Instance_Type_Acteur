#ifndef ACTEUR_H_INCLUDED
#define ACTEUR_H_INCLUDED

#include "defineform.h"

typedef struct tActor {
    SDL_Texture *textActor;
    tVector vect;
    int height;
    int width;
}tActor;


///PROTOTYPE
extern tActor *initActor(SDL_Renderer *renderer, char* chemin, tVector pos);


#endif // ACTEUR_H_INCLUDED
