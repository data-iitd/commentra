import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        int n, m;
        List<Integer>[] edges;

        void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            edges = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                edges[x].add(y);
                edges[y].add(x);
            }

            ReRootingSolver solver = new ReRootingSolver(n, edges, 1, (l, r) -> l * r % m, (v, p) -> v + 1);
            for (int i = 0; i < n; i++) {
                out.println(solver.query(i) - 1);
            }
        }
    }

    static class ReRootingSolver {
        int nodeCount;
        List<Integer>[] adjacents;
        List<Integer>[] indexForAdjacents;
        int[] res;
        int[][] dp;
        int identity;
        java.util.function.BiFunction<Integer, Integer, Integer> operate;
        java.util.function.Function<Integer, Integer> operateNode;

        ReRootingSolver(int nodeCount, List<Integer>[] edges, int identity, java.util.function.BiFunction<Integer, Integer, Integer> operate, java.util.function.Function<Integer, Integer> operateNode) {
            this.nodeCount = nodeCount;
            this.identity = identity;
            this.operate = operate;
            this.operateNode = operateNode;

            adjacents = new ArrayList[nodeCount];
            indexForAdjacents = new ArrayList[nodeCount];
            for (int i = 0; i < nodeCount; i++) {
                adjacents[i] = new ArrayList<>();
                indexForAdjacents[i] = new ArrayList<>();
            }
            for (List<Integer> edge : edges) {
                int x = edge.get(0);
                int y = edge.get(1);
                indexForAdjacents[x].add(adjacents[y].size());
                indexForAdjacents[y].add(adjacents[x].size());
                adjacents[x].add(y);
                adjacents[y].add(x);
            }

            dp = new int[nodeCount][];
            for (int i = 0; i < nodeCount; i++) {
                dp[i] = new int[adjacents[i].size()];
            }
            res = new int[nodeCount];

            if (nodeCount > 1) {
                initialize();
            } else {
                res[0] = operateNode.apply(identity, 0);
            }
        }

        int query(int node) {
            return res[node];
        }

        void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            int index = 0;
            int[] stack = new int[nodeCount];
            stack[0] = 0;
            parents[0] = -1;
            while (index < nodeCount) {
                int node = stack[index];
                order[index++] = node;
                for (int adjacent : adjacents[node]) {
                    if (adjacent == parents[node]) {
                        continue;
                    }
                    stack[index] = adjacent;
                    parents[adjacent] = node;
                }
            }

            for (int i = nodeCount - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                int accum = identity;
                int parentIndex = -1;
                for (int j = 0; j < adjacents[node].size(); j++) {
                    if (adjacents[node].get(j) == parent) {
                        parentIndex = j;
                        continue;
                    }
                    accum = operate.apply(accum, dp[node].get(j));
                }
                dp[parent][indexForAdjacents[node].get(parentIndex)] = operateNode.apply(accum, node);
            }

            for (int i = 0; i < nodeCount; i++) {
                int accum = identity;
                int[] accumsFromTail = new int[adjacents[i].size()];
                accumsFromTail[accumsFromTail.length - 1] = identity;
                for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                    accumsFromTail[j - 1] = operate.apply(dp[i].get(j), accumsFromTail[j]);
                }
                for (int j = 0; j < accumsFromTail.length; j++) {
                    dp[adjacents[i].get(j)][indexForAdjacents[i].get(j)] = operateNode.apply(operate.apply(accum, accumsFromTail[j]), i);
                    accum = operate.apply(accum, dp[i].get(j));
                }
                res[i] = operateNode.apply(accum, i);
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }
    }
}
