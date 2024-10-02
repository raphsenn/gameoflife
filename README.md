# Game Of Life

![gif](/res/gameoflife.gif)

* Note: GIF with 10fps (not accurate to real simulation in terminal)

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

#### Read more here: [https://en.wikipedia.org/wiki/Conway's_Game_of_Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

### Rules

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Initial state is random (you can choose probability for: cell alive)

## Dependencies

- C compiler (gcc or clang, or everything that compiles C code)
- Ncurses libary (retro 1990's C libary for terminal plotting)

### Install ncurses

#### Linux (debian based)

```concole
sudo apt update
sudo apt install libncurses-dev
```

#### Mac (apple sillicon)

```concole
brew install ncurses
```

## Usage

### Commands in Simulation

* Press q to quit
* Press 'space' to start or pause the simulation
* Press r to create random cells

### Compile and link

```concole
gcc -c simulation.c
gcc -c main.c
gcc -o main simulation.o run.o -lncurses
```

### Execute

```concole
./main
```