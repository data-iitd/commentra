import java.util.*;

public class Main {
    // Define constant value for INF
    static final long INF = (long) 1e18;

    // Define a custom input function
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        // Read input values for N and M
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Initialize an empty list for edges
        List<List<Integer>> edge = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<>());
        }

        // Read edges and add them to the edge list
        for (int i = 0; i < M; i++) {
            int X = scanner.nextInt() - 1;
            int Y = scanner.nextInt() - 1;
            edge.get(X).add(Y);
            edge.get(Y).add(X);
        }

        // Initialize a list of boolean values for used nodes
        boolean[] used = new boolean[N];

        // Initialize a variable for answer
        int ans = 0;

        // Iterate through all nodes
        for (int i = 0; i < N; i++) {
            // If the current node is not used
            if (!used[i]) {
                // Increment the answer
                ans++;
                // Initialize a queue for BFS traversal
                Queue<Integer> queue = new LinkedList<>();
                // Add the current node to the queue
                queue.add(i);
                // Traverse through the graph using BFS
                while (!queue.isEmpty()) {
                    // Get the next node from the queue
                    int node = queue.poll();
                    // Mark the current node as used
                    used[node] = true;
                    // Traverse through the neighbors of the current node
                    for (int nextnode : edge.get(node)) {
                        // If the neighbor is not used
                        if (!used[nextnode]) {
                            // Add the neighbor to the queue
                            queue.add(nextnode);
                        }
                    }
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
