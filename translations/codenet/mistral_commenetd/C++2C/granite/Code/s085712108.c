
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a struct QUEUE to store the current state and the total number of steps taken
typedef struct
{
	int a,b,c,tot; // a, b, c represent the current state and tot is the total number of steps taken
}QUEUE;

// Initialize an empty hash table to store visited states
int Hash[7007][10000];

// Function to check if a state is already in the hash table
int HASH(int n)
{
	for(int i=0;i<Hash[n%7007][0];i++)
		if(n==Hash[n%7007][i+1])
			return false;
	Hash[n%7007][0]++;
	Hash[n%7007][Hash[n%7007][0]]=n;
	return true;
}

int main()
{
	// Initialize some variables and read input data
	QUEUE Fro,Push;
	int i,j,k,tot;
	scanf("%d%d%d",&Fro.a,&Fro.b,&Fro.c);
	Fro.tot=0;
	tot=0;

	// Main loop to find the solution
	while(1)
	{
		// Check if the current state is the goal state
		if(Fro.a==Fro.b && Fro.b==Fro.c)
		{
			printf("%d\n",Fro.tot); // Print the total number of steps taken and exit the program
			break;
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for(i=0;i<6;i++)
		{
			Push=Fro; // Copy the current state into a new variable Push
			Push.tot++; // Increment the total number of steps taken
			Push.a+=F[i][0]; Push.b+=F[i][1]; Push.c+=F[i][2]; // Apply the move to the new state
			int n=Push.a*10000+Push.b*100+Push.c; // Calculate the hash code of the new state
			if(!HASH(n)) continue; // If the new state is already in the hash table, skip it
			Fro=Push; // Otherwise, update the current state and continue the search
		}
	}

	// Return 0 to indicate that the program has finished running
	return 0;
}

