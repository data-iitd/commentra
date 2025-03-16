
/*
URL:
https://atcoder.jp/contests/dp/tasks/dp_v
*/

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadruneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

public class s620841407{
    final static long MOD = 1000000000L + 7;
    // final static long MOD = 998244353L;
    final static int ALPHABET_NUM = 26;
    final static long INF_LONG = Long.MAX_VALUE / 2;
    final static int INF_INT = Integer.MAX_VALUE / 2;
    final static int NIL = -1;

    // for dijkstra, prim, and so on
    final static int WHITE = 0;
    final static int GRAY  = 1;
    final static int BLACK = 2;

    /********** Preprocessing **********/

    public static void main(String[] args) throws Exception {
        // Read input: number of nodes and edges
        int n = ReadInt();
        int m = ReadInt();
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int x = ReadInt() - 1;
            int y = ReadInt() - 1;
            edges.get(x).add(y);
            edges.get(y).add(x);
        }

        // Initialize the disjoint set data structure
        Function<Long, Long> f = (x, y) -> (x * y) % m;
        Function<Long, Long> g = (v, p) -> (v + 1) % m;
        Solver solver = new Solver(n, edges, 1, f, g);

        // Query the product of subtrees for all nodes and print the result
        for (int i = 0; i < n; i++) {
            System.out.println(solver.query(i));
        }
    }

    /********** Solver **********/

    static class Solver {
        int nodeCount;
        List<List<Integer>> adjacents;
        List<List<Integer>> indexForAdjacents;
        long[] res;
        long[][] dp;
        long identity;
        BiFunction<Long, Long, Long> operate;
        BiFunction<Long, Integer, Long> operateNode;

        Solver(int nodeCount, List<List<Integer>> edges, long identity, BiFunction<Long, Long, Long> operate, BiFunction<Long, Integer, Long> operateNode) {
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
                    indexForAdjacents.get(i).add(adjacents.get(adjacent).size());
                    indexForAdjacents.get(adjacent).add(adjacents.get(i).size());
                    adjacents.get(i).add(adjacent);
                    adjacents.get(adjacent).add(i);
                }
            }

            dp = new long[adjacents.size()][adjacents.get(0).size()];
            res = new long[adjacents.size()];

            if (nodeCount > 1) {
                initialize();
            } else {
                res[0] = operateNode.apply(identity, 0);
            }
        }

        long query(int node) {
            return res[node];
        }

        void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            // InitOrderedTree
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

            // fromLeaf
            for (int i = order.length - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                long accum = identity;
                int parentIndex = -1;
                for (int j = 0; j < adjacents.get(node).size(); j++) {
                    if (adjacents.get(node).get(j) == parent) {
                        parentIndex = j;
                        continue;
                    }
                    accum = operate.apply(accum, dp[node][j]);
                }
                dp[parent][indexForAdjacents.get(node).get(parentIndex)] = operateNode.apply(accum, node);
                accum = operate.apply(accum, dp[node][j]);
                dp[node][j] = accum;
            }

            // toLeaf
            for (int i = 0; i < order.length; i++) {
                int node = order[i];
                long accum = identity;
                long[] accumsFromTail = new long[adjacents.get(node).size()];
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

    /********** I/O usage **********/

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st = null;

    // Read a single string token
    static String ReadString() throws Exception {
        while (st == null ||!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    // Read an array of string tokens
    static String[] ReadStringArray() throws Exception {
        return br.readLine().split(" ");
    }

    // Read a single int token
    static int ReadInt() throws Exception {
        return Integer.parseInt(ReadString());
    }

    // Read an array of int tokens
    static int[] ReadIntArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        int[] A = new int[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Integer.parseInt(tokens[i]);
        return A;
    }

    // Read a single long token
    static long ReadLong() throws Exception {
        return Long.parseLong(ReadString());
    }

    // Read an array of long tokens
    static long[] ReadLongArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        long[] A = new long[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Long.parseLong(tokens[i]);
        return A;
    }

    // Read a single double token
    static double ReadDouble() throws Exception {
        return Double.parseDouble(ReadString());
    }

    // Read an array of double tokens
    static double[] ReadDoubleArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        double[] A = new double[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Double.parseDouble(tokens[i]);
        return A;
    }

    // Read a single char token
    static char ReadChar() throws Exception {
        return ReadString().charAt(0);
    }

    // Read an array of char tokens
    static char[] ReadCharArray() throws Exception {
        return ReadString().toCharArray();
    }

    // Read a single float token
    static float ReadFloat() throws Exception {
        return Float.parseFloat(ReadString());
    }

    // Read an array of float tokens
    static float[] ReadFloatArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        float[] A = new float[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Float.parseFloat(tokens[i]);
        return A;
    }

    // Read a single short token
    static short ReadShort() throws Exception {
        return Short.parseShort(ReadString());
    }

    // Read an array of short tokens
    static short[] ReadShortArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        short[] A = new short[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Short.parseShort(tokens[i]);
        return A;
    }

    // Read a single byte token
    static byte ReadByte() throws Exception {
        return Byte.parseByte(ReadString());
    }

    // Read an array of byte tokens
    static byte[] ReadByteArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        byte[] A = new byte[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Byte.parseByte(tokens[i]);
        return A;
    }

    // Read a single boolean token
    static boolean ReadBoolean() throws Exception {
        return Boolean.parseBoolean(ReadString());
    }

    // Read an array of boolean tokens
    static boolean[] ReadBooleanArray() throws Exception {
        String[] tokens = br.readLine().split(" ");
        boolean[] A = new boolean[tokens.length];
        for (int i = 0; i < A.length; i++)
            A[i] = Boolean.parseBoolean(tokens[i]);
        return A;
    }

    // Read an array of int tokens
    static int[] R