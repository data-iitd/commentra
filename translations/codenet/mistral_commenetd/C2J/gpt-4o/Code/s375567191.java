import java.util.Scanner;

public class DFS {
    static final int MAX = 101;
    static final int WHITE = 0;
    static final int BLACK = 2;
    static final int GRAY = 1;
    static int time, n;
    static int[][] g = new int[MAX][MAX]; // adjacency matrix
    static int[] d = new int[MAX]; // depth array
    static int[] f = new int[MAX]; // finish array
    static int[] color = new int[MAX]; // color array

    static void visit(int u) { // function to perform Depth First Search (DFS) from vertex 'u'
        color[u] = GRAY; // mark the current vertex as 'gray'
        d[u] = ++time; // assign depth value to the current vertex

        for (int i = 0; i < n; i++) { // iterate through all the adjacent vertices of 'u'
            if (g[u][i] == 0) // if there is no edge between 'u' and 'i'
                continue;
            if (color[i] == WHITE) // if 'i' is not yet visited
                visit(i); // recursively call DFS on 'i'
        }

        color[u] = BLACK; // mark the current vertex as 'black'
        f[u] = ++time; // assign finish value to the current vertex
    }

    static void dfs() { // function to perform DFS on the entire graph
        time = 0; // initialize time counter

        for (int i = 0; i < n; i++) // iterate through all the vertices in the graph
            if (color[i] == WHITE) // if 'i' is not yet visited
                visit(i); // recursively call DFS on 'i'

        for (int i = 0; i < n; i++) // print the depth, finish, and vertex number for each vertex
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
    }

    public static void main(String[] args) { // main function
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // read the number of vertices in the graph

        for (int i = 0; i < n; i++) { // iterate through each vertex in the graph
            int x = scanner.nextInt(); // read the current vertex
            int y = scanner.nextInt(); // read the number of edges for the current vertex

            for (int j = 0; j < y; j++) { // iterate through all the edges for the current vertex
                int z = scanner.nextInt(); // read the destination vertex for the current edge
                g[x - 1][z - 1] = 1; // mark that there is an edge between 'x' and 'z'
            }
        }

        dfs(); // call DFS function to perform DFS on the entire graph
        scanner.close();
    }
}
// <END-OF-CODE>
