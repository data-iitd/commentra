import java.util.Scanner;
import java.util.Stack;
public final class Main {
    private Main() {}

    // This method checks if a given character is an operator.
    public static boolean isOperator(char token) {
        return token == '+' || token == '-' || token == '/' || token == '*' || token == '^';
    }

    // This method validates if a given postfix expression is valid.
    public static boolean isValidPostfixExpression(String postfix) {
        if (postfix.length() == 1 && Character.isAlphabetic(postfix.charAt(0))) {
            return true;
        }
        if (postfix.length() < 3) {
            return false; 
        }
        int operandCount = 0;
        int operatorCount = 0;
        for (char token : postfix.toCharArray()) {
            if (isOperator(token)) {
                operatorCount++;
                if (operatorCount >= operandCount) {
                    return false; 
                }
            } else {
                operandCount++;
            }
        }
        return operandCount == operatorCount + 1;
    }

    // This method converts a valid postfix expression to an infix expression.
    public static String getMain(String postfix) {
        if (postfix.isEmpty()) {
            return "";
        }
        if (!isValidPostfixExpression(postfix)) {
            throw new IllegalArgumentException("Invalid Postfix Expression");
        }
        Stack<String> stack = new Stack<>();
        for (char token : postfix.toCharArray()) {
            if (!isOperator(token)) {
                stack.push(Character.toString(token));
            } else {
                String operandB = stack.pop();
                String operandA = stack.pop();
                stack.push('(' + operandA + token + operandB + ')');
            }
        }
        return stack.pop();
    }

    // This is the entry point of the program where the user inputs a postfix expression, and the program outputs the corresponding infix expression.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String postfix = scanner.nextLine();
        try {
            String infix = getMain(postfix);
            System.out.println("Infix Expression: " + infix);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close();
    }
}
