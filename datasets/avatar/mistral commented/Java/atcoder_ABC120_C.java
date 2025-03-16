
import java.io.OutputStream; // Output stream for writing output
import java.io.IOException; // For handling I/O exceptions
import java.io.InputStream; // Input stream for reading input
import java.util.Vector; // For creating dynamic arrays
import java.util.StringTokenizer; // For tokenizing strings
import java.io.IOException; // For handling I/O exceptions
import java.io.BufferedReader; // For reading lines from input
import java.io.InputStreamReader; // For reading input from the console
import java.util.Stack; // For implementing a stack data structure

public class Main {
    // Main method that starts the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream for reading input
        OutputStream outputStream = System.out; // Output stream for writing output
        InputReader in = new InputReader(inputStream); // Creating an InputReader object
        PrintWriter out = new PrintWriter(outputStream); // Creating a PrintWriter object
        TaskB solver = new TaskB(); // Creating a TaskB object
        solver.solve(1, in, out); // Calling the solve method of TaskB class
        out.close(); // Closing the PrintWriter object
    }

    // Static inner class for solving the problem
    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String x; // String to store the input string
            Stack<Character> s; // Stack to store characters
            int c; // Counter to store the number of pairs

            x = in.next(); // Reading the input string
            s = new Stack<>(); // Creating an empty stack
            c = 0; // Initializing the counter to zero

            // Iterating through each character in the input string
            for (int i = 0; i < x.length(); i++) {
                s.push(x.charAt(i)); // Pushing the character onto the stack

                // Popping two characters from the stack and checking for a pair
                while (s.size() > 1) {
                    Character p = s.pop(); // Popping the top character
                    Character q = s.pop(); // Popping the second top character

                    // If the popped characters form a pair, increment the counter and continue
                    if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                        c++;
                        continue;
                    }

                    // If the characters don't form a pair, push them back onto the stack and break
                    s.push(q);
                    s.push(p);
                    break;
                }
            }

            // Writing the output to the PrintWriter object
            out.println(c * 2);
        }
    }

    // Static inner class for reading input
    static class InputReader {
        BufferedReader reader; // Buffered reader for reading lines
        StringTokenizer tokenizer; // String tokenizer for tokenizing strings

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768); // Creating a BufferedReader object
            tokenizer = null; // Initializing the string tokenizer to null
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine(); // Reading a line from the input
                    tokenizer = new StringTokenizer(line); // Creating a new string tokenizer object
                } catch (IOException e) {
                    throw new RuntimeException(e); // Throwing an exception if an I/O error occurs
                }
            }
            return tokenizer.nextToken(); // Returning the next token
        }
    }
}

