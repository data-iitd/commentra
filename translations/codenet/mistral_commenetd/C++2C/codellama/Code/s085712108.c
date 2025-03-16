#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue.h>
#define MOD 7007

// Define a struct QUEUE to store the current state and the total number of steps taken
struct QUEUE
{
	int a,b,c,tot; // a, b, c represent the current state and tot is the total number of steps taken
}Push;

// Initialize an empty hash table to store visited states
int Hash[MOD];

// Function to check if a state is already in the hash table
bool HASH(int n)
{
	for(int i=0;i<Hash[n%MOD];i++)
		if(n==Hash[n%MOD][i])
			return false;
	Hash[n%MOD][i]=n;
	return true;
}

int main()
{
	// Initialize some variables and read input data
	Push.tot=0;
	queue<QUEUE> que;
	scanf("%d%d%d",&Push.a,&Push.b,&Push.c);
	que.push(Push);

	// Main loop to find the solution
	while(!que.empty())
	{
		QUEUE Fro=que.front(); // Dequeue the front element from the queue

		// Check if the current state is the goal state
		if(Fro.a==Fro.b && Fro.b==Fro.c)
		{
			printf("%d\n",Fro.tot); // Print the total number of steps taken and exit the program
			return 0;
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for(int i=0;i<6;i++)
		{
			Push=Fro; // Copy the current state into a new variable Push
			Push.tot++; // Increment the total number of steps taken
			Push.a+=F[i][0]; Push.b+=F[i][1]; Push.c+=F[i][2]; // Apply the move to the new state
			int n=Push.a*10000+Push.b*100+Push.c; // Calculate the hash code of the new state
			if(!HASH(n)) continue; // If the new state is already in the hash table, skip it
			que.push(Push); // Otherwise, push it into the queue and continue the search
		}

		// Dequeue the front element from the queue to continue the search
		que.pop();
	}

	// Return 0 to indicate that the program has finished running
	return 0;
}

