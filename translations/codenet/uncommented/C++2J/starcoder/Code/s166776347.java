import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // IO
        // new FileReader("in.txt");
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        // new BufferedWriter("out.txt");
        PrintWriter w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        // 入力
        try {
            String[] line = r.readLine().split(" ");
            int N = Integer.parseInt(line[0]);
            int K = Integer.parseInt(line[1]);
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(r.readLine());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        // 解法
        int ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue;
                if (A[i] > A[j]) ans1++;
                ans1 %= mod;
            }
        }

        int[] count = new int[2005];
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++;
        }
        int ans2 = 0;
        int remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i];
            ans2 += count[i] * remain;
        }
        int ans = 0;
        int tmp = K * (K - 1);
        tmp /= 2;
        tmp %= mod;
        tmp *= ans2;
        tmp %= mod;
        ans += ans1 * K;
        ans %= mod;
        ans += tmp;
        ans %= mod;

        // 出力
        w.println(ans);
        w.close();
    }
}

