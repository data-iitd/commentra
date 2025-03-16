import java.util.Scanner; // Import the Scanner class for input

public class Calculator { // Define the Calculator class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c; // Declare three integer variables: a, b, and c
        char op; // Declare a character variable: op

        a = scanner.nextInt(); // Read the first integer
        op = scanner.next().charAt(0); // Read the operator
        b = scanner.nextInt(); // Read the second integer

        while (true) { // Start of an infinite loop
            if (op == '+') { // Check if the operator is '+'
                c = a + b; // If so, add the two numbers and store the result in variable c
                System.out.println(c); // Print the result to the standard output
            } else if (op == '-') { // Check if the operator is '-'
                c = a - b; // If so, subtract the second number from the first and store the result in variable c
                System.out.println(c); // Print the result to the standard output
            } else if (op == '*') { // Check if the operator is '*'
                c = a * b; // If so, multiply the two numbers and store the result in variable c
                System.out.println(c); // Print the result to the standard output
            } else if (op == '/') { // Check if the operator is '/'
                c = a / b; // If so, divide the first number by the second and store the result in variable c
                System.out.println(c); // Print the result to the standard output
            } else { // If the operator is not one of the above, break the loop
                break;
            }

            a = scanner.nextInt(); // Read the next integer
            op = scanner.next().charAt(0); // Read the next operator
            b = scanner.nextInt(); // Read the next integer
        }

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Calculator class
// <END-OF-CODE>
