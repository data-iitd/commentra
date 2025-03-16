#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200100

int main() {
    long long N, K;
    long long A[MAX_SIZE];
    long long B[MAX_SIZE]; // Array to track visited nodes
    int now = 1; // Starting node
    long long cnt = 0; // Counter for cycle detection
    scanf("%lld %lld", &N, &K);
    
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]); // Read the sequence of nodes
    }
    
    for (int i = 0; i < MAX_SIZE; i++) {
        B[i] = -1; // Initialize all nodes as unvisited
    }
    
    // Detect cycle and find the position after K steps
    B[1] = 0; // Mark the starting node
    long long j;
    for (j = 1; j <= K; j++) {
        now = A[now]; // Move to the next node
        if (B[now] == -1) {
            B[now] = j; // Mark the node as visited
        } else {
            cnt = j; // Record the cycle start
            break; // Exit the loop as cycle is detected
        }
    }
    
    if (j < K) {
        long long tmp = (K - B[now]) % (cnt - B[now]); // Calculate remaining steps
        for (long long j = 0; j < tmp; j++) {
            now = A[now]; // Move to the position after K steps
        }
    }
    
    printf("%d\n", now); // Output the final position
    return 0;
}

// <END-OF-CODE>
