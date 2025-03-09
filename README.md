# push-swap

## Introduction
`push-swap` is a project from the 42 cursus that focuses on sorting a stack of integers using a limited set of operations. The goal is to implement an efficient sorting algorithm with the least number of moves.

## Features
- Implements a sorting algorithm using two stacks (`a` and `b`).
- Uses a restricted set of push, swap, and rotate operations.
- Finds the optimal sequence of moves to sort the stack efficiently.
- Handles varying stack sizes with different algorithmic approaches.

## Installation
Clone the repository and compile the project:
```sh
$ git clone https://github.com/serg-backend-developer/push-swap.git
$ cd push-swap
$ make
```

## Usage
1. Run the program with a set of space-separated integers:
   ```sh
   ./push_swap 4 67 3 87 23
   ```
   The program will output the sequence of operations needed to sort the numbers.

2. Validate the sorting with the checker:
   ```sh
   ./checker 4 67 3 87 23
   ```
   Enter the operations manually or provide them from push_swap:
   ```sh
   ./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
   ```
   If the sorting is correct, the checker will return `OK`, otherwise `KO`.

## Compilation
`push-swap` is compiled using `Makefile` with the following commands:
- `make` - Compiles the project.
- `make clean` - Removes object files.
- `make fclean` - Removes object files and binaries.
- `make re` - Recompiles the project.

## Allowed Operations
- `sa` / `sb` / `ss` - Swap the top two elements of a stack.
- `pa` / `pb` - Push the top element from one stack to another.
- `ra` / `rb` / `rr` - Rotate a stack upwards.
- `rra` / `rrb` / `rrr` - Rotate a stack downwards.

