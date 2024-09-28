
compile:
	gcc -c life.c
	gcc -c run.c
	gcc -o run run.o life.o

clean:
	rm -f *.o
	rm -f run	
