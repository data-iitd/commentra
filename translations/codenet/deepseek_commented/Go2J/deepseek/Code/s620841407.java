import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.math.BigInteger;

public class Main {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    static int n, m;
    static List<List<Integer>> edges = new ArrayList<>();

    static int readInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    static int[] readIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = readInt();
        }
        return arr;
    }

    static double readDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }

    static double[] readDoubleArray(int n) throws IOException {
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = readDouble();
        }
        return arr;
    }

    static String readString() throws IOException {
        in.nextToken();
        return in.sval;
    }

    static void init() {
        // bufio.ScanWords <---> bufio.ScanLines
        // ReadString = newReadString(os.Stdin, bufio.ScanWords);
        // stdout = bufio.NewWriter(os.Stdout);
    }

    public static void main(String[] args) throws IOException {
        n = readInt();
        m = readInt();

        for (int i = 0; i < n - 1; i++) {
            int x = readInt() - 1;
            int y = readInt() - 1;
            edges.add(List.of(x, y));
        }

        // Define the operations for the ReRootingSolver
        java.util.function.BiFunction<Integer, Integer, Integer> f = (x, y) -> (x * y) % m;
        java.util.function.IntFunction<Integer> g = v -> v + 1;

        // Initialize and use the ReRootingSolver to compute the results
        ReRootingSolver s = new ReRootingSolver(n, edges, 1, f, g);
        for (int i = 0; i < n; i++) {
            out.println(s.query(i) - 1);
        }
        out.flush();
    }

    static class ReRootingSolver {
        int nodeCount;
        List<List<Integer>> adjacents;
        List<List<Integer>> indexForAdjacents;
        List<Integer> res;
        List<List<Integer>> dp;
        int identity;
        java.util.function.BiFunction<Integer, Integer, Integer> operate;
        java.util.function.IntFunction<Integer> operateNode;

        ReRootingSolver(int nodeCount, List<List<Integer>> edges, int identity, java.util.function.BiFunction<Integer, Integer, Integer> operate, java.util.function.IntFunction<Integer> operateNode) {
            this.nodeCount = nodeCount;
            this.identity = identity;
            this.operate = operate;
            this.operateNode = operateNode;

            adjacents = new ArrayList<>(nodeCount);
            for (int i = 0; i < nodeCount; i++) {
                adjacents.add(new ArrayList<>());
            }
            indexForAdjacents = new ArrayList<>(nodeCount);
            for (int i = 0; i < nodeCount; i++) {
                indexForAdjacents.add(new ArrayList<>());
            }
            for (List<Integer> e : edges) {
                int x = e.get(0);
                int y = e.get(1);
                indexForAdjacents.get(x).add(adjacents.get(y).size());
                indexForAdjacents.get(y).add(adjacents.get(x).size());
                adjacents.get(x).add(y);
                adjacents.get(y).add(x);
            }

            dp = new ArrayList<>(adjacents.size());
            for (int i = 0; i < adjacents.size(); i++) {
                dp.add(new ArrayList<>(Collections.nCopies(adjacents.get(i).size(), identity)));
            }
            res = new ArrayList<>(Collections.nCopies(nodeCount, identity));

            if (nodeCount > 1) {
                initialize();
            } else {
                res.set(0, operateNode.apply(identity));
            }
        }

        void initialize() {
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
                    accum = operate.apply(accum, dp.get(node).get(j));
                }
                dp.get(parent).set(indexForAdjacents.get(node).get(parentIndex), operateNode.apply(accum, node));
            }

            for (int i = 0; i < order.length; i++) {
                int node = order[i];
                int accum = identity;
                List<Integer> accumsFromTail = new ArrayList<>(Collections.nCopies(adjacents.get(node).size(), identity));
                for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                    accumsFromTail.set(j - 1, operate.apply(dp.get(node).get(j), accumsFromTail.get(j)));
                }
                for (int j = 0; j < accumsFromTail.size(); j++) {
                    dp.get(adjacents.get(node).get(j)).set(indexForAdjacents.get(node).get(j), operateNode.apply(operate.apply(accum, accumsFromTail.get(j)), node));
                    accum = operate.apply(accum, dp.get(node).get(j));
                }
                res.set(node, operateNode.apply(accum, node));
            }
        }

        int query(int node) {
            return res.get(node);
        }
    }
}
