
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s482866535{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");

        int n = Integer.parseInt(br.readLine());
        int[] mm = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            mm[i] = Integer.parseInt(st.nextToken());
            mm[i + 1] = Integer.parseInt(st.nextToken());
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

        pw.println(dp[1][n]);
        pw.close();
    }
}

