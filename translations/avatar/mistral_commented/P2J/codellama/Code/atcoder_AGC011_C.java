// Importing the queue module for implementing Depth First Search (DFS) using a stack
import java.util.Queue;
import java.util.LinkedList;

// Taking the number of vertices (n) and edges (m) as input
int n, m;
n = sc.nextInt();
m = sc.nextInt();

// Initializing the visited list and other variables
int[] vis = new int[n + 1];
int ci, cb, cc;
ArrayList<Integer>[] g = new ArrayList[n + 1];

// Function to perform DFS traversal from a given vertex 'x'
boolean dfs(int x) {
    /*
    This function performs Depth First Search traversal from a given vertex 'x'.
    It returns True if all vertices in the connected component are of the same color,
    and False otherwise.
    */
    // Creating an empty stack and initializing a flag
    Queue<Integer> stk = new LinkedList<>();
    boolean flag = true;

    // Pushing the current vertex 'x' into the stack with color '1'
    stk.add(x);
    stk.add(1);

    // Traversing the graph until the stack is empty
    while (!stk.isEmpty()) {
        int u = stk.remove();
        int col = stk.remove();

        // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
        if (vis[u] != 0) {
            flag &= (vis[u] == col);
            continue;
        }

        // Mark the current vertex 'u' as visited with the current color 'col'
        vis[u] = col;

        // Recursively traverse all the adjacent vertices of 'u'
        for (int i : g[u]) {
            stk.add(i);
            stk.add(3 - col);
        }
    }

    // Return the flag indicating whether all vertices in the connected component have the same color or not
    return flag;
}

// Adding edges to the graph
for (int i = 0; i < m; i++) {
    int u, v;
    u = sc.nextInt();
    v = sc.nextInt();
    // Adding an edge between vertices 'u' and 'v' in both the adjacency lists
    g[u].add(v);
    g[v].add(u);
}

// Finding the number of isolated vertices and connected components
for (int i = 1; i <= n; i++) {
    // If the current vertex 'i' is not visited yet
    if (vis[i] == 0) {
        // If the current vertex 'i' has no edges, then it is an isolated vertex
        if (g[i].size() == 0) {
            ci++;
        }
        // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
        else {
            if (dfs(i)) {
                cb++;
            } else {
                cc++;
            }
        }
    }
}

// Calculating and printing the final answer
System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);

