#include "gen_LM.h"

extern lm_t initialiser(void){
  lm_t codeur;
  char temp;
  int i = 0;
    
	printf("\n Saisir la longueur de la sequence a generer: ");
	scanf("%i", &codeur.taille);
	
	if( ( codeur.registre = malloc( sizeof(int) * codeur.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf(" Saisir la longueur du poynome de generation: ");
	scanf("%i", &codeur.polynome.taille);

	if( ( codeur.polynome.tab = malloc( sizeof(int) * codeur.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf(" Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur.polynome.taille ; i++ )
		scanf("%i", &codeur.polynome.tab[i]);
	
	printf(" Saisir le registre: ");
	for( i = 0 ; i < codeur.taille ; i++ )
		scanf("%i", &codeur.registre[i]);
	
	return codeur;
}

extern void print_codeur( lm_t codeur ){
	int i, taille_pol, taille;
  
  taille = codeur.taille;
  taille_pol = codeur.polynome.taille;
  
  printf("\nLongueur de la sequence: %i\nPolynome: [ ", taille);
  //Affichage du polynome
  for( i = 0 ; i < taille_pol ; i++ ){
		printf("%i", codeur.polynome.tab[i]);
		if( i != taille_pol -1 )
			printf(",");
	}
	printf(" ]");
  
  //Affichage du registre
  printf("\nRegistre: ");
	for( i = 0 ; i < codeur.taille ; i++ )
		printf("%i ", codeur.registre[i]);
} 


extern int * codeur(lm_t codeur){
	int i, j;
	int xor_pred = 0;
	int * res = NULL;
	int nb_decalage= pow(2,codeur.taille) - 1 ; 
	int tab_temp[codeur.taille + 1];

	if ( (res = malloc(sizeof(int) * codeur.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	for(i = 0; i < codeur.taille; i++){

		res[i] = codeur.registre[codeur.taille - 1];
		
		xor_pred = 0;
		/* On calcule la valeur pour le prochain decalage */
		for(j = 0; j < codeur.polynome.taille; j++){
			xor_pred = codeur.registre[codeur.polynome.tab[j] - 1 ] ^ xor_pred;
		}
		//printf("xor : %i\n",xor_pred);
	
		/* sauvegarde du registre precedent */
		for( j = 0; j < codeur.taille - 1; j++ ){
			tab_temp[j + 1] = codeur.registre[j];
		}
	
		/*On affecte la nouvelle valeur au registre */
		codeur.registre[0] = xor_pred;
	
		/* On decale le registre */
		for(j = 1; j < codeur.taille; j++){
			codeur.registre[j] = tab_temp[j];
		}
		/*
		for(j = 0; j < codeur.taille; j++){
			printf("\n%i-\n", codeur.registre[j]);
		}
		*/
	}
	return res;
}
