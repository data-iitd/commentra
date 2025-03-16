import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader;
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
        } else {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }
        
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(reader.readLine().trim());
        int[] mm = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];
        
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            mm[i] = Integer.parseInt(tokenizer.nextToken());
            mm[i + 1] = Integer.parseInt(tokenizer.nextToken());
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j - 1; k++) {
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        writer.write(dp[1][n] + "\n");
        writer.flush();
        writer.close();
        reader.close();
    }
}
