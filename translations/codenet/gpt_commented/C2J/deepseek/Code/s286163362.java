import java.util.Scanner;

public class Main {
    // Global arrays to hold data and sequence counts
    static int[] data = new int[111111];
    static int[] seq = new int[222222];

    // Function to return the maximum of two integers
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    public static void main(String[] args) {
        // Declare variables for input and results
        int n, k, t, i, p, ret = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously read input until termination condition
        while (true) {
            // Read values for n and k
            n = scanner.nextInt();
            k = scanner.nextInt();

            // Break the loop if both n and k are zero
            if (n == 0 && k == 0) break;

            // Initialize data and seq arrays to zero
            java.util.Arrays.fill(data, 0);
            java.util.Arrays.fill(seq, 0);

            // Read k integers and count their occurrences in the data array
            for (i = 0; i < k; i++) {
                t = scanner.nextInt();
                data[t]++;
            }

            // Initialize pointer for the sequence array
            p = 0;

            // Build the seq array based on the data array
            for (i = 1; i <= n; i++) {
                // If the current index has data, increment the sequence count
                if (data[i] > 0) {
                    seq[p]++;
                } else {
                    // If no data, move the pointer by 2
                    p += 2;
                }
            }
            // Increment pointer to account for the last sequence
            p++;

            // Calculate the maximum sequence length based on the presence of data[0]
            if (data[0] > 0) {
                // If data[0] exists, consider sequences with gaps
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                // If data[0] does not exist, consider sequences without gaps
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i]);
                }
            }

            // Print the maximum sequence length found
            System.out.println(ret);
        }

        scanner.close();
    }
}
