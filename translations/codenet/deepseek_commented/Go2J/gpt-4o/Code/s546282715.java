import java.io.*;
import java.util.*;

public class Main {
    // Method to read the next word from the input
    private static String getNextWord(Scanner scanner) {
        return scanner.next();
    }

    // Method to read the next integer from the input
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextWord(scanner));
    }

    public static void main(String[] args) throws IOException {
        // Determine the input source based on command-line arguments
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }

        // Create a new scanner to read from the determined input source
        Scanner scanner = new Scanner(inputStream);

        // Read the number of elements (n) and the number of restricted positions (m)
        int n = getNextInt(scanner);
        int m = getNextInt(scanner);

        // Create a set to store the restricted positions
        Set<Integer> restrictedPositions = new HashSet<>();
        for (int i = 0; i < m; i++) {
            restrictedPositions.add(getNextInt(scanner));
        }

        // Initialize the dynamic programming array
        int[] dp = new int[n + 1];
        dp[0] = 1;

        // Fill the dynamic programming array based on restricted positions
        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (restrictedPositions.contains(i + ii)) {
                    continue;
                }
                dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007;
            }
        }

        // Print the result
        System.out.println(dp[n]);
    }
}
// <END-OF-CODE>
