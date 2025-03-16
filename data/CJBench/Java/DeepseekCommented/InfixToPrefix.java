import java.util.Scanner;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String infixExpression = scanner.nextLine(); // Step 1: Reading the Input
        try {
            String prefixExpression = infix2Prefix(infixExpression); // Step 3: Converting Infix to Prefix
            System.out.println("Prefix Expression:");
            System.out.println(prefixExpression); // Step 7: Output
        } catch (IllegalArgumentException | NullPointerException e) {
            System.out.println("Error: " + e.getMessage()); // Step 7: Output
        }
        scanner.close();
    }

    public static String infix2Prefix(String infixExpression) throws IllegalArgumentException {
        if (infixExpression == null) {
            throw new NullPointerException("Input expression cannot be null."); // Step 2: Handling Input
        }
        infixExpression = infixExpression.trim(); // Step 2: Handling Input
        if (infixExpression.isEmpty()) {
            return ""; // Step 2: Handling Input
        }
        if (!isBalanced(filterBrackets(infixExpression))) { // Step 2: Handling Input
            throw new IllegalArgumentException("Invalid expression: unbalanced brackets."); // Step 2: Handling Input
        }
        StringBuilder output = new StringBuilder(); // Step 3: Converting Infix to Prefix
        Stack<Character> stack = new Stack<>(); // Step 3: Converting Infix to Prefix
        String reversedInfix = new StringBuilder(infixExpression).reverse().toString(); // Step 3: Converting Infix to Prefix
        for (char element : reversedInfix.toCharArray()) { // Step 3: Converting Infix to Prefix
            if (Character.isLetterOrDigit(element)) {
                output.append(element); // Step 3: Converting Infix to Prefix
            } else if (element == ')') {
                stack.push(element); // Step 3: Converting Infix to Prefix
            } else if (element == '(') {
                while (!stack.isEmpty() && stack.peek() != ')') {
                    output.append(stack.pop()); // Step 3: Converting Infix to Prefix
                }
                stack.pop(); // Step 3: Converting Infix to Prefix
            } else {
                while (!stack.isEmpty() && precedence(element) <= precedence(stack.peek())) {
                    output.append(stack.pop()); // Step 3: Converting Infix to Prefix
                }
                stack.push(element); // Step 3: Converting Infix to Prefix
            }
        }
        while (!stack.isEmpty()) {
            output.append(stack.pop()); // Step 3: Converting Infix to Prefix
        }
        return output.reverse().toString(); // Step 3: Converting Infix to Prefix
    }

    private static int precedence(char operator) { // Step 4: Precedence Calculation
        switch (operator) {
            case '+':
            case '-':
                return 1; // Step 4: Precedence Calculation
            case '*':
            case '/':
                return 2; // Step 4: Precedence Calculation
            case '^':
                return 3; // Step 4: Precedence Calculation
            default:
                return 0; // Step 4: Precedence Calculation
        }
    }

    private static String filterBrackets(String input) { // Step 5: Filtering Brackets
        Pattern pattern = Pattern.compile("[^(){}\\[\\]<>]");
        Matcher matcher = pattern.matcher(input);
        return matcher.replaceAll(""); // Step 5: Filtering Brackets
    }

    private static boolean isBalanced(String expression) { // Step 6: Balancing Check
        Stack<Character> stack = new Stack<>();
        for (char ch : expression.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[' || ch == '<') {
                stack.push(ch); // Step 6: Balancing Check
            } else if (ch == ')' || ch == '}' || ch == ']' || ch == '>') {
                if (stack.isEmpty()) {
                    return false; // Step 6: Balancing Check
                }
                char top = stack.pop(); // Step 6: Balancing Check
                if (!isMatchingPair(top, ch)) { // Step 6: Balancing Check
                    return false; // Step 6: Balancing Check
                }
            }
        }
        return stack.isEmpty(); // Step 6: Balancing Check
    }

    private static boolean isMatchingPair(char open, char close) { // Step 6: Balancing Check
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>'); // Step 6: Balancing Check
    }
}
