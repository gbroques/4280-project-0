# CS 4280: Program Translation Project 0

A C++ program that reads in positive integers, and for each value, outputs quotients for incrementally increased divisors. The divisor begins with 2 and increases by 1 until the quotient equals 0. These divisions are implemented with a recursive function.

## Usage
You can pass a list of positive integers to the program, with a maximum length of 10, either in a file, or as separate command line arguments.

`P0 filename`

* Where `filename` is a file containing a list of positive integers with a maximum length of 10.

`P0 n1 [n2 ...]`

* Where `n1, n2, etc.` is a list of positive integers with a maximum length of 10.

### Example Invocation

* `P0 55 15 16`

```
27 9 2 0 numCalls = 4
7 2 0 numCalls = 3
53 17 4 0 numCalls = 4
```

