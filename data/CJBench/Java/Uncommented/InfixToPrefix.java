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
        return output.reverse().toString();
    }
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
    private static String filterBrackets(String input) {
        Pattern pattern = Pattern.compile("[^(){}\\[\\]<>]");
        Matcher matcher = pattern.matcher(input);
        return matcher.replaceAll("");
    }
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
