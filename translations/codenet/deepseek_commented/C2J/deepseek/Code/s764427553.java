public class PrimeCounter {
    public static void main(String[] args) {
        // Define the maximum value for the sieve
        final int MAX_V = 999999;
        // Array to store prime status of numbers from 0 to MAX_V
        boolean[] prime = new boolean[MAX_V + 1];
        
        // Initialize the prime array to true (true), indicating all numbers are potential primes
        for (int i = 2; i <= MAX_V; i++) {
            prime[i] = true;
        }
        
        // Sieve of Eratosthenes to find prime numbers
        for (int i = 2; i * i <= MAX_V; i++) {
            if (prime[i]) {
                // If i is a prime, mark its multiples as non-prime
                for (int k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = false;
                }
            }
        }
        
        // Set 0 and 1 as non-prime
        prime[0] = false;
        prime[1] = false;
        
        // Counter for the number of inputs processed
        int count = 0;
        
        // Read integers from standard input until EOF
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            count++;
            int n = scanner.nextInt();
            int cnt = 0;
            // Count the number of primes less than or equal to n
            for (int i = n; i > 0; i--) {
                if (prime[i]) {
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
