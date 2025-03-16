/*Lucky_Glass*/
#include<stdio.h> // Include the standard input/output library for input/output operations.
#include<string.h> // Include the C string library for string manipulation.
#include<stdlib.h> // Include the standard library for memory allocation operations.
#include<stdbool.h> // Include the standard boolean library for boolean operations.
#define MOD 7007 // Define a constant MOD with the value 7007.

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
typedef struct
{
	int a,b,c,tot;
}QUEUE;

// Define a transformation matrix F with six possible transformations.
int F[6][3]={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};

// Define a hash table as an array of vectors to store unique states.
int *Hash[MOD];

// Function to check if a state has been visited before.
bool HASH(int n)
{
	for(int i=0;i<Hash[n%MOD].size;i++) // Iterate through the hash table.
		if(n==Hash[n%MOD][i]) // Check if the state is already present.
			return false; // Return false if the state is already visited.
	Hash[n%MOD].push_back(n); // Add the state to the hash table.
	return true; // Return true if the state is new.
}

// Main function to execute the program.
int main()
{
	QUEUE Push; // Create a structure QUEUE.
	Push.tot=0; // Initialize the total number of operations to 0.
	QUEUE *que=(QUEUE*)malloc(sizeof(QUEUE)); // Allocate memory for a QUEUE structure.
	scanf("%d%d%d",&Push.a,&Push.b,&Push.c); // Read the initial values of a, b, and c.
	que->a=Push.a;que->b=Push.b;que->c=Push.c; // Copy the initial values to the queue.
	que->tot=Push.tot; // Copy the initial value to the queue.
	HASH(que->a*10000+que->b*100+que->c); // Add the initial state to the hash table.
	while(true) // Continue until the queue is empty.
	{
		QUEUE Fro=*que; // Retrieve the front element of the queue.
		if(Fro.a==Fro.b && Fro.b==Fro.c) // Check if the current state is the goal state.
		{
			printf("%d\n",Fro.tot); // Print the total number of operations and exit.
			return 0;
		}
		for(int i=0;i<6;i++) // Apply each transformation to the current state.
		{
			Push=Fro; // Copy the current state to Push.
			Push.tot++; // Increment the total number of operations.
			Push.a+=F[i][0];Push.b+=F[i][1];Push.c+=F[i][2]; // Apply the transformation.
			int n=Push.a*10000+Push.b*100+Push.c; // Create a unique identifier for the state.
			if(!HASH(n)) continue; // Check if the state has been visited before.
			QUEUE *New=(QUEUE*)malloc(sizeof(QUEUE)); // Allocate memory for a QUEUE structure.
			New->a=Push.a;New->b=Push.b;New->c=Push.c; // Copy the new state to the new structure.
			New->tot=Push.tot; // Copy the new value to the new structure.
			que->push(New); // Push the new state into the queue.
		}
		que->pop(); // Remove the front element from the queue.
	}
	return 0; // Return 0 to indicate successful execution.
}

