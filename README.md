# clife
clife is an artificial life simulator (game of life,  langton's ant, ...) inside the terminal using C and ncurses libary.

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

## Conways game of life
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

#### Read more here: [https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

### Rules

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Initial state is random (you can choose probability for: cell alive)

## Langton's ants

## Usage

### Compile and link

```concole
gcc -c simulation.c
gcc -c run.c
gcc -o run simulation.o run.o -lncurses
```

### Execute

```concole
./run
```