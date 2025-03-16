import java.util.Scanner;

public class SumOfIntegers {
    public static void main(String[] args) {
        // Declare variables
        int i, N, x;
        x = 0; // Initialize x to 0 to hold the sum

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read an integer N from user input
        N = scanner.nextInt();

        // Loop from 1 to N to calculate the sum of integers
        for (i = 1; i <= N; i++) {
            x += i; // Add the current value of i to x
        }

        // Print the calculated sum
        System.out.println(x);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
