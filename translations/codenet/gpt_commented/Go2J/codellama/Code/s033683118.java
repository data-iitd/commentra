
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize file pointers for input and output.
        BufferedReader fp = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wfp = new PrintWriter(System.out);
        int cnt = 0;

        // Check for environment variables to determine input and output files.
        if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
            fp = new BufferedReader(new InputStreamReader(System.in));
            cnt = 2; // Set the count for additional processing.
        }
        if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
            wfp = new PrintWriter(System.out);
        }

        // Create a scanner for reading input and a writer for output.
        Scanner scanner = new Scanner(fp);
        PrintWriter writer = new PrintWriter(wfp);

        // Solve the problem for the first time.
        solve(scanner, writer);

        // If cnt is greater than 0, solve the problem additional times.
        for (int i = 0; i < cnt; i++) {
            writer.println("-----------------------------------");
            solve(scanner, writer);
        }

        // Flush the writer to ensure all output is written.
        writer.flush();
    }

    // solve processes the input values and determines if the condition is met.
    // It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
    public static void solve(Scanner scanner, PrintWriter writer) {
        int k = scanner.nextInt(); // Read the first integer k.
        int x = scanner.nextInt(); // Read the second integer x.

        String ans = "No"; // Default answer is "No".
        if (k * 500 >= x) { // Check the condition.
            ans = "Yes"; // Update answer to "Yes" if condition is met.
        }
        writer.println(ans); // Output the result.
    }
}

