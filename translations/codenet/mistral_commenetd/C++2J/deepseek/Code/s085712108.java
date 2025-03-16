import java.util.*;

public class Main {
    static final int MOD = 7007;

    // Define a class QUEUE to store the current state and the total number of steps taken
    static class QUEUE {
        int a, b, c, tot; // a, b, c represent the current state and tot is the total number of steps taken

        QUEUE(int a, int b, int c, int tot) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.tot = tot;
        }
    }

    // Initialize an empty hash table to store visited states
    static List<Integer>[] Hash = new ArrayList[MOD];

    // Function to initialize the hash table
    static {
        for (int i = 0; i < MOD; i++) {
            Hash[i] = new ArrayList<>();
        }
    }

    // Function to check if a state is already in the hash table
    static boolean HASH(int n) {
        for (int i = 0; i < Hash[n % MOD].size(); i++) {
            if (n == Hash[n % MOD].get(i)) {
                return false;
            }
        }
        Hash[n % MOD].add(n);
        return true;
    }

    public static void main(String[] args) {
        // Initialize some variables and read input data
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        Queue<QUEUE> que = new LinkedList<>();
        que.add(new QUEUE(a, b, c, 0));

        // Main loop to find the solution
        while (!que.isEmpty()) {
            QUEUE Fro = que.poll(); // Dequeue the front element from the queue

            // Check if the current state is the goal state
            if (Fro.a == Fro.b && Fro.b == Fro.c) {
                System.out.println(Fro.tot); // Print the total number of steps taken and exit the program
                return;
            }

            // Try all six possible moves and check if the resulting state is already in the hash table
            int[][] F = {
                {1, 0, 0}, {-1, 0, 0},
                {0, 1, 0}, {0, -1, 0},
                {0, 0, 1}, {0, 0, -1}
            };
            for (int i = 0; i < 6; i++) {
                QUEUE Push = new QUEUE(Fro.a + F[i][0], Fro.b + F[i][1], Fro.c + F[i][2], Fro.tot + 1);
                int n = Push.a * 10000 + Push.b * 100 + Push.c; // Calculate the hash code of the new state
                if (!HASH(n)) continue; // If the new state is already in the hash table, skip it
                que.add(Push); // Otherwise, push it into the queue and continue the search
            }
        }

        // Return 0 to indicate that the program has finished running
    }
}
