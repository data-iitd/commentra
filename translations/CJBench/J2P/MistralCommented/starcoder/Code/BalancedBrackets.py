
import java.util.Stack;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read input from the standard input
        String input = scanner.nextLine(); // Read a line of text from the standard input
        scanner.close(); // Close the Scanner object to free system resources

        boolean result = isBalanced(input); // Call the isBalanced method to check if the input string is balanced
        System.out.println(result? "Balanced" : "Not Balanced"); // Print the result to the standard output
    }

    // This method checks if a pair of brackets is valid
    public static boolean isPaired(char leftBracket, char rightBracket) {
        char[][] pairedBrackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
            {'<', '>'},
        };

        // Search for the pair of brackets in the pairedBrackets array
        for (char[] pairedBracket : pairedBrackets) {
            if (pairedBracket[0] == leftBracket && pairedBracket[1] == rightBracket) {
                return true; // If found, return true
            }
        }
        return false; // If not found, return false
    }

    // This method checks if the given string is balanced
    public static boolean isBalanced(String brackets) {
        if (brackets == null) { // Check if the input string is null
            throw new IllegalArgumentException("Input string is null"); // If so, throw an IllegalArgumentException
        }

        Stack<Character> bracketsStack = new Stack<>(); // Create a new Stack object to store the brackets

        // Iterate through each character in the input string
        for (char bracket : brackets.toCharArray()) {
            switch (bracket) {
                case '(':
                case '[':
                case '<':
                case '{':
                    bracketsStack.push(bracket); // Push the left bracket to the stack
                    break;
                case ')':
                case ']':
                case '>':
                case '}':
                    // If the stack is empty or the right bracket does not match the top left bracket, return false
                    if (bracketsStack.isEmpty() ||!isPaired(bracketsStack.pop(), bracket)) {
                        return false;
                    }
                    break;
                default:
                    return false; // If the character is not a valid bracket, return false
            }
        }

        // If the stack is empty, the string is balanced
        return bracketsStack.isEmpty();
    }
}

