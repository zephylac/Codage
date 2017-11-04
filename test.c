#include "emetteur.h"
#include "recepteur.h"

int main(){
  int len;
	int nb = choixNbUtilisateurs();
  int * message = NULL;
	int * trame = NULL;
	printf("Veuiller entrer le nombre de bit(s) a envoyer : ");
	scanf("%i", &len);


  /* Creation */
  int * matriceH = creationMatriceH( nb );
  
  /*Initialisation */
  etalementH( matriceH, nb );
  
  /* Affichage */
  affichageMatriceH( matriceH, nb );

	/* Saisie des messages */
  message = saisirMessage(nb, len);

	/* Creation du message */
	trame = messageAEnvoyer(matriceH, message, nb, len);

	/* Envoi du message */
	envoyerMessage( trame, nb, len );

	free(trame);
	trame = NULL;
	free(message);
	message = NULL;
	

	/* Recupere la trame recu via le canal */
	trame = recevoirMessage(nb, len);

	/* Desetale la trame  pour reconstituer le message*/
	message = desetalementMessage(matriceH, trame, nb, len);

	/*Affiche le message recu */
	afficheMessageRecu(message, nb, len);

	free(trame);
	trame = NULL;
	free(message);
	message = NULL;

	free(matriceH);
	matriceH = NULL;
}
