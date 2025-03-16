/*Lucky_Glass*/
#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>
=======
#include <stdlib.h>
#include <string.h>
>>>>>>> 98c87cb78a (data updated)
#include <stdbool.h>

#define MOD 7007

// Structure to represent the state of the glass
struct QUEUE {
    int a, b, c, tot; // a, b, c represent the amounts in the glasses, tot represents the number of operations
};

// Array to define the possible operations on the glasses
int F[6][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

// Hash table to keep track of visited states
int Hash[MOD][10000]; // Assuming a maximum of 10000 states per hash bucket
int HashCount[MOD] = {0}; // To keep track of the number of states in each bucket

// Function to check if a state has already been visited
bool HASH(int n) {
    int index = n % MOD;
    for (int i = 0; i < HashCount[index]; i++) {
        if (n == Hash[index][i]) {
            return false; // State already visited
        }
    }
    // If not visited, add the state to the hash table
    Hash[index][HashCount[index]++] = n;
    return true; // State is new
}

int main() {
    // Initialize the total operations count
    struct QUEUE Push;
    Push.tot = 0;

    // Create a queue to perform BFS
<<<<<<< HEAD
    struct QUEUE que[100000]; // Assuming a maximum queue size
    int front = 0, rear = 0;
=======
    struct QUEUE *que = (struct QUEUE *)malloc(100000 * sizeof(struct QUEUE)); // Allocate memory for the queue
    int front = 0, rear = 0; // Queue pointers
>>>>>>> 98c87cb78a (data updated)

    // Read the initial amounts in the glasses
    scanf("%d%d%d", &Push.a, &Push.b, &Push.c);
    // Push the initial state into the queue
    que[rear++] = Push;

    // Perform BFS until the queue is empty
    while (front < rear) {
        // Get the front state from the queue
        struct QUEUE Fro = que[front++];

        // Check if all glasses have the same amount
        if (Fro.a == Fro.b && Fro.b == Fro.c) {
            // If they are equal, print the number of operations and exit
            printf("%d\n", Fro.tot);
<<<<<<< HEAD
=======
            free(que); // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
            return 0;
        }

        // Iterate through all possible operations
        for (int i = 0; i < 6; i++) {
            // Copy the current state to a new state
<<<<<<< HEAD
            struct QUEUE PushNew = Fro;
            PushNew.tot++; // Increment the operation count

            // Apply the operation to the glasses
            PushNew.a += F[i][0];
            PushNew.b += F[i][1];
            PushNew.c += F[i][2];

            // Create a unique identifier for the new state
            int n = PushNew.a * 10000 + PushNew.b * 100 + PushNew.c;
=======
            struct QUEUE NewState = Fro;
            NewState.tot++; // Increment the operation count

            // Apply the operation to the glasses
            NewState.a += F[i][0];
            NewState.b += F[i][1];
            NewState.c += F[i][2];

            // Create a unique identifier for the new state
            int n = NewState.a * 10000 + NewState.b * 100 + NewState.c;
>>>>>>> 98c87cb78a (data updated)

            // Check if the new state has been visited
            if (!HASH(n)) continue; // If visited, skip to the next operation

            // Push the new state into the queue for further exploration
<<<<<<< HEAD
            que[rear++] = PushNew;
        }
    }

=======
            que[rear++] = NewState;
        }
    }

    free(que); // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    return 0; // Exit the program
}

// <END-OF-CODE>
