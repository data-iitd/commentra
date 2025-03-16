
/*Lucky_Glass*/
import java.util.*;

public class s085712108{
	// Define a constant for the modulus value
	private static final int MOD = 7007;

	// Structure to represent the state of the glass
	private static class QUEUE {
		int a, b, c, tot; // a, b, c represent the amounts in the glasses, tot represents the number of operations
	}

	// Array to define the possible operations on the glasses
	private static final int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

	// Hash table to keep track of visited states
	private static List<Integer>[] Hash = new ArrayList[MOD];

	// Function to check if a state has already been visited
	private static boolean HASH(int n) {
		// Check if the state is already in the hash table
		for (int i = 0; i < Hash[n % MOD].size(); i++)
			if (n == Hash[n % MOD].get(i))
				return false; // State already visited
		// If not visited, add the state to the hash table
		if (Hash[n % MOD] == null)
			Hash[n % MOD] = new ArrayList<>();
		Hash[n % MOD].add(n);
		return true; // State is new
	}

	public static void main(String[] args) {
		// Initialize the total operations count
		QUEUE Push = new QUEUE();
		Push.tot = 0;

		// Create a queue to perform BFS
		Queue<QUEUE> que = new LinkedList<>();

		// Read the initial amounts in the glasses
		Scanner sc = new Scanner(System.in);
		Push.a = sc.nextInt();
		Push.b = sc.nextInt();
		Push.c = sc.nextInt();
		// Push the initial state into the queue
		que.add(Push);

		// Perform BFS until the queue is empty
		while (!que.isEmpty()) {
			// Get the front state from the queue
			Push = que.poll();

			// Check if all glasses have the same amount
			if (Push.a == Push.b && Push.b == Push.c) {
				// If they are equal, print the number of operations and exit
				System.out.println(Push.tot);
				return;
			}

			// Iterate through all possible operations
			for (int i = 0; i < 6; i++) {
				// Copy the current state to a new state
				Push = new QUEUE();
				Push.tot = Push.tot + 1; // Increment the operation count
				Push.a = Push.a + F[i][0];
				Push.b = Push.b + F[i][1];
				Push.c = Push.c + F[i][2];

				// Create a unique identifier for the new state
				int n = Push.a * 10000 + Push.b * 100 + Push.c;

				// Check if the new state has been visited
				if (!HASH(n)) continue; // If visited, skip to the next operation

				// Push the new state into the queue for further exploration
				que.add(Push);
			}
		}
	}
}

