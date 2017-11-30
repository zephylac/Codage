#include "gen_LM.h"

typedef struct gold_s{
	lm_t codeur1;
	lm_t codeur2;
} gold_t;

extern gold_t initialiser_gold(void);

extern int * codeur_gold(gold_t gold);

extern int detruire_gold(gold_t gold);

