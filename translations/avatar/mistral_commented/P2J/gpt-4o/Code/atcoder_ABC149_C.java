import java.util.Scanner;

public class PrimeFinder {
    public static void main(String[] args) {
        // Initialize an array 'prime' of boolean values with all elements as True
        // The array 'prime' will be used to store whether a number is prime or not
        // The size of the array is 100010
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        boolean[] prime = new boolean[100010];

        // Set all elements to true initially
        for (int i = 0; i < prime.length; i++) {
            prime[i] = true;
        }

        // Set the first two elements of the array as False, as 0 and 1 are not prime numbers
        prime[0] = false;
        prime[1] = false;

        // Sieve of Eratosthenes algorithm to find prime numbers up to 100008
        for (int i = 4; i < 100010; i += 2) {
            // If the number 'i' is prime
            if (prime[i]) {
                // Mark all multiples of 'i' as composite (non-prime)
                for (int j = i + i; j < 100010; j += i) {
                    prime[j] = false;
                }
            }
        }

        // Find the prime number 'X' and print it
        int i = X;
        while (i < 100010) {
            // If the number 'i' is prime
            if (prime[i]) {
                System.out.println(i);
                // Exit the loop as we have found the prime number 'X'
                break;
            }
            i++;
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
