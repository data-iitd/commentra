import java.util.Scanner;
import java.util.Stack;

public class StackCalculator {
    // Stack to hold integer values
    private static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) {
        // Scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read input until end of file
        while (scanner.hasNext()) {
            String input = scanner.next();

            // Check the operation based on the first character of the input
            switch (input.charAt(0)) {
                case '+':
                    // Pop two values, add them, and push the result
                    int add1 = pop();
                    int add2 = pop();
                    push(add1 + add2);
                    break;
                case '-':
                    // Pop two values, subtract the second from the first, and push the result
                    int sub1 = pop();
                    int sub2 = pop();
                    push(sub2 - sub1);
                    break;
                case '*':
                    // Pop two values, multiply them, and push the result
                    int mul1 = pop();
                    int mul2 = pop();
                    push(mul1 * mul2);
                    break;
                default:
                    // Convert input to integer and push it onto the stack
                    push(Integer.parseInt(input));
                    break;
            }
        }

        // Print the final result from the stack
        System.out.println(pop());
        scanner.close();
    }

    // Function to push a value onto the stack
    private static void push(int value) {
        stack.push(value);
    }

    // Function to pop a value from the stack
    private static int pop() {
        return stack.pop();
    }
}

// <END-OF-CODE>
