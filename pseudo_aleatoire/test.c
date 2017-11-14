#include "gen_LM.h"

int main(){
	int i;
	lm_t code = initialiser();

	print_codeur(code);	
  
	int * res = codeur(code);
	
	
	printf("\n");
	for( i = 0; i < code.taille; i++){
		printf("%i",res[i]);
	}

	printf("\n");		
}
