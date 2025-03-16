import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static int N, ss, ans, A, B, C;

    public static void main(String[] args) throws IOException {
        String[] X = br.readLine().split(" ");
        N = Integer.parseInt(X[0]);
        A = Integer.parseInt(X[1]);
        B = Integer.parseInt(X[2]);
        C = Integer.parseInt(X[3]);

        int[] arr = new int[N];
        int[] dp = new int[N];
        ans = 10000;
        ss = A + B + C;

        String[] Y = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(Y[i]);
        }

        dfs(dp, 0, arr);
        pw.println(ans);
        pw.flush();
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
        int cost = 0, AA = 0, BB = 0, CC = 0;
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

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int abs(int a) {
        return a < 0 ? a * -1 : a;
    }
}
