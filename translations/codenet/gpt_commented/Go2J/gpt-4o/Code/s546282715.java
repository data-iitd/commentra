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
        // Set the input source to standard input; if a file is provided as an argument, open that file.
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }

        // Create a new scanner to read from the input source
        Scanner scanner = new Scanner(inputStream);

        // Read the first two integers, n and m, from the input.
        int n = getNextInt(scanner);
        int m = getNextInt(scanner);

        // Initialize a set to store the positions that are blocked (not allowed).
        Set<Integer> blockedPositions = new HashSet<>();
        for (int i = 0; i < m; i++) {
            // Read each blocked position and mark it in the set.
            blockedPositions.add(getNextInt(scanner));
        }

        // Create a dynamic programming array to store the number of ways to reach each position.
        int[] dp = new int[n + 1];
        dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

        // Iterate through each position from 0 to n.
        for (int i = 0; i < n; i++) {
            // Check the next two positions (i+1 and i+2) to see if they can be reached.
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (blockedPositions.contains(i + ii)) {
                    continue; // If blocked, skip to the next iteration.
                }
                // Update the number of ways to reach position i+ii based on the current position i.
                dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007; // Ensure the result stays within the modulo limit.
            }
        }

        // Output the total number of ways to reach position n.
        System.out.println(dp[n]);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
