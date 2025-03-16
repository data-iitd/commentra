import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    static final int M = 100;
    static final int whi = 0;
    static final int gra = 1;
    static final int bla = 2;

    static int n;
    static int[][] T = new int[M][M];
    static int[] color = new int[M];
    static int[] d = new int[M];
    static int[] Q = new int[M];
    static int head = 0, tail = 0;

    // Function to add an element to the queue
    static void enqueue(int x) {
        Q[tail] = x;
        tail = (tail + 1) % M;
    }

    // Function to remove an element from the queue
    static int dequeue() {
        int x = Q[head];
        head = (head + 1) % M;
        return x;
    }

    // Breadth First Search Algorithm
    static void bfs(int s) {
        int i, u, v;

        // Initialize all vertices with white color and infinite distance
        for (i = 0; i < n; i++) {
            color[i] = whi;
            d[i] = 1000000;
        }

        // Initialize source vertex with gray color and zero distance
        color[s] = gra;
        d[s] = 0;
        enqueue(s);

        // Traverse the queue until it is empty
        while (head != tail) {
            u = dequeue();
            for (v = 0; v < n; v++) {
                if (T[u][v] == 1 && color[v] == whi) {
                    color[v] = gra;
                    d[v] = d[u] + 1;
                    enqueue(v);
                }
            }
            color[u] = bla;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, j;
        int u, k, v;

        // Read the number of vertices
        n = scanner.nextInt();

        // Initialize the adjacency matrix with zeros
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                T[i][j] = 0;
            }
        }

        // Read the edges and add them to the adjacency matrix
        for (i = 0; i < n; i++) {
            u = scanner.nextInt() - 1;
            k = scanner.nextInt();
            for (j = 0; j < k; j++) {
                v = scanner.nextInt() - 1;
                T[u][v] = 1;
            }
        }

        // Perform BFS algorithm starting from the source vertex 0
        bfs(0);

        // Print the results
        for (i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1;
            System.out.println((i + 1) + " " + d[i]);
        }
    }
}
