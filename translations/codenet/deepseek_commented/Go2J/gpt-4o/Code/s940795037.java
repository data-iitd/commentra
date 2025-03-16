import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(); // Initialize a new Scanner instance

        int n = sc.nextInt(); // Read an integer n from the standard input
        double ans = 0.0; // Initialize a variable ans to 0.0
        for (int i = 0; i < n; i++) { // Enter a loop that runs n times
            double tmp = 1.0 / sc.nextInt(); // Read an integer, convert it to a double, and divide 1 by this value
            ans += tmp; // Add this result to ans
        }
        System.out.printf("%f\n", 1.0 / ans); // Calculate the reciprocal of ans and print it
    }
}

class Scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Scanner() {
        reader = new BufferedReader(new InputStreamReader(System.in)); // Create a new buffered reader
        tokenizer = null; // Initialize tokenizer
    }

    public String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = reader.readLine(); // Read the next line from the input
            tokenizer = new StringTokenizer(line); // Tokenize the line
        }
        return tokenizer.nextToken(); // Return the next token
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next()); // Read the next integer from the input
    }
}
