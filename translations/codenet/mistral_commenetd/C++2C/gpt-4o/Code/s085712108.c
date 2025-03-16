#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 7007
#define MAX_QUEUE_SIZE 10000

// Define a struct QUEUE to store the current state and the total number of steps taken
typedef struct {
    int a, b, c, tot; // a, b, c represent the current state and tot is the total number of steps taken
} QUEUE;

// Initialize an empty hash table to store visited states
int Hash[MOD][MAX_QUEUE_SIZE];
int HashCount[MOD] = {0};

// Function to check if a state is already in the hash table
bool HASH(int n) {
    for (int i = 0; i < HashCount[n % MOD]; i++) {
        if (n == Hash[n % MOD][i]) {
            return false;
        }
    }
    Hash[n % MOD][HashCount[n % MOD]++] = n;
    return true;
}

// Define the possible moves
int F[6][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1}
};

int main() {
    // Initialize some variables and read input data
    QUEUE Push;
    Push.tot = 0;
    Push.a = Push.b = Push.c = 0; // Initialize a, b, c
    scanf("%d%d%d", &Push.a, &Push.b, &Push.c);

    QUEUE queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0; // Queue pointers
    queue[rear++] = Push; // Enqueue the initial state

    // Main loop to find the solution
    while (front < rear) {
        QUEUE Fro = queue[front++]; // Dequeue the front element from the queue

        // Check if the current state is the goal state
        if (Fro.a == Fro.b && Fro.b == Fro.c) {
            printf("%d\n", Fro.tot); // Print the total number of steps taken and exit the program
            return 0;
        }

        // Try all six possible moves and check if the resulting state is already in the hash table
        for (int i = 0; i < 6; i++) {
            Push = Fro; // Copy the current state into a new variable Push
            Push.tot++; // Increment the total number of steps taken
            Push.a += F[i][0]; 
            Push.b += F[i][1]; 
            Push.c += F[i][2]; // Apply the move to the new state
            int n = Push.a * 10000 + Push.b * 100 + Push.c; // Calculate the hash code of the new state
            if (!HASH(n)) continue; // If the new state is already in the hash table, skip it
            queue[rear++] = Push; // Otherwise, push it into the queue and continue the search
        }
    }

    // Return 0 to indicate that the program has finished running
    return 0;
}

// <END-OF-CODE>
