import java.util.Scanner;

public class Main {
    // Function to find the number of digits in a given number
    public static int digit(long n) {
        int res = 0; // Initialize result
        while (n > 0) { // While number is not zero
            res++; // Increment result by 1
            n /= 10; // Divide number by 10 to get next digit
        }
        return res; // Return the result
    }

    // Function to run the program
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // Read number from standard input
        int min = digit(n); // Initialize minimum with the number of digits in the number
        for (int i = 1; (long) i * i <= n; i++) { // Loop from 1 to square root of the number
            if (n % i != 0) continue; // If current number is not a factor of the given number, skip to next iteration
            long a = i; // Initialize first factor
            long b = n / i; // Initialize second factor
            min = Math.min(min, Math.max(digit(a), digit(b))); // Update minimum with the maximum of digits in first and second factors
        }
        System.out.println(min); // Print the minimum number of digits in any factor of the given number
    }

    // Main function
    public static void main(String[] args) {
        run(); // Call run function to execute the program
    }
}

// <END-OF-CODE>
