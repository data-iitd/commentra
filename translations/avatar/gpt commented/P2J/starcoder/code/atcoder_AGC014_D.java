import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes in the tree
        int N = sc.nextInt();

        // Initialize adjacency list for the tree
        List<Integer>[] adj = new List[N + 1];
        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        // Read edges and build the adjacency list
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }

        // Initialize a queue for BFS and mark the starting node
        Queue<Integer> que = new LinkedList<>();
        que.add(1);

        // Array to keep track of visited nodes
        boolean[] seen = new boolean[N + 1];
        seen[1] = true;  // Mark the root node as seen

        // Array to store parent of each node
        int[] par = new int[N + 1];

        // Array to count the number of children for each node
        int[] child_num = new int[N + 1];

        // Perform BFS to populate parent and child count information
        while (!que.isEmpty()) {
            int v = que.poll();  // Get the current node
            for (int u : adj[v]) {  // Iterate through adjacent nodes
                if (!seen[u]) {  // If the node has not been visited
                    seen[u] = true;  // Mark it as seen
                    par[u] = v;  // Set the parent of the node
                    child_num[v]++;  // Increment the child count for the parent
                    que.add(u);  // Add the node to the queue for further exploration
        }

        // Initialize a deque to process leaf nodes
        Deque<Integer> seq = new LinkedList<>();

        // Identify all leaf nodes (nodes with no children)
        for (int i = 1; i <= N; i++) {
            if (child_num[i] == 0) {
                seq.add(i);
        }

        // Process the leaf nodes in reverse order
        while (!seq.isEmpty()) {
            int c = seq.poll();  // Get the current leaf node
            seen[c] = false;  // Mark the leaf node as unseen
            if (!seen[par[c]]) {  // Check if the parent is unseen
                System.out.println("First");  // If so, print 'First' and exit
                return;
        }
            seen[par[c]] = false;  // Mark the parent as unseen
            child_num[par[par[c]]]--;  // Decrement the child count of the grandparent
            if (child_num[par[par[c]]] == 0) {  // If the grandparent has no children left
                seq.add(par[par[c]]);  // Add the grandparent to the sequence for processing
        }

        // If all nodes are processed without triggering 'First', print 'Second'
        System.out.println("Second");
    }
}

