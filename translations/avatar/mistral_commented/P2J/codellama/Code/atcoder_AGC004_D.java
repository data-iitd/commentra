// Set the recursion limit for the function call stack to 1 million
import java.lang.Runtime;
import java.lang.RuntimeException;

public class Main {
    public static void main(String[] args) {
        Runtime.getRuntime().runFinalizersOnExit(true);
        try {
            Runtime.getRuntime().removeShutdownHook(Thread.currentThread());
        } catch (IllegalStateException e) {
            throw new RuntimeException(e);
        }
        Runtime.getRuntime().halt(1);
    }
}

// Define the depth-first search function 'dfs'
public class Main {
    public static void dfs(int[][] links, int n, int k, int v, int p) {
        // Initialize variables for height from leaf node and cut count
        int height_from_leaf = 0;
        int cut_count = 0;

        // Iterate through neighbors of the current node 'v'
        for (int u : links[v]) {
            // Skip if the neighbor is not a valid node (0)
            if (u == 0) {
                continue;
            }

            // Recursively call the 'dfs' function for the neighbor 'u'
            int hgt = 0;
            int cut = 0;
            dfs(links, n, k, u, v);

            // Update the height from leaf and cut count
            height_from_leaf = Math.max(height_from_leaf, hgt);
            cut_count += cut;
        }

        // Update the height from leaf and cut count for the current node 'v'
        height_from_leaf += 1;

        // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
        // then this node is a cut vertex and we need to add 1 to the cut count
        if (p != 0 && height_from_leaf == k) {
            height_from_leaf = 0;
            cut_count += 1;
        }

        // Return the height from leaf and cut count for the current node 'v'
        return height_from_leaf;
    }
}

// Read input from standard input
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] links = new int[n][];
        for (int i = 0; i < n; i++) {
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
            }
            links[i] = a;
        }

        // Call the 'dfs' function with the initial parameters
        int ans = dfs(links, n, k, 0, 0);

        // If the first node is not a root node, add 1 to the answer
        if (links[0][0] != 1) {
            ans += 1;
        }

        // Print the final answer
        System.out.println(ans);
    }
}

// END-OF-CODE
