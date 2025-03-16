
import java.io.OutputStream; // Output stream to write output to the console
import java.io.IOException; // Exception for I/O errors
import java.io.InputStream; // Input stream to read input from the console
import java.io.PrintWriter; // Class for writing to the output stream
import java.io.UncheckedIOException; // Exception for unchecked I/O errors
import java.util.StringTokenizer; // Class for tokenizing strings
import java.io.IOException; // Exception for I/O errors
import java.io.BufferedReader; // Buffered reader for reading lines from the input stream
import java.io.InputStreamReader; // Input stream reader for reading text from the input stream

public class Main {
    // Main method that runs the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream from the console
        OutputStream outputStream = System.out; // Output stream to the console
        LightScanner in = new LightScanner(inputStream); // Initialize LightScanner for reading input
        PrintWriter out = new PrintWriter(outputStream); // Initialize PrintWriter for writing output

        int testNumber = 1; // Test case number
        BUnhappyHackingABCEdit solver = new BUnhappyHackingABCEdit(); // Initialize the solver

        solver.solve(testNumber, in, out); // Run the solver with the given input and output streams

        out.close(); // Close the PrintWriter to flush the output buffer
    }

    // Static class for reading input
    static class LightScanner {
        BufferedReader reader; // Buffered reader for reading lines from the input stream
        StringTokenizer tokenizer; // String tokenizer for tokenizing strings

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in)); // Initialize the reader
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) { // If there are no more tokens
                try { // Try to read a new line from the input stream
                    String line = reader.readLine();
                    if (line == null) { // If there is no more input
                        throw new UncheckedIOException(); // Throw an exception
                    }
                    tokenizer = new StringTokenizer(line); // Initialize the tokenizer with the new line
                } catch (IOException e) {
                    throw new UncheckedIOException(e); // Throw an unchecked I/O exception
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }
    }

    // Static class for solving the problem
    static class BUnhappyHackingABCEdit {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String s = in.string(); // Read the input string
            StringBuilder d = new StringBuilder(); // Initialize an empty StringBuilder for the output

            for (char c : s.toCharArray()) { // Iterate through each character in the input string
                switch (c) { // Switch statement to handle different characters
                    case '0':
                        d.append("0"); // Append "0" to the output StringBuilder
                        break;
                    case '1':
                        d.append("1"); // Append "1" to the output StringBuilder
                        break;
                    case 'B':
                        if (d.length() > 0) { // If there is a character in the output StringBuilder
                            d.setLength(d.length() - 1); // Remove the last character from the output StringBuilder
                            d.trimToSize(); // Trim the size of the output StringBuilder to the new length
                        }
                        break;
                }
            }

            out.println(d); // Print the output StringBuilder to the console
        }
    }
}

