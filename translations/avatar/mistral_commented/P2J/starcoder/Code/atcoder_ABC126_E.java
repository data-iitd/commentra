

import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input values for N and M
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize an empty list for edge
        List<List<Integer>> edge = new ArrayList<List<Integer>>();
        for (int i = 0; i < N; i++) {
            edge.add(new ArrayList<Integer>());
        }

        // Read edges and add them to the edge list
        for (int i = 0; i < M; i++) {
            int X = sc.nextInt() - 1;
            int Y = sc.nextInt() - 1;
            int Z = sc.nextInt();
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
                // Initialize a queue for DFS traversal
                Queue<Integer> queue = new LinkedList<Integer>();
                // Add the current node to the queue
                queue.add(i);
                // Traverse through the graph using DFS
                while (!queue.isEmpty()) {
                    // Get the next node from the queue
                    int node = queue.remove();
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

