#=================
# Makefile Codage
#=================

#-------------
# Executables 
#-------------

test : test.o gen_LM.o
	gcc -lm -Wall -g -D_DEBUG_ test.o gen_LM.o -o test.exe

test.o : test.c
	gcc -g -c test.c -o test.o
  
#----------
# Modules
#----------

gen_LM.o : gen_LM.c gen_LM.h
	gcc -g -lm -c gen_LM.c -o gen_LM.o

#----------------------------
# Gestion generale du projet
#----------------------------

all : test

clean :
	rm *.o *.exe

