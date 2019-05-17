#include "defineform.h"

/************************
Principe : crée un acteur avec les données passées en arguments

Entrée : le renderer, le chemin de l'image pour la texture, un vecteur pour la position

Sortie : un acteur tout propre

Note : ne fonctionne pas, donne un segmentation fault
***********************/
tActor *initActor(SDL_Renderer *renderer, char* chemin, tVector pos)
{
    tActor *tempActor = NULL;

    //Création de la texture
    SDL_Surface *tempSurface = IMG_Load(chemin);
    SDL_Texture *tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_free(tempSurface);
    //Assignation de la texture
    tempActor->textActor = tempTexture;
    //Assignation de la position
    tempActor->vect = pos;
    //Assignation de la hauteur et la largeur
    SDL_QueryTexture(tempActor->textActor, NULL, NULL, &tempActor->width, &tempActor->height);  //récupère la taille et la hauteur d'une
                                                                                                //texture et stocke les données dans les
                                                                                                //variables en arguments

    return tempActor;
}
