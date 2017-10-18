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


/* Retourne la longueur d'un message (Marqueur de fin exclut)
 * @param : 
 *   const int message * : tableau d'entier contenant le message 
 */
int messageLen(const int message *){
  int i = 1;
  int compteur = 0;
  int valeur = message[0];
  
  /* tant que le delimiteur de fin n'est pas atteint */
  while (valeur != 0){
    valeur = message[i];
    i++;
  }
  /* i - 1 car i est offset de 1 */
  return i - 1
} 


/* Retourne la trame message qui va etre envoye dans le canal
 * @param : 
 *   const int * matriceH : Sequence d'etalement 
 *   const int message * : tableau de longueur nbUtilisateurs  contenant un message dans chacunes de ses cases 
 *   const int nbUtilisateurs : le nombre d'utilisateurs
 */
int * messageAEnvoyer(const int * matriceH, const int * message, const int nbUtilisateurs ){
  
  int i;
  int valeur = message[i][0];
  int chips[nbUtilisateurs];
  /* On sait que le message retour contient des chips de longueurs nbUtilisateurs
     Et qu'il y a autant de chips que la longueur du plus grand message */
  int * messageRetour = NULL;
  
  if( ( messageRetour = malloc(sizeof(int) * nbUtilisateurs * messageLen(message[0]) ) ) == NULL ){
    printf("Debordement memoire\n");
    return NULL;
  }
  else{
    /* on repete la boucle pour tout les utilisateurs */
    for(i = 0; i < nbUtilisateurs; i++){
    
      /* on repete la boucle pour chaque caractere du message */
      j = 0
      while( valeur != 0 ){
     
        /* on va chercher la sequence d'etalement de l'utilisateur specifie */
        for(k = 0; k < nbUtilistateurs; k++){
          /* messageRetour[j*k] permet de pointer vers le chip numero j et d'indice k */
          messageRetour[j*k] = (valeur * matriceH[i + k * nbUtilisateurs]) + messageRetour[j*k];

