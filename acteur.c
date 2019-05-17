#include "defineform.h"

/************************
Principe : cr�e un acteur avec les donn�es pass�es en arguments

Entr�e : le renderer, le chemin de l'image pour la texture, un vecteur pour la position

Sortie : un acteur tout propre

Note : ne fonctionne pas, donne un segmentation fault
***********************/
tActor *initActor(SDL_Renderer *renderer, char* chemin, tVector pos)
{
    tActor *tempActor = NULL;

    //Cr�ation de la texture
    SDL_Surface *tempSurface = IMG_Load(chemin);
    SDL_Texture *tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_free(tempSurface);
    //Assignation de la texture
    tempActor->textActor = tempTexture;
    //Assignation de la position
    tempActor->vect = pos;
    //Assignation de la hauteur et la largeur
    SDL_QueryTexture(tempActor->textActor, NULL, NULL, &tempActor->width, &tempActor->height);  //r�cup�re la taille et la hauteur d'une
                                                                                                //texture et stocke les donn�es dans les
                                                                                                //variables en arguments

    return tempActor;
}
