import java.io.*;
import java.util.*;

public class Main {
    // Constants used throughout the program
    private static final int MOD = 1000000000 + 7;
    private static final int ALPHABET_NUM = 26;
    private static final long INF_INT64 = Long.MAX_VALUE;
    private static final int INF_INT32 = Integer.MAX_VALUE;

    // Global variables
    private static int n, m;
    private static List<int[]> edges = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        // Read the number of nodes and edges
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // Construct the graph from the edges
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            edges.add(new int[]{x, y});
        }

        // Define the operations for the ReRootingSolver
        BiFunction<Integer, Integer, Integer> f = (x, y) -> (int) ((1L * x * y) % m);
        Function<Integer, Integer> g = v -> v + 1;

        // Initialize and use the ReRootingSolver to compute the results
        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, f, g);
        for (int i = 0; i < n; i++) {
            out.println(solver.query(i) - 1);
        }

        out.flush();
    }

    // ReRootingSolver class for solving the re-rooting problem
    static class ReRootingSolver {
        private int nodeCount;
        private List<List<Integer>> adjacents;
        private List<List<Integer>> indexForAdjacents;
        private int[] res;
        private int[][] dp;
        private int identity;
        private BiFunction<Integer, Integer, Integer> operate;
        private Function<Integer, Integer> operateNode;

        public ReRootingSolver(int nodeCount, List<int[]> edges, int identity,
                               BiFunction<Integer, Integer, Integer> operate,
                               Function<Integer, Integer> operateNode) {
            this.nodeCount = nodeCount;
            this.identity = identity;
            this.operate = operate;
            this.operateNode = operateNode;

            adjacents = new ArrayList<>(nodeCount);
            indexForAdjacents = new ArrayList<>(nodeCount);
            for (int i = 0; i < nodeCount; i++) {
                adjacents.add(new ArrayList<>());
                indexForAdjacents.add(new ArrayList<>());
            }

            for (int[] e : edges) {
                indexForAdjacents.get(e[0]).add(adjacents.get(e[1]).size());
                indexForAdjacents.get(e[1]).add(adjacents.get(e[0]).size());
                adjacents.get(e[0]).add(e[1]);
                adjacents.get(e[1]).add(e[0]);
            }

            dp = new int[nodeCount][];
            res = new int[nodeCount];
            for (int i = 0; i < nodeCount; i++) {
                dp[i] = new int[adjacents.get(i).size()];
            }

            if (nodeCount > 1) {
                initialize();
            } else {
                res[0] = operateNode.apply(identity, 0);
            }
        }

        public int query(int node) {
            return res[node];
        }

        private void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            // InitOrderedTree initializes the tree in a way that is useful for traversal
            int index = 0;
            Stack<Integer> stack = new Stack<>();
            stack.push(0);
            parents[0] = -1;
            while (!stack.isEmpty()) {
                int node = stack.pop();
                order[index++] = node;
                for (int adjacent : adjacents.get(node)) {
                    if (adjacent == parents[node]) continue;
                    stack.push(adjacent);
                    parents[adjacent] = node;
                }
            }

            // fromLeaf computes values starting from the leaves
            for (int i = order.length - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                int accum = identity;
                int parentIndex = -1;
                for (int j = 0; j < adjacents.get(node).size(); j++) {
                    if (adjacents.get(node).get(j) == parent) {
                        parentIndex = j;
                        continue;
                    }
                    accum = operate.apply(accum, dp[node][j]);
                }
                dp[parent][indexForAdjacents.get(node).get(parentIndex)] = operateNode.apply(accum, node);
            }

            // toLeaf computes values propagating from leaves to the root
            for (int i = 0; i < order.length; i++) {
                int node = order[i];
                int accum = identity;
                int[] accumsFromTail = new int[adjacents.get(node).size()];
                accumsFromTail[accumsFromTail.length - 1] = identity;
                for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                    accumsFromTail[j - 1] = operate.apply(dp[node][j], accumsFromTail[j]);
                }
                for (int j = 0; j < accumsFromTail.length; j++) {
                    dp[adjacents.get(node).get(j)][indexForAdjacents.get(node).get(j)] =
                            operateNode.apply(operate.apply(accum, accumsFromTail[j]), node);
                    accum = operate.apply(accum, dp[node][j]);
                }
                res[node] = operateNode.apply(accum, node);
            }
        }
    }
}
