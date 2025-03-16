// 深さ優先探索
import java.util.Scanner;

public class Main {
    // genid generates a unique identifier for an edge between two nodes.
    public static int genid(int a, int b) {
        if (b < a) {
            a = b;
            b = a;
        }
        return a * 100000 + b;
    }

    public static void main(String[] args) {
        // Read the number of nodes from standard input.
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize a slice to store edges and an adjacency list for the graph.
        int[][] ab = new int[N - 1][2];
        int[][] edges = new int[N][];
        for (int i = 0; i < N - 1; i++) {
            // Read edge information and populate the adjacency list.
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            edges[a] = append(edges[a], b);
            edges[b] = append(edges[b], a);
        }

        // Initialize a map to store the color of each edge and a queue for DFS traversal.
        int[] colors = new int[N * (N - 1) / 2];
        int[][] q = new int[N][3];
        q[0][0] = 0;
        q[0][1] = -1;
        q[0][2] = -1;
        for (int i = 0; i < N; i++) {
            // Pop the last element from the queue for DFS traversal.
            int currentNode = q[i][0];
            int usedColor = q[i][1];
            int parentNode = q[i][2];
            int color = 1;
            for (int childNode : edges[currentNode]) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors[genid(currentNode, childNode)] = color;
                q[i][0] = childNode;
                q[i][1] = color;
                q[i][2] = currentNode;
                color++;
            }
        }

        // Determine the maximum degree of any node in the graph.
        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges[i].length;
            if (t > K) {
                K = t;
            }
        }
        System.out.println(K);

        // Output the colors of the edges.
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors[genid(ab[i][0], ab[i][1])]);
        }
    }

    // append appends an element to the end of a slice.
    public static int[] append(int[] slice, int element) {
        int[] result = new int[slice.length + 1];
        for (int i = 0; i < slice.length; i++) {
            result[i] = slice[i];
        }
        result[slice.length] = element;
        return result;
    }
}

