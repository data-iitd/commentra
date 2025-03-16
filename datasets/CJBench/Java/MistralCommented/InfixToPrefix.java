import java.util.Scanner;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    // Main method to start the application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read input from the console

        String infixExpression = scanner.nextLine(); // Read the infix expression from the user input

        try {
            String prefixExpression = infix2Prefix(infixExpression); // Call the infix2Prefix method to convert infix expression to prefix expression
            System.out.println("Prefix Expression:"); // Print the prefix expression to the console
            System.out.println(prefixExpression);
        } catch (IllegalArgumentException | NullPointerException e) { // Catch any IllegalArgumentException or NullPointerException thrown during the execution
            System.out.println("Error: " + e.getMessage()); // Print the error message to the console
        }

        scanner.close(); // Close the Scanner object to release system resources
    }

    // Method to convert infix expression to prefix expression
    public static String infix2Prefix(String infixExpression) throws IllegalArgumentException {
        if (infixExpression == null) { // Check if the input expression is null
            throw new NullPointerException("Input expression cannot be null."); // Throw a NullPointerException if it is
        }

        infixExpression = infixExpression.trim(); // Trim any leading or trailing white spaces from the input expression

        if (infixExpression.isEmpty()) { // Check if the input expression is empty
            return ""; // Return an empty string if it is
        }

        if (!isBalanced(filterBrackets(infixExpression))) { // Check if the input expression is balanced
            throw new IllegalArgumentException("Invalid expression: unbalanced brackets."); // Throw an IllegalArgumentException if it is not balanced
        }

        StringBuilder output = new StringBuilder(); // Create a StringBuilder object to store the prefix expression
        Stack<Character> stack = new Stack<>(); // Create a Stack object to store the opening brackets or operators

        String reversedInfix = new StringBuilder(infixExpression).reverse().toString(); // Reverse the input expression

        for (char element : reversedInfix.toCharArray()) { // Iterate through each character in the reversed input expression
            if (Character.isLetterOrDigit(element)) { // If the character is a letter or a digit, add it to the output
                output.append(element);
            } else if (element == ')' || element == '}' || element == ']' || element == '>') { // If the character is a closing bracket, pop and add the corresponding opening bracket to the output
                while (!stack.isEmpty() && !isMatchingPair(stack.peek(), element)) {
                    output.append(stack.pop());
                }
                stack.pop();
            } else { // If the character is an operator, push it to the stack if it has higher or equal precedence than the top element
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(element)) {
                    output.append(stack.pop());
                }
                stack.push(element);
            }
        }

        while (!stack.isEmpty()) { // Add any remaining operators to the output
            output.append(stack.pop());
        }

        return output.reverse().toString(); // Reverse the output and return it as the prefix expression
    }

    // Helper method to calculate the precedence of an operator
    private static int precedence(char operator) {
        switch (operator) { // Use a switch statement to determine the precedence of the operator
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

    // Helper method to filter out any non-relevant characters from the input expression
    private static String filterBrackets(String input) {
        Pattern pattern = Pattern.compile("[^(){}\\[\\]<>]"); // Create a regular expression pattern to match any non-bracket characters
        Matcher matcher = pattern.matcher(input); // Create a Matcher object to apply the pattern to the input
        return matcher.replaceAll(""); // Return the filtered string after removing all non-bracket characters
    }

    // Helper method to check if two brackets are matching pairs
    private static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>'); // Use a simple if-else statement to determine if the brackets are matching pairs
    }
}
