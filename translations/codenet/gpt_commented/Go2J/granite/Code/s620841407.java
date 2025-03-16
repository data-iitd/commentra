

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s620841407{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int[][] edges = new int[n - 1][2];
        for (int i = 0; i < n - 1; i++) {
            line = br.readLine().split(" ");
            edges[i][0] = Integer.parseInt(line[0]);
            edges[i][1] = Integer.parseInt(line[1]);
        }
        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, (l, r) -> (l + r) % m, (v, p) -> (v + 1) % m);
        for (int i = 0; i < n; i++) {
            System.out.println(solver.Query(i) - 1);
        }
    }
}

class ReRootingSolver {
    int nodeCount;
    int[][] adjacents;
    int[][] indexForAdjacents;
    int[] res;
    int[][] dp;
    int identity;
    BiFunction<Integer, Integer, Integer> operate;
    BiFunction<Integer, Integer, Integer> operateNode;

    public ReRootingSolver(int nodeCount, int[][] edges, int identity, BiFunction<Integer, Integer, Integer> operate, BiFunction<Integer, Integer, Integer> operateNode) {
        this.nodeCount = nodeCount;
        this.identity = identity;
        this.operate = operate;
        this.operateNode = operateNode;

        adjacents = new int[nodeCount][];
        indexForAdjacents = new int[nodeCount][];
        for (int i = 0; i < nodeCount; i++) {
            adjacents[i] = new int[0];
            indexForAdjacents[i] = new int[0];
        }

        for (int[] edge : edges) {
            int x = edge[0];
            int y = edge[1];
            adjacents[x] = Arrays.stream(adjacents[x]).boxed().toArray(Integer[]::new);
            adjacents[y] = Arrays.stream(adjacents[y]).boxed().toArray(Integer[]::new);
            indexForAdjacents[x] = Arrays.stream(indexForAdjacents[x]).boxed().toArray(Integer[]::new);
            indexForAdjacents[y] = Arrays.stream(indexForAdjacents[y]).boxed().toArray(Integer[]::new);
        }

        res = new int[nodeCount];
        dp = new int[nodeCount][];
        for (int i = 0; i < nodeCount; i++) {
            dp[i] = new int[adjacents[i].length];
        }
    }

    public void Initialize() {
        int[] parents = new int[nodeCount];
        int[] order = new int[nodeCount];
        int[] stack = new int[nodeCount];
        stack[0] = 0;
        stack = Arrays.stream(stack).boxed().toArray(Integer[]::new);
        parents[0] = -1;
        for (int i = 0; i < nodeCount; i++) {
            for (int j = 0; j < adjacents[i].length; j++) {
                int adjacent = adjacents[i][j];
                if (adjacent == parents[i]) {
                    continue; // Skip the parent node
                }
                stack[index] = i; // Record the order of nodes
                index++;
            }
            accum = identity; // Initialize accumulator
            int parentIndex = -1;
            for (int j = 0; j < adjacents[i].length; j++) {
                if (adjacents[i][j] == parent) {
                    continue; // Skip the parent node
                }
                accum = operate(accum, dp[i][j]); // Accumulate results from children
                parentIndex = -1;
                accumsFromTail := make([]int, len(accumsFromTail))
                accumsFromTail[len(accumsFromTail)-1] = identity; // Initialize tail accumulator
                for j := len(accumsFromTail) - 1; j--) {
                    accumsFromTail[j-1] = operate(s.DP[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[node][s.IndexForAdjacents[no