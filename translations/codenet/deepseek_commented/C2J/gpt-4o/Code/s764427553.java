import java.util.Scanner;

public class PrimeSieve {
    public static void main(String[] args) {
        // Define the maximum value for the sieve
        final int MAX_V = 999999;
        // Array to store prime status of numbers from 0 to MAX_V
        int[] prime = new int[MAX_V + 1];

        // Initialize the prime array to 1 (true), indicating all numbers are potential primes
        for (int i = 2; i <= MAX_V; i++) {
            prime[i] = 1;
        }

        // Sieve of Eratosthenes to find prime numbers
        for (int i = 2; i * i <= MAX_V; i++) {
            if (prime[i] == 1) {
                // If i is a prime, mark its multiples as non-prime
                for (int k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = 0;
                }
            }
        }

        // Set 0 and 1 as non-prime
        prime[0] = 0;
        prime[1] = 0;

        // Counter for the number of inputs processed
        int count = 0;
        Scanner scanner = new Scanner(System.in);

        // Read integers from standard input until EOF
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            count++;
            int cnt = 0;
            // Count the number of primes less than or equal to n
            for (int i = n; i > 0; i--) {
                if (prime[i] == 1) {
                    cnt++;
                }
            }
            // Print the count of primes for the current input
            System.out.println(cnt);
            // Break the loop after processing 30 inputs
            if (count == 30) break;
        }

        scanner.close();
    }
}
// <END-OF-CODE>
