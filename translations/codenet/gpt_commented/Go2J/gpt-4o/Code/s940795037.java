import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Main class where the execution starts
public class Main {
    public static void main(String[] args) throws IOException {
        // Create a new scanner to read input
        Scanner sc = new Scanner();

        // Read the number of integers to process
        int n = sc.nextInt();
        double ans = 0.0;

        // Loop through each integer, calculate the reciprocal, and accumulate the sum
        for (int i = 0; i < n; i++) {
            double tmp = 1.0 / sc.nextInt();
            ans += tmp;
        }

        // Print the harmonic mean of the input integers
        System.out.printf("%f\n", 1.0 / ans);
    }
}

// Scanner class to handle input reading efficiently
class Scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    // Constructor to initialize the BufferedReader
    public Scanner() {
        reader = new BufferedReader(new InputStreamReader(System.in));
    }

    // Method to read the next integer from the input
    public int nextInt() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return Integer.parseInt(tokenizer.nextToken());
    }
}

// <END-OF-CODE>
