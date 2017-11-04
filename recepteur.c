#include "recepteur.h"


/* Permet de lire la trame recu
 * const int nbUtilisateurs : le nombre d'utilisateurs
 * const int len : le nombre de bit(s) envoyé
 */
int * recevoirMessage(const int nbUtilisateurs, const int len ){
	int i;
  FILE * fichier = NULL;
	int * message;

	fichier = fopen("trame.data","r");
	if( ( message = malloc(sizeof(int) * nbUtilisateurs * len) ) == NULL ){
    printf("Debordement memoire\n");
    return NULL;
  }
	
	for(i = 0; i < nbUtilisateurs * len ; i++){
		fscanf(fichier, "%i ",message[i]);
	}
	fclose(fichier);
	return message;
}


int * desetalementMessage( const int * matriceH, const int * message, const int nbUtilisateurs, const int len ){

	int i, j, k;	
	int * messageDesetale = NULL;
	int somme = 0;

	if( ( messageDesetale = malloc(sizeof(int) * nbUtilisateurs * len) ) == NULL ){
    printf("Debordement memoire\n");
    return NULL;
  }

	for(i = 0; i < nbUtilisateurs; i++){
		for(j = 0; j < len; j++){
			somme = 0;
			for(k = 0; k < nbUtilisateurs; k++){
				somme += message[k + i * nbUtilisateurs] * matriceH[ k + i * nbUtilisateurs];
			}	
			messageDesetale[j + i * nbUtilisateurs] = 1 / nbUtilisateurs * somme;
		}
	}
	return messageDesetale;
}

/* Affichage matrice */
void afficheMessageUtilisateur( int * messageDesetale, const int utilisateur, const int len ){
	int i;

	printf("\nMessage de l'utilisateur %i:\n",utilisateur);
	for( i = 0 ; i < len; i++ ){
		printf(" %i \n", messageDesetale[i + utilisateur * len]); 
	}
}

/* Affichage matrice */
void afficheMessageRecu( int * messageDesetale, const int nbUtilisateurs, const int len ){
	int i;

	for( i = 0 ; i < nbUtilisateurs; i++ ){
		afficheMessageUtilisateur(messageDesetale, i, len);
	}
}
