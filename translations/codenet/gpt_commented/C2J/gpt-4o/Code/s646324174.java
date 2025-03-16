import java.util.Scanner;
import java.util.Stack;

public class RPNCalculator {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>(); // Stack to hold integers
        Scanner scanner = new Scanner(System.in); // Scanner for input

        // Read input until EOF
        while (scanner.hasNext()) {
            String s = scanner.next(); // Read the next token

            // Check for addition operation
            if (s.equals("+")) {
                int b = stack.pop(); // Pop the top two values from the stack
                int a = stack.pop();
                stack.push(a + b); // Push the result of addition back onto the stack
            }
            // Check for subtraction operation
            else if (s.equals("-")) {
                int b = stack.pop(); // Pop the top two values from the stack
                int a = stack.pop();
                stack.push(a - b); // Push the result of subtraction back onto the stack
            }
            // Check for multiplication operation
            else if (s.equals("*")) {
                int b = stack.pop(); // Pop the top two values from the stack
                int a = stack.pop();
                stack.push(a * b); // Push the result of multiplication back onto the stack
            }
            // If the input is a number, convert it and push onto the stack
            else {
                stack.push(Integer.parseInt(s)); // Convert string to integer and push onto the stack
            }
        }

        // Print the final result which is the last remaining value in the stack
        System.out.println(stack.pop());
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
