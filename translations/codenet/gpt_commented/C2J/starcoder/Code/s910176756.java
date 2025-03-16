import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for two integers and one character operator
        int a, b, c;
        char op;

        // Read input values: two integers and an operator
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        op = sc.next().charAt(0);
        b = sc.nextInt();

        // Start an infinite loop to continuously process operations
        while(true) {
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

            // Read the next set of inputs: two integers and an operator
            a = sc.nextInt();
            op = sc.next().charAt(0);
            b = sc.nextInt();
        }
    }
}
