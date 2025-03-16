import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Stack to hold the integers
    private static Stack<Integer> stack = new Stack<>();

    // Function to push an element onto the stack
    private static void push(int x) {
        stack.push(x);
    }

    // Function to pop an element from the stack
    private static int pop() {
        return stack.pop();
    }

    public static void main(String[] args) {
        // Initialize scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read input until end of file
        while (scanner.hasNext()) {
            String s = scanner.next();

            // Check if the input is an operator or a number
            if (s.equals("+") || s.equals("-") || s.equals("*")) {
                // Pop the top two elements from the stack
                int b = pop();
                int a = pop();

                // Perform the operation and push the result back onto the stack
                if (s.equals("+")) {
                    push(a + b);
                } else if (s.equals("-")) {
                    push(a - b);
                } else { // s.equals("*")
                    push(a * b);
                }
            } else { // Input is a number
                // Push the number directly onto the stack
                push(Integer.parseInt(s));
            }
        }

        // Print the final result
        System.out.println(pop());

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
