import java.util.*;

class Edge {
    long s, g, c; // An edge has source, destination, and cost.
    Edge(long s, long g, long c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt; // Number of vertices and edges in the graph.
    Edge[] e; // Array to store edges.
    int[] id; // Array to store the index of each vertex in the sorted edge list.

    Graph(int n) {
        this.vcnt = n;
        this.ecnt = 2 * n - 2;
        this.e = new Edge[ecnt + 10];
        this.id = new int[vcnt + 10];
    }
}

public class TreeDiameter {
    static Graph g;
    static int[] tyokkeitemp;

    // Comparison function for sorting edges based on their source vertex.
    static int esort(Edge p, Edge q) {
        if (p.s < q.s) return -1;
        if (p.s > q.s) return 1;
        if (p.g < q.g) return -1;
        return 1;
    }

    // Read the graph from the standard input.
    static void readGraph() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        g = new Graph((int) n);

        for (int i = 0; i < n - 1; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long c = scanner.nextLong();
            g.e[i] = new Edge(x, y, c);
            g.e[i + g.ecnt] = new Edge(y, x, c);
        }

        g.ecnt *= 2;
        Arrays.sort(g.e, 0, g.ecnt, (p, q) -> esort(p, q));

        int p = 0;
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.ecnt && g.e[p].s < i) p++;
            g.id[i] = p;
        }
        g.id[g.vcnt] = g.ecnt;
    }

    // Function to find the diameter of the tree using DFS algorithm.
    static void tyokkeidfs(long s) {
        for (int i = g.id[(int) s]; i < g.id[(int) s + 1]; i++) {
            if (tyokkeitemp[(int) g.e[i].g] == 0) {
                tyokkeitemp[(int) g.e[i].g] = tyokkeitemp[(int) s] + (int) g.e[i].c;
                tyokkeidfs(g.e[i].g);
            }
        }
    }

    static int tyokkei() {
        tyokkeitemp = new int[g.vcnt + 10];
        tyokkeitemp[0] = 1;
        tyokkeidfs(0);

        int M = 0, Mi = 0;
        for (int i = 0; i < g.vcnt; i++) {
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        return M - 1;
    }

    // Main function to read the graph and print the diameter.
    public static void main(String[] args) {
        readGraph();
        System.out.println(tyokkei());
    }
}

// <END-OF-CODE>
