import java.util.*;

public class GraphTraversal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Define number of vertices in the graph
        int N = input.nextInt();
        
        // Initialize adjacency list with empty lists for each vertex
        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        // Read edges and add them to the adjacency list
        for (int i = 0; i < N - 1; i++) {
            int a = input.nextInt();
            int b = input.nextInt();
            // Add edge between vertices a and b in both directions
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        // Initialize empty deque for BFS traversal
        Deque<Integer> que = new ArrayDeque<>();

        // Mark starting vertex as visited and add it to the queue
        que.add(1);

        // Initialize arrays to store parent, seen, and child count for each vertex
        int[] seen = new int[N + 1];
        int[] par = new int[N + 1];
        int[] childNum = new int[N + 1];

        // BFS traversal starting from the starting vertex
        while (!que.isEmpty()) {
            int v = que.poll();
            // Iterate through neighbors of the current vertex
            for (int u : adj.get(v)) {
                // If neighbor is not yet visited, mark it as visited, update parent and child count
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    childNum[v]++;
                    que.add(u);
                }
            }
        }

        // Initialize empty deque for storing vertices in topological order
        Deque<Integer> seq = new ArrayDeque<>();

        // Find vertices with no incoming edges and add them to the sequence
        for (int i = 1; i <= N; i++) {
            if (childNum[i] == 0) {
                seq.add(i);
            }
        }

        // Topological sort using the sequence of vertices with no incoming edges
        while (!seq.isEmpty()) {
            int c = seq.removeLast();
            // If parent of the current vertex is not yet processed, print "First" and exit
            if (seen[par[c]] == 0) {
                System.out.println("First");
                return;
            }
            // Mark parent as not visited and update child count of its parent
            seen[par[c]] = 0;
            childNum[par[par[c]]]--;
            // If the parent of the parent has no children, add it to the sequence
            if (childNum[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }

        // Print "Second" if all vertices have been processed
        System.out.println("Second");
    }
}
// <END-OF-CODE>
