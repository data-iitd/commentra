
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize constants and arrays
        final int MX = 10000;
        int[] sieve = new int[MX];
        int[] primes = new int[0];

        // Use the Sieve of Eratosthenes to find all primes up to MX
        for (int i = 2; i < MX; i++) {
            if (sieve[i] != 0) {
                continue; // Skip if i is not a prime
            }
            primes = append(primes, i); // i is a prime, add it to the primes list
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i; // Mark j as not prime
            }
        }

        // Read the number of integers to process
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;

        // Process each integer and update the answer
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            ans++; // Assume the number is valid
            for (int j = 0; j < primes.length; j++) {
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

