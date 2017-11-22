#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menuAgent(){

	int choix = 0;
	while(choix < 1 || choix > 8){
		printf("Veuiller choisir ce que vous voulez faire :\n");
		printf("Choix 1 : Create\n");
		printf("Choix 2 : Invoke\n");
		printf("Choix 3 : Destroy\n");
		printf("Choix 4 : Quit\n");
		printf("Choix 5 : Suspend\n");
		printf("Choix 6 : Resume\n");
		printf("Choix 7 : Wait\n");
		printf("Choix 8 : Wake Up\n");
		
		scanf("%i",&choix);
	}
	return choix;
}


int menuFonction(){

	int choix = 0;
	while(choix < 1 || choix > 8){
		printf("Veuiller choisir ce que vous voulez faire :\n");
		printf("Choix 1 : \n");
		printf("Choix 2 : \n");
		printf("Choix 3 : \n");
		printf("Choix 4 : \n");
		printf("Choix 5 : \n");
		printf("Choix 6 : \n");
		printf("Choix 7 : \n");
		printf("Choix 8 : \n");
		
		scanf("%i",&choix);
	}
	return choix;
}

int addAgent(int tabAgent[MAX_AGENT], int pid){
	int i = 0;	
	while( i < MAX_AGENT && tabAgent[i] != 0){
		i++;
	}
	if( i == MAX_AGENT ){
		printf("La creation d'un nouvel agent est impossible\n");
		exit(1);
	}
	else{
		tabAgent[i] = pid;
		printf("Un nouvel agent a ete cree, ID : %i | PID : %i\n",i,pid
		exit(0);
	}
}

int removeAgent(int tabAgent[MAX_AGENT], int id){
	tabAgent[i] = 0;
	printf("L'agent %i a ete supprime\n",id);
}


int chooseAgent(int tabAgent[MAX_AGENT]){
	int id = 0;
	printAgent(tabAgent);
	while(id < 0 || id > MAX_AGENT || tabAgent[id] == 0){
		printf("ERROR : invalid id\n");
		scanf("%i",id);
	}
	return id;
}


int retrieveAgentPID(int tabAgent[MAX_AGENT], int id){
	return tabAgent[id];
}



int printAgent(int tabAgent[MAX_AGENT]){
	int i;
	
	for( i = 0; i < MAX_AGENT; i++){
		printf(" Agent ID | PID processus\n");
		printf("    %i    |      %i      \n",i,tabAgent[i]);
	}
}



int main(void){

	int tabAgent[100];


	int choix1 = 0;
	int choix2 = 0;
	int pid;		
	int agent;	
		choix1 = menuAgent();
		

		switch(choix1){
			case 1:
				/* On appel la fonction choisit */
					
				choix2 = menuFonction();				
				
				switch(pid = fork()){
					case 1 : /* erreur */
					case 0 : /* fils */
						switch(choix2){
							case 1: printf("choix 1\n");break;				
							case 2:	printf("choix 2\n");break;
							default : printf("error\n");break;
						}

					default : 
						kill(pid, SIGSTOP);
						createAgent(tabAgent,pid);
						break;

			case 2:
				/* Invoke Agent  */
				printAgent(tabAgent);
				
				agent = chooseAgent(tabAgent);			
				
				pid = retrieveAgentPID(tabAgent, agent);

				kill(pid, SIGCONT);
				break;
			case 3:
				/* SIGKILL */
				printAgent(tabAgent);
				
				agent = chooseAgent(tabAgent);			
				
				pid = retrieveAgentPID(tabAgent, agent);

				kill(pid, SIGQUITTER);

				break;
			case 4:
				/* Suspend */
				printAgent(tabAgent);
				
				agent = chooseAgent(tabAgent);			
				
				pid = retrieveAgentPID(tabAgent, agent);

				kill(pid, SIGSTOP);


				break;
			case 5:
				/* Suspend SIGSTOP */
				break;
			case 6:
				/* Resume SIGCONT */
				break;
			case 7:
				/* Wait SIGSTOP */
				break;
			case 8:
				/* Wake up SIGCONT */
				break;
	

    if (pthread_create(&thread1, NULL, thread_1, NULL)) {
	    perror("pthread_create");
	    return EXIT_FAILURE;
    }


    if (pthread_join(thread1, NULL)) {
	    perror("pthread_join");
	    return EXIT_FAILURE;
    }


    printf("Après la création du thread.\n");
	  return EXIT_SUCCESS;

}
