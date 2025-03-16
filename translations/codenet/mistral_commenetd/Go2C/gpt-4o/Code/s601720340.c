#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC 1000000007
#define MAX_N 200000

int N;
int p[MAX_N];

// Function to check if a given number n is present in the p array
int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

// Main logic of the problem
void solve() {
    int X;
    scanf("%d", &X);
    printf("%d\n", X);
    scanf("%d", &N);
    printf("%d\n", N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }
    
    // Check if X or its neighbors are present in the p array
    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            printf("%d\n", X - i);
            exit(0);
        }
        if (find(X + i) == 1) {
            printf("%d\n", X + i);
            exit(0);
        }
    }

    // If no valid number is found, you can add additional output here if needed
    // printf("No valid number found\n");
}

int main() {
    solve(); // Call the solve function
    return 0;
}

// <END-OF-CODE>
