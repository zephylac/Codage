#include "gen_LM.h"

typedef struct jpl_s{
	lm_t * tab;
	int taille;
	int longueur_seq;
} jpl_t;

extern jpl_t initialiser_jpl(void);

extern int * codeur_jpl(jpl_t jpl);

extern int detruire_jpl(jpl_t jpl);

