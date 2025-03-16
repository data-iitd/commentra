import java.io.*;
import java.util.*;

public class Main {
    // Constants for general purpose usage
    static final int MOD = 1000000000 + 7; // Modulus for calculations
    static final int INF_INT64 = Long.MAX_VALUE; // Maximum value for int64
    static final int NIL = -1; // Nil value indicator

    static int n, m; // n: number of nodes, m: modulus
    static List<List<Integer>> edges = new ArrayList<>(); // edges: adjacency list for the graph

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1; // Convert to zero-based index
            int y = Integer.parseInt(st.nextToken()) - 1;

            edges.add(Arrays.asList(x, y)); // Append edge to the list
        }

        // Define operations for the re-rooting solver
        BiFunction<Integer, Integer, Integer> f = (x, y) -> (int) ((1L * x * y) % m); // Multiplication operation
        Function<Integer, Integer> g = v -> v + 1; // Increment operation

        // Create a new re-rooting solver instance
        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, f, g);
        // Query results for each node and print them
        for (int i = 0; i < n; i++) {
            System.out.println(solver.query(i) - 1); // Output the result for each node
        }
    }

    // Type definition for generic operations
    static class ReRootingSolver {
        int nodeCount; // Number of nodes
        List<List<Integer>> adjacents; // Adjacency list
        List<List<Integer>> indexForAdjacents; // Index mapping for adjacency
        int[] res; // Result array
        int[][] dp; // Dynamic programming table

        int identity; // Identity element for operations
        BiFunction<Integer, Integer, Integer> operate; // Operation function
        Function<Integer, Integer> operateNode; // Node operation function

        // Constructor for ReRootingSolver
        public ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity,
                                BiFunction<Integer, Integer, Integer> operate,
                                Function<Integer, Integer> operateNode) {
            this.nodeCount = nodeCount;
            this.identity = identity;
            this.operate = operate;
            this.operateNode = operateNode;

            // Initialize adjacency lists
            adjacents = new ArrayList<>(nodeCount);
            indexForAdjacents = new ArrayList<>(nodeCount);
            for (int i = 0; i < nodeCount; i++) {
                adjacents.add(new ArrayList<>());
                indexForAdjacents.add(new ArrayList<>());
            }
            for (List<Integer> e : edges) {
                int u = e.get(0);
                int v = e.get(1);
                indexForAdjacents.get(u).add(adjacents.get(v).size());
                indexForAdjacents.get(v).add(adjacents.get(u).size());
                adjacents.get(u).add(v);
                adjacents.get(v).add(u);
            }

            // Initialize DP and result arrays
            dp = new int[nodeCount][];
            res = new int[nodeCount];
            for (int i = 0; i < nodeCount; i++) {
                dp[i] = new int[adjacents.get(i).size()]; // Allocate DP table
            }

            // Initialize the solver if there are more than one node
            if (nodeCount > 1) {
                initialize();
            } else {
                // Base case for a single node
                res[0] = operateNode.apply(identity);
            }
        }

        // Query function to get the result for a specific node
        public int query(int node) {
            return res[node]; // Return the result for the queried node
        }

        // Initialize the re-rooting solver
        private void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            // Depth-first search to establish parent-child relationships and order of nodes
            int index = 0;
            Stack<Integer> stack = new Stack<>();
            stack.push(0); // Start from the root node
            parents[0] = -1; // Root has no parent
            while (!stack.isEmpty()) {
                int node = stack.pop();
                order[index++] = node; // Record the order of nodes
                for (int i = 0; i < adjacents.get(node).size(); i++) {
                    int adjacent = adjacents.get(node).get(i);
                    if (adjacent == parents[node]) {
                        continue; // Skip the parent node
                    }
                    stack.push(adjacent); // Add child to the stack
                    parents[adjacent] = node; // Set parent
                }
            }

            // Process nodes from leaves to root
            for (int i = order.length - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                int accum = identity; // Initialize accumulator
                int parentIndex = -1;
                for (int j = 0; j < adjacents.get(node).size(); j++) {
                    if (adjacents.get(node).get(j) == parent) {
                        parentIndex = j; // Find index of parent
                        continue;
                    }
                    accum = operate.apply(accum, dp[node][j]); // Accumulate results from children
                }
                dp[parent][indexForAdjacents.get(node).get(parentIndex)] = operateNode.apply(accum, node); // Update DP for parent
            }

            // Process nodes from root to leaves
            for (int i = 0; i < order.length; i++) {
                int node = order[i];
                int accum = identity; // Initialize accumulator
                int[] accumsFromTail = new int[adjacents.get(node).size()];
                accumsFromTail[accumsFromTail.length - 1] = identity; // Initialize tail accumulator
                for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                    accumsFromTail[j - 1] = operate.apply(dp[node][j], accumsFromTail[j]); // Accumulate results from tail
                }
                for (int j = 0; j < accumsFromTail.length; j++) {
                    // Update DP for adjacent nodes
                    dp[adjacents.get(node).get(j)][indexForAdjacents.get(node).get(j)] = operateNode.apply(operate.apply(accum, accumsFromTail[j]), node);
                    accum = operate.apply(accum, dp[node][j]); // Update accumulator
                }
                res[node] = operateNode.apply(accum, node); // Store result for the node
            }
        }
    }
}
// <END-OF-CODE>
