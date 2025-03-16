import java.io.*;
import java.util.*;

public class Main {
    private static final int MOD = 1000000007;

    private static String getNextWord(Scanner scanner) {
        return scanner.next();
    }

    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextWord(scanner));
    }

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }

        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        int n = getNextInt(scanner);
        int m = getNextInt(scanner);
        Set<Integer> aa = new HashSet<>();
        for (int i = 0; i < m; i++) {
            aa.add(getNextInt(scanner));
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (aa.contains(i + ii)) {
                    continue;
                }
                dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
            }
        }
        writer.println(dp[n]);

        writer.flush();
        writer.close();
        scanner.close();
    }
}
// <END-OF-CODE>
