
import java.io.OutputStream; import java.io.IOException; import java.io.InputStream; import java.io.PrintWriter; import java.util.Scanner;
// Import necessary classes for input/output operations and utility classes.

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Get the input stream from the system.
        OutputStream outputStream = System.out; // Get the output stream from the system.
        Scanner in = new Scanner(inputStream); // Create a Scanner object to read input.
        PrintWriter out = new PrintWriter(outputStream); // Create a PrintWriter object to write output.
        BABC solver = new BABC(); // Create an instance of the BABC class.
        solver.solve(1, in, out); // Call the solve method of the BABC class.
        out.close(); // Close the PrintWriter to flush the output.
    }

    static class BABC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next().replaceAll("BC", "D");
            // Read the input string and replace all occurrences of "BC" with "D".
            long cnt = 0; // Initialize a counter to keep track of the result.
            long tmp = 0; // Temporary variable to count consecutive 'A's.
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'A') {
                    tmp++; // Increment tmp if the current character is 'A'.
                } else if (s.charAt(i) == 'D') {
                    cnt += tmp; // Add tmp to cnt if the current character is 'D'.
                } else {
                    tmp = 0; // Reset tmp if the current character is not 'A' or 'D'.
                }
            }
            out.println(cnt); // Print the final count.
        }
    }
}
// The BABC class contains the logic to solve the problem. The solve method implements the main logic.