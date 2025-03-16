import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, S;

        // Continuously read input until a non-positive integer is entered
        while ((N = scanner.nextInt()) > 0) {
            int M = -1; // Maximum value initialized to -1 (less than any possible input)
            int m = 1001; // Minimum value initialized to 1001 (greater than any possible input)
            int addup = 0; // Variable to accumulate the sum of inputs

            // Loop to read N integers
            for (int i = 0; i < N; i++) {
                S = scanner.nextInt(); // Read the next integer

                addup += S; // Add the current integer to the total sum

                // Update the maximum value if the current integer is greater
                if (S > M) M = S;

                // Update the minimum value if the current integer is smaller
                if (S < m) m = S;
            }

            // Calculate the average excluding the maximum and minimum values
            // and print the result
            System.out.println((addup - M - m) / (N - 2));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
