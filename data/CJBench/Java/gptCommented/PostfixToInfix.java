import java.util.Scanner;
import java.util.Stack;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    // Method to check if a character is a valid operator
    public static boolean isOperator(char token) {
        return token == '+' || token == '-' || token == '/' || token == '*' || token == '^';
    }

    // Method to validate if the given string is a valid postfix expression
    public static boolean isValidPostfixExpression(String postfix) {
        // A single alphabetic character is a valid postfix expression
        if (postfix.length() == 1 && Character.isAlphabetic(postfix.charAt(0))) {
            return true;
        }
        // Postfix expressions must have at least 3 characters to be valid
        if (postfix.length() < 3) {
            return false; 
        }

        int operandCount = 0; // Count of operands
        int operatorCount = 0; // Count of operators

        // Iterate through each character in the postfix expression
        for (char token : postfix.toCharArray()) {
            if (isOperator(token)) {
                operatorCount++; // Increment operator count
                // There must be at least one operand for each operator
                if (operatorCount >= operandCount) {
                    return false; 
                }
            } else {
                operandCount++; // Increment operand count
            }
        }
        // A valid postfix expression must have exactly one more operand than operators
        return operandCount == operatorCount + 1;
    }

    // Method to convert a valid postfix expression to infix expression
    public static String getMain(String postfix) {
        // Return an empty string if the postfix expression is empty
        if (postfix.isEmpty()) {
            return "";
        }
        // Validate the postfix expression; throw an exception if invalid
        if (!isValidPostfixExpression(postfix)) {
            throw new IllegalArgumentException("Invalid Postfix Expression");
        }

        Stack<String> stack = new Stack<>(); // Stack to hold operands

        // Iterate through each character in the postfix expression
        for (char token : postfix.toCharArray()) {
            if (!isOperator(token)) {
                // Push operands onto the stack
                stack.push(Character.toString(token));
            } else {
                // Pop the top two operands from the stack for the operator
                String operandB = stack.pop();
                String operandA = stack.pop();
                // Form a new infix expression and push it back onto the stack
                stack.push('(' + operandA + token + operandB + ')');
            }
        }
        // The final infix expression is the only element left in the stack
        return stack.pop();
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        String postfix = scanner.nextLine(); // Read the postfix expression from input
        try {
            // Convert the postfix expression to infix and print it
            String infix = getMain(postfix);
            System.out.println("Infix Expression: " + infix);
        } catch (IllegalArgumentException e) {
            // Handle invalid postfix expression
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close(); // Close the scanner
    }
}
