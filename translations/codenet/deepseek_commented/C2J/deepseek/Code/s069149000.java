import java.util.*;

public class PrimMST {
    static final int INF = 100000;
    static final int MAX = 101;
    static final int NIL = -6;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;

    static int[][] G = new int[MAX][MAX]; // 2D array to represent the graph
    static int n; // Number of vertices in the graph

    // Prim's algorithm to find the Minimum Spanning Tree (MST)
    static void prim(){
        int[] d = new int[MAX]; // Array to store the minimum distance from the tree to each vertex
        int[] pi = new int[MAX]; // Array to store the parent of each vertex in the MST
        int[] color = new int[MAX]; // Array to keep track of the color of each vertex (WHITE, GRAY, BLACK)
        int min, u, v, sum = 0; // Variables to find the minimum distance vertex and to store the sum of MST weights

        // Initialize all distances to infinity, parents to NIL, and colors to WHITE
        for(int i = 0; i < n; i++){
            d[i] = INF;
            pi[i] = NIL;
            color[i] = WHITE;
        }

        // Distance of the first vertex is set to 0
        d[0] = 0;

        // Continue until all vertices are processed
        while(true){
            min = INF;
            u = NIL;
            // Find the vertex with the minimum distance that is not BLACK
            for(int i = 0; i < n; i++){
                if(color[i] != BLACK && d[i] < min){
                    min = d[i];
                    u = i;
                }
            }
            // If no such vertex is found, break the loop
            if(u == NIL){
                break;
            }
            // Mark the selected vertex as BLACK
            color[u] = BLACK;
            // Update the distances and parents of adjacent vertices
            for(v = 0; v < n; v++){
                if(color[v] != BLACK && G[u][v] != INF){
                    if(d[v] > G[u][v]){
                        d[v] = G[u][v];
                        pi[v] = u;
                        color[v] = GRAY;
                    }
                }
            }
        }
        // Calculate the sum of the weights of the edges in the MST
        for(int i = 0; i < n; i++){
            if(pi[i] != NIL) sum += G[i][pi[i]];
        }
        // Print the sum of the weights of the MST
        System.out.println(sum);
    }

    // Main function to read the graph and call Prim's algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of vertices

        // Read the adjacency matrix of the graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int e = scanner.nextInt();
                if(e == -1){
                    G[i][j] = INF; // If no edge, set weight to INF
                } else {
                    G[i][j] = e; // Otherwise, set the weight of the edge
                }
            }
        }

        prim(); // Call Prim's algorithm to find and print the sum of the MST
    }
}
