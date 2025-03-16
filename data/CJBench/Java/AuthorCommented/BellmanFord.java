
import java.util.Scanner;


class BellmanFord /*
                   * Implementation of Bellman ford to detect negative cycles. Graph accepts
                   * inputs
                   * in form of edges which have start vertex, end vertex and weights. Vertices
                   * should be labelled with a
                   * number between 0 and total number of vertices-1,both inclusive
                   */
{

    int vertex;
    int edge;
    private Edge[] edges;
    private int index = 0;

    BellmanFord(int v, int e) {
        vertex = v;
        edge = e;
        edges = new Edge[e];
    }

    class Edge {
        int u;
        int v;
        int w;

        /**
         * @param u Source Vertex
         * @param v End vertex
         * @param c Weight
         */
        Edge(int a, int b, int c) {
            u = a;
            v = b;
            w = c;
        }
    }

    /**
     * @param x Source Vertex
     * @param y End vertex
     * @param z Weight
     */
    public void addEdge(int x, int y, int z) { // Adds unidirectional edge
        edges[index++] = new Edge(x, y, z);
    }

    public Edge[] getEdgeArray() {
        return edges;
    }

    /**
     * @param p[] Parent array which shows updates in edges
     * @param i   Current vertex under consideration
     */
    void printPath(int[] parent, int vertex) {
        if (parent[vertex] == -1) { // Found the path back to parent
            return;
        }
        printPath(parent, parent[vertex]);
        System.out.print(vertex + " ");
    }

    public void execute(int source) {
        int[] dist = new int[vertex];
        int[] parent = new int[vertex];

        for (int i = 0; i < vertex; i++) {
            dist[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }
        dist[source] = 0;

        for (int i = 0; i < vertex - 1; i++) {
            for (int j = 0; j < edge; j++) {
                Edge e = edges[j];
                if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                }
            }
        }

        for (int j = 0; j < edge; j++) {
            Edge e = edges[j];
            if (dist[e.u] != Integer.MAX_VALUE && dist[e.v] > dist[e.u] + e.w) {
                System.out.println("Negative cycle detected");
                return;
            }
        }

        System.out.println("Vertex distances from source:");
        for (int i = 0; i < vertex; i++) {
            System.out.println("Vertex: " + i + ", Distance: " + dist[i]);
        }

        System.out.println("Paths:");
        for (int i = 0; i < vertex; i++) {
            System.out.print("Path to " + i + ": " + source + " ");
            printPath(parent, i);
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();

        BellmanFord bf = new BellmanFord(v, e);

        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int ve = sc.nextInt();
            int w = sc.nextInt();
            bf.addEdge(u, ve, w);
        }

        int source = sc.nextInt();
        bf.execute(source);
    }
}
