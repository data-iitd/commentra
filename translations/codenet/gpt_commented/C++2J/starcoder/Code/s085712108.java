/*Lucky_Glass*/
import java.util.*;
import java.io.*;

public class Lucky_Glass
{
	// Define a constant for the modulus value
	static final int MOD = 7007;

	// Structure to represent the state of the glass
	static class QUEUE
	{
		int a, b, c, tot; // a, b, c represent the amounts in the glasses, tot represents the number of operations
	}

	// Array to define the possible operations on the glasses
	static int F[][] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

	// Hash table to keep track of visited states
	static Vector<Integer> Hash[] = new Vector[MOD];

	// Function to check if a state has already been visited
	static boolean HASH(int n)
	{
		// Check if the state is already in the hash table
		for(int i = 0; i < Hash[n % MOD].size(); i++)
			if(n == Hash[n % MOD].get(i))
				return false; // State already visited
		// If not visited, add the state to the hash table
		Hash[n % MOD].add(n);
		return true; // State is new
	}

	public static void main(String[] args) throws java.lang.Exception
	{
		// Initialize the total operations count
		QUEUE Push = new QUEUE();
		Push.tot = 0;

		// Create a queue to perform BFS
		Queue<QUEUE> que = new LinkedList<QUEUE>();

		// Read the initial amounts in the glasses
		Scanner sc = new Scanner(System.in);
		Push.a = sc.nextInt();
		Push.b = sc.nextInt();
		Push.c = sc.nextInt();
		// Push the initial state into the queue
		que.add(Push);

		// Perform BFS until the queue is empty
		while(!que.isEmpty())
		{
			// Get the front state from the queue
			QUEUE Fro = que.peek();

			// Check if all glasses have the same amount
			if(Fro.a == Fro.b && Fro.b == Fro.c)
			{
				// If they are equal, print the number of operations and exit
				System.out.println(Fro.tot);
				return;
			}

			// Iterate through all possible operations
			for(int i = 0; i < 6; i++)
			{
				// Copy the current state to a new state
				QUEUE Push = new QUEUE();
				Push.tot = Fro.tot + 1; // Increment the operation count

				// Apply the operation to the glasses
				Push.a = Fro.a + F[i][0]; 
				Push.b = Fro.b + F[i][1]; 
				Push.c = Fro.c + F[i][2];

				// Create a unique identifier for the new state
				int n = Push.a * 10000 + Push.b * 100 + Push.c;

				// Check if the new state has been visited
				if(!HASH(n)) continue; // If visited, skip to the next operation

				// Push the new state into the queue for further exploration
				que.add(Push);
			}

			// Remove the processed state from the queue
			que.remove();
		}
	}
}
