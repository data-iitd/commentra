import java.util.Scanner;

public class PrimePairs {
    // Global array to hold the sieve flags for prime numbers
    static int[] flag;

    // Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
    public static void prime(int num) {
        // Allocate memory for the flag array to mark non-prime numbers
        flag = new int[num + 1];

        // Implementing the Sieve of Eratosthenes
        for (int i = 2; i * i <= num; i++) {
            // If the number is still marked as prime
            if (flag[i] == 0) {
                // Mark all multiples of i as non-prime
                for (int j = 2; i * j <= num; j++) {
                    flag[i * j] = 1; // Marking the multiple as non-prime
                }
            }
        }
    }

    // Main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, cnt;

        // Generate prime numbers up to 50000
        prime(50000);

        // Infinite loop to continuously accept user input
        while (true) {
            // Read an integer from the user
            n = scanner.nextInt();
            // Exit the loop if the input is 0
            if (n == 0) {
                break;
            }

            int i = 2; // Start checking from the smallest prime number
            cnt = 0; // Initialize count of valid pairs

            // Check pairs of primes that sum up to n
            while (i * 2 <= n) {
                // If both i and n-i are prime
                if (flag[i] == 0 && flag[n - i] == 0) {
                    cnt++; // Increment the count of valid pairs
                }
                i++; // Move to the next number
            }

            // Output the count of prime pairs that sum up to n
            System.out.println(cnt);
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
