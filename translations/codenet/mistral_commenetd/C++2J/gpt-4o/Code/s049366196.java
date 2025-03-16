import java.util.Scanner;

public class PrimeFactorCount {
    // Function to check if a number is prime
    public static boolean isPrime(long x) {
        // Check for edge cases
        if (x <= 1) return false;
        if (x == 2) return true;

        // Check for composite numbers up to the square root of x
        for (long i = 2; i * i <= x; i++) {
            // If x is divisible by i, it's not prime
            if (x % i == 0) return false;
        }

        // If we've made it this far, x is prime
        return true;
    }

    public static void main(String[] args) {
        // Read the input number N
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize answer to 1
        long ans = 1;
        final int mod = 1000000007;

        // Iterate through all numbers from 2 to N
        for (int i = 2; i <= N; i++) {
            // If the number is prime, calculate its contribution to the answer
            if (isPrime(i)) {
                // Initialize variables for counting prime factors and total count
                int NN = N;
                int cnt = 0;

                // Count the number of occurrences of i as a factor in N
                while (NN > 0) {
                    // Increment the count
                    cnt += NN / i;

                    // Update NN to the next number without the current factor
                    NN /= i;
                }

                // Multiply the answer by the count and update it modulo mod
                ans = (ans * (cnt + 1)) % mod;
            }
        }

        // Print the final answer
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
