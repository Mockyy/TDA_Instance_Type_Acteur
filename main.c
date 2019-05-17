#include "defineform.h"

int main(int argc, char *argv[])
{
    SDL_Window *fenetre;
    SDL_Renderer *renderer;

    ///Initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    ///Création de la fenêtre
    fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_HEIGHT , WINDOW_WIDTH, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    ///Création du renderer
    renderer = SDL_CreateRenderer(fenetre, -1, 0);
    if(renderer == NULL)
        printf("Erreur de création du renderer : %s,",SDL_GetError());

    ///Déclaration
    tFile *managerActor;
    tActor *actor1;
    tVector vect1 = {10, 10};

    ///Allocation mémoire
    if((managerActor = (tFile *) malloc(sizeof(tFile))) == NULL)
        return -1;
    if((actor1 = (tActor *) malloc(sizeof(tActor))) == NULL)
        return -1;


    ///Initialisation de la file
    initialisation(managerActor);

    ///Création de la texture
    SDL_Surface *testSurface = IMG_Load("Assets/stitch.bmp");
    SDL_Texture *testTexture = SDL_CreateTextureFromSurface(renderer, testSurface);
    SDL_FreeSurface(testSurface);

    ///Initialisation de l'acteur
    actor1->textActor = testTexture;
    actor1->vect = vect1;
    SDL_QueryTexture(actor1->textActor, NULL, NULL, &actor1->width, &actor1->width);

    ///Fonction de création d'acteur(ne marche pas -> segmentation fault)
//    actor1 = initActor(renderer, "stitch.bmp", vect1, 0, 0);


    if(fenetre)
    {
        int isRunning = 1;

        ///Boucle principale

        while(isRunning!=0){

            afficher(managerActor, renderer);

            ///Gestion d'événement
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                switch(event.type)
                {
                    case SDL_QUIT:
                    printf("Fermeture\n");
                    isRunning = 0;
                    break;
                    case SDL_KEYDOWN:
                        ///Echap = fermeture du programme
                        if(event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            printf("Fermeture\n");
                            isRunning = 0;
                        }
                        ///Z = ajout d'un acteur dans la file
                        if(event.key.keysym.sym == SDLK_z)
                        {
                            enFiler(managerActor, managerActor->fin, actor1);
                        }
                        ///S = suppression d'un acteur dans la file (ne marche pas)
                        if(event.key.keysym.sym == SDLK_s)
                        {
                            deFiler(managerActor);
                        }
                    break;
                }
            }
            ///Affichage du renderer
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyWindow(fenetre);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
