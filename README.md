*This project has been created as part of the 42 curriculum by msievier, cavarlam.	.*

# push_swap

## Description

`push_swap` is a 42 project focused on sorting integers using two stacks, **Stack A** and **Stack B**, and a limited set of operations.

The goal is to produce a valid sequence of operations that sorts the input in ascending order while keeping the number of operations as low as possible.

The project implements several sorting strategies and an optional benchmark mode.

## Features

* Input parsing and validation
* Duplicate and integer-range checking
* Linked-list based stacks
* Index assignment for relative value ordering
* Multiple sorting strategies
* Input disorder calculation
* Benchmark mode
* Memory management and error handling

## Algorithms

The program provides four sorting strategies:

### Simple

Designed for small inputs. It uses direct stack operations and simple sorting logic where the number of possible states is limited.

### Medium

Uses indexed values and divides the input into manageable groups. Elements are moved between the two stacks while maintaining a useful ordering, reducing unnecessary operations compared with the simple approach.

### Complex

uses a binary LSD radix sort based on the normalized indexes. For each bit position, elements with a 0 bit are pushed from stack A to stack B, while elements with a 1 bit are rotated in stack A. After processing all elements for the current bit, the elements in stack B are pushed back to stack A. This process is repeated for every bit of the largest index.

### Adaptive

Calculates the initial **disorder** of the input and selects a suitable strategy based on how far the sequence is from being sorted. The goal is to avoid using an unnecessarily complex strategy for inputs that are already relatively ordered.

### Why multiple strategies?

Different input sizes and initial configurations can favour different approaches. Small inputs can be handled efficiently with simple logic, while larger or highly disordered inputs require more operation-efficient strategies. The adaptive mode uses the input characteristics to choose an appropriate approach.

## Instructions

### Compilation

```bash
make
```

Other available commands:

```bash
make clean
make fclean
make re
```

### Usage

```bash
./push_swap 2 1 3 6 5 8
```

The program prints the operations required to sort the input.

A quoted string can also be used:

```bash
./push_swap "2 1 3 6 5 8"
```

### Testing

Generate 100 unique random numbers and count the operations:

```bash
./push_swap $(shuf -i 1-1000 -n 100) | wc -l
```

The result can be checked with the 42 `checker`:

```bash
ARG=$(shuf -i 1-1000 -n 100)
./push_swap $ARG | ./checker $ARG
```

A correct result should return:

```text
OK
```

## Resources

* 42 `push_swap` subject — project requirements and allowed operations
* 42 Norminette — coding standard
* C documentation and Linux `man` pages
* References on linked lists, sorting algorithms and algorithmic complexity

### AI Usage

AI was used as a learning and development aid for:

* understanding C and linked-list concepts;
* discussing sorting strategies and algorithmic complexity;
* debugging and interpreting compiler/Norminette errors;
* developing testing commands;
* reviewing code structure and refactoring;
* proofreading and structuring this README.

The implementation was developed and tested by the authors. AI suggestions were reviewed and adapted to the project's actual implementation.