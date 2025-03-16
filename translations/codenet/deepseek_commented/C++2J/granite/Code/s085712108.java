
/*Lucky_Glass*/
import java.util.*; // Import the necessary libraries for input/output and algorithm operations.

public class s085712108{ // Define the main class.
	public static void main(String[] args) { // Define the main function.
		int MOD = 7007; // Define a constant MOD with the value 7007.
		int[][] F = {{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}}; // Define a transformation matrix F with six possible transformations.
		List<Integer>[] Hash = new ArrayList[MOD]; // Define a hash table as an array of lists to store unique states.
		for(int i=0;i<MOD;i++) Hash[i] = new ArrayList<Integer>(); // Initialize the hash table with empty lists.
		Queue<int[]> que = new LinkedList<int[]>(); // Create a queue of integer arrays to store the states.
		Scanner sc = new Scanner(System.in); // Create a scanner object for input.
		int[] Push = new int[3]; // Define an integer array Push to store the values of a, b, and c.
		for(int i=0;i<3;i++) Push[i] = sc.nextInt(); // Read the initial values of a, b, and c.
		que.add(Push); // Push the initial state into the queue.
		while(!que.isEmpty()) { // Continue until the queue is empty.
			int[] Fro = que.poll(); // Retrieve the front element of the queue.
			if(Fro[0]==Fro[1] && Fro[1]==Fro[2]) { // Check if the current state is the goal state.
				System.out.println(Fro[3]); // Print the total number of operations and exit.
				return;
			}
			for(int i=0;i<6;i++) { // Apply each transformation to the current state.
				Push = Fro.clone(); // Copy the current state to Push.
				Push[3]++; // Increment the total number of operations.
				Push[0] += F[i][0]; Push[1] += F[i][1]; Push[2] += F[i][2]; // Apply the transformation.
				int n = Push[0]*10000 + Push[1]*100 + Push[2]; // Create a unique identifier for the state.
				if(Hash[n%MOD].contains(n)) continue; // Check if the state has been visited before.
				Hash[n%MOD].add(n); // Add the state to the hash table.
				que.add(Push); // Push the new state into the queue.
			}
		}
	}
}
