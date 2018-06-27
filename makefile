all: tree.exe

tree.exe: stack.o tree.o queue.o
	gcc -o tree.exe stack.o tree.o queue.o

stack.o: stack.c
	gcc -c stack.c	
tree.o: tree.c
	gcc -g -c tree.c
queue.o: queue.c
	gcc -c queue.c

clean: 
	rm tree.exe stack.o tree.o queue.o

