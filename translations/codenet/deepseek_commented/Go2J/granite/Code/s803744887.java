
import java.util.Scanner;

public class s803744887{
    public static void main(String[] args) {
        // Initialize constants and arrays
        final int MX = 10000;
        int[] sieve = new int[MX];
        int[] primes = new int[MX];
        int p = 0;

        // Use the Sieve of Eratosthenes to find all primes up to MX
        for (int i = 2; i < MX; i++) {
            if (sieve[i]!= 0) {
                continue; // Skip if i is not a prime
            }
            primes[p++] = i; // i is a prime, add it to the primes list
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i; // Mark j as not prime
            }
        }

        // Read the number of integers to process
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;

        // Process each integer and update the answer
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            ans++; // Assume the number is valid
            for (int j = 0; j < p; j++) {
                if (x > primes[j] && x % primes[j] == 0) {
                    ans--; // The number is not valid
                    break;
                }
            }
        }

        // Output the result
        System.out.println(ans);
    }
}
