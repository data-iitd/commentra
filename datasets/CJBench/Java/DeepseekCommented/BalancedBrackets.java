import java.util.Stack;
import java.util.Scanner;

public final class Main {
    private Main() {
    } // Private constructor to prevent instantiation

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine(); // Read input from user
        scanner.close(); // Close the scanner
        boolean result = isBalanced(input); // Check if the input is balanced
        System.out.println(result ? "Balanced" : "Not Balanced"); // Print the result
    }

    // Method to check if a pair of brackets is matched
    public static boolean isPaired(char leftBracket, char rightBracket) {
        char[][] pairedBrackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
            {'<', '>'},
        };
        for (char[] pairedBracket : pairedBrackets) {
            if (pairedBracket[0] == leftBracket && pairedBracket[1] == rightBracket) {
                return true;
            }
        }
        return false;
    }

    // Method to check if the input string of brackets is balanced
    public static boolean isBalanced(String brackets) {
        if (brackets == null) {
            throw new IllegalArgumentException("Input string is null"); // Check for null input
        }
        Stack<Character> bracketsStack = new Stack<>(); // Create a stack to keep track of brackets
        for (char bracket : brackets.toCharArray()) {
            switch (bracket) {
                case '(':
                case '[':
                case '<':
                case '{':
                    bracketsStack.push(bracket); // Push opening brackets onto the stack
                    break;
                case ')':
                case ']':
                case '>':
                case '}':
                    if (bracketsStack.isEmpty() || !isPaired(bracketsStack.pop(), bracket)) {
                        return false; // Check for mismatched closing brackets
                    }
                    break;
                default:
                    return false; // Return false if an invalid character is found
            }
        }
        return bracketsStack.isEmpty(); // Return true if the stack is empty (all brackets are balanced)
    }
}
