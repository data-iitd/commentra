import java.util.Scanner;
import java.util.Stack;

public class StackCalculator {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Scanner scanner = new Scanner(System.in);

        // Read input until end of file
        while (scanner.hasNext()) {
            String s = scanner.next();

            switch (s) {
                case "+":
                    // Pop two elements, add them, and push the result
                    int b = stack.pop();
                    int a = stack.pop();
                    stack.push(a + b);
                    break;
                case "-":
                    // Pop two elements, subtract the top element from the bottom element, and push the result
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a - b);
                    break;
                case "*":
                    // Pop two elements, multiply them, and push the result
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a * b);
                    break;
                default:
                    // Convert the input string to an integer and push it onto the stack
                    stack.push(Integer.parseInt(s));
                    break;
            }
        }
        // Print the final result from the stack
        System.out.println(stack.pop());
        scanner.close();
    }
}
// <END-OF-CODE>
