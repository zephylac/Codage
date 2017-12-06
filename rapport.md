# TP Codage


Pour executer les TP exécuter les commandes suivantes

```C
cd Codage/(Le dossier du tp)
make
./test
```
## TP1 Code d'etalement

L'emetteur et le récepteur on la même matrice de Hadamard ainsi que la même façon de déterminer les séquences des utilisateurs.


### Emetteur

L'emetteur se charge de saisir le nombre d'utilisateurs. Une fois saisit, il génère la matrice de Hadamard dynamiquement en fonction de ce nombre et détermine les séquences d'étalement pour chaque utilisateur. <br />
On saisit la taille du message a envoyer (ce nombre est le même pour tous les utilisateurs), il est exprime en nombre de bit.
On saisit enfin les messages de chaque utilisateurs.

### Recepteur

Le recepteur se charge de lire dans le canal. Il connait le nombre d'utilisateurs. Il peut donc décoder la trame reçu, puis isoler le message de chaque utilisateur.


### Canal

Pour representer le canal parfait lors de ce TP, nous avons décidé d'utiliser un fichier.
<br />
<br />

## TP2 Générateur Pseudo Aléatoire

### Utilisation 
Lors de la saisie, si plusieurs nombres doivent être saisis, il faut les séparer par un espace ou par un retour chariot (entrée).
```C
Saisir la longueur de la sequence a generer: 20
Saisir la longueur du registre: 5
Saisir le registre: 1 1 1 1 1
Saisir la longueur du polynome de generation: 2
Saisir le polynome de generation: 5 2
```
### Code à longueur maximale
Lors de l'initialisation d'un code à Longueur Maximale, l'utilisateur choisit :
<br />
* La longueur de la séquence a générer 
* Le nombre d'étages souhaité
* L'initialisation du codeur 
* La longueur du polynôme de génération (le nombre de colonnes qui effectueront le XOR )
* Le polynome de génération

### Code de Gold

Le code de Gold étant deux CLM (Code à Longueur Maximale), on saisit deux code LM.
Pour qu'un code de Gold soit valide les deux CLM doivent avoir le même nombre de registres (étages),
De même il suffit de ne saisir qu'une fois la longueur de la séquence  que l'on veut générer.

### Code JPL

Le code de JPL est composé d'au moins deux CLM. On choisit donc le nombre de CLM que l'on veut.
Puis on saisit les CLM un par un. Pour qu'un code JPL soit valide, le nombre de registres de chaque CLM doit être premier avec les autres. On verifie donc a chaque fois qu'un nouveau CLM est rentré s'il est bien premier avec les autres.
De même il suffit de ne saisir qu'une fois la longueur de la séquence  que l'on veut générer.

## TP3 Agent Life Cycle
Par faute de temps  nous n'avons pas réussi à finir ce TP. Mais nous pouvons tout de même dire comment nous avons procéder pour essayer le faire.<br />
Nous avons utilisé des Fork au lieu des Thread pour créer les fils, en effet on fait autant de fork qu'il y a d'agents. Pour réaliser les différentes transistions des états de l'agent on a utilisé des signaux. Par exemple pour suspendre un agent on utilise le signal SIGSTOP, pour le reprendre le signal SIGCONT, pour quitter et le détruire le signal SIGKILL.
