import java.util.*;

public class Main {
    static int INF = Integer.MAX_VALUE;
    static int mod = 1000000007;
    static List<List<Integer>> g;
    static Integer[] ta_dist, ao_dist;

    // Function to read an integer from input
    static int inp(Scanner scanner) {
        return scanner.nextInt();
    }

    // Function to read a list of integers from input
    static List<Integer> inpl(Scanner scanner) {
        List<Integer> list = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    // Depth First Search from a given node
    static void dfs(int node, Integer[] dist) {
        for (int v : g.get(node)) {
            if (dist[v] != null) continue;
            dist[v] = dist[node] + 1;
            dfs(v, dist);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of nodes, starting and ending nodes
        int n = inp(scanner);
        int ta = inp(scanner) - 1;
        int ao = inp(scanner) - 1;

        // Initialize the adjacency list
        g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        // Read edges and add them to the graph
        for (int i = 0; i < n - 1; i++) {
            int a = inp(scanner) - 1;
            int b = inp(scanner) - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Initialize distance arrays for both nodes
        ta_dist = new Integer[n];
        ao_dist = new Integer[n];

        // Initialize distances for starting and ending nodes
        ta_dist[ta] = 0;
        ao_dist[ao] = 0;

        // Perform Depth First Search from starting and ending nodes
        dfs(ao, ao_dist);
        dfs(ta, ta_dist);

        // Calculate the answer
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] == null || ao_dist[i] == null || ta_dist[i] > ao_dist[i]) continue;
            res = Math.max(res, ao_dist[i]);
        }

        // Print the answer
        System.out.println(res - 1);
    }
}
// <END-OF-CODE>
