
import java.util.*;
import java.io.*;

// Function to read an integer from standard input
int inp() {
    return Integer.parseInt(br.readLine());
}

// Function to read a list of integers from standard input
List<Integer> inpl() {
    return Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Read the number of nodes, starting node for Ta, and starting node for Ao
List<Integer> l = inpl();
int n = l.get(0);
int ta = l.get(1);
int ao = l.get(2);

// Adjust indices to be zero-based
ta--;
ao--;

// Initialize the graph as a list of lists, each representing adjacency list of a node
List<List<Integer>> g = new ArrayList<>(n);
for (int i = 0; i < n; i++) {
    g.add(new ArrayList<>());
}

// Read edges to construct the graph
for (int i = 0; i < n - 1; i++) {
    List<Integer> l = inpl();
    int a = l.get(0);
    int b = l.get(1);
    g.get(a - 1).add(b - 1);  // Append the zero-based index of the neighbor
    g.get(b - 1).add(a - 1);  // Append the zero-based index of the neighbor
}

// Initialize distance arrays to -1, will be populated during DFS
int[] ta_dist = new int[n];
ta_dist[ta] = 0;  // Distance from Ta to Ta is 0
int[] ao_dist = new int[n];
ao_dist[ao] = 0;  // Distance from Ao to Ao is 0

// Depth-First Search (DFS) function to compute distances from Ta
void ta_dfs(int node) {
    for (int v : g.get(node)) {
        if (ta_dist[v] != -1)  // If already visited, skip
            continue;
        ta_dist[v] = ta_dist[node] + 1;  // Update distance
        ta_dfs(v);  // Recursively visit neighbors
    }
}

// Depth-First Search (DFS) function to compute distances from Ao
void ao_dfs(int node) {
    for (int v : g.get(node)) {
        if (ao_dist[v] != -1)  // If already visited, skip
            continue;
        ao_dist[v] = ao_dist[node] + 1;  // Update distance
        ao_dfs(v);  // Recursively visit neighbors
    }
}

// Start DFS from Ao to compute distances
ao_dfs(ao);

// Start DFS from Ta to compute distances
ta_dfs(ta);

// Initialize result variable
int res = 0;

// Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
for (int i = 0; i < n; i++) {
    if (ta_dist[i] > ao_dist[i])  // Skip if Ta's distance is greater
        continue;
    res = Math.max(res, ao_dist[i]);  // Update result with the maximum distance
}

// Print the result, which is the maximum distance minus one
System.out.println(res - 1);

