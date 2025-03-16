import java.util.Scanner;
import java.util.Stack;

public class StackCalculator {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>(); // Initialize a stack to hold integers
        Scanner scanner = new Scanner(System.in); // Create a scanner for input

        // Read input strings from standard input until EOF is reached
        while (scanner.hasNext()) {
            String input = scanner.next(); // Read the next input string

            // Check if the first character of the input string is '+'
            if (input.charAt(0) == '+') {
                // Pop two elements from the stack
                int chonda = stack.pop();
                int yamagami = stack.pop();

                // Add the popped elements and push the result onto the stack
                stack.push(chonda + yamagami);
            }
            // Check if the first character of the input string is '-'
            else if (input.charAt(0) == '-') {
                // Pop two elements from the stack
                int yamagami = stack.pop();
                int chonda = stack.pop();

                // Subtract the second popped element from the first popped element and push the result onto the stack
                stack.push(chonda - yamagami);
            }
            // Check if the first character of the input string is '*'
            else if (input.charAt(0) == '*') {
                // Pop two elements from the stack
                int chonda = stack.pop();
                int yamagami = stack.pop();

                // Multiply the popped elements and push the result onto the stack
                stack.push(chonda * yamagami);
            }
            // If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
            else {
                stack.push(Integer.parseInt(input));
            }
        }

        // Print the top element of the stack, which is the final result
        System.out.println(stack.pop());

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
