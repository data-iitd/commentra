public class SimpleCalculator {
    public static void main(String[] args) {
        // Declare variables for two integers and one character operator
        int a, b, c;
        char op;

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Start an infinite loop to continuously process operations
        while (true) {
            // Read input values: two integers and an operator
            a = scanner.nextInt();
            op = scanner.next().charAt(0);
            b = scanner.nextInt();

            // Check if the operator is addition
            if (op == '+') {
                c = a + b; // Perform addition
                System.out.println(c); // Output the result
            } 
            // Check if the operator is subtraction
            else if (op == '-') {
                c = a - b; // Perform subtraction
                System.out.println(c); // Output the result
            } 
            // Check if the operator is multiplication
            else if (op == '*') {
                c = a * b; // Perform multiplication
                System.out.println(c); // Output the result
            } 
            // Check if the operator is division
            else if (op == '/') {
                c = a / b; // Perform division
                System.out.println(c); // Output the result
            } 
            // If the operator is not recognized, exit the loop
            else {
                break; // Exit the loop if an invalid operator is provided
            }
        }

        // Close the scanner object
        scanner.close();
    }
}
