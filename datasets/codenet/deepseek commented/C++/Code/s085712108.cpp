/*Lucky_Glass*/
#include<cstdio> // Include the standard input/output library for input/output operations.
#include<cstring> // Include the C string library for string manipulation.
#include<algorithm> // Include the standard algorithm library for algorithmic operations.
#include<queue> // Include the queue library for queue operations.
#include<vector> // Include the vector library for dynamic array operations.
using namespace std; // Use the standard namespace.
#define MOD 7007 // Define a constant MOD with the value 7007.

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
struct QUEUE
{
	int a,b,c,tot;
}Push;

// Define a transformation matrix F with six possible transformations.
int F[6][3]={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};

// Define a hash table as an array of vectors to store unique states.
vector<int> Hash[MOD];

// Function to check if a state has been visited before.
bool HASH(int n)
{
	for(int i=0;i<Hash[n%MOD].size();i++) // Iterate through the hash table.
		if(n==Hash[n%MOD][i]) // Check if the state is already present.
			return false; // Return false if the state is already visited.
	Hash[n%MOD].push_back(n); // Add the state to the hash table.
	return true; // Return true if the state is new.
}

// Main function to execute the program.
int main()
{
	Push.tot=0; // Initialize the total number of operations to 0.
	queue<QUEUE> que; // Create a queue of QUEUE structures.
	scanf("%d%d%d",&Push.a,&Push.b,&Push.c); // Read the initial values of a, b, and c.
	que.push(Push); // Push the initial state into the queue.
	while(!que.empty()) // Continue until the queue is empty.
	{
		QUEUE Fro=que.front(); // Retrieve the front element of the queue.
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
			que.push(Push); // Push the new state into the queue.
		}
		que.pop(); // Remove the front element from the queue.
	}
	return 0; // Return 0 to indicate successful execution.
}
