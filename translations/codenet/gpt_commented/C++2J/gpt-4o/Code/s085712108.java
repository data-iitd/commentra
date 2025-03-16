import java.util.*;

public class LuckyGlass {
    // Define a constant for the modulus value
    private static final int MOD = 7007;

    // Structure to represent the state of the glass
    static class QUEUE {
        int a, b, c, tot; // a, b, c represent the amounts in the glasses, tot represents the number of operations

        QUEUE(int a, int b, int c, int tot) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.tot = tot;
        }
    }

    // Array to define the possible operations on the glasses
    static int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

    // Hash table to keep track of visited states
    static List<Integer>[] Hash = new ArrayList[MOD];

    // Function to check if a state has already been visited
    static boolean HASH(int n) {
        // Check if the state is already in the hash table
        for (int i = 0; i < Hash[n % MOD].size(); i++) {
            if (n == Hash[n % MOD].get(i)) {
                return false; // State already visited
            }
        }
        // If not visited, add the state to the hash table
        Hash[n % MOD].add(n);
        return true; // State is new
    }

    public static void main(String[] args) {
        // Initialize the hash table
        for (int i = 0; i < MOD; i++) {
            Hash[i] = new ArrayList<>();
        }

        // Initialize the total operations count
        QUEUE Push = new QUEUE(0, 0, 0, 0);

        // Create a queue to perform BFS
        Queue<QUEUE> que = new LinkedList<>();

        // Read the initial amounts in the glasses
        Scanner scanner = new Scanner(System.in);
        Push.a = scanner.nextInt();
        Push.b = scanner.nextInt();
        Push.c = scanner.nextInt();
        // Push the initial state into the queue
        que.add(Push);

        // Perform BFS until the queue is empty
        while (!que.isEmpty()) {
            // Get the front state from the queue
            QUEUE Fro = que.poll();

            // Check if all glasses have the same amount
            if (Fro.a == Fro.b && Fro.b == Fro.c) {
                // If they are equal, print the number of operations and exit
                System.out.println(Fro.tot);
                return;
            }

            // Iterate through all possible operations
            for (int i = 0; i < 6; i++) {
                // Copy the current state to a new state
                QUEUE newState = new QUEUE(Fro.a, Fro.b, Fro.c, Fro.tot + 1);

                // Apply the operation to the glasses
                newState.a += F[i][0];
                newState.b += F[i][1];
                newState.c += F[i][2];

                // Create a unique identifier for the new state
                int n = newState.a * 10000 + newState.b * 100 + newState.c;

                // Check if the new state has been visited
                if (!HASH(n)) continue; // If visited, skip to the next operation

                // Push the new state into the queue for further exploration
                que.add(newState);
            }
        }
    }
}
// <END-OF-CODE>
