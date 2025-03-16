import java.util.Scanner;

public class Main {
    // Initialize a scanner to read input efficiently
    private static final Scanner sc = new Scanner(System.in);

    // Main function to execute the program
    public static void main(String[] args) {
        // Read two integers n and m from the input
        int n = readInt();
        int m = readInt();

        // Initialize an array to hold m integers
        int[] a = new int[m];
        int sum = 0;

        // Read m integers into the array a and calculate their sum
        for (int i = 0; i < m; i++) {
            a[i] = readInt();
            sum += a[i];
        }

        // Check if the sum of integers exceeds n
        if (sum > n) {
            // Print -1 if the sum exceeds n and exit
            System.out.println("-1");
            return;
        }

        // Print the difference between n and the sum if it's within bounds
        System.out.println(n - sum);
    }

    // Method to read a single integer from the standard input
    private static int readInt() {
        return sc.nextInt();
    }
}

// <END-OF-CODE>
