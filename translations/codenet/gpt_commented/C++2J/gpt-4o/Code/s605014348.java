import java.util.Scanner;

public class Main {
    // Function prototype for div
    public static int div(int n) {
        // Check if n is even, return 2 if it is
        if (n % 2 == 0) return 2;

        // Calculate the square root of n for optimization
        int s = (int) Math.sqrt(n);
        
        // Check for odd divisors from 3 up to the square root of n
        for (int i = 3; i <= s; i += 2) {
            // If i is a divisor of n, return it
            if (n % i == 0) return i;
        }

        // If no divisors found, return n (n is prime)
        return n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num; // Variable to store the input number
        num = scanner.nextInt(); // Read an integer from the user
        System.out.print(num + ":"); // Output the initial number followed by a colon

        // Loop until num is reduced to 1
        while (num != 1) {
            // Find and output the smallest divisor of num
            System.out.print(" " + div(num));
            // Divide num by its smallest divisor
            num = num / div(num);
        }
        System.out.println(); // Print a newline at the end of output
    }
}

// <END-OF-CODE>
