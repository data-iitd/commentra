import java.util.Scanner; // Import the Scanner class for user input

public class Calculator { // Define the Calculator class
    public static void main(String[] args) { // Define the main method, the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c; // Declare three integer variables to store the operands and the result
        char op; // Declare a character variable to store the operator
        
        // Read the first set of inputs
        a = scanner.nextInt(); // Read the first integer
        op = scanner.next().charAt(0); // Read the operator
        b = scanner.nextInt(); // Read the second integer
        
        while (true) { // Start an infinite loop
            if (op == '+') { // Check if the operator is addition
                c = a + b; // Perform the addition operation
                System.out.println(c); // Print the result
            } else if (op == '-') { // Check if the operator is subtraction
                c = a - b; // Perform the subtraction operation
                System.out.println(c); // Print the result
            } else if (op == '*') { // Check if the operator is multiplication
                c = a * b; // Perform the multiplication operation
                System.out.println(c); // Print the result
            } else if (op == '/') { // Check if the operator is division
                c = a / b; // Perform the division operation
                System.out.println(c); // Print the result
            } else { // If the operator is not recognized
                break; // Exit the loop and end the program
            }
            // Read the next set of operands and operator
            a = scanner.nextInt(); // Read the next integer
            op = scanner.next().charAt(0); // Read the next operator
            b = scanner.nextInt(); // Read the next integer
        }
        
        scanner.close(); // Close the scanner
    }
} // End of the Calculator class
// <END-OF-CODE>
