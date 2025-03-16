#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Set the recursion limit for the function call stack
// This is necessary to prevent a "RecursionError" when dealing with large inputs
#define RECURSION_LIMIT 1000000

// Define the input function to read input from standard input
#define input(type) \
    type _; \
    scanf("%lf", &_); \
    _

// Define a function to read multiple integers as a list
#define LMIIS(type) \
    type _; \
    scanf("%lf", &_); \
    _ = (int)(_ * 100 + 0.1); \
    type

// Define input reading functions for single integer and string
#define II() input(int)
#define P 1000000007
#define INF 10000000010

int main() {
    // Set the recursion limit to a large value
    // This is necessary to prevent a "RecursionError" when dealing with large inputs
    // This is not necessary in a compiled language
    #ifdef _MSC_VER
    _setrecursionlimit(RECURSION_LIMIT);
    #else
    setrlimit(RLIMIT_STACK, (struct rlimit){.rlim_cur = RECURSION_LIMIT,.rlim_max = RECURSION_LIMIT});
    #endif

    // Read input for two numbers 'a' and 'b'
    char sa[100], sb[100];
    scanf("%s %s", sa, sb);
    int a = atoi(sa);
    int b = atoi(sb);

    // Calculate the product of 'a' and 'b' and print the result
    printf("%d\n", a * b / 100);

    // 