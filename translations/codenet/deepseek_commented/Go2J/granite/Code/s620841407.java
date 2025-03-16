
import java.io.*;
import java.util.*;

public class s620841407{
    public static void main(String[] args) throws Exception {
        // Read the number of nodes and edges
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);

        // Construct the graph from the edges
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            inputs = br.readLine().split(" ");
            int x = Integer.parseInt(inputs[0]) - 1;
            int y = Integer.parseInt(inputs[1]) - 1;
            edges.get(x).add(y);
            edges.get(y).add(x);
        }

        // Define the operations for the ReRootingSolver
        Function<Integer, Integer> f = (x, y) -> (x * y) % m;
        Function<Integer, Integer> g = (v, p) -> v + 1;

        // Initialize and use the ReRootingSolver to compute the results
        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, f, g);
        for (int i = 0; i < n; i++) {
            System.out.println(solver.query(i) - 1);
        }

        // Flush the output buffer
        System.out.flush();
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

    public ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity, BiFunction<Integer, Integer, Integer> operate, BiFunction<Integer, Integer, Integer> operateNode) {
        this.nodeCount = nodeCount;
        this.identity = identity;
        this.operate = operate;
        this.operateNode = operateNode;

        adjacents = new ArrayList<>();
        indexForAdjacents = new ArrayList<>();
        for (int i = 0; i < nodeCount; i++) {
            adjacents.add(new ArrayList<>());
            indexForAdjacents.add(new ArrayList<>());
        }

        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < edges.get(i).size(); j++) {
                int adjacent = edges.get(i).get(j);
                adjacents.get(i).add(adjacent);
                adjacents.get(adjacent).add(i);
                indexForAdjacents.get(i).add(adjacents.get(adjacent).indexOf(i));
                indexForAdjacents.get(adjacent).add(adjacents.get(i).indexOf(adjacent));
            }
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

    public void initialize() {
        int[] parents = new int[nodeCount];
        int[] order = new int[nodeCount];

        // InitOrderedTree initializes the tree in a way that is useful for traversal
        int index = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);
        parents[0] = -1;
        while (!stack.isEmpty()) {
            int node = stack.pop();
            order[index] = node;
            index++;
            for (int i = 0; i < adjacents.get(node).size(); i++) {
                int adjacent = adjacents.get(node).get(i);
                if (adjacent == parents[node]) {
                    continue;
                }
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
                dp[adjacents.get(node).get(j)][indexForAdjacents.get(node).get(j)] = operateNode.apply(operate.apply(accum, accumsFromTail[j]), node);
                accum = operate.apply(accum, dp[node][j]);
            }
            res[node] = operateNode.apply(accum, node);
        }
    }
}