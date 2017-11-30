#=================
# Makefile Codage
#=================

#-------------
# Executables 
#-------------

test : test.o gen_LM.o gold.o jpl.o
	gcc -Wall -g -D_DEBUG_ test.o gen_LM.o gold.o jpl.o -o test.exe -lm

test.o : test.c
	gcc -g -lm -c test.c -o test.o
  
#----------
# Modules
#----------

gen_LM.o : gen_LM.c gen_LM.h
	gcc -g -lm -c gen_LM.c -o gen_LM.o
	
gold.o : gold.c gold.h
	gcc -g -lm -c gold.c -o gold.o

jpl.o : jpl.c jpl.h
	gcc -g -lm -c jpl.c -o jpl.o

#----------------------------
# Gestion generale du projet
#----------------------------

all : test

clean :
	rm *.o *.exe

