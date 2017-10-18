#include "emetteur.h"

int main(){
  int nb = choixNbUtilisateurs();
  
  /* Creation */
  int * matriceH = creationMatriceH( nb );
  
  /*Initialisation */
  matriceH = etalementH( matriceH, nb );
  
  /* Affichage */
  affichageMatriceH( matriceH, nb );
}
