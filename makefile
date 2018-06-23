all: tree.exe

tree.exe: stack.o tree.o
	gcc -o tree.exe stack.o tree.o

stack.o: stack.c
	gcc -c stack.c	
tree.o: tree.c
	gcc -c tree.c

clean: 
	rm tree.exe stack.o tree.o

