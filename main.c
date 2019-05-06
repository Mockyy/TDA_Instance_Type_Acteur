#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600


int main(int argc, char *argv[])
{
    SDL_Window *fenetre;
    SDL_Renderer *renderer;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_HEIGHT , WINDOW_WIDTH, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    //Création du renderer
    renderer = SDL_CreateRenderer(fenetre, -1, 0);
    if(renderer == NULL)
    {
        printf("Erreur de création du renderer : %s,",SDL_GetError());
    }

    SDL_RenderPresent(renderer);

    //Gestion d'évenements
    if(fenetre)
    {
        int isRunning = 1;
        //Boucle principale
        while(isRunning!=0){

            //Gestion d'événement
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                switch(event.type)
                {
                    case SDL_QUIT:
                    printf("Fermeture\n");
                    isRunning = 0;
                    break;
                    case SDL_KEYDOWN:
                        if(event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            printf("Fermeture\n");
                            isRunning = 0;
                        }
                    break;
                }
            }
        }
    }

    SDL_DestroyWindow(fenetre);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
