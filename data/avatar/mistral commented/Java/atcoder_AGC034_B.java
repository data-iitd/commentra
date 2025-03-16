
import java.io.OutputStream; // Output stream for writing to the console
import java.io.IOException; // Exception for I/O operations
import java.io.InputStream; // Input stream for reading from the console
import java.util.Scanner; // Class for reading input from the console

public class Main {
    // Main method that starts the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream for reading from the console
        OutputStream outputStream = System.out; // Output stream for writing to the console
        Scanner in = new Scanner(inputStream); // Create a new scanner for reading input
        PrintWriter out = new PrintWriter(outputStream); // Create a new print writer for writing output

        BABC solver = new BABC(); // Create a new instance of the BABC class
        solver.solve(1, in, out); // Solve the problem and print the result

        out.close(); // Close the print writer to flush the output buffer
    }

    static class BABC {
        // Inner class for solving the problem

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // Method for solving the problem

            String s = in.next().replaceAll("BC", "D"); // Replace all occurrences of "BC" with "D" in the input string

            long cnt = 0; // Initialize counter for the number of "D"s
            long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

            for (int i = 0; i < s.length(); i++) {
                // Loop through each character in the string

                if (s.charAt(i) == 'A') {
                    // If the character is "A", increment the temporary counter
                    tmp++;
                } else if (s.charAt(i) == 'D') {
                    // If the character is "D", add the temporary counter to the total count
                    cnt += tmp;
                } else {
                    // If the character is neither "A" nor "D", reset the temporary counter
                    tmp = 0;
                }
            }

            // Print the result
            out.println(cnt);
        }
    }
}

These comments should provide a clear understanding of the logic behind each part of the code. Let me know if you need any further clarification or modification.