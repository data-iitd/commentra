import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a new scanner to read input
        Scanner sc = new Scanner();
        
        // Read three integers from input: H, W, and N
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();

        // Calculate the maximum of H and W
        int A = Math.max(H, W);

        // Calculate and print the number of full groups needed to accommodate N items
        System.out.println((N + A - 1) / A);
    }

    // Custom Scanner class to facilitate reading input
    static class Scanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        // Reads the next integer from the input
        public int nextInt() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return Integer.parseInt(tokenizer.nextToken());
        }

        // Reads the next line from the input
        public String nextLine() throws IOException {
            return reader.readLine();
        }
    }
}

// <END-OF-CODE>
