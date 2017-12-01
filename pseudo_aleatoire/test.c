#include "gen_LM.h"
#include "gold.h"
#include "jpl.h"

int main(){
	int i;
	int choix = 0;
	
	lm_t code;
	gold_t gold;
	jpl_t jpl;

	int * res;
	
	while(choix < 1 || choix > 3){
		printf("Veuiller choisir ce que vous voulez faire :\n");
		printf("Choix 1 : Code a Longueur Maximale\n");
		printf("Choix 2 : Code de Gold\n");
		printf("Choix 3 : Code JPL\n");
		printf("Choix : ");
		scanf("%i",&choix);
	}
	switch(choix){
		case 1:
			code = initialiser();
	
			for( i = 0 ; i < code.registre.taille ; i++ )
			printf("%i ", code.registre.tab[i]);

			print_codeur(code);	
  
			res = codeur(code);
	
			printf("\nResultat: ");
			for( i = 0; i < code.taille; i++){
				printf("%i ",res[i]);
			}
			printf("\n");		
			
			detruire_lm(code);
			free(res);
			break;
		
		case 2:
			gold = initialiser_gold();

			res =	codeur_gold(gold);
		
			printf("\nResultat: ");
			for( i = 0; i < gold.codeur1.taille; i++){
				printf("%i ",res[i]);
			}
			printf("\n");		
			
			detruire_gold(gold);
			free(res);
			break;
		case 3:
			jpl = initialiser_jpl();

			res =	codeur_jpl(jpl);
		
			printf("\nResultat: ");
			for( i = 0; i < jpl.longueur_seq; i++){
				printf("%i ",res[i]);
			}
			printf("\n");		
			
			detruire_jpl(jpl);
			free(res);
			break;
	}
}
