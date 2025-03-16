
import java.util.ArrayList;
import java.util.Scanner;

public final class LCA {
    private LCA() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of vertices
        int v = scanner.nextInt();

        // Adjacency list to represent the tree
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        // Input edges
        for (int i = 0; i < v - 1; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            adj.get(from).add(to);
            adj.get(to).add(from);
        }

        // Array to store parent and depth of each vertex
        int[] parent = new int[v];
        int[] depth = new int[v];

        // Perform DFS to calculate parent and depth
        dfs(adj, 0, -1, parent, depth);

        // Input the two vertices whose LCA is to be calculated
        int v1 = scanner.nextInt();
        int v2 = scanner.nextInt();

        // Output the LCA
        System.out.println(getLCA(v1, v2, depth, parent));

        scanner.close();
    }

    /**
     * Depth first search to calculate parent and depth of every vertex
     *
     * @param adj The adjacency list representation of the tree
     * @param s The source vertex
     * @param p Parent of source
     * @param parent An array to store parents of all vertices
     * @param depth An array to store depth of all vertices
     */
    private static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int p, int[] parent, int[] depth) {
        for (int adjacent : adj.get(s)) {
            if (adjacent != p) {
                parent[adjacent] = s;
                depth[adjacent] = 1 + depth[s];
                dfs(adj, adjacent, s, parent, depth);
            }
        }
    }

    /**
     * Method to calculate Lowest Common Ancestor
     *
     * @param v1 The first vertex
     * @param v2 The second vertex
     * @param depth An array with depths of all vertices
     * @param parent An array with parents of all vertices
     * @return Returns a vertex that is LCA of v1 and v2
     */
    private static int getLCA(int v1, int v2, int[] depth, int[] parent) {
        if (depth[v1] < depth[v2]) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        while (depth[v1] != depth[v2]) {
            v1 = parent[v1];
        }
        if (v1 == v2) {
            return v1;
        }
        while (v1 != v2) {
            v1 = parent[v1];
            v2 = parent[v2];
        }
        return v1;
    }
}
