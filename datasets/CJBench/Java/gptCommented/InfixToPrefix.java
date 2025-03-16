import java.util.Scanner;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the infix expression from the user
        String infixExpression = scanner.nextLine();
        
        try {
            // Convert the infix expression to prefix notation
            String prefixExpression = infix2Prefix(infixExpression);
            // Output the resulting prefix expression
            System.out.println("Prefix Expression:");
            System.out.println(prefixExpression);
        } catch (IllegalArgumentException | NullPointerException e) {
            // Handle any exceptions that occur during conversion
            System.out.println("Error: " + e.getMessage());
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    public static String infix2Prefix(String infixExpression) throws IllegalArgumentException {
        // Check if the input expression is null and throw an exception if it is
        if (infixExpression == null) {
            throw new NullPointerException("Input expression cannot be null.");
        }
        
        // Trim whitespace from the expression
        infixExpression = infixExpression.trim();
        
        // Return an empty string if the expression is empty
        if (infixExpression.isEmpty()) {
            return "";
        }
        
        // Check if the brackets in the expression are balanced
        if (!isBalanced(filterBrackets(infixExpression))) {
            throw new IllegalArgumentException("Invalid expression: unbalanced brackets.");
        }
        
        // Initialize a StringBuilder to hold the output prefix expression
        StringBuilder output = new StringBuilder();
        // Create a stack to hold operators and parentheses
        Stack<Character> stack = new Stack<>();
        // Reverse the infix expression for processing
        String reversedInfix = new StringBuilder(infixExpression).reverse().toString();
        
        // Process each character in the reversed infix expression
        for (char element : reversedInfix.toCharArray()) {
            // If the character is an operand, add it to the output
            if (Character.isLetterOrDigit(element)) {
                output.append(element);
            } 
            // If the character is a closing parenthesis, push it onto the stack
            else if (element == ')') {
                stack.push(element);
            } 
            // If the character is an opening parenthesis, pop from the stack until a closing parenthesis is found
            else if (element == '(') {
                while (!stack.isEmpty() && stack.peek() != ')') {
                    output.append(stack.pop());
                }
                // Pop the closing parenthesis from the stack
                stack.pop();
            } 
            // If the character is an operator
            else {
                // Pop operators from the stack to the output based on precedence
                while (!stack.isEmpty() && precedence(element) <= precedence(stack.peek())) {
                    output.append(stack.pop());
                }
                // Push the current operator onto the stack
                stack.push(element);
            }
        }
        
        // Pop any remaining operators from the stack to the output
        while (!stack.isEmpty()) {
            output.append(stack.pop());
        }
        
        // Reverse the output to get the final prefix expression
        return output.reverse().toString();
    }

    // Method to determine the precedence of operators
    private static int precedence(char operator) {
        switch (operator) {
            case '+':
            case '-':
                return 1; // Lowest precedence
            case '*':
            case '/':
                return 2; // Medium precedence
            case '^':
                return 3; // Highest precedence
            default:
                return 0; // Non-operator
        }
    }

    // Method to filter out non-bracket characters from the input
    private static String filterBrackets(String input) {
        Pattern pattern = Pattern.compile("[^(){}\\[\\]<>]");
        Matcher matcher = pattern.matcher(input);
        return matcher.replaceAll(""); // Return only the brackets
    }

    // Method to check if the brackets in the expression are balanced
    private static boolean isBalanced(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char ch : expression.toCharArray()) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[' || ch == '<') {
                stack.push(ch);
            } 
            // For closing brackets, check for matching opening brackets
            else if (ch == ')' || ch == '}' || ch == ']' || ch == '>') {
                if (stack.isEmpty()) {
                    return false; // Unmatched closing bracket
                }
                char top = stack.pop();
                if (!isMatchingPair(top, ch)) {
                    return false; // Mismatched brackets
                }
            }
        }
        // The expression is balanced if the stack is empty at the end
        return stack.isEmpty();
    }

    // Method to check if a pair of brackets match
    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>');
    }
}
