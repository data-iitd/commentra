

import java.util.Scanner;

public class s236040683{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes (N) and the number of edges (M)
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize a 2D array of size N x N to represent the adjacency matrix
        int[][] graph = new int[N][N];

        // Read M pairs of edges and populate the adjacency matrix
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            graph[from][to] = 1;
            graph[to][from] = 1;
        }

        // Print the number of connected nodes for each node
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == 1) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}

