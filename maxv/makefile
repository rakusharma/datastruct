all: maxv.exe



maxv.exe: stack.o maxv.o 
	gcc -o max.exe stack.o maxv.o
stack.o: ../stack.c
	gcc -c /home/ravi/vxworks/tree/stack.c	
maxv.o: maxv.c
	gcc -c maxv.c -I/home/ravi/vxworks/tree/

clean: 
	rm maxv.exe stack.o maxv.o

