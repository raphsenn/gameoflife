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

## Langton's ants

## Usage

### Compile and link

```concole
gcc -c life.c
gcc -c run.c
gcc -o run life.o run.o
```

### Execute

```concole
./run
```