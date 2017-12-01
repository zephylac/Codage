#include "gold.h"

/* Fonction permettant d'initialiser une structure du type gold_t
 * Cette structure permet de generer un code de Gold
 * Soit deux code LM ayant la meme longueur de sequence a generer
 * La fonction retourne une structure de type gold_t
 * @param :
 *      void
 */
extern gold_t initialiser_gold(void){
	gold_t codeur;	

  lm_t codeur1;
  lm_t codeur2;
   
  int tmp = 0, i = 0;
   
 /* On ne saisit la longueur de la sequence a generer qu'une fois car
  * c'est obligatoirement la meme pour les deux code LM
  */ 
	printf("\nSaisir la longueur de la sequence a generer: ");
	scanf("%i", &codeur1.taille);
	codeur2.taille = codeur1.taille;	

	
	printf("\tCodeur 1");
	printf("\n\t========\n");
	
	printf("Saisir la longueur du registre: ");
	do{
		scanf("%i", &codeur1.registre.taille);
	}while( codeur1.registre.taille > TAILLE_MAX_REGISTRE );
	
	/* On alloue un espace memoire pour le registre du premier code LM */
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

	/* On alloue un espace memoire pour le polynome du premier code LM */
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
	
	/* On alloue un espace memoire pour le registre du deuxieme code LM */
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

	/* On alloue un espace memoire pour le polynome du deuxieme code LM */
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

/* Fonction qui prend en parametre une structure gold_t
 * et qui retourne la sequence genere a partir de ce codeur
 * @param
 *      gold_t codeur : structure contenant les paramètres pour generer la sequence
 */
extern int * codeur_gold(gold_t gold){

	int * res, * temp1, * temp2, i;

	/* On alloue un espace memoire pour le resultat */
	if ( (res = malloc(sizeof(int) * gold.codeur1.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	/* On creer les deux codes de Longueur Maximal saisi par l'utilisateur */
	temp1 = codeur(gold.codeur1);
	temp2 = codeur(gold.codeur2);

	/* On effectue un OU exclusif sur les deux code LM */
	for(i = 0; i < gold.codeur1.taille; i++){
		res[i] = temp1[i] ^ temp2[i];
	} 

	return  res;
}

/* Fonction permettant de liberer l'espace alloue en memoire pour la structure gold_t
 * @param
 *      lm_t codeur : la structure que l'on veux detruire
 */
extern int detruire_gold(gold_t gold){
	/* On detruit le premier code LM */
	detruire_lm(gold.codeur1);
	/* On detruit le deuxieme code LM */
	detruire_lm(gold.codeur2);
}	
