
// Import necessary modules
import java.util.*;

// Function to read input
public static String readLine() throws IOException {
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Define number of vertices in the graph
public static int N = Integer.parseInt(readLine());

// Initialize adjacency list with empty lists for each vertex
public static List<Integer>[] adj = new List[N + 1];
for (int i = 0; i <= N; i++) {
    adj[i] = new ArrayList<Integer>();
}

// Read edges and add them to the adjacency list
for (int i = 0; i < N - 1; i++) {
    int a, b = Arrays.stream(readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    // Add edge between vertices a and b in both directions
    adj[a].add(b);
    adj[b].add(a);
}

// Initialize empty deque for BFS traversal
public static Deque<Integer> que = new ArrayDeque<Integer>();

// Mark starting vertex as visited and add it to the queue
que.add(1);

// Initialize lists to store parent, seen, and child count for each vertex
public static int[] seen = new int[N + 1];
public static int[] par = new int[N + 1];
public static int[] child_num = new int[N + 1];

// BFS traversal starting from the starting vertex
while (!que.isEmpty()) {
    int v = que.removeFirst();
    // Iterate through neighbors of the current vertex
    for (int u : adj[v]) {
        // If neighbor is not yet visited, mark it as visited, update parent and child count
        if (seen[u] == 0) {
            seen[u] = 1;
            par[u] = v;
            child_num[v]++;
            que.add(u);
        }
    }
}

// Initialize empty deque for storing vertices in topological order
public static Deque<Integer> seq = new ArrayDeque<Integer>();

// Find vertices with no incoming edges and add them to the sequence
for (int i = 1; i <= N; i++) {
    if (child_num[i] == 0) {
        seq.add(i);
    }
}

// Topological sort using the sequence of vertices with no incoming edges
while (!seq.isEmpty()) {
    int c = seq.removeFirst();
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

