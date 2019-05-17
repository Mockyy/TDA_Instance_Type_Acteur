#include "vue.h"

/************************
Principe : copie la texture d'un acteur sur le renderer

Entrée : un acteur, le renderer, un entier

Sortie :

Note : on passe un entier en argument pour décaler automatiquement les images afin de tester le programme
***********************/
void Copy(tActor *acteur, SDL_Renderer *renderer, int i)
{
    SDL_Rect tailleTexture;

    //On stocke les infos de l'acteur dans un SDL_Rect (pour pouvoir utiliser Rendercopy)
    tailleTexture.x = acteur->vect.nX;
    tailleTexture.y = acteur->vect.nY;
    SDL_QueryTexture(acteur->textActor, NULL, NULL, &tailleTexture.h, &tailleTexture.w);

    //On décale les images pour pouvoir tester
    tailleTexture.x = 10 + (50*i);
    tailleTexture.y = 10 + (50*i);

    //On copie la texture sur le renderer
    SDL_RenderCopy(renderer, acteur->textActor, NULL, &tailleTexture);
}
