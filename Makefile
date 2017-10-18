#=================
# Makefile Codage
#=================

#-------------
# Executables 
#-------------

test : test.o emetteur.o
	gcc test.o emetteur.o -o test.exe

test.o : test.c
	gcc -c test.c -o test.o
  
#----------
# Modules
#----------

emetteur.o : emetteur.c emetteur.h
	gcc -c emetteur.c -o emetteur.o
  
#----------------------------
# Gestion generale du projet
#----------------------------

all : test

clean :
	rm *.o *.exe
