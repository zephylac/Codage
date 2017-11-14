#include <stdio.h>
#include <stdlib.h>


int choixNbUtilisateurs( void );

int * creationMatriceH( const int nbUtilisateurs );

void etalementH (int * matriceH, const int nbUtilisateurs );

void affichageMatriceH( const int * matriceH, const int nbUtilisateurs );

int * saisirMessage( const int nbUtilisateurs, const int len);

int * messageAEnvoyer(const int * matriceH, const int * message, const int nbUtilisateurs, const int len );

void envoyerMessage( const int * message, const int nbUtilisateurs, const int len );
