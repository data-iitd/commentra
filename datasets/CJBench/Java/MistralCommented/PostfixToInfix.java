
import java.util.Scanner;
import java.util.Stack;

public final class Main {
    private Main() {}

    // Check if given character is an operator
    public static boolean isOperator(char token) {
        return token == '+' || token == '-' || token == '/' || token == '*' || token == '^';
    }

    // Check if given postfix expression is valid
    public static boolean isValidPostfixExpression(String postfix) {
        // Check if the postfix expression is empty or contains only one alphabetic character
        if (postfix.length() == 1 && Character.isAlphabetic(postfix.charAt(0))) {
            return true;
        }

        // Check if the length of the postfix expression is less than 3
        if (postfix.length() < 3) {
            return false;
        }

        int operandCount = 0; // Initialize operand count
        int operatorCount = 0; // Initialize operator count

        // Iterate through each character in the postfix expression
        for (char token : postfix.toCharArray()) {
            // If the current character is an operator
            if (isOperator(token)) {
                operatorCount++; // Increment operator count

                // Check if the number of operators is greater than or equal to the number of operands
                if (operatorCount >= operandCount) {
                    return false;
                }
            } else {
                operandCount++; // Increment operand count
            }
        }

        // Check if the number of operands is equal to the number of operators plus one
        return operandCount == operatorCount + 1;
    }

    // Convert postfix expression to infix expression
    public static String getMain(String postfix) {
        // Check if the postfix expression is empty
        if (postfix.isEmpty()) {
            return "";
        }

        // Check if the postfix expression is invalid
        if (!isValidPostfixExpression(postfix)) {
            throw new IllegalArgumentException("Invalid Postfix Expression");
        }

        Stack<String> stack = new Stack<>(); // Initialize stack

        // Iterate through each character in the postfix expression
        for (char token : postfix.toCharArray()) {
            // If the current character is not an operator
            if (!isOperator(token)) {
                stack.push(Character.toString(token)); // Push the operand onto the stack
            } else {
                // Pop two operands from the stack and apply the operator on them
                String operandB = stack.pop();
                String operandA = stack.pop();

                // Push the result of the operation onto the stack
                stack.push('(' + operandA + token + operandB + ')');
            }
        }

        // Return the final result from the stack
        return stack.pop();
    }

    // Main method to read user input and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner to read user input

        String postfix = scanner.nextLine(); // Read postfix expression from user input

        try {
            // Convert postfix expression to infix expression and print it
            String infix = getMain(postfix);
            System.out.println("Infix Expression: " + infix);
        } catch (IllegalArgumentException e) {
            // Print error message if the postfix expression is invalid
            System.out.println("Error: " + e.getMessage());
        }

        scanner.close(); // Close scanner after use
    }
}