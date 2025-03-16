import java.util.Scanner;

public class Main {
    // Define long long type for convenience
    static long mod = 1000000007;

    // Function to check if a number is prime
    static boolean isPrime(long x) {
        // Check divisibility from 2 to the square root of x
        for (long i = 2; i * i <= x; i++) {
            if (x % i == 0) return false; // If divisible, not prime
        }
        return true; // If no divisors found, it is prime
    }

    public static void main(String[] args) {
        // Read the input value N
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize the answer variable to 1
        long ans = 1;

        // Loop through all numbers from 2 to N
        for (int i = 2; i <= N; i++) {
            // Check if the current number i is prime
            if (isPrime(i)) {
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
                ans = (ans * (cnt + 1)) % mod; // Take modulo to prevent overflow
            }
        }

        // Output the final result
        System.out.println(ans);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
