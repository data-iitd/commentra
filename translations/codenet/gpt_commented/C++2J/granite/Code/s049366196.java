
import java.io.*;
import java.util.*;

public class s049366196{
    public static void main(String[] args) throws IOException {
        // Read the input value N
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // Initialize the answer variable to 1
        long ans = 1;

        // Loop through all numbers from 2 to N
        for (int i = 2; i <= N; i++) {
            // Check if the current number i is prime
            if (isPrime((long)i)) {
                // Store the original value of N for calculations
                int NN = N;
                // Initialize a counter for the prime factor's exponent
                int cnt = 0;

                // Count the number of times i is a factor in the numbers from 1 to N
                while (NN > 0) {
                    cnt += NN / i; // Count multiples of i
                    NN /= i; // Reduce NN by dividing by i
                }

                // Update the answer by multiplying with the count of factors + 1
                ans *= cnt + 1;
                ans %= mod; // Take modulo to prevent overflow
            }
        }

        // Output the final result
        System.out.println(ans);
    }

    // Function to check if a number is prime
    public static boolean isPrime(long x) {
        // Check divisibility from 2 to the square root of x
        for (long i = 2; i * i <= x; i++)
            if (x % i == 0) return false; // If divisible, not prime
        return true; // If no divisors found, it is prime
    }
}

