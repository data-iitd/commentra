import java.util.Scanner;

public class Main {
    // Declare global arrays to store data and sequences
    static int[] data = new int[111111]; // Array to store the frequency of each number
    static int[] seq = new int[222222];  // Array to store sequences of consecutive numbers

    // Function to return the maximum of two integers
    static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k, t, i, p, ret = 0;

        // Loop to read input values and process them
        while (true) {
            // Read values of n and k
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (n == 0 && k == 0) break; // Break the loop if both n and k are zero

            // Initialize the data and seq arrays to zero
            java.util.Arrays.fill(data, 0);
            java.util.Arrays.fill(seq, 0);

            // Read k numbers and store their frequencies in data
            for (i = 0; i < k; i++) {
                t = scanner.nextInt();
                data[t]++;
            }

            // Construct the seq array based on the frequencies in data
            p = 0;
            for (i = 1; i <= n; i++) {
                if (data[i] > 0) {
                    seq[p]++;
                } else {
                    p += 2;
                }
            }
            p++;

            // Calculate the maximum value of ret based on the sequences in seq
            if (data[0] > 0) {
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                for (i = 0; i < p; i++) {
                    ret = max(ret, seq[i]);
                }
            }

            // Print the result
            System.out.println(ret);
        }
    }
}
