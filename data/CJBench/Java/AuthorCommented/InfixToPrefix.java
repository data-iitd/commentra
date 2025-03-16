import java.util.Scanner;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class InfixToPrefix {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        String infixExpression = scanner.nextLine();

        try {
            String prefixExpression = infix2Prefix(infixExpression);
            System.out.println("Prefix Expression:");
            System.out.println(prefixExpression);
        } catch (IllegalArgumentException | NullPointerException e) {
            System.out.println("Error: " + e.getMessage());
        }

        scanner.close();
    }

    /**
     * Convert an infix expression to a prefix expression using stack.
     *
     * @param infixExpression the infix expression to convert
     * @return the prefix expression
     * @throws IllegalArgumentException if the infix expression has unbalanced brackets
     * @throws NullPointerException     if the infix expression is null
     */
    public static String infix2Prefix(String infixExpression) throws IllegalArgumentException {
        if (infixExpression == null) {
            throw new NullPointerException("Input expression cannot be null.");
        }
        infixExpression = infixExpression.trim();
        if (infixExpression.isEmpty()) {
            return "";
        }
        if (!isBalanced(filterBrackets(infixExpression))) {
            throw new IllegalArgumentException("Invalid expression: unbalanced brackets.");
        }

        StringBuilder output = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        // Reverse the infix expression for prefix conversion
        String reversedInfix = new StringBuilder(infixExpression).reverse().toString();
        for (char element : reversedInfix.toCharArray()) {
            if (Character.isLetterOrDigit(element)) {
                output.append(element);
            } else if (element == ')') {
                stack.push(element);
            } else if (element == '(') {
                while (!stack.isEmpty() && stack.peek() != ')') {
                    output.append(stack.pop());
                }
                stack.pop();
            } else {
                while (!stack.isEmpty() && precedence(element) <= precedence(stack.peek())) {
                    output.append(stack.pop());
                }
                stack.push(element);
            }
        }
        while (!stack.isEmpty()) {
            output.append(stack.pop());
        }

        // Reverse the result to get the prefix expression
        return output.reverse().toString();
    }

    /**
     * Determines the precedence of an operator.
     *
     * @param operator the operator whose precedence is to be determined
     * @return the precedence of the operator
     */
    private static int precedence(char operator) {
        switch (operator) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return 0;
        }
    }

    /**
     * Filters out all characters from the input string except brackets.
     *
     * @param input the input string to filter
     * @return a string containing only brackets from the input string
     */
    private static String filterBrackets(String input) {
        Pattern pattern = Pattern.compile("[^(){}\\[\\]<>]");
        Matcher matcher = pattern.matcher(input);
        return matcher.replaceAll("");
    }

    /**
     * Checks if the brackets in the expression are balanced.
     *
     * @param expression the expression to check
     * @return true if the brackets are balanced, false otherwise
     */
    private static boolean isBalanced(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char ch : expression.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[' || ch == '<') {
                stack.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']' || ch == '>') {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.pop();
                if (!isMatchingPair(top, ch)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>');
    }
}
