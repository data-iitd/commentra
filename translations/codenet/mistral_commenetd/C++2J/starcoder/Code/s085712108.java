import java.util.*;

public class Main
{
	// Define a struct QUEUE to store the current state and the total number of steps taken
	static class QUEUE
	{
		int a,b,c,tot; // a, b, c represent the current state and tot is the total number of steps taken
	}

	// Initialize an empty hash table to store visited states
	static Vector<Integer>[] Hash=new Vector[7007];

	// Function to check if a state is already in the hash table
	static boolean HASH(int n)
	{
		for(int i=0;i<Hash[n%7007].size();i++)
			if(n==Hash[n%7007].get(i))
				return false;
		Hash[n%7007].add(n);
		return true;
	}

	public static void main(String[] args)
	{
		// Initialize some variables and read input data
		QUEUE Push=new QUEUE();
		Push.tot=0;
		Scanner sc=new Scanner(System.in);
		Push.a=sc.nextInt();
		Push.b=sc.nextInt();
		Push.c=sc.nextInt();
		Queue<QUEUE> que=new LinkedList<QUEUE>();
		que.add(Push);

		// Main loop to find the solution
		while(!que.isEmpty())
		{
			QUEUE Fro=que.peek(); // Dequeue the front element from the queue

			// Check if the current state is the goal state
			if(Fro.a==Fro.b && Fro.b==Fro.c)
			{
				System.out.println(Fro.tot); // Print the total number of steps taken and exit the program
				return;
			}

			// Try all six possible moves and check if the resulting state is already in the hash table
			for(int i=0;i<6;i++)
			{
				QUEUE Push=new QUEUE(); // Copy the current state into a new variable Push
				Push.tot=Fro.tot+1; // Increment the total number of steps taken
				Push.a=Fro.a+F[i][0]; Push.b=Fro.b+F[i][1]; Push.c=Fro.c+F[i][2]; // Apply the move to the new state
				int n=Push.a*10000+Push.b*100+Push.c; // Calculate the hash code of the new state
				if(!HASH(n)) continue; // If the new state is already in the hash table, skip it
				que.add(Push); // Otherwise, push it into the queue and continue the search
			}

			// Dequeue the front element from the queue to continue the search
			que.poll();
		}
	}
}

