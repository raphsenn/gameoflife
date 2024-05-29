

compile:
	clang++ -c TerminalManager.cpp
	clang++ -c GameOfLife.cpp
	clang++ -c main.cpp
	clang++ -o main main.o GameOfLife.o TerminalManager.o -lncurses

clean:
	rm -f *.o
	rm -f main