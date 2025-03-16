
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // 頂点数
    private static int N;

    // 隣接リスト
    private static List<Integer>[] adjacents;

    // 頂点iの隣接リストの添字
    private static int[] indexForAdjacents;

    // 結果
    private static long[] res;

    // 動的計画法
    private static long[][] dp;

    // 単位元
    private static long identity;

    // 演算
    private static long operate(long x, long y) {
        return (x * y) % MOD;
    }

    // 頂点vの演算
    private static long operateNode(long v, int p) {
        return (v + 1) % MOD;
    }

    public static void main(String[] args) {
        // 頂点数と辺数
        N = readInt();
        int M = readInt();

        // グラフを作る
        adjacents = new ArrayList[N];
        indexForAdjacents = new int[N];
        for (int i = 0; i < N; i++) {
            adjacents[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int x = readInt() - 1;
            int y = readInt() - 1;
            adjacents[x].add(y);
            adjacents[y].add(x);
            indexForAdjacents[x] = adjacents[x].size() - 1;
            indexForAdjacents[y] = adjacents[y].size() - 1;
        }

        // 動的計画法の準備
        dp = new long[N][];
        res = new long[N];
        identity = 1;

        if (N > 1) {
            initialize();
        } else {
            res[0] = operateNode(identity, 0);
        }

        // 結果を出力
        for (int i = 0; i < N; i++) {
            System.out.println(res[i] - 1);
        }
    }

    // 動的計画法の初期化
    private static void initialize() {
        // 頂点の順序
        int[] order = new int[N];
        int[] parents = new int[N];

        // 頂点の順序を決める
        int index = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        parents[0] = -1;
        while (!stack.isEmpty()) {
            int node = stack.peek();
            stack.pop();
            order[index] = node;
            index++;
            for (int i = 0; i < adjacents[node].size(); i++) {
                int adjacent = adjacents[node].get(i);
                if (adjacent == parents[node]) {
                    continue;
                }
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }

        // 葉から根に向かって動的計画法を行う
        for (int i = order.length - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];

            long accum = identity;
            int parentIndex = -1;
            for (int j = 0; j < adjacents[node].size(); j++) {
                if (adjacents[node].get(j) == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = operate(accum, dp[node][j]);
            }
            dp[parent][indexForAdjacents[node][parentIndex]] = operateNode(accum, node);
        }

        // 根から葉に向かって動的計画法を行う
        for (int i = 0; i < order.length; i++) {
            int node = order[i];
            long accum = identity;
            long[] accumsFromTail = new long[adjacents[node].size()];
            accumsFromTail[accumsFromTail.length - 1] = identity;
            for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = operate(dp[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.length; j++) {
                dp[adjacents[node].get(j)][indexForAdjacents[node][j]] = operateNode(operate(accum, accumsFromTail[j]), node);
                accum = operate(accum, dp[node][j]);
            }
            res[node] = operateNode(accum, node);
        }
    }

    private static int readInt() {
        try {
            return Integer.parseInt(br.readLine());
        } catch (IOException e) {
            return -1;
        }
    }

    private static long readLong() {
        try {
            return Long.parseLong(br.readLine());
        } catch (IOException e) {
            return -1;
        }
    }

    private static String readLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
}

