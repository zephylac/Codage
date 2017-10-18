#include "emetteur.h"

/* Demande un nombre d'utilisateurs qui est soit 1 soit 2 ou un multiple de 4 */
int choixNbUtilisateurs( void ){
  int nb = 1;
  do{
  	if( nb == 0 || nb != 2 && nb != 1 && nb%4 != 0 )
  		printf("\nErreur: nombre d'utilisateurs incorrect.");
  		
    printf("\nNombre d'utilisateurs: ");
    scanf("%i", &nb);
  }while( nb == 0 || nb != 2 && nb != 1 && nb%4 != 0 );
  
  return nb;
}

/* Creation de la matrice de Hadamard en fonction du nombre d'utilisateurs */
int * creationMatriceH( const int nbUtilisateurs ){
  int * matriceH = malloc(sizeof( int )* nbUtilisateurs );
  
  return matriceH;
}

/* Initialisation de la matrice de Hadamard */
int * etalementH( int * matriceH, const int nbUtilisateurs ){
  int i, j, k;
  
  matriceH[0] = 1;
  
  
  
  
  
  
  
  
	/*for( i = 1 ; i <= nbUtilisateurs/2 ; i++ )
		for( j = 0 ; j < nbUtilisateurs ; j++ ){
		  for( k = 0 ; k < nbUtilisateurs ; k++ ){
			  matriceH[i + j*nbUtilisateurs] = matrice[i-1 + j * nbUtilisateurs];
   		}
		}
  }*/
  return matriceH;
}

/* Affichage matrice */
void affichageMatriceH( int * matriceH, const int nbUtilisateurs ){
	int i, j;

	printf("\nMatriceH:\n");
	for( i = 0 ; i < nbUtilisateurs ; i++ ){
		printf("\n");
		for( j = 0 ; j < nbUtilisateurs; j++ )
			printf(" %i ", matriceH[i + j*nbUtilisateurs]); 
	}
	printf("\n\n");
}

