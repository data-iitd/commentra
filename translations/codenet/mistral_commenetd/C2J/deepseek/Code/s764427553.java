import java.util.Scanner;

public class PrimeDigits {
    public static void main(String[] args) {
        final int MAX_V = 999999;
        boolean[] prime = new boolean[MAX_V + 1];
        for (int i = 0; i <= MAX_V; i++) {
            prime[i] = true; // Initialize all elements to true
        }

        // Sieve of Eratosthenes algorithm to find prime numbers
        for (int i = 2; i <= MAX_V; i++) {
            // If i is prime, mark all its multiples as composite
            if (prime[i]) {
                for (int k = i * i; k <= MAX_V; k += i) {
                    prime[k] = false;
                }
            }
        }

        // Set prime[0] and prime[1] to false as they are not prime numbers
        prime[0] = false;
        prime[1] = false;

        // Initialize a counter 'count' for the number of test cases
        int count = 0;

        // Initialize a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read input test cases until end of file is reached
        while (scanner.hasNextInt()) {
            // Increment the counter for each test case
            count++;

            // Read the current test case
            int n = scanner.nextInt();

            // Initialize a counter 'cnt' to count the number of prime digits in n
            int cnt = 0;

            // Iterate through each digit of n from right to left and count the number of prime digits
            for (int i = n; i > 0; i /= 10) {
                int digit = i % 10;
                if (prime[digit]) {
                    cnt++; // Increment the counter if the digit is prime
                }
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
