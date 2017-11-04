#include "emetteur.h"

/* Demande un nombre d'utilisateurs qui est soit 1 soit 2 ou un multiple de 4 
 * @param : void
 */
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


/* Creation de la matrice de Hadamard en fonction du nombre d'utilisateurs 
 * @param :
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 */
int * creationMatriceH( const int nbUtilisateurs ){
  int * matriceH = malloc(sizeof( int )* nbUtilisateurs *nbUtilisateurs );
  
  return matriceH;
}


/* Permet d'initialiser de la matrice de Hadamard
 * @param : 
 * 	int * matriceH : la matrice d'Hadamard
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 */
void etalementH( int * matriceH, const int nbUtilisateurs ){
  int i, j, k, pred;
  pred = 1;
	matriceH[0] = 1;
  
	if(nbUtilisateurs == 1){
	}
	else{
		for(i = 2; i <= nbUtilisateurs; i+=i){
	  	for(j = 0; j < pred; j++){
				for(k = 0; k < pred; k++){
					matriceH[(pred + j) + k * nbUtilisateurs] = matriceH[j + k * nbUtilisateurs];
					matriceH[j + (k + pred) * nbUtilisateurs] = matriceH[j + k * nbUtilisateurs];	
					matriceH[(pred + j) + (k + pred) * nbUtilisateurs] = -1 * matriceH[j + k * nbUtilisateurs];
				}
			}
		pred = i;
		}
	}
}


/* Fonction permettant d'afficher la matrice de Hadamard
 * @param :
 * 	const int * matriceH : la matrice de Hadamard
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 */
void affichageMatriceH( const int * matriceH, const int nbUtilisateurs ){
	int i, j;

	printf("\nMatriceH:\n");
	for( i = 0 ; i < nbUtilisateurs ; i++ ){
		printf("\n");
		for( j = 0 ; j < nbUtilisateurs; j++ )
			printf(" %i ", matriceH[i + j*nbUtilisateurs]); 
	}
	printf("\n\n");
}


/* Fonction permettant de saisir le message de chaque utilisateur et
 * de l'enregistrer dans un tableau, le retourne une fois la fonction termine
 * @param :
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 * 	const int len ; la longueur du message ( la meme pour tous les utilisateurs )
 */
int * saisirMessage( const int nbUtilisateurs, const int len){

	int valeur, i, j;
  int * message = NULL;

	if ((message = malloc(sizeof( int )* nbUtilisateurs * len)) == NULL){
 		printf("Debordement memoire\n");
		exit(1);
	}	
	for(i = 0; i < nbUtilisateurs; i++){
		printf("Message de l'utilisateur %i :\n",i+1);
		for(j = 0; j < len; j++){
			printf("Bit %i : ",j);
			scanf("%i", &valeur);
			if(valeur == 0){
				valeur = -1;
			}
			else{
				valeur = 1;
			}
			message[j + i * len] = valeur;
		}
	}
	return message;
}


/* Retourne la trame message qui va etre envoye dans le canal
 * @param : 
 * 	const int * matriceH : Sequence d'etalement 
 *  const int message * : tableau de longueur nbUtilisateurs  contenant un message dans chacunes de ses cases 
 *  const int nbUtilisateurs : le nombre d'utilisateurs
 *	cont int len : la longueur du message ( la meme pour tous les utilisateurs )
 */
int * messageAEnvoyer(const int * matriceH, const int * message, const int nbUtilisateurs, const int len ){
  
  int i, j, k, l;
  int valeur;

  /* On sait que le message retour contient des chips de longueurs nbUtilisateurs
     Et qu'il y a autant de chips que la longueur du plus grand message */
  int * messageRetour = NULL;
  
  if( ( messageRetour = malloc(sizeof(int) * nbUtilisateurs * len) ) == NULL ){
    printf("Debordement memoire\n");
    exit(1);
  }
  else{
		/* On initialise la trame */
		for(i = 0; i < nbUtilisateurs * len; i++){
			messageRetour[i] = 0;
		}
    /* on repete la boucle pour tout les utilisateurs */
    for(i = 0; i < nbUtilisateurs; i++){
    	//printf("Utilisateur %i\n",i);
      /* on repete la boucle pour chaque caractere du message */
      for( j = 0; j < len; j++){
     		//printf("valeur bit %i\n",message[j + i * nbUtilisateurs]);
        /* On parcours la sequence d'etalement de l'utilisateur specifie */
        for(k = 0; k < nbUtilisateurs; k++){
					//printf("valeur d'etalement %i\n",matriceH[k + i * nbUtilisateurs]);
          /* messageRetour[j*k] permet de pointer vers le chip numero j et d'indice k */
					messageRetour[j * len + k] += message[j + i * len] * matriceH[k + i * nbUtilisateurs];
					//printf("index : %i, res combinatoire : %i\n",j * len + k, messageRetour[j + k * len]);
				}
			}
		}
	}
	return messageRetour;
}


/* Permet d'envoyer le message via le canal. Ici le canal est represente par un fichier
 * @param : 
 * 	const int * message : le message a transmettre dans le canal
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 * 	const int len : la taille du train de bit des utilisateurs (la meme pour tous les utilisateurs)
 */
void envoyerMessage( const int * message, const int nbUtilisateurs, const int len ){
	int i;
  FILE * fichier = NULL;

	/* On utilise un fichier pour representer le canal */
	fichier = fopen("trame.data","w");

	/* On envoi la trame bit par bit */
	for(i = 0; i < nbUtilisateurs * len ; i++){
		fprintf(fichier, "%i ",message[i]);
	}
	fclose(fichier);
}
