import java.util.Scanner;

// Define a class for the program
public class Main {
    // Method to count the number of digits in a given integer
    public static int digit(long n) {
        int res = 0; // Initialize digit count to zero
        // Loop until all digits are processed
        while (n > 0) {
            res++; // Increment digit count
            n /= 10; // Remove the last digit
        }
        return res; // Return the total count of digits
    }

    // Method to execute the main logic of the program
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        long n; // Variable to store the input number
        // Read a long integer from standard input
        n = scanner.nextLong();

        // Initialize minimum digit count with the digit count of n
        int min = digit(n);
        
        // Loop through all possible divisors of n
        for (int i = 1; (long) i * i <= n; i++) {
            // Skip if i is not a divisor of n
            if (n % i != 0) continue;

            // Calculate the corresponding divisor
            long a = i;
            long b = n / i;

            // Update the minimum digit count based on the digits of the divisors
            min = Math.min(min, Math.max(digit(a), digit(b)));
        }

        // Print the minimum digit count found
        System.out.println(min);
    }

    // Main method to start the program execution
    public static void main(String[] args) {
        run(); // Call the run method to execute the logic
    }
}

// <END-OF-CODE>
