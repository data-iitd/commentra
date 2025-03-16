import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the upper limit of the range

        // Initialize a 2D array to count occurrences of digit pairs
        long[][] cnt = new long[10][10];
        for (int i = 0; i < 100; i++) {
            cnt[i % 10][i / 10] = 0; // Set all counts to zero
        }

        // Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            int b = i % 10; // Get the last digit of the number
            int a = i; // Store the original number
            while (a >= 10) { // Extract the first digit
                a /= 10; // Divide by 10 until we get the first digit
            }
            cnt[a][b]++; // Increment the count for the pair (first digit, last digit)
        }

        long ans = 0; // Initialize the answer variable to accumulate results

        // Calculate the total number of valid pairs by multiplying counts
        for (int i = 1; i <= 9; i++) { // Iterate over possible first digits
            for (int j = 1; j <= 9; j++) { // Iterate over possible last digits
                // Uncomment the following line for debugging to see counts
                // System.out.println(i + " " + j + " " + cnt[i][j] + " " + cnt[j][i]);
                ans += cnt[i][j] * cnt[j][i]; // Add the product of counts for pairs (i, j) and (j, i)
            }
        }

        System.out.println(ans); // Output the final result
    }
}
