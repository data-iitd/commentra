public class PrimeCounter {
    public static void main(String[] args) {
        // Define a constant for the maximum value to check for primes
        final int MAX_V = 999999;
        
        // Array to hold the prime status of numbers from 0 to MAX_V
        boolean[] prime = new boolean[MAX_V + 1];
        int i, n;

        // Initialize the prime array; assume all numbers are prime initially
        for(i = 2; i <= MAX_V; i++) {
            prime[i] = true; // true indicates that the number is prime
        }

        // Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
        for(i = 2; i * i <= MAX_V; i++) {
            if(prime[i]) { // If i is still marked as prime
                // Mark all multiples of i as non-prime
                for(int k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = false; // false indicates that the number is not prime
                }
            }
        }

        // Explicitly mark 0 and 1 as non-prime
        prime[0] = false;
        prime[1] = false;

        // Variable to count the number of inputs processed
        int count = 0;

        // Read integers from standard input until EOF
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while(scanner.hasNextInt()) {
            count++; // Increment the count of numbers processed
            n = scanner.nextInt(); // Read the next integer
            int cnt = 0; // Counter for the number of primes less than or equal to n

            // Count how many primes are less than or equal to n
            for(i = n; i > 0; i--) {
                if(prime[i]) { // Check if the number is prime
                    cnt++; // Increment the prime count
                }
            }

            // Output the count of primes found
            System.out.println(cnt);

            // Stop processing after 30 numbers
            if(count == 30) break;
        }

        scanner.close(); // Close the scanner to free up resources
    }
}
