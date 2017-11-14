
static gold_t initialiser(void){
	gold_t codeur;	

  lm_t codeur1;
  lm_t codeur2;
	char temp;
  int i = 0;
    
	printf("\n Saisir la longueur de la sequence a generer: ");
	scanf("%i", &codeur1.taille);
	
	codeur2.taille =codeur1.taille;	

	if( ( codeur1.registre = malloc( sizeof(int) * codeur1.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	if( ( codeur2.registre = malloc( sizeof(int) * codeur2.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}


	printf(" Saisir la longueur du polynome de generation: ");
	scanf("%i", &codeur1.polynome.taille);

	if( ( codeur1.polynome.tab = malloc( sizeof(int) * codeur1.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf(" Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur1.polynome.taille ; i++ )
		scanf("%i", &codeur1.polynome.tab[i]);
	
	printf(" Saisir le registre d'initialisation: ");
	for( i = 0 ; i < codeur1.taille ; i++ )
		scanf("%i", &codeur1.registre[i]);


	/* CODEUR 2 */

	printf(" Saisir la longueur du polynome de generation: ");
	scanf("%i", &codeur2.polynome.taille);

	if( ( codeur2.polynome.tab = malloc( sizeof(int) * codeur2.polynome.taille ) ) == NULL ){
		printf("Debordement memoire\n");
		exit(1);
	}
	
	printf(" Saisir le polynome de generation: ");
	for( i = 0 ; i < codeur2.polynome.taille ; i++ )
		scanf("%i", &codeur2.polynome.tab[i]);
	
	printf(" Saisir le registre d'initialisation: ");
	for( i = 0 ; i < codeur2.taille ; i++ )
		scanf("%i", &codeur2.registre[i]);

	codeur.codeur1 = codeur1;
	codeur.codeur2 = codeur2;
		
	return codeur;
}



void code_gold(void){


