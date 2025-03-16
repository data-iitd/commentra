
// Importing necessary packages
import java.util.Scanner;

// Constants and variables declaration
class Main {
    public static void main(String[] args) {
        // Setting up logging
        System.out.println("Starting program...");

        // Creating a new scanner object
        Scanner next = new Scanner(System.in);

        // Reading input
        int n = next.nextInt();
        int x = next.nextInt();

        // Initializing arrays
        int[] a = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = next.nextInt();
        }
        for (int i = 0; i < n; i++) {
            v[i] = a[i];
        }

        // Initializing answer variable
        int ans = Integer.MAX_VALUE;

        // Iterating through all possible subarrays
        for (int k = 0; k < n; k++) {
            // Initializing variable to store sum of subarray elements
            int kans = 0;

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

    // Helper functions
    public static int min(int... a) {
        int r = a[0];
        for (int i = 0; i < a.length; i++) {
            if (r > a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Function to check if a given number is inside a given range
    public static boolean in(int c, int a, int z) {
        return c >= a && c < z;
    }

    // Function to convert boolean value to integer
    public static int btoi(boolean b) {
        if (b) {
            return 1;
        }
        return 0;
    }

    // Function to convert integer value to boolean
    public static boolean itob(int a) {
        if (a == 0) {
            return false;
        }
        return true;
    }
}

