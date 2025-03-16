import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    static int N, ss, ans, A, B, C;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }

        ans = Integer.MAX_VALUE;
        ss = A + B + C;
        dfs(new int[N], 0, arr);

        pw.println(ans);
        pw.close();
    }

    static void dfs(int[] dp, int times, int[] arr) {
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr));
            return;
        }

        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr);
        }
    }

    static int calc(int[] dp, int[] arr) {
        int cost = 0;
        int AA = 0, BB = 0, CC = 0;

        int[] memo = new int[4];
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                AA += arr[i];
            } else if (dp[i] == 2) {
                BB += arr[i];
            } else if (dp[i] == 3) {
                CC += arr[i];
            }
        }

        cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);

        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }

        return cost;
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int abs(int a) {
        return a < 0 ? -a : a;
    }
}
