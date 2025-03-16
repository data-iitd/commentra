#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    // Read the number of balls (N) and the number of operations (M)
    int N = read_int();
    int M = read_int();

    // Initialize a list to represent the state of each ball (weight and radius)
    int balls[MAX_N][2]; // balls[i][0] for weight, balls[i][1] for radius
    for (int i = 0; i < N; i++) {
        balls[i][0] = 1; // Initial weight
        balls[i][1] = 0; // Initial radius
    }
    balls[0][0] = 0; // Set the first ball's weight to 0
    balls[0][1] = 1; // Set the first ball's radius to 1

    // Process each operation
    for (int i = 0; i < M; i++) {
        int x = read_int() - 1; // Read the index of ball x (0-based)
        int y = read_int() - 1; // Read the index of ball y (0-based)

        int w_x = balls[x][0]; // Get the weight of ball x
        int r_x = balls[x][1]; // Get the radius of ball x
        int w_y = balls[y][0]; // Get the weight of ball y
        int r_y = balls[y][1]; // Get the radius of ball y

        // Update the states of the balls based on their weights and radii
        if (w_x >= 1 && r_x >= 1) {
            balls[x][0]--; // Decrease weight of ball x
            balls[y][1]++; // Increase radius of ball y
        } else if (w_x == 0) {
            balls[x][1]--; // Decrease radius of ball x
            balls[y][1]++; // Increase radius of ball y
        } else {
            balls[x][0]--; // Decrease weight of ball x
            balls[y][0]++; // Increase weight of ball y
        }
    }

    // Calculate the number of balls with a non-zero radius
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1] > 0) { // Check if the radius of the ball is non-zero
            ans++; // Increment the count of balls with non-zero radius
        }
    }

    // Print the final count of balls with non-zero radius
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
