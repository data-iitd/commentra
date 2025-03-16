// Import necessary libraries
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

// Take input number of vertices N and number of edges M
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int M = sc.nextInt();

// Initialize empty sets for each vertex representing its adjacent vertices
ArrayList<Integer>[] edges = new ArrayList[N];
for (int i = 0; i < N; i++) {
    edges[i] = new ArrayList<>();
}

// Initialize degree array to keep track of number of edges for each vertex
int[] degs = new int[N];

// Initialize parity array to keep track of parity of each vertex
int[] parity = new int[N];

// Initialize flag array to keep track of visited vertices
boolean[] flag = new boolean[N];

// Read edges from input and add them to their respective sets and update their degrees
for (int i = 0; i < M; i++) {
    int a = sc.nextInt();
    int b = sc.nextInt();
    // Add edge between vertices a and b in both their sets
    edges[a-1].add(b-1);
    edges[b-1].add(a-1);
    // Update degrees of both vertices
    degs[a-1]++;
    degs[b-1]++;
}

// Check if number of edges is even, if not print -1 and exit
if (M % 2 != 0) {
    System.out.println(-1);
    return;
}

// Initialize empty list Q to store vertices based on their degrees
ArrayList<Integer> Q = new ArrayList<>();

// Iterate through all vertices and add them to Q based on their degrees
for (int i = 0; i < N; i++) {
    Q.add(i);
}

// Sort Q based on degree of vertices
Collections.sort(Q, new Comparator<Integer>() {
    @Override
    public int compare(Integer a, Integer b) {
        return degs[a] - degs[b];
    }
});

// Iterate through Q until it is empty
while (Q.size() > 0) {
    // Get vertex with minimum degree from Q
    int u = Q.get(0);
    Q.remove(0);
    // Skip if vertex is already visited
    if (flag[u]) {
        continue;
    }
    // Mark vertex as visited
    flag[u] = true;
    // Iterate through all adjacent vertices and print their edges and update their parity
    for (int i = 0; i < edges[u].size(); i++) {
        // Skip if vertex is already visited
        if (flag[edges[u].get(i)]) {
            continue;
        }
        // Print edge and update parity of both vertices
        if (parity[u] != 0 && i == 0) {
            System.out.println(u+1 + " " + edges[u].get(i)+1);
            parity[u] = 1 - parity[u];
        } else {
            System.out.println(edges[u].get(i)+1 + " " + u+1);
            parity[edges[u].get(i)] = 1 - parity[edges[u].get(i)];
        }
        // Decrease degree of adjacent vertex and add it to Q
        degs[edges[u].get(i)]--;
        Q.add(edges[u].get(i));
    }
}

// End of code
