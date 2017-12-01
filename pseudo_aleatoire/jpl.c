#include "jpl.h"

/* Retourne le Plus Grand Diviseur Commun */
int pgcd(int a, int b){
  int res;
  while (b != 0){
  	res = a%b;
    a = b;
    b = res;
  }
  return a;
}

/* Retourne vrai si les deux nombres sont premiers entre eux sinon faux */
static int est_premier(int a, int b){
	return pgcd(a,b) == 1;
}

/* On parcours tout le tableau jusqu'au rang - 1 
 * et on verifie qu'il sont bien premier avec celui
 * la valeur donné
 */
static int verif_premier(jpl_t jpl, int rang, int valeur){
	int i = 0;
	
	/* On parcourt les codes precedents */
	for(i = 0; i < rang; i++){
		/* On verifie si le nombre d'etages du nouveau code LM
		 * est bien premier avec les precedents codes LM
		 */ 
		if( !est_premier(jpl.tab[i].registre.taille, valeur) ){
			return 0;
		}
	}
	return 1;
}


/* Fonction permettant d'initialiser une structure du type jpl_t
 * Cette structure permet de generer un code JPL qui contient un
 * certain nombre de code LM
 * La fonction retourne une structure jpl_t
 * @param :
 *      void
 */
extern jpl_t initialiser_jpl(void){
  jpl_t jpl;
   
  int tmp = 0, i = 0, j = 0;
	int nb_gen_lm = 0;    
	int len_sequence;
	int len_registre;

	
	/* Un code JPL a au moins deux code a Longueur Maximal */
	while(nb_gen_lm < 2){ 
		printf("\nSaisir le nombre de generateur a Longueur Maximal (min : 2): ");
		scanf("%i", &nb_gen_lm);
	}

	jpl.taille = nb_gen_lm;	

	/* On alloue un espace memoire pour le nombre de code lm a generer */
	if( ( jpl.tab = malloc( sizeof(lm_t) * nb_gen_lm ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	printf("\nSaisir la longueur de la sequence a generer: ");
	scanf("%i", &jpl.longueur_seq);

	/* On parcourt le tableau contenant les codes LM*/
	for(i = 0; i < nb_gen_lm; i++){
		printf("\tCodeur %i",i);
		printf("\n\t========\n");
	
		do{
		printf("Les longueurs des differents registres doivent etre premieres entre elles\n");
		printf("Saisir la longueur du registre : ");
		scanf("%i", &len_registre);
		}
		while(!verif_premier(jpl, i, len_registre) );
		
		/* Une fois que le nobmre d'etages est valide */
		
		jpl.tab[i].registre.taille = len_registre;		

    /* On alloue un espace memoire pour le registre*/
		if( ( jpl.tab[i].registre.tab = malloc( sizeof(int) * jpl.tab[i].registre.taille ) ) == NULL ){
			printf("Debordement memoire\n");
			exit(1);
		}

		printf("Saisir le registre: ");
		for( j = 0 ; j < jpl.tab[i].registre.taille ; j++ ){
			scanf("%i", &jpl.tab[i].registre.tab[j]);
		}
	
	 	printf("Saisir la longueur du polynome de generation: ");
		scanf("%i", &jpl.tab[i].polynome.taille);

    /* On alloue un espace memoire pour le polynome*/
		if( ( jpl.tab[i].polynome.tab = malloc( sizeof(int) * jpl.tab[i].polynome.taille ) ) == NULL ){
			printf("Debordement memoire\n");
			exit(1);
		}
	
		printf("Saisir le polynome de generation: ");
		for( j = 0 ; j < jpl.tab[i].polynome.taille ; j++ ){
			scanf("%i", &jpl.tab[i].polynome.tab[j]);
		}
	}
	return jpl;
}


/* Fonction qui prend en parametre une structure jpl_t
 * et qui retourne la sequence genere a partir de ce codeur
 * @param
 *      jpl_t codeur : structure contenant les paramètres pour generer la sequence
 */
extern int * codeur_jpl(jpl_t jpl){

	int * res, * temp;
	int pred_xor, i, j;

  /* On alloue un espace memoire pour le resultat */
	if ( (res = malloc(sizeof(int) * jpl.longueur_seq ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}

	/* On met les valeurs xor à 0 */
	for(i = 0; i < jpl.taille; i++){
		res[i] = 0;
	}	

	/* On parcourt le tableau des codes LM*/
	for(i = 0; i < jpl.taille; i++){
		temp = codeur(jpl.tab[i]);
		
		/* On parcourt le tableau des resultats*/
		for(j = 0; j < jpl.longueur_seq; j++){
			/* On effectue un XOR sur tous les codes LM pour obtenir les resultats */
			res[j] = res[j] ^ temp[j];
		}
		free(temp);
	}	
	return  res;
}

/* Fonction permettant de liberer l'espace alloue en memoire pour la structure jpl_t
 * @param
 *      jpl_t codeur : la structure que l'on veux detruire
 */
extern int detruire_jpl(jpl_t jpl){
	int i;

	for(i = 0; i < jpl.taille; i++){
		detruire_lm(jpl.tab[i]);
	}	
	return 0;
}

