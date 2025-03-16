#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read a single line of input from stdin
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Function to convert a single input line to an integer
int INT() {
    char* line = input();
    int value = atoi(line);
    free(line);
    return value;
}

// Function to read multiple integers from a single line of input
int* MAP() {
    char* line = input();
    int* values = malloc(sizeof(int) * 2);
    sscanf(line, "%d %d", &values[0], &values[1]);
    free(line);
    return values;
}

// Function to read a list of integers from a single line of input
int* LIST() {
    char* line = input();
    int* values = malloc(sizeof(int) * 2);
    sscanf(line, "%d %d", &values[0], &values[1]);
    free(line);
    return values;
}

// Function to read multiple lines of input and return them as a list of tuples
int** ZIP(int n) {
    int** values = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        values[i] = MAP();
    }
    return values;
}

// Setting the recursion limit to a higher value to avoid recursion errors
#define RECURSION_LIMIT 1000000000

// Defining a constant for infinity
#define INF 1000000000

// Defining a constant for modulo operation
#define mod 1000000007

// Reading the number of balls (N) and the number of operations (M)
int N = INT();
int M = INT();

// Initializing the list of balls with pairs [white pieces, red pieces]
int** balls = malloc(sizeof(int*) * N);
for (int i = 0; i < N; i++) {
    balls[i] = malloc(sizeof(int) * 2);
    balls[i][0] = 1;
    balls[i][1] = 0;
}

// Special initialization for the first ball
balls[0][0] = 0;
balls[0][1] = 1;

// Loop to process each operation
for (int i = 0; i < M; i++) {
    int* xy = MAP();
    int x = xy[0];
    int y = xy[1];
    int w_x = balls[x - 1][0];
    int r_x = balls[x - 1][1];
    int w_y = balls[y - 1][0];
    int r_y = balls[y - 1][1];
    
    // Swapping the balls if possible
    if (w_x >= 1 && r_x >= 1) {
        balls[x - 1][0] -= 1;
        balls[y - 1][1] += 1;
    } else if (w_x == 0) {
        balls[x - 1][1] -= 1;
        balls[y - 1][1] += 1;
    } else {
        balls[x - 1][0] -= 1;
        balls[y - 1][0] += 1;
    }
}

// Counting the number of balls with at least one red or white piece
int ans = 0;
for (int i = 0; i < N; i++) {
    if (balls[i][1]) {
        ans += 1;
    }
}

// Printing the final count
printf("%d\n", ans);

// End of code
