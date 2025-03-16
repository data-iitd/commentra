import java.util.*;

public class Main {
    static final long INF = (long) 1e18;  // Define a constant for infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Read the number of nodes
        int M = scanner.nextInt();  // Read the number of edges
        List<List<Integer>> edge = new ArrayList<>(N);  // Initialize the edge list to represent the graph

        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<>());  // Initialize each list for the graph
        }

        for (int i = 0; i < M; i++) {
            int X = scanner.nextInt() - 1;  // Read each edge and adjust indices
            int Y = scanner.nextInt() - 1;
            edge.get(X).add(Y);  // Add edge in both directions for an undirected graph
            edge.get(Y).add(X);
        }

        boolean[] used = new boolean[N];  // Initialize a list to track visited nodes
        int ans = 0;  // Initialize the counter for connected components

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                ans++;  // Increment the counter for each new connected component found
                Queue<Integer> queue = new LinkedList<>();  // Initialize a queue for BFS
                queue.add(i);  // Start BFS from the current node

                while (!queue.isEmpty()) {
                    int node = queue.poll();  // Get the next node from the queue
                    used[node] = true;  // Mark the node as visited

                    for (int nextnode : edge.get(node)) {
                        if (!used[nextnode]) {
                            queue.add(nextnode);  // Add unvisited neighbors to the queue
                        }
                    }
                }
            }
        }

        System.out.println(ans);  // Output the total number of connected components
        scanner.close();
    }
}
// <END-OF-CODE>
