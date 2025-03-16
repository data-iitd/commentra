import java.util.Scanner;

public class Main {
    static int[] data = new int[111112]; // Initialize an array 'data' of size 111112 for storing the frequency of each number.
    static int[] seq = new int[222222]; // Initialize an array 'seq' of size 222222 for storing the sequence numbers.

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k, t, p, ret;

        while (true) { // Start an infinite loop.
            n = scanner.nextInt(); // Read the number of elements 'n'.
            k = scanner.nextInt(); // Read the size of the sequence 'k'.
            if (n == 0 && k == 0) break; // If both 'n' and 'k' are zero, break the loop.

            // Initialize all elements of the 'data' and 'seq' arrays to zero.
            for (int i = 0; i < data.length; i++) {
                data[i] = 0;
            }
            for (int i = 0; i < seq.length; i++) {
                seq[i] = 0;
            }

            for (int i = 0; i < k; i++) { // Loop through each number in the sequence.
                t = scanner.nextInt(); // Read a number 't' from the standard input.
                data[t]++; // Increment the frequency of the number 't' in the 'data' array.
            }

            p = 0; // Initialize a pointer 'p' to the first element of the 'seq' array.
            for (int i = 1; i <= n; i++) { // Loop through each number from 1 to 'n'.
                if (data[i] > 0) { // If the frequency of the number 'i' is not zero.
                    seq[p]++; // Increment the corresponding element in the 'seq' array.
                } else { // If the frequency of the number 'i' is zero.
                    p += 2; // Move the pointer 'p' to the next even index.
                }
            }
            p++; // Increment the pointer 'p' to the next index.
            ret = 0; // Initialize 'ret' to zero.

            if (data[0] > 0) { // If the frequency of the number 0 is not zero.
                for (int i = 0; i < p; i++) {
                    ret = max(ret, seq[i] + seq[i + 2] + 1); // Calculate the sum of the current and next sequence.
                }
            } else { // If the frequency of the number 0 is zero.
                for (int i = 0; i < p; i++) {
                    ret = max(ret, seq[i]); // Calculate the sum of the current sequence.
                }
            }

            System.out.println(ret); // Print the maximum sum of sequences to the standard output.
        }

        scanner.close(); // Close the scanner.
    }

    // The 'max' function to return the maximum of two integers.
    static int max(int a, int b) {
        return (a > b) ? a : b; // Return the maximum of 'a' and 'b'.
    }
}
// <END-OF-CODE>
