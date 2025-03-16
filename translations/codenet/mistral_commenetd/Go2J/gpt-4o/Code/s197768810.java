import java.util.Scanner;

public class Main {
    // Initialize a new scanner for reading input from stdin
    private static final Scanner sc = new Scanner(System.in);

    // Function to read an integer from standard input
    private static int readInt() {
        // Read an integer from standard input
        return sc.nextInt();
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of elements n and the number of queries m from standard input
        int n = readInt();
        int m = readInt();
        // Allocate an array a of size m
        int[] a = new int[m];
        // Initialize a variable sum to keep track of the sum of elements in the array
        int sum = 0;
        // Process each query
        for (int i = 0; i < m; i++) {
            // Read an integer from standard input and add it to the array a
            a[i] = readInt();
            // Add the current element to the sum
            sum += a[i];
            // Check if the sum is greater than the size of the array
            if (sum > n) {
                // If so, print -1 and exit the program
                System.out.println("-1");
                return;
            }
        }
        // Print the result, which is the difference between the size of the array and the sum of its elements
        System.out.println(n - sum);
    }
}

// <END-OF-CODE>
