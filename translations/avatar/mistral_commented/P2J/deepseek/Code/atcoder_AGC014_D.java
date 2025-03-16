import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read number of vertices
        int N = scanner.nextInt();
        
        // Initialize adjacency list with empty lists for each vertex
        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        
        // Read edges and add them to the adjacency list
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            // Add edge between vertices a and b in both directions
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        
        // Initialize empty queue for BFS traversal
        Queue<Integer> que = new LinkedList<>();
        
        // Mark starting vertex as visited and add it to the queue
        que.add(1);
        
        // Initialize lists to store parent, seen, and child count for each vertex
        int[] seen = new int[N + 1];
        int[] par = new int[N + 1];
        int[] child_num = new int[N + 1];
        
        // BFS traversal starting from the starting vertex
        while (!que.isEmpty()) {
            int v = que.poll();
            // Iterate through neighbors of the current vertex
            for (int u : adj.get(v)) {
                // If neighbor is not yet visited, mark it as visited, update parent and child count
                if (seen[u] == 0) {
                    seen[u] = 1;
                    par[u] = v;
                    child_num[v]++;
                    que.add(u);
                }
            }
        }
        
        // Initialize empty queue for storing vertices in topological order
        Queue<Integer> seq = new LinkedList<>();
        
        // Find vertices with no incoming edges and add them to the sequence
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
            }
        }
        
        // Topological sort using the sequence of vertices with no incoming edges
        while (!seq.isEmpty()) {
            int c = seq.poll();
            // If parent of the current vertex is not yet processed, print "First" and exit
            if (seen[par[c]] == 0) {
                System.out.println("First");
                return;
            }
            // Mark parent as not visited and update child count of its parent
            seen[par[c]] = 0;
            child_num[par[par[c]]]--;
            // If the parent of the parent has no children, add it to the sequence
            if (child_num[par[par[c]]] == 0) {
                seq.add(par[par[c]]);
            }
        }
        
        // Print "Second" if all vertices have been processed
        System.out.println("Second");
    }
}
