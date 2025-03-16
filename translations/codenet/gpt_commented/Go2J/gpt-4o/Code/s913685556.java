import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a new scanner to read input
        Scanner sc = new Scanner();
        // Read two integers from input
        int A = sc.nextInt();
        int B = sc.nextInt();

        // Calculate the maximum of A+B, A-B, and A*B
        int mx = max(A + B, A - B);
        mx = max(mx, A * B);
        // Print the maximum value
        System.out.println(mx);
    }

    // Function to return the maximum of two integers
    private static int max(int a, int b) {
        return a < b ? b : a;
    }

    // Scanner class to handle input reading
    static class Scanner {
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

        // Method to read the next line from the input
        public String nextLine() throws IOException {
            return reader.readLine();
        }
    }
}
// <END-OF-CODE>
