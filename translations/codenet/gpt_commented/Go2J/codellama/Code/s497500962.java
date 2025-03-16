
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the values for R, G, B, and N from standard input
        int R = nextInt(); // Number of red items
        int G = nextInt(); // Number of green items
        int B = nextInt(); // Number of blue items
        int N = nextInt(); // Total number of items to choose

        int ans = 0; // Variable to store the count of valid combinations

        // Iterate over possible counts of red items (x)
        for (int x = 0; x <= N; x++) {
            // Iterate over possible counts of green items (y)
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining items after choosing x red and y green
                int tmp = N - R*x - G*y;
                // Check if the remaining items can be fully represented by blue items
                if (tmp >= 0 && tmp%B == 0) {
                    ans++; // Increment the count of valid combinations
                }
            }
        }

        // Output the total count of valid combinations
        System.out.println(ans);
    }

    // Function to read the next integer from input
    public static int nextInt() {
        Scanner sc = new Scanner(System.in); // Initialize a scanner for reading input
        return sc.nextInt(); // Return the next integer
    }

    // Function to read the next float from input
    public static float nextFloat() {
        Scanner sc = new Scanner(System.in); // Initialize a scanner for reading input
        return sc.nextFloat(); // Return the next float
    }

    // Function to read the next string from input
    public static String nextString() {
        Scanner sc = new Scanner(System.in); // Initialize a scanner for reading input
        return sc.next(); // Return the next string
    }
}

