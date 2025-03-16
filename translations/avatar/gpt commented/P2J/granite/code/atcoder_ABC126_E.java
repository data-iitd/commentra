
import java.io.*;
import java.util.*;

public class atcoder_ABC126_E{
    static final long MOD = 100000007;
    static final int INF = 100000000;

    public static void main(String[] args) throws Exception {
        // Set the recursion limit to a high value to handle deep recursions if needed
        int N = 100000;
        Thread.currentThread().setStackSize(N * 1024 * 1024);

        // Read input from standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int M = Integer.parseInt(inputs[1]);

        // Initialize an adjacency list to represent the graph
        List<List<Integer>> edge = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<>());
        }

        // Read each edge and populate the adjacency list
        for (int i = 0; i < M; i++) {
            inputs = br.readLine().split(" ");
            int X = Integer.parseInt(inputs[0]) - 1;
            int Y = Integer.parseInt(inputs[1]) - 1;
            int Z = Integer.parseInt(inputs[2]);
            edge.get(X).add(Y);
            edge.get(Y).add(X);
        }

        // Array to track visited nodes
        boolean[] used = new boolean[N];

        // Variable to count the number of connected components
        int ans = 0;

        // Iterate through each node to find connected components
        for (int i = 0; i < N; i++) {
            if (!used[i]) {  // If the node has not been visited
                ans++;  // Increment the count of connected components
                Queue<Integer> queue = new ArrayDeque<>();  // Initialize a queue for BFS
                queue.add(i);  // Start BFS from the current node

                // Perform BFS to mark all reachable nodes from the current node
                while (!queue.isEmpty()) {
                    int node = queue.poll();  // Dequeue a node
                    used[node] = true;  // Mark the node as visited

                    // Explore all adjacent nodes
                    for (int nextnode : edge.get(node)) {
                        if (!used[nextnode]) {  // If the adjacent node has not been visited
                            queue.add(nextnode);  // Enqueue the adjacent node
                        }
                    }
                }
            }
        }

        // Output the number of connected components found
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "