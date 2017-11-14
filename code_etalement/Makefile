#=================
# Makefile Codage
#=================

#-------------
# Executables 
#-------------

test : test.o emetteur.o recepteur.o
	gcc -Wall -ansi -g -D_DEBUG_ test.o emetteur.o recepteur.o -o test.exe

test.o : test.c
	gcc -g -c test.c -o test.o
  
#----------
# Modules
#----------

emetteur.o : emetteur.c emetteur.h
	gcc -g -c emetteur.c -o emetteur.o

recepteur.o : recepteur.c recepteur.h
	gcc -g -c recepteur.c -o recepteur.o



#----------------------------
# Gestion generale du projet
#----------------------------

all : test

clean :
	rm *.o *.exe
