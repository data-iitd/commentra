import java.util.*;

class Edge {
    long s, g, c; // Define the structure for edges
    Edge(long s, long g, long c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt;
    Edge[] e = new Edge[200010]; // Define the array of edges
    int[] id = new int[100010]; // Define the array of indices

    void readGraph() { // Define a function to read the graph
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // Read the number of vertices
        for (int i = 0; i < n - 1; i++) { // Read each edge and store it in the graph structure
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long c = scanner.nextLong();
            e[2 * i] = new Edge(x, y, c);
            e[2 * i + 1] = new Edge(y, x, c);
        }
        vcnt = (int) n; // Set the number of vertices
        ecnt = 2 * (int) n - 2; // Set the number of edges
        Arrays.sort(e, 0, ecnt, Comparator.comparingLong(edge -> edge.s)); // Sort the edges

        int p = 0;
        for (int i = 0; i < vcnt; i++) { // Populate the id array with the starting index of edges for each vertex
            while (p < ecnt && e[p].s < i) p++;
            id[i] = p;
        }
        id[vcnt] = ecnt; // Set the sentinel value for the id array
    }

    int[] tyokkeitemp; // Define a temporary array for DFS

    void tyokkeidfs(int s) { // Define a function to perform DFS and update distances
        for (int i = id[s]; i < id[s + 1]; i++) {
            if (tyokkeitemp[(int) e[i].g] == 0) {
                tyokkeitemp[(int) e[i].g] = tyokkeitemp[s] + (int) e[i].c;
                tyokkeidfs((int) e[i].g);
            }
        }
    }

    int tyokkei() { // Define a function to find the diameter of the tree
        tyokkeitemp = new int[vcnt + 10]; // Allocate memory for the temporary array
        tyokkeitemp[0] = 1; // Start DFS from the root
        tyokkeidfs(0); // Perform DFS
        int M = 0, Mi = 0; // Initialize variables to find the maximum distance
        for (int i = 0; i < vcnt; i++) { // Find the vertex with the maximum distance from the root
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        Arrays.fill(tyokkeitemp, 0); // Reset the temporary array
        tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
        tyokkeidfs(Mi); // Perform DFS
        for (int i = 0; i < vcnt; i++) M = Math.max(M, tyokkeitemp[i]); // Find the maximum distance in the second DFS
        return M - 1; // Return the diameter of the tree
    }
}

public class Main { // Define the main class
    public static void main(String[] args) { // Define the main function
        Graph g = new Graph(); // Create a new graph instance
        g.readGraph(); // Read the graph
        System.out.println(g.tyokkei()); // Print the diameter of the tree
    }
}

//<END-OF-CODE>
