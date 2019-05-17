#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED

#include "defineform.h"

///Déclaration type vecteur
typedef struct tVector{
    int nX;
    int nY;
}tVector;

///PROTOTYPES

///L'addition vectorielle -> retour : un vecteur
extern tVector additionVecteur(tVector vect1, tVector vect2);

///La soustraction vectorielle -> retour : un vecteur
extern tVector soustractionVecteur(tVector vect1, tVector vect2);

///La multiplication d'un vecteur par un scalaire (un entier/réél) -> retour : un vecteur
extern tVector multiplicationVecteur(tVector vect1, float scal1);

///Le produit scalaire de deux vecteurs -> scalaire (réél/entier)
extern int produitScalaire(tVector vect1, tVector vect2);

///Le produit vectoriel de deux vecteurs -> un vecteur
extern tVector produitVectoriel(tVector vect1, tVector vect2);

///La norme -> un scalaire
extern float normeVecteur(tVector vect1, tVector vect2);


#endif // VECTEUR_H_INCLUDED
