/*Lucky_Glass*/
#include <stdio.h> // Include the standard input/output library for input/output operations.
#include <string.h> // Include the C string library for string manipulation.
#include <stdlib.h> // Include the standard library for memory allocation and other utilities.
#include <stdbool.h> // Include the standard library for boolean type.
#include <queue> // Include the queue library for queue operations.
#include <vector> // Include the vector library for dynamic array operations.

#define MOD 7007 // Define a constant MOD with the value 7007.

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
struct QUEUE {
    int a, b, c, tot;
};

// Define a transformation matrix F with six possible transformations.
int F[6][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

// Define a hash table as an array of arrays to store unique states.
<<<<<<< HEAD
int Hash[MOD][100]; // Assuming a maximum of 100 states per hash bucket for simplicity.
=======
int Hash[MOD][100]; // Assuming a maximum of 100 states per hash bucket.
>>>>>>> 98c87cb78a (data updated)
int HashCount[MOD]; // To keep track of the number of states in each bucket.

// Function to check if a state has been visited before.
bool HASH(int n) {
    int index = n % MOD;
    for (int i = 0; i < HashCount[index]; i++) { // Iterate through the hash table.
        if (n == Hash[index][i]) // Check if the state is already present.
            return false; // Return false if the state is already visited.
    }
    Hash[index][HashCount[index]++] = n; // Add the state to the hash table.
    return true; // Return true if the state is new.
}

// Main function to execute the program.
int main() {
    struct QUEUE Push; // Declare a QUEUE structure for the initial state.
    Push.tot = 0; // Initialize the total number of operations to 0.
<<<<<<< HEAD
    struct QUEUE que[10000]; // Create a queue of QUEUE structures (fixed size for simplicity).
    int front = 0, rear = 0; // Initialize front and rear for the queue.

    scanf("%d%d%d", &Push.a, &Push.b, &Push.c); // Read the initial values of a, b, and c.
    que[rear++] = Push; // Push the initial state into the queue.

    while (front < rear) { // Continue until the queue is empty.
        struct QUEUE Fro = que[front++]; // Retrieve and remove the front element of the queue.
=======

    // Read the initial values of a, b, and c.
    scanf("%d%d%d", &Push.a, &Push.b, &Push.c);
    
    // Initialize the hash table counts to 0.
    memset(HashCount, 0, sizeof(HashCount));

    // Create a queue of QUEUE structures.
    struct queue {
        struct QUEUE data[10000]; // Assuming a maximum of 10000 states in the queue.
        int front, rear;
    } que;

    que.front = 0;
    que.rear = 0;

    // Function to push to the queue.
    void push(struct QUEUE item) {
        que.data[que.rear++] = item;
    }

    // Function to pop from the queue.
    struct QUEUE pop() {
        return que.data[que.front++];
    }

    // Function to check if the queue is empty.
    int is_empty() {
        return que.front == que.rear;
    }

    push(Push); // Push the initial state into the queue.

    while (!is_empty()) { // Continue until the queue is empty.
        struct QUEUE Fro = pop(); // Retrieve the front element of the queue.
>>>>>>> 98c87cb78a (data updated)
        if (Fro.a == Fro.b && Fro.b == Fro.c) { // Check if the current state is the goal state.
            printf("%d\n", Fro.tot); // Print the total number of operations and exit.
            return 0;
        }
        for (int i = 0; i < 6; i++) { // Apply each transformation to the current state.
            Push = Fro; // Copy the current state to Push.
            Push.tot++; // Increment the total number of operations.
            Push.a += F[i][0]; Push.b += F[i][1]; Push.c += F[i][2]; // Apply the transformation.
            int n = Push.a * 10000 + Push.b * 100 + Push.c; // Create a unique identifier for the state.
            if (!HASH(n)) continue; // Check if the state has been visited before.
<<<<<<< HEAD
            que[rear++] = Push; // Push the new state into the queue.
=======
            push(Push); // Push the new state into the queue.
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return 0; // Return 0 to indicate successful execution.
}

/* <END-OF-CODE> */
