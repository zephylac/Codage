/* Retourne la trame message qui va etre envoye dans le canal
 * @param : 
 *   const int * matriceH : Sequence d'etalement 
 *   const int message * : tableau de longueur nbUtilisateurs  contenant un message dans chacunes de ses cases 
 *   const int nbUtilisateurs : le nombre d'utilisateurs
 */
int * messageAEnvoyer(const int * matriceH, const int * message, const int nbUtilisateurs ){
  
  int i;
  int valeur = message[i][0];
  int chips[nbUtilisateurs];
  /* On sait que le message retour contient des chips de longueurs nbUtilisateurs
     Et qu'il y a autant de chips que la longueur du plus grand message */
  int * messageRetour = NULL;
  
  if( ( messageRetour = malloc(sizeof(int) * nbUtilisateurs * plusGrandMessage(message, nbUtilisateurs) ) ) == NULL ){
    printf("Debordement memoire\n");
    return NULL;
  }
  else{
    /* on repete la boucle pour tout les utilisateurs */
    for(i = 0; i < nbUtilisateurs; i++){
    
      /* on repete la boucle pour chaque caractere du message */
      j = 0
      while( valeur != 0 ){
     
        /* on va chercher la sequence d'etalement de l'utilisateur specifie */
        for(k = 0; k < nbUtilistateurs; k++){
          /* messageRetour[j*k] permet de pointer vers le chip numero j et d'indice k */
          messageRetour[j*k] = (valeur * matriceH[i + k * nbUtilisateurs]) * messageRetour[j*k];
        }
      valeur = message[i][j+1];
      j++;
      }
    }  
  }
}
