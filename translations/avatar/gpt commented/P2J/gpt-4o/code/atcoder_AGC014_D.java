import java.util.*;

public class TreeGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes in the tree
        int N = scanner.nextInt();
        
        // Initialize adjacency list for the tree
        List<List<Integer>> adj = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        
        // Read edges and build the adjacency list
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        
        // Initialize a queue for BFS and mark the starting node
        Queue<Integer> que = new LinkedList<>();
        que.add(1);
        
        // Array to keep track of visited nodes
        int[] seen = new int[N + 1];
        seen[1] = 1;  // Mark the root node as seen
        
        // Array to store parent of each node
        int[] par = new int[N + 1];
        
        // Array to count the number of children for each node
        int[] childNum = new int[N + 1];
        
        // Perform BFS to populate parent and child count information
        while (!que.isEmpty()) {
            int v = que.poll();  // Get the current node
            for (int u : adj.get(v)) {  // Iterate through adjacent nodes
                if (seen[u] == 0) {  // If the node has not been visited
                    seen[u] = 1;  // Mark it as seen
                    par[u] = v;  // Set the parent of the node
                    childNum[v]++;  // Increment the child count for the parent
                    que.add(u);  // Add the node to the queue for further exploration
                }
            }
        }
        
        // Initialize a deque to process leaf nodes
        Deque<Integer> seq = new ArrayDeque<>();
        
        // Identify all leaf nodes (nodes with no children)
        for (int i = 1; i <= N; i++) {
            if (childNum[i] == 0) {
                seq.add(i);
            }
        }
        
        // Process the leaf nodes in reverse order
        while (!seq.isEmpty()) {
            int c = seq.removeLast();  // Get the current leaf node
            seen[c] = 0;  // Mark the leaf node as unseen
            if (seen[par[c]] == 0) {  // Check if the parent is unseen
                System.out.println("First");  // If so, print 'First' and exit
                return;
            }
            seen[par[c]] = 0;  // Mark the parent as unseen
            childNum[par[par[c]]]--;  // Decrement the child count of the grandparent
            if (childNum[par[par[c]]] == 0) {  // If the grandparent has no children left
                seq.add(par[par[c]]);  // Add the grandparent to the sequence for processing
            }
        }
        
        // If all nodes are processed without triggering 'First', print 'Second'
        System.out.println("Second");
    }
}
// <END-OF-CODE>
