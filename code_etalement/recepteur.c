#include "recepteur.h"


/* Permet de recevoir la trame via le canal. Ici le canal est represente par un fichier
 * @param :
 *  const int nbUtilisateurs : le nombre d'utilisateurs
 * 	const int len : la taille du train de bit des utilisateurs (la meme pour tous les utilisateurs)
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
		fscanf(fichier, "%i",&message[i]);
	}
	fclose(fichier);
	return message;
}


/* Permet de desetaler la trame recu pour pouvoir recuperer les informations utiles (les trains de bit envoye par l'utilisateur)
 * @param :
 * 	const int nbUtilisateurs : le nombre d'utilisateurs
 * 	const int len : la taille du train de bit des utilisateurs (la meme pour tous les utilisateurs)
 */
int * desetalementMessage( const int * matriceH, const int * message, const int nbUtilisateurs, const int len ){

	int i, j, k;	
	int * messageDesetale = NULL;
	float somme = 0.0;
	float temp;

	if( ( messageDesetale = malloc(sizeof(int) * nbUtilisateurs * len) ) == NULL ){
    printf("Debordement memoire\n");
    return NULL;
  }

	for(i = 0; i < nbUtilisateurs; i++){
		for(j = 0; j < len; j++){
			somme = 0;
			for(k = 0; k < nbUtilisateurs; k++){
				//printf("message : %i, matriceH : %i\n", message[k + j * len], matriceH[k + i * nbUtilisateurs]);
				somme += message[k + j * (len)] * matriceH[ k +  i* nbUtilisateurs];
			}
			temp = (1 / ((float)nbUtilisateurs * 1.0))  * somme;
			//printf("\n%i\n", (int)temp);
			messageDesetale[j + i * len] =  (int)temp;
		}
	}
	//printf("\n");
	for( i = 0; i < nbUtilisateurs * len;i++){
		//printf("%i", messageDesetale[i]);
	}
	//printf("\n");
	return messageDesetale;
}


/* Permet d'afficher les donnee envoye par un utilisateur donne
 * @param :
 * 	const int * messageDesetale : le message desetaler
 * 	const int utilisateur : l'utilisateur choisi
 * 	const int len : la taille du train de bit des utilisateurs (la meme pour tous les utilisateurs)
 */
void afficheMessageUtilisateur( const int * messageDesetale, const int utilisateur, const int len ){
	int i;

	printf("\nMessage de l'utilisateur %i:\n",utilisateur);
	for( i = 0 ; i < len; i++ ){
		if(messageDesetale[i + utilisateur * len] == -1){
			printf(" 0 \n");
		}
		else{
			printf(" %i \n", messageDesetale[i + utilisateur * len]); 
		}
	}
}


/* Permet d'afficher les donnee envoye par tout les utilisateurs
 * @param :
 * 	const int * messageDesetale : le message desetaler
 * 	const int nbUtilisateur : le nombre d'utilisateurs
 * 	const int len : la taille du train de bit des utilisateurs (la meme pour tous les utilisateurs)
 */
void afficheMessageRecu( const int * messageDesetale, const int nbUtilisateurs, const int len ){
	int i;

	for( i = 0 ; i < nbUtilisateurs; i++ ){
		afficheMessageUtilisateur(messageDesetale, i, len);
	}
}
