/*Lucky_Glass*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

// Define a constant for the modulus value
#define MOD 7007

// Structure to represent the state of the glass
struct QUEUE
{
	int a, b, c, tot; // a, b, c represent the amounts in the glasses, tot represents the number of operations
} Push;

// Array to define the possible operations on the glasses
int F[6][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

// Hash table to keep track of visited states
int Hash[MOD][100000];

// Function to check if a state has already been visited
bool HASH(int n)
{
	// Check if the state is already in the hash table
	for(int i = 0; i < Hash[n % MOD][n / 10000]; i++)
		if(n == Hash[n % MOD][i])
			return false; // State already visited
	// If not visited, add the state to the hash table
	Hash[n % MOD][n / 10000] = n;
	return true; // State is new
}

int main()
{
	// Initialize the total operations count
	Push.tot = 0;

	// Create a queue to perform BFS
	struct QUEUE *que = malloc(sizeof(struct QUEUE));

	// Read the initial amounts in the glasses
	scanf("%d%d%d", &Push.a, &Push.b, &Push.c);
	// Push the initial state into the queue
	que[0] = Push;

	// Perform BFS until the queue is empty
	while(que[0].tot != -1)
	{
		// Get the front state from the queue
		QUEUE Fro = que[0];

		// Check if all glasses have the same amount
		if(Fro.a == Fro.b && Fro.b == Fro.c)
		{
			// If they are equal, print the number of operations and exit
			printf("%d\n", Fro.tot);
			return 0;
		}

		// Iterate through all possible operations
		for(int i = 0; i < 6; i++)
		{
			// Copy the current state to a new state
			Push = Fro;
			Push.tot++; // Increment the operation count

			// Apply the operation to the glasses
			Push.a += F[i][0]; 
			Push.b += F[i][1]; 
			Push.c += F[i][2];

			// Create a unique identifier for the new state
			int n = Push.a * 10000 + Push.b * 100 + Push.c;

			// Check if the new state has been visited
			if(!HASH(n)) continue; // If visited, skip to the next operation

			// Push the new state into the queue for further exploration
			que[que[0].tot + 1] = Push;
		}

		// Remove the processed state from the queue
		que[0].tot = -1;
	}

	return 0; // Exit the program
}

