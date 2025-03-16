// Importing necessary packages
import java.util.Scanner;

public class Main {
    // Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
    public static void reva(int[] b, int start, int end) {
        // Reverse the subarray using a simple method of swapping elements
        while (start < end) {
            int temp = b[start];
            b[start] = b[end];
            b[end] = temp;
            start++;
            end--;
        }
    }

    // Main function
    public static void main(String[] args) {
        // Initialize a scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array 'a'
        int n = sc.nextInt();
        // Allocate memory for the array 'a' of size 'n'
        int[] a = new int[n];

        // Read 'n' integers from the standard input and store them in the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Read the number of queries 'q'
        int q = sc.nextInt();

        // Process each query by reversing the subarray of 'a'
        for (int i = 0; i < q; i++) {
            // Read the starting and ending indices of the subarray to be reversed
            int b = sc.nextInt();
            int e = sc.nextInt();

            // Reverse the subarray 'a[b:e]'
            reva(a, b, e);
        }

        // Write the reversed array 'a' to the standard output
        for (int i = 0; i < n; i++) {
            // Print each element of the array 'a' to the standard output with a space in between (except for the first element)
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(a[i]);
        }
        System.out.println();

        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
