#include "gen_LM.h"
#include "gold.h"

int main(){
	int i;
	int choix = 0;
	lm_t code;

	gold_t gold;

	while(choix < 1 || choix > 2){
		printf("Veuiller choisir ce que vous voulez faire :\n");
		printf("Choix 1 : Code longueur maximale\n");
		printf("Choix 2 : Code de Gold\n");
		printf("Choix : ");
		scanf("%i",&choix);
	}
	switch(choix){
		case 1:
			code = initialiser();
	
			for( i = 0 ; i < code.registre.taille ; i++ )
			printf("%i ", code.registre.tab[i]);

			print_codeur(code);	
  
			int * res = codeur(code);
	
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
			
			break;
	}
}
