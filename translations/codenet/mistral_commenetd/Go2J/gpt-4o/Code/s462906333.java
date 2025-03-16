// Importing necessary packages
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Main class
public class Main {
    // Constants
    static final long INF = (long) 1e14;

    // Main method
    public static void main(String[] args) throws IOException {
        // Setting up buffered reader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        // Reading input
        int n = Integer.parseInt(tokenizer.nextToken());
        int x = Integer.parseInt(tokenizer.nextToken());

        // Initializing arrays
        int[] a = new int[n];
        int[] v = new int[n];

        // Reading array elements
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(tokenizer.nextToken());
            v[i] = a[i]; // Copying values to v
        }

        // Initializing answer variable
        long ans = INF;

        // Iterating through all possible subarrays
        for (int k = 0; k < n; k++) {
            // Initializing variable to store sum of subarray elements
            long kans = 0;

            // Iterating through all elements of the subarray
            for (int i = 0; i < n; i++) {
                // Checking if current index is out of bounds for subarray
                if (i - k < 0) {
                    // Updating current element in subarray with minimum of itself and corresponding element from the main array
                    v[i] = Math.min(v[i], a[n + i - k]);
                } else {
                    // Updating current element in subarray with minimum of itself and previous element in subarray
                    v[i] = Math.min(v[i], a[i - k]);
                }

                // Adding current element to the sum of subarray
                kans += v[i];
            }

            // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
            ans = Math.min(ans, kans + k * x);
        }

        // Printing the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
