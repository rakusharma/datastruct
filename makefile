all: tree.exe

tree.exe: stack.o queue.o tree.o 
	gcc -o tree.exe stack.o queue.o tree.o

stack.o: stack.c
	gcc -c stack.c	
queue.o: queue.c
	gcc -c queue.c
tree.o: tree.c
	gcc -c tree.c

clean: 
	rm tree.exe stack.o queue.o tree.o

