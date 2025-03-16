
import java.util.Stack;
import java.util.Scanner;
public final class BalancedBrackets {
    private BalancedBrackets() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();
        boolean result = isBalanced(input);
        System.out.println(result ? "Balanced" : "Not Balanced");
    }
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
    public static boolean isBalanced(String brackets) {
        if (brackets == null) {
            throw new IllegalArgumentException("Input string is null");
        }
        Stack<Character> bracketsStack = new Stack<>();
        for (char bracket : brackets.toCharArray()) {
            switch (bracket) {
                case '(':
                case '[':
                case '<':
                case '{':
                    bracketsStack.push(bracket);
                    break;
                case ')':
                case ']':
                case '>':
                case '}':
                    if (bracketsStack.isEmpty() || !isPaired(bracketsStack.pop(), bracket)) {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return bracketsStack.isEmpty();
    }
}
