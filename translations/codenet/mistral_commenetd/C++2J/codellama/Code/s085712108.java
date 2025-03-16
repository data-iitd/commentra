import java.util.*;

// Define a class QUEUE to store the current state and the total number of steps taken
class QUEUE
{
	int a,b,c,tot; // a, b, c represent the current state and tot is the total number of steps taken
}

// Initialize an empty hash table to store visited states
HashMap<Integer,Integer> Hash=new HashMap<Integer,Integer>();

// Function to check if a state is already in the hash table
boolean HASH(int n)
{
	if(Hash.containsKey(n))
		return false;
	Hash.put(n,n);
	return true;
}

public class Main
{
	// Define an array F to store the six possible moves
	static int[][] F={{-1,0,0},{0,-1,0},{0,0,-1},{1,0,0},{0,1,0},{0,0,1}};

	public static void main(String[] args)
	{
		// Initialize some variables and read input data
		QUEUE Push=new QUEUE();
		Queue<QUEUE> que=new LinkedList<QUEUE>();
		Push.tot=0;
		scanf("%d%d%d",&Push.a,&Push.b,&Push.c);
		que.add(Push);

		// Main loop to find the solution
		while(!que.isEmpty())
		{
			QUEUE Fro=que.poll(); // Dequeue the front element from the queue

			// Check if the current state is the goal state
			if(Fro.a==Fro.b && Fro.b==Fro.c)
			{
				printf("%d\n",Fro.tot); // Print the total number of steps taken and exit the program
				return;
			}

			// Try all six possible moves and check if the resulting state is already in the hash table
			for(int i=0;i<6;i++)
			{
				Push=Fro; // Copy the current state into a new variable Push
				Push.tot++; // Increment the total number of steps taken
				Push.a+=F[i][0]; Push.b+=F[i][1]; Push.c+=F[i][2]; // Apply the move to the new state
				int n=Push.a*10000+Push.b*100+Push.c; // Calculate the hash code of the new state
				if(!HASH(n)) continue; // If the new state is already in the hash table, skip it
				que.add(Push); // Otherwise, push it into the queue and continue the search
			}

			// Dequeue the front element from the queue to continue the search
			que.poll();
		}

		// Return 0 to indicate that the program has finished running
		return;
	}
}

