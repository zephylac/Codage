#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct polynome_s{
	int * tab;
	int taille;
} polynome_t;

typedef struct lm_s{
	int taille;
	polynome_t polynome;
	int * registre;
} lm_t;


extern lm_t initialiser(void);

extern int * codeur(lm_t codeur);

extern void print_codeur( lm_t codeur );
