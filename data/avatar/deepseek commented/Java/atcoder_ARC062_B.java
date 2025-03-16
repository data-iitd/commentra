import java.io.OutputStream; // Importing the OutputStream class for output operations
import java.io.IOException; // Importing IOException for exception handling
import java.io.InputStream; // Importing InputStream class for input operations
import java.io.PrintWriter; // Importing PrintWriter for efficient output
import java.util.StringTokenizer; // Importing StringTokenizer for tokenizing input strings
import java.io.IOException; // Importing IOException again for consistency
import java.io.BufferedReader; // Importing BufferedReader for efficient input reading
import java.io.InputStreamReader; // Importing InputStreamReader for reading input streams
import java.io.InputStream; // Importing InputStream again for consistency

// The Main class is defined to run the program
public class Main {
    // The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Get the input stream from the system
        OutputStream outputStream = System.out; // Get the output stream from the system
        InputReader in = new InputReader(inputStream); // Create an InputReader instance to read input
        PrintWriter out = new PrintWriter(outputStream); // Create a PrintWriter instance to write output
        TaskD solver = new TaskD(); // Create an instance of TaskD
        solver.solve(1, in, out); // Call the solve method of TaskD
        out.close(); // Close the output stream
    }

    // The TaskD class contains the solve method which calculates a score based on the input string
    static class TaskD {
        // The solve method takes a test number, an InputReader instance, and a PrintWriter instance
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String S = in.next(); // Read the next string from the input
            int score = 0; // Initialize the score to 0
            // Iterate through each character in the string S
            for (int i = 0; i < S.length(); i++) {
                char my = i % 2 == 0 ? 'g' : 'p'; // Determine the expected character based on the index
                char his = S.charAt(i); // Get the character at the current index in S
                // Compare the expected character with the actual character and update the score
                if (my != his) {
                    score += my == 'p' ? 1 : -1; // Update the score based on the expected character
                }
            }
            out.println(score); // Print the final score
        }
    }

    // The InputReader class is used to read input efficiently
    static class InputReader {
        public BufferedReader reader; // BufferedReader for reading input
        public StringTokenizer tokenizer; // StringTokenizer for tokenizing input strings

        // Constructor for InputReader
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768); // Create a BufferedReader with a buffer size of 32768
            tokenizer = null; // Initialize the tokenizer as null
        }

        // Method to read the next token from the input stream
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { // Check if there are more tokens
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); // Read the next line and tokenize it
                } catch (IOException e) {
                    throw new RuntimeException(e); // Throw a RuntimeException if an IOException occurs
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }
    }
}
