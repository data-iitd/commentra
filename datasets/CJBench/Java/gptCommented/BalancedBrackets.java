import java.util.Stack;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of input from the user
        String input = scanner.nextLine();
        
        // Close the scanner to free resources
        scanner.close();
        
        // Check if the input brackets are balanced and store the result
        boolean result = isBalanced(input);
        
        // Print the result: either "Balanced" or "Not Balanced"
        System.out.println(result ? "Balanced" : "Not Balanced");
    }

    // Method to check if a pair of brackets is valid
    public static boolean isPaired(char leftBracket, char rightBracket) {
        // Define a 2D array of paired brackets
        char[][] pairedBrackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
            {'<', '>'},
        };
        
        // Iterate through the paired brackets to find a match
        for (char[] pairedBracket : pairedBrackets) {
            if (pairedBracket[0] == leftBracket && pairedBracket[1] == rightBracket) {
                return true; // Return true if a matching pair is found
            }
        }
        return false; // Return false if no matching pair is found
    }

    // Method to check if the input string of brackets is balanced
    public static boolean isBalanced(String brackets) {
        // Check for null input and throw an exception if true
        if (brackets == null) {
            throw new IllegalArgumentException("Input string is null");
        }
        
        // Create a stack to keep track of opening brackets
        Stack<Character> bracketsStack = new Stack<>();
        
        // Iterate through each character in the input string
        for (char bracket : brackets.toCharArray()) {
            switch (bracket) {
                // If the character is an opening bracket, push it onto the stack
                case '(':
                case '[':
                case '<':
                case '{':
                    bracketsStack.push(bracket);
                    break;
                // If the character is a closing bracket
                case ')':
                case ']':
                case '>':
                case '}':
                    // Check if the stack is empty or if the brackets do not match
                    if (bracketsStack.isEmpty() || !isPaired(bracketsStack.pop(), bracket)) {
                        return false; // Return false if not balanced
                    }
                    break;
                // If the character is not a bracket, return false
                default:
                    return false;
            }
        }
        // Return true if all opening brackets have been matched and the stack is empty
        return bracketsStack.isEmpty();
    }
}
