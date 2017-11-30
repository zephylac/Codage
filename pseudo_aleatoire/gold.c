#include "gold.h"

extern gold_t initialiser_gold(void){
	gold_t codeur;	

  lm_t codeur1;
  lm_t codeur2;
   
  int tmp = 0, i = 0;
    
	printf("\nSaisir la longueur de la sequence a generer: ");
	scanf("%i", &codeur1.taille);
	codeur2.taille = codeur1.taille;	

	
	printf("\tCodeur 1");
	printf("\n\t========\n");
	
	printf("Saisir la longueur du registre: ");
	do{
		scanf("%i", &codeur1.registre.taille);
	}while( codeur1.registre.taille > TAILLE_MAX_REGISTRE );
	
	if( ( codeur1.registre.tab = malloc( sizeof(int) * codeur1.registre.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	printf("Saisir le registre: ");
	for( i = 0 ; i < codeur1.registre.taille ; i++ ){
		scanf("%i", &codeur1.registre.tab[i]);
	}
	
 	printf("Saisir la longueur du poynome de generation: ");
	scanf("%i", &codeur1.polynome.taille);

	if( ( codeur1.polynome.tab = malloc( sizeof(int) * codeur1.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf("Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur1.polynome.taille ; i++ )
		scanf("%i", &codeur1.polynome.tab[i]);

	printf("\tCodeur 2");
	printf("\n\t========\n");
	
	printf("Saisir la longueur du registre: ");
	do{
		scanf("%i", &codeur2.registre.taille);
	}while( codeur2.registre.taille > TAILLE_MAX_REGISTRE );
	
	if( ( codeur2.registre.tab = malloc( sizeof(int) * codeur2.registre.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	printf("Saisir le registre: ");
	for( i = 0 ; i < codeur2.registre.taille ; i++ ){
		scanf("%i", &codeur2.registre.tab[i]);
	}
	
 	printf("Saisir la longueur du poynome de generation: ");
	scanf("%i", &codeur2.polynome.taille);

	if( ( codeur2.polynome.tab = malloc( sizeof(int) * codeur2.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf("Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur2.polynome.taille ; i++ )
		scanf("%i", &codeur2.polynome.tab[i]);	
	
	codeur.codeur1 = codeur1;
	codeur.codeur2 = codeur2;
	
	return codeur;
}

extern int * codeur_gold(gold_t gold){

	int * res, * temp1, * temp2, i;

	if ( (res = malloc(sizeof(int) * gold.codeur1.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	/* On creer les deux codes de Longueur Maximal saisi par l'utilisateur */
	temp1 = codeur(gold.codeur1);
	temp2 = codeur(gold.codeur2);

	for(i = 0; i < gold.codeur1.taille; i++){
		res[i] = temp1[i] ^ temp2[i];
	} 

	return  res;
}


extern int detruire_gold(gold_t gold){
	detruire_lm(gold.codeur1);
	detruire_lm(gold.codeur2);
}	



/*extern void print_codeur_gold( gold_t codeur ){
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
	for( i = 0 ; i < codeur.registre.taille ; i++ )
		printf("%i ", codeur.registre.tab[i]);
}*/



