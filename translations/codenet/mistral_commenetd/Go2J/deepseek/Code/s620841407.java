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
    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        in = new InputReader(inputStream);
        out = new PrintWriter(outputStream);

        int n = in.nextInt();
        int m = in.nextInt();
        List<List<Integer>> edges = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            edges.get(x).add(y);
            edges.get(y).add(x);
        }

        ReRootingSolver solver = new ReRootingSolver(n, edges, 1, (l, r) -> l * r % m, (v, p) -> v + 1);

        for (int i = 0; i < n; i++) {
            out.println(solver.query(i) - 1);
        }
        out.close();
    }

    static class ReRootingSolver {
        int nodeCount;
        List<List<Integer>> adjacents;
        List<List<Integer>> indexForAdjacents;
        List<Integer> res;
        List<List<Integer>> dp;
        int identity;
        java.util.function.BiFunction<Integer, Integer, Integer> operate;
        java.util.function.Function<Integer, Integer> operateNode;

        public ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity, java.util.function.BiFunction<Integer, Integer, Integer> operate, java.util.function.Function<Integer, Integer> operateNode) {
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
            for (int i = 0; i < edges.size(); i++) {
                for (int j = 0; j < edges.get(i).size(); j++) {
                    int adjacent = edges.get(i).get(j);
                    indexForAdjacents.get(i).add(adjacents.get(adjacent).size());
                    indexForAdjacents.get(adjacent).add(adjacents.get(i).size());
                    adjacents.get(i).add(adjacent);
                    adjacents.get(adjacent).add(i);
                }
            }

            dp = new ArrayList<>(nodeCount);
            res = new ArrayList<>(nodeCount);
            for (int i = 0; i < nodeCount; i++) {
                dp.add(new ArrayList<>());
                res.add(identity);
            }

            if (nodeCount > 1) {
                initialize();
            } else {
                res.set(0, operateNode.apply(identity, 0));
            }
        }

        public int query(int node) {
            return res.get(node);
        }

        public void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            int index = 0;
            int[] stack = new int[nodeCount];
            stack[0] = 0;
            parents[0] = -1;
            int stackIndex = 1;
            while (stackIndex > 0) {
                int node = stack[--stackIndex];
                order[index++] = node;
                for (int adjacent : adjacents.get(node)) {
                    if (adjacent == parents[node]) {
                        continue;
                    }
                    stack[stackIndex++] = adjacent;
                    parents[adjacent] = node;
                }
            }

            for (int i = nodeCount - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                int accum = identity;
                int parentIndex = -1;
                for (int j = 0; j < adjacents.get(node).size(); j++) {
                    if (adjacents.get(node).get(j) == parent) {
                        parentIndex = j;
                        continue;
                    }
                    accum = operate.apply(accum, dp.get(node).get(j));
                }
                dp.get(parent).set(indexForAdjacents.get(node).get(parentIndex), operateNode.apply(accum, node));
                accum = operate.apply(accum, dp.get(node).get(j));
                dp.get(node).set(j, accum);
            }

            for (int i = 0; i < nodeCount; i++) {
                int accum = identity;
                int[] accumsFromTail = new int[adjacents.get(i).size()];
                accumsFromTail[accumsFromTail.length - 1] = identity;
                for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                    accumsFromTail[j - 1] = operate.apply(dp.get(i).get(j), accumsFromTail[j]);
                }
                for (int j = 0; j < accumsFromTail.length; j++) {
                    dp.get(adjacents.get(i).get(j)).set(indexForAdjacents.get(i).get(j), operateNode.apply(operate.apply(accum, accumsFromTail[j]), i));
                    accum = operate.apply(accum, dp.get(i).get(j));
                }
                res.set(i, operateNode.apply(accum, i));
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

        public int[] nextIntArray(int s) {
            int[] in = new int[s];
            for (int i = 0; i < s; i++) {
                in[i] = nextInt();
            }
            return in;
        }

        public char[] nextCharArray(int s) {
            char[] in = new char[s];
            for (int i = 0; i < s; i++) {
                in[i] = next().charAt(0);
            }
            return in;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] nextLongArray(int s) {
            long[] in = new long[s];
            for (int i = 0; i < s; i++) {
                in[i] = nextLong();
            }
            return in;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public double[] nextDoubleArray(int s) {
            double[] in = new double[s];
            for (int i = 0; i < s; i++) {
                in[i] = nextDouble();
            }
            return in;
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
