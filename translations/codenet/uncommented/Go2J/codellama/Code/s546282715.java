
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        Set<Integer> aa = new HashSet<>();
        for (int i = 0; i < m; i++) {
            aa.add(Integer.parseInt(br.readLine()));
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (aa.contains(i + ii)) {
                    continue;
                }
                dp[i + ii] += dp[i];
                dp[i + ii] %= 1000000007;
            }
        }
        pw.println(dp[n]);

        pw.flush();
    }
}

