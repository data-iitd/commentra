import java.util.Scanner;
import java.util.Stack;

public class StackCalculator {
    // Global variables for stack management
    private static Stack<Integer> stack = new Stack<>(); // Stack to hold integer values

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for reading input
        String input; // Variable to hold input strings

        // Read input until EOF
        while (scanner.hasNext()) {
            input = scanner.next(); // Read the next input

            // If the input is a '+' operator, perform addition
            if (input.equals("+")) {
                int chonda = pop(); // Pop the top two values from the stack
                int yamagami = pop();
                push(chonda + yamagami); // Push the result of addition back onto the stack
            }
            // If the input is a '-' operator, perform subtraction
            else if (input.equals("-")) {
                int yamagami = pop(); // Pop the top two values from the stack
                int chonda = pop();
                push(chonda - yamagami); // Push the result of subtraction back onto the stack
            }
            // If the input is a '*' operator, perform multiplication
            else if (input.equals("*")) {
                int chonda = pop(); // Pop the top two values from the stack
                int yamagami = pop();
                push(chonda * yamagami); // Push the result of multiplication back onto the stack
            }
            // If the input is a number, convert it to an integer and push onto the stack
            else {
                push(Integer.parseInt(input));
            }
        }

        // Pop and print the final result from the stack
        System.out.println(pop());

        scanner.close(); // Close the scanner
    }

    // Function to push an integer onto the stack
    private static void push(int value) {
        stack.push(value); // Push the value onto the stack
    }

    // Function to pop an integer from the stack
    private static int pop() {
        return stack.pop(); // Pop and return the value from the stack
    }
}

// <END-OF-CODE>
