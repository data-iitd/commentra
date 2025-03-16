import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Stores shift values for each character in the pattern
    private static HashMap<Character, Integer> shiftValues; 
    
    // Stores the length of the pattern
    private static Integer patternLength;
    
    // Counter for the number of character comparisons
    private static int comparisons = 0; 

    // Finds the first occurrence of the pattern in the text
    public static int findFirst(String pattern, String text) {
        return firstOccurrence(pattern, text, true);
    }

    // Implements the Boyer-Moore algorithm to find the first occurrence
    private static int firstOccurrence(String pattern, String text, boolean caseSensitive) {
        shiftValues = calcShiftValues(pattern);
        comparisons = 0;
        
        // If the pattern is empty, return -1
        if (pattern.isEmpty()) {
            return -1;
        }

        int textIndex = pattern.length() - 1;
        while (textIndex < text.length()) {
            int i = pattern.length() - 1;
            while (i >= 0) {
                comparisons++;
                char patternChar = pattern.charAt(i);
                char textChar = text.charAt((textIndex + i) - (pattern.length() - 1));
                if (!charEquals(patternChar, textChar, caseSensitive)) {
                    textIndex += getShiftValue(text.charAt(textIndex));
                    break;
                }
                i--;
            }
            if (i == -1) {
                return textIndex - pattern.length() + 1;
            }
        }
        return -1;
    }

    // Compares characters, optionally ignoring case sensitivity
    private static boolean charEquals(char c1, char c2, boolean caseSensitive) {
        return caseSensitive ? c1 == c2 : Character.toLowerCase(c1) == Character.toLowerCase(c2);
    }

    // Calculates the shift values for each character in the pattern
    private static HashMap<Character, Integer> calcShiftValues(String pattern) {
        patternLength = pattern.length();
        HashMap<Character, Integer> table = new HashMap<>();
        for (int i = pattern.length() - 2; i >= 0; i--) {
            char c = pattern.charAt(i);
            int finalI = i;
            table.computeIfAbsent(c, k -> pattern.length() - 1 - finalI);
        }
        return table;
    }

    // Retrieves the shift value for a given character
    private static Integer getShiftValue(char c) {
        return shiftValues.getOrDefault(c, patternLength);
    }

    // Main method to read input and find the pattern
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        String pattern = scanner.nextLine();
        int position = findFirst(pattern, text);
        if (position != -1) {
            System.out.println("Pattern found at index: " + position);
        } else {
            System.out.println("Pattern not found.");
        }
        scanner.close();
    }
}
