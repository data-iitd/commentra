
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // 頂点数
    private static int N;
    // 辺の数
    private static int M;
    // 隣接リスト
    private static List<Integer>[] adjacents;
    // 隣接リストのインデックス
    private static int[][] indexForAdjacents;
    // 結果
    private static long[] res;
    // 累積和
    private static long[][] dp;

    // 結果を返す
    public static long query(int node) {
        return res[node];
    }

    // 初期化
    public static void initialize() {
        // 頂点数
        N = adjacents.length;
        // 辺の数
        M = 0;
        for (int i = 0; i < N; i++) {
            M += adjacents[i].size();
        }

        // 累積和
        dp = new long[N][M];
        // 結果
        res = new long[N];

        // 頂点数が1の場合
        if (N == 1) {
            res[0] = 1;
            return;
        }

        // 頂点の順序
        int[] order = new int[N];
        // 親の頂点
        int[] parents = new int[N];

        // 根を探す
        int index = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        parents[0] = -1;
        while (!stack.isEmpty()) {
            int node = stack.pop();
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

        // 葉から根に向かって
        for (int i = order.length - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];

            long accum = 1;
            int parentIndex = -1;
            for (int j = 0; j < adjacents[node].size(); j++) {
                if (adjacents[node].get(j) == parent) {
                    parentIndex = j;
                    continue;
                }
                accum *= dp[node][j];
            }
            dp[parent][indexForAdjacents[node][parentIndex]] = accum * node;
            accum *= dp[node][j];
            dp[node][j] = accum;
        }

        // 根から葉に向かって
        for (int i = 0; i < order.length; i++) {
            int node = order[i];
            long accum = 1;
            long[] accumsFromTail = new long[adjacents[node].size()];
            accumsFromTail[accumsFromTail.length - 1] = 1;
            for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = accumsFromTail[j] * dp[node][j];
            }
            for (int j = 0; j < accumsFromTail.length; j++) {
                dp[adjacents[node].get(j)][indexForAdjacents[node][j]] = accumsFromTail[j] * node;
                accum *= dp[node][j];
            }
            res[node] = accum * node;
        }
    }

    public static void main(String[] args) {
        // 頂点数と辺の数
        N = readInt();
        M = readInt();
        // 隣接リスト
        adjacents = new ArrayList[N];
        // 隣接リストのインデックス
        indexForAdjacents = new int[N][M];
        for (int i = 0; i < N; i++) {
            adjacents[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            int x = readInt() - 1;
            int y = readInt() - 1;
            adjacents[x].add(y);
            adjacents[y].add(x);
            indexForAdjacents[x][adjacents[x].size() - 1] = adjacents[y].size() - 1;
            indexForAdjacents[y][adjacents[y].size() - 1] = adjacents[x].size() - 1;
        }

        // 初期化
        initialize();

        // クエリ
        for (int i = 0; i < N; i++) {
            System.out.println(res[i]);
        }
    }

    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer tokenizer = new StringTokenizer("");

    private static String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(next());
    }

    private static long nextLong() {
        return Long.parseLong(next());
    }

    private static double nextDouble() {
        return Double.parseDouble(next());
    }

    private static char nextChar() {
        return next().charAt(0);
    }

    private static String nextLine() throws IOException {
        return reader.readLine().trim();
    }
}

