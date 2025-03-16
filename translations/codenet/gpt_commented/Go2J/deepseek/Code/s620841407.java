import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static class FastScanner {
        private static BufferedReader br;
        private static StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            st = null;
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public long[] nextLongArray(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        public double[] nextDoubleArray(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }
    }

    static class ReRootingSolver {
        int nodeCount;
        List<List<Integer>> adjacents;
        List<List<Integer>> indexForAdjacents;
        int[] res;
        int[][] dp;
        int identity;
        java.util.function.BiFunction<Integer, Integer, Integer> operate;
        java.util.function.IntFunction<Integer> operateNode;

        public ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity, java.util.function.BiFunction<Integer, Integer, Integer> operate, java.util.function.IntFunction<Integer> operateNode) {
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
                indexForAdjacents.get(e.get(0)).add(adjacents.get(e.get(1)).size());
                indexForAdjacents.get(e.get(1)).add(adjacents.get(e.get(0)).size());
                adjacents.get(e.get(0)).add(e.get(1));
                adjacents.get(e.get(1)).add(e.get(0));
            }

            dp = new int[nodeCount][];
            for (int i = 0; i < nodeCount; i++) {
                dp[i] = new int[adjacents.get(i).size()];
            }
            res = new int[nodeCount];

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
                    dp[adjacents.get(node).get(j)][indexForAdjacents.get(node).get(j)] = operateNode.apply(operate.apply(accum, accumsFromTail[j]), node);
                    accum = operate.apply(accum, dp[node][j]);
                }
                res[node] = operateNode.apply(accum, node);
            }
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = fs.nextInt();
        int m = fs.nextInt();
        List<List<Integer>> edges = new ArrayList<>(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int x = fs.nextInt() - 1;
            int y = fs.nextInt() - 1;
            edges.add(Arrays.asList(x, y));
        }

        java.util.function.BiFunction<Integer, Integer, Integer> f = (x, y) -> x * y % m;
        java.util.function.IntFunction<Integer> g = v -> v + 1;

        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, f, g);
        for (int i = 0; i < n; i++) {
            out.println(solver.query(i) - 1);
        }

        out.close();
    }
}
