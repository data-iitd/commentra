import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Vector;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        // Set up the standard input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        // Create an InputReader to read input from the standard input stream
        InputReader in = new InputReader(inputStream);
        // Create a PrintWriter to write output to the standard output stream
        PrintWriter out = new PrintWriter(outputStream);
        // Create an instance of TaskB and call its solve method
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        // Close the PrintWriter to flush the output and close the stream
        out.close();
    }

    // TaskB class contains the main logic of the program
    static class TaskB {
        // The solve method implements the main logic
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the input string
            String x = in.next();
            // Initialize a stack to keep track of characters
            Stack<Character> s = new Stack<>();
            // Initialize a counter to count balanced pairs
            int c = 0;
            // Iterate through each character in the input string
            for (int i = 0; i < x.length(); i++) {
                // Push the current character onto the stack
                s.push(x.charAt(i));
                // While the stack has more than one element, check for balanced pairs
                while (s.size() > 1) {
                    // Pop the top two elements from the stack
                    Character p = s.pop();
                    Character q = s.pop();
                    // Check if they form a balanced pair
                    if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                        // Increment the counter if a balanced pair is found
                        c++;
                        continue;
                    } else {
                        // If not a balanced pair, push the popped elements back onto the stack
                        s.push(q);
                        s.push(p);
                        break;
                    }
                }
            }
            // Output the result, which is twice the counter value
            out.println(c * 2);
        }
    }

    // Helper class to read input from the standard input stream
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        // Constructor to initialize the InputReader with the standard input stream
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        // Method to read the next token from the input stream
        public String next() {
            while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}
