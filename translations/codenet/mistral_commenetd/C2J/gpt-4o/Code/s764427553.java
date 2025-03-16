import java.util.Scanner;

public class PrimeDigitCounter {
    public static void main(String[] args) {
        // Initialize a constant MAX_V
        final int MAX_V = 999999;
        int[] prime = new int[MAX_V + 1];

        // Initialize all elements to 1
        for (int i = 0; i <= MAX_V; i++) {
            prime[i] = 1; // Initialize all elements to 1
        }

        // Sieve of Eratosthenes algorithm to find prime numbers
        for (int i = 2; i <= MAX_V; i++) {
            // If i is prime, mark all its multiples as composite
            if (prime[i] == 1) {
                for (int k = i * i; k <= MAX_V; k += i) {
                    prime[k] = 0;
                }
            }
        }

        // Set prime[0] and prime[1] to 0 as they are not prime numbers
        prime[0] = 0;
        prime[1] = 0;

        // Initialize a counter 'count' for the number of test cases
        int count = 0;
        Scanner scanner = new Scanner(System.in);

        // Read input test cases until end of file is reached
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            // Increment the counter for each test case
            count++;

            // Initialize a counter 'cnt' to count the number of prime digits in n
            int cnt = 0;

            // Iterate through each digit of n from right to left and count the number of prime digits
            while (n > 0) {
                int digit = n % 10; // Get the last digit
                if (prime[digit] == 1) {
                    cnt++; // Increment the counter if the digit is prime
                }
                n /= 10; // Remove the last digit
            }

            // Print the result for the current test case
            System.out.println(cnt);

            // Break the loop if the required number of test cases have been processed
            if (count == 30) break;
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
