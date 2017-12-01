#include "gen_LM.h"

/* Fonction permettant d'initialiser une structure du type lm_t
 * Cette structure permet de generer un code a Longueur Maximal
 * La fonction retourne une structure lm_t
 * @param :
 *      void
 */
extern lm_t initialiser(void){
  lm_t codeur;
  int tmp = 0, i = 0;
  

  /* On ne saisit la longueur de la sequence a generer qu'une fois car
   * c'est obligatoirement la meme pour les deux code LM
   */ 
	printf("\nSaisir la longueur de la sequence a generer: ");
	scanf("%i", &codeur.taille);	

	printf("Saisir la longueur du registre: ");
	do{
		scanf("%i", &codeur.registre.taille);
	}while( codeur.registre.taille > TAILLE_MAX_REGISTRE );
	
	/* On alloue un espace memoire pour le registre*/
	if( ( codeur.registre.tab = malloc( sizeof(int) * codeur.registre.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf("Saisir le registre: ");
	for( i = 0 ; i < codeur.registre.taille ; i++ ){
		scanf("%i", &codeur.registre.tab[i]);
	}
	
 	printf("Saisir la longueur du poynome de generation: ");
	scanf("%i", &codeur.polynome.taille);

	/* On alloue un espace memoire pour le polynome */
	if( ( codeur.polynome.tab = malloc( sizeof(int) * codeur.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf("Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur.polynome.taille ; i++ )
		scanf("%i", &codeur.polynome.tab[i]);

	return codeur;
}

/* Fonction prenant en parametre une struture lm_t puis l'affiche
 * @param
 *  lm_t codeur : structure a afficher*
 */
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
	for( i = 0 ; i < codeur.registre.taille ; i++ )
		printf("%i ", codeur.registre.tab[i]);
} 

/* Fonction qui prend en parametre une structure lm_t
 * et qui retourne la sequence genere a partir de ce codeur
 * @param
 *      lm_t codeur : structure contenant les paramètres pour generer la sequence
 */
extern int * codeur(lm_t codeur){
	int i, j;
	int xor_pred = 0;
	int * res = NULL;
	int nb_decalage= pow(2,codeur.taille) - 1 ; 
	int tab_temp[codeur.taille + 1];

	/* On allloue un espace memoire pour le resultat */
	if ( (res = malloc(sizeof(int) * codeur.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	/* On parcourt le tableau res */
	for(i = 0; i < codeur.taille; i++){

		/* La valeur rentré dans res est celle de la derniere colonne du code LM */
		res[i] = codeur.registre.tab[codeur.registre.taille - 1];
		
		/*  la valeur du xor est initialisé a 0 a chaque boucle */
		xor_pred = 0;

		/* On calcule la valeur pour le prochain decalage */
    /* On effectue l'operation logique XOR sur les colonnes que l'on a indique dans le polynome */
		for(j = 0; j < codeur.polynome.taille; j++){
			xor_pred = codeur.registre.tab[codeur.polynome.tab[j] - 1 ] ^ xor_pred;
		}
		//printf("xor : %i\n",xor_pred);
	
		/* sauvegarde du registre precedent */
		for( j = 0; j < codeur.registre.taille - 1; j++ ){
			tab_temp[j + 1] = codeur.registre.tab[j];
		}
	
		/*On affecte la nouvelle valeur au registre */
		codeur.registre.tab[0] = xor_pred;
	
		/* On decale le registre */
		for(j = 1; j < codeur.registre.taille; j++){
			codeur.registre.tab[j] = tab_temp[j];
		}
	}
	return res;
}

/* Fonction permettant de liberer l'espace alloue en memoire pour la structure lm_t
 * @param
 *      lm_t codeur : la structure que l'on veux detruire
 */
int detruire_lm(lm_t codeur){
	free(codeur.registre.tab);
	free(codeur.polynome.tab);
	return 0;
}
