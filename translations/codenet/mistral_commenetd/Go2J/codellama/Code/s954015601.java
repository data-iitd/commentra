// 深さ優先探索
import java.util.Scanner;

public class Main {
    // Function to generate unique id based on two integers
    public static int genid(int a, int b) {
        if (b < a) {
            a = b;
            b = a;
        }
        // Multiply the larger number by 100000 and add the smaller number
        return a * 100000 + b;
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of edges in the graph
        int N = new Scanner(System.in).nextInt();

        // Initialize an adjacency list and a 2D array to store the edges between nodes
        int[][] ab = new int[N - 1][2];
        int[][] edges = new int[N][];
        for (int i = 0; i < N - 1; i++) {
            // Read two integers representing the nodes connected by an edge
            int a = new Scanner(System.in).nextInt() - 1;
            int b = new Scanner(System.in).nextInt() - 1;
            // Store the nodes and their indices in the ab array
            ab[i][0] = a;
            ab[i][1] = b;
            // Add the edge to the adjacency list
            edges[a] = new int[edges[a].length + 1];
            edges[a][edges[a].length - 1] = b;
            edges[b] = new int[edges[b].length + 1];
            edges[b][edges[b].length - 1] = a;
        }

        // Initialize a map to store the colors of each connected component
        int[] colors = new int[N];
        // Initialize a queue to perform DFS
        int[][] q = new int[N][3];
        // Add the first node to the queue with initial color and parent node set to -1
        q[0][0] = 0;
        q[0][1] = -1;
        q[0][2] = -1;
        for (int i = 0; i < N; i++) {
            // Dequeue the current node, its color, and its parent node
            int currentNode = q[i][0];
            int usedColor = q[i][1];
            int parentNode = q[i][2];
            // Set the color of the current node to the next available color
            int color = 1;
            for (int j = 0; j < edges[currentNode].length; j++) {
                if (edges[currentNode][j] == parentNode) {
                    continue;
                }
                // If the color of the current node is the same as the color of the child node, increment the color
                if (color == usedColor) {
                    color++;
                }
                // Assign the color to the child node and add it to the queue with the current node as its parent node
                colors[genid(currentNode, edges[currentNode][j])] = color;
                q[i + 1][0] = edges[currentNode][j];
                q[i + 1][1] = color;
                q[i + 1][2] = currentNode;
                // Increment the color for the next iteration
                color++;
            }
        }

        // Initialize a variable to store the maximum number of edges in a connected component
        int K = -1;
        // Iterate through all nodes in the graph and update the maximum number of edges if necessary
        for (int i = 0; i < N; i++) {
            int t = edges[i].length;
            if (t > K) {
                K = t;
            }
        }
        // Print the maximum number of edges in a connected component
        System.out.println(K);

        // Iterate through all edges in the graph and print their colors
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors[genid(ab[i][0], ab[i][1])]);
        }
    }
}

