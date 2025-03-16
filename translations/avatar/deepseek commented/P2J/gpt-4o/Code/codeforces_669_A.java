import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take an integer input from the user
        int n = scanner.nextInt();
        // Perform a calculation and print the result
        System.out.println((n * 2 + 1) / 3);

        // Take an integer input from the user for factorial
        int number = scanner.nextInt();
        // Calculate the factorial of the input number
        int result = factorial(number);
        // Print the result
        System.out.println(result);

        // Take an integer input from the user for Fibonacci
        int index = scanner.nextInt();
        // Print the nth Fibonacci number
        System.out.println(fibonacci(index));

        scanner.close();
    }

    // Method to calculate factorial
    public static int factorial(int n) {
        if (n == 0) { // Base case: factorial of 0 is 1
            return 1;
        } else {
            return n * factorial(n - 1); // Recursive case
        }
    }

    // Method to calculate Fibonacci
    public static int fibonacci(int n) {
        if (n <= 0) { // Return 0 for non-positive input
            return 0;
        } else if (n == 1) { // Return 1 for input of 1
            return 1;
        } else {
            int a = 0, b = 1; // Initialize the first two Fibonacci numbers
            for (int i = 2; i <= n; i++) { // Loop from 2 to n
                int temp = b; // Store the current Fibonacci number
                b = a + b; // Update b to the next Fibonacci number
                a = temp; // Update a to the previous Fibonacci number
            }
            return b; // Return the nth Fibonacci number
        }
    }
}

// <END-OF-CODE>
