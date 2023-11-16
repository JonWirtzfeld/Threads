# Threads 
### Jon Wirtzfeld

## Description 
Threads is a program that spins up a user-defined number of threads, and allows each thread to increment a single counter a user-defined number of times.

## Getting Started
To compile Threads on Ubuntu, run the following command:

`g++ -o Threads main.cpp`

and run with:

`./Threads <number of threads> <number of increments>`

Example:
```
> ./Threads 2 2
Sleeping for 10 seconds...
Thread #0, value: 0
Thread #1, value: 1
Thread #0, value: 2
Thread #1, value: 3
```
