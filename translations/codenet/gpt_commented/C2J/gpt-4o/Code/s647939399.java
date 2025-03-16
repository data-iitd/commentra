import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        char operator; // Variable to store the operator
        int a, b; // Variables for operands
        int[] results = new int[256]; // Array to store results
        int i; // Loop counter

        Scanner scanner = new Scanner(System.in);

        // Infinite loop to continuously read input until a termination condition is met
        for (i = 0; i > -1; i++) {
            // Read two integers and an operator from the user
            a = scanner.nextInt();
            operator = scanner.next().charAt(0);
            b = scanner.nextInt();

            // Check if the operator is '?' to terminate the loop
            if (operator == '?') {
                break; // Exit the loop if the termination operator is encountered
            }

            // Perform addition if the operator is '+'
            if (operator == '+') {
                results[i] = a + b; // Store the result of addition in the results array
            }

            // Perform subtraction if the operator is '-'
            if (operator == '-') {
                results[i] = a - b; // Store the result of subtraction in the results array
            }

            // Perform multiplication if the operator is '*'
            if (operator == '*') {
                results[i] = a * b; // Store the result of multiplication in the results array
            }

            // Perform division if the operator is '/'
            if (operator == '/') {
                results[i] = a / b; // Store the result of division in the results array
            }
        }

        // Print all results stored in the results array
        for (int j = 0; j < i; j++) {
            System.out.println(results[j]); // Output each result on a new line
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
