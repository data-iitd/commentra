#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 7007

// Define a struct QUEUE to store the current state and the total number of steps taken
typedef struct {
    int a, b, c, tot;
} QUEUE;

// Initialize an empty hash table to store visited states
int Hash[MOD][1000];
int hash_size = 0;

// Function to check if a state is already in the hash table
int HASH(int n) {
    for (int i = 0; i < hash_size; i++) {
        if (n == Hash[i]) {
            return 0;
        }
    }
    Hash[hash_size++] = n;
    return 1;
}

int main() {
    // Initialize some variables and read input data
    QUEUE Push;
    Push.tot = 0;
    QUEUE que[1000];
    int que_size = 0;
    scanf("%d%d%d", &Push.a, &Push.b, &Push.c);
    que[que_size++] = Push;

    // Main loop to find the solution
    while (que_size > 0) {
        QUEUE Fro = que[0]; // Dequeue the front element from the queue
        for (int i = 0; i < que_size - 1; i++) {
            que[i] = que[i + 1];
        }
        que_size--;

        // Check if the current state is the goal state
        if (Fro.a == Fro.b && Fro.b == Fro.c) {
            printf("%d\n", Fro.tot); // Print the total number of steps taken and exit the program
            return 0;
        }

        // Try all six possible moves and check if the resulting state is already in the hash table
        int F[6][3] = {
            {1, 0, 0}, {-1, 0, 0},
            {0, 1, 0}, {0, -1, 0},
            {0, 0, 1}, {0, 0, -1}
        };
        for (int i = 0; i < 6; i++) {
            Push = Fro; // Copy the current state into a new variable Push
            Push.tot++; // Increment the total number of steps taken
            Push.a += F[i][0]; Push.b += F[i][1]; Push.c += F[i][2]; // Apply the move to the new state
            int n = Push.a * 10000 + Push.b * 100 + Push.c; // Calculate the hash code of the new state
            if (!HASH(n)) continue; // If the new state is already in the hash table, skip it
            que[que_size++] = Push; // Otherwise, push it into the queue and continue the search
        }
    }

    // Return 0 to indicate that the program has finished running
    return 0;
}
