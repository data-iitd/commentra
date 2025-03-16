import java.util.*;

class Edge {
    int s, g, c; // start vertex, end vertex, and cost of the edge

    Edge(int s, int g, int c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt; // number of vertices and edges
    List<Edge> e = new ArrayList<>(); // list to hold edges
    int[] id; // array to hold index of edges for each vertex

    Graph(int vcnt) {
        this.vcnt = vcnt;
        this.id = new int[vcnt];
    }
}

public class Main {
    static Graph g;
    static int[] tyokkeitemp; // Temporary array to store distances during DFS

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        g = new Graph(n);

        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int c = scanner.nextInt();
            g.e.add(new Edge(x, y, c));
            g.e.add(new Edge(y, x, c));
        }
        g.ecnt = g.e.size();

        // Sort edges based on start and end vertices
        g.e.sort(Comparator.comparingInt(a -> a.s));

        int p = 0;
        // Create an index for edges for each vertex
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.ecnt && g.e.get(p).s < i) p++;
            g.id[i] = p;
        }
        g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex

        System.out.println(tyokkei()); // Calculate and print the diameter of the tree
    }

    // Recursive DFS function to explore the tree
    static void tyokkeidfs(int s) {
        for (int i = g.id[s]; i < g.id[s + 1]; i++) {
            // If the vertex has not been visited
            if (tyokkeitemp[g.e.get(i).g] == 0) {
                // Update the distance and continue DFS
                tyokkeitemp[g.e.get(i).g] = tyokkeitemp[s] + g.e.get(i).c;
                tyokkeidfs(g.e.get(i).g);
            }
        }
    }

    // Function to calculate the diameter of the tree
    static int tyokkei() {
        // Allocate memory for distance array
        tyokkeitemp = new int[g.vcnt + 10];
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[0] = 1; // Start DFS from vertex 0
        tyokkeidfs(0); // First DFS to find the farthest vertex

        int M = 0, Mi = 0; // Variables to track maximum distance and corresponding vertex
        for (int i = 0; i < g.vcnt; i++) {
            // Find the vertex with the maximum distance
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }

        // Reset distances for the second DFS
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
        tyokkeidfs(Mi); // Second DFS to find the diameter

        // Find the maximum distance from the second DFS
        for (int i = 0; i < g.vcnt; i++) M = Math.max(M, tyokkeitemp[i]);
        return M - 1; // Return the diameter (subtract 1 for edge count)
    }
}
