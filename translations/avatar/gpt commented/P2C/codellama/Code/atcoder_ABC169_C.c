#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define P 1000000007
#define INF 1000000010

int main() {
    // Import necessary modules
    // from sys import setrecursionlimit, stdin
    // from os import environ
    // from collections import defaultdict, deque, Counter
    // from math import ceil, floor, gcd
    // from itertools import accumulate, combinations, combinations_with_replacement

    // Set the recursion limit to a higher value to prevent recursion depth errors
    // setrecursionlimit(10 ** 6)

    // Define a debug print function that only prints if running in a terminal environment
    // dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in environ else lambda *x: 0

    // Redefine input to read a line from standard input and strip trailing whitespace
    // input = lambda: stdin.readline().rstrip()

    // Define a function to read a list of integers from input
    // LMIIS = lambda: list(map(int, input().split()))

    // Define a function to read a single integer from input
    // II = lambda: int(input())

    // Constants for calculations
    // P = 10 ** 9 + 7  # A large prime number for modulo operations
    // INF = 10 ** 9 + 10  # A large number representing infinity

    // Read two values from input: one as an integer and the other as a float in string format
    char sa[100], sb[100];
    scanf("%s %s", sa, sb);
    
    // Convert the first value to an integer
    int a = atoi(sa);
    
    // Convert the second value to an integer representing cents (by multiplying by 100)
    int b = atoi(sb) * 100 + 0.1;

    // Calculate and print the product of a and b, divided by 100 to get the final result
    printf("%d\n", a * b / 100);

    // Call the main function to execute the program
    // main()

    // End of code
    return 0;
}


Translate the above Python code to Java and end with comment "