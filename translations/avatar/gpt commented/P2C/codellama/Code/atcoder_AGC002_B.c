#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define constants for infinity and modulo
#define INF 1000000000
#define mod 1000000007

// Function to read a line of input and strip whitespace
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\n")] = 0;
    return line;
}

// Function to read an integer from input
int INT() {
    return atoi(input());
}

// Function to read a list of integers from input
int* MAP() {
    int* list = malloc(sizeof(int) * 2);
    char* line = input();
    sscanf(line, "%d %d", &list[0], &list[1]);
    return list;
}

// Function to read a list of integers and return it as a list
int* LIST() {
    int* list = malloc(sizeof(int) * 2);
    char* line = input();
    sscanf(line, "%d %d", &list[0], &list[1]);
    return list;
}

// Function to read multiple lists of integers and return them as zipped tuples
int** ZIP(int n) {
    int** lists = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        lists[i] = LIST();
    }
    return lists;
}

// Set the recursion limit to a high value to allow deep recursion
#define RECURSION_LIMIT 1000000000

// Define a struct to represent the state of each ball (weight and radius)
typedef struct {
    int weight;
    int radius;
} Ball;

// Define a function to process each operation
void process_operation(Ball* balls, int x, int y) {
    Ball* ball_x = &balls[x - 1];  // Get the state of ball x
    Ball* ball_y = &balls[y - 1];  // Get the state of ball y
    
    // Update the states of the balls based on their weights and radii
    if (ball_x->weight >= 1 && ball_x->radius >= 1) {
        ball_x->weight -= 1;  // Decrease weight of ball x
        ball_y->radius += 1;  // Increase radius of ball y
    } else if (ball_x->weight == 0) {
        ball_x->radius -= 1;  // Decrease radius of ball x
        ball_y->radius += 1;  // Increase radius of ball y
    } else {
        ball_x->weight -= 1;  // Decrease weight of ball x
        ball_y->weight += 1;  // Increase weight of ball y
    }
}

// Define a function to calculate the number of balls with a non-zero radius
int count_non_zero_radius(Ball* balls, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (balls[i].radius) {  // Check if the radius of the ball is non-zero
            count++;  // Increment the count of balls with non-zero radius
        }
    }
    return count;
}

int main() {
    // Read the number of balls (N) and the number of operations (M)
    int N = INT();
    int M = INT();
    
    // Initialize a list to represent the state of each ball (weight and radius)
    Ball* balls = malloc(sizeof(Ball) * N);
    for (int i = 0; i < N; i++) {
        balls[i].weight = 1;
        balls[i].radius = 0;
    }
    balls[0].weight = 0;  // Set the first ball's state
    balls[0].radius = 1;
    
    // Process each operation
    for (int i = 0; i < M; i++) {
        int* operation = MAP();
        process_operation(balls, operation[0], operation[1]);
    }
    
    // Calculate the number of balls with a non-zero radius
    int ans = count_non__zero_radius(balls, N);
    
    // Print the final count of balls with non-zero radius
    printf("%d\n", ans);
    
    return 0;
}

