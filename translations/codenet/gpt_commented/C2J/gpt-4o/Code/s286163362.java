import java.util.Scanner;

public class Main {
    // Global arrays to hold data and sequence counts
    static int[] data = new int[111112]; // Adjusted size for 0-based indexing
    static int[] seq = new int[222224];   // Adjusted size for 0-based indexing

    // Function to return the maximum of two integers
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables for input and results
        int n, k, t, ret;

        // Infinite loop to continuously read input until termination condition
        while (true) {
            // Read values for n and k
            n = scanner.nextInt();
            k = scanner.nextInt();

            // Break the loop if both n and k are zero
            if (n == 0 && k == 0) break;

            // Initialize data and seq arrays to zero
            for (int i = 0; i < data.length; i++) {
                data[i] = 0;
            }
            for (int i = 0; i < seq.length; i++) {
                seq[i] = 0;
            }

            // Read k integers and count their occurrences in the data array
            for (int i = 0; i < k; i++) {
                t = scanner.nextInt();
                data[t]++;
            }

            // Initialize pointer for the sequence array
            int p = 0;
            ret = 0;

            // Build the seq array based on the data array
            for (int i = 1; i <= n; i++) {
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
                for (int i = 0; i < p; i++) {
                    ret = max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                // If data[0] does not exist, consider sequences without gaps
                for (int i = 0; i < p; i++) {
                    ret = max(ret, seq[i]);
                }
            }

            // Print the maximum sequence length found
            System.out.println(ret);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
