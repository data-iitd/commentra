
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class s546282715{

    private static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        Map<Integer, Integer> map = new HashMap<>();
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < m; i++) {
            map.put(Integer.parseInt(tokenizer.nextToken()), 1);
        }
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 2 && i + j <= n; j++) {
                if (map.containsKey(i + j)) {
                    continue;
                }
                dp[i + j] += dp[i];
                dp[i + j] %= MOD;
            }
        }
        writer.println(dp[n]);
        writer.close();
    }
}

