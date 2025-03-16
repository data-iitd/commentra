import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000 + 7;
    static int n, m;
    static List<List<Integer>> edges = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            edges.add(Arrays.asList(x, y));
        }

        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, (a, b) -> (int) ((1L * a * b) % m), v -> v + 1);
        for (int i = 0; i < n; i++) {
            System.out.println(solver.query(i) - 1);
        }
    }
}

class ReRootingSolver {
    int nodeCount;
    List<List<Integer>> adjacents;
    List<List<Integer>> indexForAdjacents;
    int[] res;
    int[][] dp;
    int identity;
    BiFunction<Integer, Integer, Integer> operate;
    BiFunction<Integer, Integer, Integer> operateNode;

    public ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity,
                           BiFunction<Integer, Integer, Integer> operate,
                           BiFunction<Integer, Integer, Integer> operateNode) {
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

        for (List<Integer> e : edges) {
            int u = e.get(0);
            int v = e.get(1);
            indexForAdjacents.get(u).add(adjacents.get(v).size());
            indexForAdjacents.get(v).add(adjacents.get(u).size());
            adjacents.get(u).add(v);
            adjacents.get(v).add(u);
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

/* <END-OF-CODE> */
