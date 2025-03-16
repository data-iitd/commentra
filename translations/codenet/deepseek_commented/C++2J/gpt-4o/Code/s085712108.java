import java.util.*; // Import the Java utility library for data structures and utility functions.

public class LuckyGlass {
    // Define a constant MOD with the value 7007.
    static final int MOD = 7007;

    // Define a class QUEUE to store the values of a, b, c, and the total number of operations.
    static class QUEUE {
        int a, b, c, tot;
    }

    // Define a transformation matrix F with six possible transformations.
    static int[][] F = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1},
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    };

    // Define a hash table as an array of lists to store unique states.
    static List<Integer>[] Hash = new ArrayList[MOD];

    // Function to check if a state has been visited before.
    static boolean HASH(int n) {
        int index = n % MOD;
        if (Hash[index] == null) {
            Hash[index] = new ArrayList<>();
        }
        for (int state : Hash[index]) { // Iterate through the hash table.
            if (n == state) // Check if the state is already present.
                return false; // Return false if the state is already visited.
        }
        Hash[index].add(n); // Add the state to the hash table.
        return true; // Return true if the state is new.
    }

    // Main function to execute the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input.
        QUEUE Push = new QUEUE(); // Create an instance of QUEUE.
        Push.tot = 0; // Initialize the total number of operations to 0.
        
        // Read the initial values of a, b, and c.
        Push.a = scanner.nextInt();
        Push.b = scanner.nextInt();
        Push.c = scanner.nextInt();
        
        // Create a queue of QUEUE structures.
        Queue<QUEUE> que = new LinkedList<>();
        que.add(Push); // Push the initial state into the queue.

        while (!que.isEmpty()) { // Continue until the queue is empty.
            QUEUE Fro = que.poll(); // Retrieve and remove the front element of the queue.
            if (Fro.a == Fro.b && Fro.b == Fro.c) { // Check if the current state is the goal state.
                System.out.println(Fro.tot); // Print the total number of operations and exit.
                return;
            }
            for (int i = 0; i < 6; i++) { // Apply each transformation to the current state.
                QUEUE newPush = new QUEUE(); // Create a new instance for the new state.
                newPush.a = Fro.a + F[i][0];
                newPush.b = Fro.b + F[i][1];
                newPush.c = Fro.c + F[i][2];
                newPush.tot = Fro.tot + 1; // Increment the total number of operations.

                int n = newPush.a * 10000 + newPush.b * 100 + newPush.c; // Create a unique identifier for the state.
                if (!HASH(n)) continue; // Check if the state has been visited before.
                que.add(newPush); // Push the new state into the queue.
            }
        }
    }
}
// <END-OF-CODE>
