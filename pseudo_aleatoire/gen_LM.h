#ifndef _GEN_LM_H
#define _GEN_LM_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TAILLE_MAX_REGISTRE 10

typedef struct polynome_s{
	int * tab;
	int taille;
} polynome_t;

typedef struct registre_s{
	int taille;
	int * tab;
} registre_t;

typedef struct lm_s{
	int taille;
	polynome_t polynome;
	registre_t registre;
} lm_t;


extern lm_t initialiser(void);

extern int * codeur(lm_t codeur);

extern void print_codeur( lm_t codeur );

extern int detruire_lm(lm_t codeur);
#endif
