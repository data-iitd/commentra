// Import necessary packages
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Main class
public class Main {
    // BufferedReader for reading input
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    // Function to read the next integer from input
    private static int nextInt() throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        return Integer.parseInt(tokenizer.nextToken());
    }

    // Function to write output
    private static void out(int a) {
        System.out.println(a);
    }

    // Function to solve the problem
    private static void solve() throws IOException {
        // Read two integers N and K from input
        int N = nextInt();
        int K = nextInt(); // K is read but not used in the solution

        // Initialize an array A of size N
        int[] A = new int[N];

        // Read N integers from input and store them in the array A
        for (int i = 0; i < N; i++) {
            A[i] = nextInt();
        }

        // Initialize variables maxProfit, maxCnt, and maxA
        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];

        // Iterate through the array A from the last index to the first index
        for (int i = N - 2; i >= 0; i--) {
            // Calculate the profit of the current transaction
            int profit = Math.max(0, maxA - A[i]);

            // If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }

            // Update maxA with the maximum of the current element and maxA
            maxA = Math.max(maxA, A[i]);
        }

        // Write the output to the console
        out(maxCnt);
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Call the solve function to solve the problem
        solve();
    }
}

// <END-OF-CODE>
