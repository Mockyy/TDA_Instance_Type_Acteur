#include "defineform.h"

///L'addition vectorielle -> retour : un vecteur
/************************
Principe : addition de deux vecteurs

Entrée : les deux vecteurs à additionner

Sortie : vecteur

Note :
***********************/
tVector additionVecteur(tVector vect1, tVector vect2){

    tVector vectSomme;
    vectSomme.nX = vect1.nX + vect2.nX;
    vectSomme.nY = vect1.nY + vect2.nY;

    return vectSomme;
}

///La soustraction vectorielle -> retour : un vecteur
tVector soustractionVecteur(tVector vect1, tVector vect2){

    tVector vectSomme;
    vectSomme.nX = vect1.nX - vect2.nX;
    vectSomme.nY = vect1.nY - vect2.nY;

    return vectSomme;
}

///La multiplication d'un vecteur par un scalaire (un entier/réél) -> retour : un vecteur
tVector multiplicationVecteur(tVector vect1, float scal1){

    tVector vectSomme;
    vectSomme.nX = vect1.nX * scal1;
    vectSomme.nY = vect1.nY * scal1;

    return vectSomme;
}

///Le produit scalaire de deux vecteurs -> scalaire (réél/entier)
int produitScalaire(tVector vect1, tVector vect2){

    int nScal;

    nScal = (vect1.nX*vect2.nX) + (vect1.nY*vect2.nY);

    return nScal;
}

///Le produit vectoriel de deux vecteurs -> un vecteur
tVector produitVectoriel(tVector vect1, tVector vect2){
        ///u*v = (uY * vZ - uZ * vY),(uZ * vX - uX * vZ),(uX * vY - uY * vX)
        tVector vect2mult;

        vect2mult.nX = vect1.nY*NZ-NZ*vect2.nY;
        vect2mult.nY = NZ*vect2.nX-vect1.nX*NZ;

        return vect2mult;
}

///La norme -> un scalaire
float normeVecteur(tVector vect1, tVector vect2){

    return sqrt((vect2.nX-vect1.nX)*(vect2.nX-vect1.nX)+(vect2.nY-vect1.nY)*(vect2.nY-vect1.nY));
}
