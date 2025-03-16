import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        Set<Integer> aa = new HashSet<>();
        for (int i = 0; i < m; i++) {
            aa.add(Integer.parseInt(tokenizer.nextToken()));
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
        writer.write(dp[n] + "\n");
        writer.flush();
    }
}
