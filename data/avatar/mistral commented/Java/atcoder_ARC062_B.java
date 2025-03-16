
import java.io.OutputStream; // Output stream to write output
import java.io.IOException; // For handling I/O errors
import java.io.InputStream; // Input stream to read input
import java.util.StringTokenizer; // For handling string tokens
import java.io.IOException; // For handling I/O errors
import java.io.BufferedReader; // For reading lines from input
import java.io.InputStreamReader; // For reading input from console

public class Main {
    // Main method to start the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream from console
        OutputStream outputStream = System.out; // Output stream to console
        InputReader in = new InputReader(inputStream); // Create InputReader object
        PrintWriter out = new PrintWriter(outputStream); // Create PrintWriter object
        TaskD solver = new TaskD(); // Create TaskD object
        solver.solve(1, in, out); // Solve the problem and print output
        out.close(); // Close the output stream
    }

    // Static inner class to solve the problem
    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String S; // String to store the input
            int score = 0; // Variable to store the score

            // Read the input string
            S = in.next();

            // Iterate through each character in the string
            for (int i = 0; i < S.length(); i++) {
                char my; // Character representing my move
                char his; // Character representing his move

                // Determine my move based on the index
                my = i % 2 == 0 ? 'g' : 'p';

                // Read his move from the input string
                his = S.charAt(i);

                // Update the score based on the moves
                if (my != his) {
                    score += my == 'p' ? 1 : -1;
                }
            }

            // Print the score
            out.println(score);
        }
    }

    // Static inner class to read input
    static class InputReader {
        BufferedReader reader; // Buffered reader to read input lines
        StringTokenizer tokenizer; // String tokenizer to parse input lines

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768); // Create BufferedReader object
            tokenizer = null; // Initialize tokenizer to null
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine(); // Read a line from input
                    tokenizer = new StringTokenizer(line); // Create a new tokenizer for the line
                } catch (IOException e) {
                    throw new RuntimeException(e); // Throw an exception if there's an error reading input
                }
            }
            return tokenizer.nextToken(); // Return the next token from the tokenizer
        }
    }
}

These comments should provide a good understanding of what each part of the code does. Let me know if you need any further clarification!