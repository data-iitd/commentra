#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000  // Assuming a maximum size for the number of balls
#define MOD 1000000007

// Function to read an integer from stdin
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read multiple integers from a single line
void read_multiple_ints(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int N = read_int();  // Number of balls
    int M = read_int();  // Number of operations

    // Initializing the balls array
    int balls[MAX_N][2];  // Each ball has [white pieces, red pieces]
    
    // Special initialization for the first ball
    for (int i = 0; i < N; i++) {
        balls[i][0] = 1;  // 1 white piece
        balls[i][1] = 0;  // 0 red pieces
    }
    balls[0][0] = 0;  // 0 white pieces for the first ball
    balls[0][1] = 1;  // 1 red piece for the first ball

    // Loop to process each operation
    for (int i = 0; i < M; i++) {
        int x = read_int() - 1;  // Reading the index of the first ball (0-based)
        int y = read_int() - 1;  // Reading the index of the second ball (0-based)

        int w_x = balls[x][0];  // White pieces of ball x
        int r_x = balls[x][1];  // Red pieces of ball x
        int w_y = balls[y][0];  // White pieces of ball y
        int r_y = balls[y][1];  // Red pieces of ball y

        // Swapping the balls if possible
        if (w_x >= 1 && r_x >= 1) {
            balls[x][0]--;  // Decrease white pieces of ball x
            balls[y][1]++;  // Increase red pieces of ball y
        } else if (w_x == 0) {
            balls[x][1]--;  // Decrease red pieces of ball x
            balls[y][1]++;  // Increase red pieces of ball y
        } else {
            balls[x][0]--;  // Decrease white pieces of ball x
            balls[y][0]++;  // Increase white pieces of ball y
        }
    }

    // Counting the number of balls with at least one red or white piece
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1] > 0) {
            ans++;
        }
    }

    // Printing the final count
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
