import java.util.*;

public class Main {
    // Function to find the smallest integer n >= N such that n/S(n) is minimized
    public static long f(long N) {
        // Array to store the digits of N
        long[] a = new long[20];
        long d = 0; // Digit counter

        // Extract digits of N and store them in the array
        while (N > 0) {
            a[d] = N % 10; // Get the last digit
            N /= 10; // Remove the last digit
            d++; // Increment digit counter
        }

        double m = 1e18; // Initialize minimum fraction to a large value
        long res = N; // Result variable to store the best candidate

        // Iterate through possible positions to replace digits with 9s
        for (int i = 0; i <= d; i++) {
            long bunsi = 0; // Numerator
            long bunbo = 9 * i; // Denominator starts with 9 times the number of replaced digits

            // Construct the numerator and denominator based on the current digit manipulation
            for (int j = d - 1; j >= 0; j--) {
                bunsi *= 10; // Shift left for the next digit
                if (j < i) 
                    bunsi += 9; // Replace with 9 if below the current index
                else 
                    bunsi += a[j]; // Keep the original digit
                
                if (j >= i) 
                    bunbo += a[j]; // Add to denominator if the digit is not replaced
            }

            // Calculate the fraction n/S(n)
            double frac = (double)bunsi / (double)bunbo;

            // Update the result if a new minimum fraction is found
            if (frac < m) {
                m = frac; // Update minimum fraction
                res = bunsi; // Update result with the new candidate
            }
        }
        return res; // Return the best candidate found
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int K = in.nextInt(); // Number of outputs to generate
        long N = f(1); // Initialize N by finding the first candidate starting from 1

        // Generate K outputs
        for (int i = 0; i < K; i++) {
            System.out.println(N); // Output the current candidate
            N = f(N + 1); // Find the next candidate starting from N + 1
        }
    }
}

