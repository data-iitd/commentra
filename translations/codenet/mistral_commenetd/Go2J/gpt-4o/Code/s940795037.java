// Importing necessary packages
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Creating a new scanner instance
        Scanner sc = new Scanner();

        // Reading the first integer from the standard input
        int n = sc.nextInt();
        // Initializing the answer variable
        double ans = 0.0;

        // Iterating through the given number of integers
        for (int i = 0; i < n; i++) {
            // Reading the next integer from the standard input
            double tmp = 1.0 / sc.nextInt();
            // Adding the reciprocal of the current integer to the answer
            ans += tmp;
        }

        // Printing the final answer
        System.out.printf("%f\n", 1.0 / ans);
    }

    // Scanner class definition
    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        // Constructor to initialize the BufferedReader
        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        // Method to read the next integer from the standard input
        public int nextInt() throws IOException {
            if (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return Integer.parseInt(st.nextToken());
        }
    }
}

// <END-OF-CODE>
