#include "gen_LM.h"

int main(){
	int i;
	lm_t code = initialiser();
	
		for( i = 0 ; i < code.registre.taille ; i++ )
		printf("%i ", code.registre.tab[i]);

	print_codeur(code);	
  
	int * res = codeur(code);
	
	printf("\nResultat: ");
	for( i = 0; i < code.taille; i++){
		printf("%i ",res[i]);
	}

	printf("\n");		
}
