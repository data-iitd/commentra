import java.util.Scanner;

public class Main {
    static int[] data = new int[111111]; // Initialize an array 'data' of size 111111 for storing the frequency of each number.
    static int[] seq = new int[222222]; // Initialize an array 'seq' of size 222222 for storing the sequence numbers.

    public static int max(int a, int b) { // Declare a function 'max' that returns the maximum of two integers.
        if (a > b) { // If 'a' is greater than 'b', return 'a' as the maximum.
            return a;
        }
        return b; // Otherwise, return 'b' as the maximum.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k, t, i, p, ret = 0; // Declare variables 'n' and 'k' for the number of elements and the size of the sequence, 't' as a temporary variable, 'i' as a loop counter, 'p' as a pointer, and 'ret' as the result.

        while (true) { // Start an infinite loop.
            n = scanner.nextInt(); // Read the number of elements 'n' from the standard input.
            k = scanner.nextInt(); // Read the size of the sequence 'k' from the standard input.
            if (n == 0 && k == 0) break; // If both 'n' and 'k' are zero, break the loop.

            for (i = 0; i < 111111; i++) { // Loop through each number in the sequence.
                data[i] = 0; // Initialize all elements of the 'data' array to zero.
            }
            for (i = 0; i < 222222; i++) { // Loop through each number in the sequence.
                seq[i] = 0; // Initialize all elements of the 'seq' array to zero.
            }

            for (i = 0; i < k; i++) { // Loop through each number in the sequence.
                t = scanner.nextInt(); // Read a number 't' from the standard input.
                data[t]++; // Increment the frequency of the number 't' in the 'data' array.
            }

            p = 0; // Initialize a pointer 'p' to the first element of the 'seq' array.
            for (i = 1; i <= n; i++) { // Loop through each number from 1 to 'n'.
                if (data[i] > 0) { // If the frequency of the number 'i' is not zero, increment the corresponding element in the 'seq' array.
                    seq[p]++;
                } else { // If the frequency of the number 'i' is zero, move the pointer 'p' to the next even index.
                    p += 2;
                }
            }
            p++; // Increment the pointer 'p' to the next index.

            if (data[0] > 0) { // If the frequency of the number 0 is not zero, calculate the maximum sum of consecutive sequences in the 'seq' array.
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i] + seq[i + 2] + 1); // Calculate the sum of the current and next sequence and update the maximum sum if necessary.
                }
            } else { // If the frequency of the number 0 is zero, calculate the maximum sum of sequences in the 'seq' array.
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i]); // Calculate the sum of the current sequence and update the maximum sum if necessary.
                }
            }

            System.out.println(ret); // Print the maximum sum of sequences to the standard output.
        }

        scanner.close(); // Close the scanner to release resources.
    }
}
