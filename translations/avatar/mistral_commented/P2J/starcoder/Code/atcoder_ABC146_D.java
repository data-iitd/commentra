#######
# Code
#######

// Import necessary libraries
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Function to perform Breadth First Search (BFS)
public static int bfs(int v, int N, Queue<Integer>[] G, int[] E) {
    // Initialize visited array and queue
    boolean[] visited = new boolean[N];
    Queue<Integer> queue = new LinkedList<>();

    // Initialize variables for coloring nodes
    int K = -1;
    int[] node2color = new int[N];

    // Add starting node to the queue and mark it as visited
    queue.add(v);
    visited[v] = true;

    // BFS algorithm
    while (!queue.isEmpty()) {
        // Dequeue the next node from the queue
        int q = queue.remove();

        // Initialize color for the current node
        int color = 0;

        // Traverse through all neighbors of the current node
        for (int nex : G[q]) {
            // Skip if the neighbor is already visited
            if (visited[nex]) {
                continue;
            }

            // Mark the neighbor as visited and assign it a color
            visited[nex] = true;
            color += 1;

            // If the color of the current node is same as its neighbor, assign a new color to the neighbor
            if (color == node2color[q]) {
                color += 1;
            }

            // Update node2color and E dictionary with the new color
            node2color[nex] = color;
            E[Math.min(q, nex) * N + Math.max(q, nex)] = color;

            // Add the neighbor to the queue
            queue.add(nex);
        }

        // Update the maximum color found so far
        K = Math.max(K, color);
    }

    // Return the maximum color
    return K;
}

// Main function to read input and call bfs function
public static void main(String[] args) {
    // Read number of nodes from the input
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    // Initialize graph as a list of queues and empty dictionary for edges
    Queue<Integer>[] G = new Queue[N];
    int[] E = new int[N * N];

    // Read edges from the input and add them to the graph
    for (int i = 0; i < N-1; i++) {
        int a = sc.nextInt() - 1;
        int b = sc.nextInt() - 1;
        G[a] = G[a] == null? new LinkedList<>() : G[a];
        G[b] = G[b] == null? new LinkedList<>() : G[b];
        G[a].add(b);
        G[b].add(a);
        E[a * N + b] = 0;
    }

    // Call bfs function and print the result
    int K = bfs(0, N, G, E);
    System.out.println(K);

    // Print colors of all edges
    for (int value : E) {
        System.out.println(value);
    }
}

// Call the main function
main(args);

