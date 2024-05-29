

compile:
	clang++ -c TerminalManager.cpp
	clang++ -c GameOfLife.cpp
	clang++ -c UserInput.cpp
	clang++ -c main.cpp
	clang++ -o main main.o GameOfLife.o UserInput.o TerminalManager.o -lncurses

run:
	./main

clean:
	rm -f *.o
	rm -f main