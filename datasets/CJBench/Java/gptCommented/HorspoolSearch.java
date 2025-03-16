import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // HashMap to store shift values for characters in the pattern
    private static HashMap<Character, Integer> shiftValues; 
    // Length of the pattern
    private static Integer patternLength;
    // Counter for the number of comparisons made
    private static int comparisons = 0; 

    // Public method to find the first occurrence of a pattern in a text
    public static int findFirst(String pattern, String text) {
        return firstOccurrence(pattern, text, true);
    }

    // Private method to find the first occurrence of a pattern in a text
    private static int firstOccurrence(String pattern, String text, boolean caseSensitive) {
        // Calculate shift values for the pattern
        shiftValues = calcShiftValues(pattern);
        comparisons = 0; // Reset comparisons count
        // If the pattern is empty, return -1 (not found)
        if (pattern.isEmpty()) {
            return -1;
        }
        // Start searching from the end of the pattern in the text
        int textIndex = pattern.length() - 1;
        while (textIndex < text.length()) {
            int i = pattern.length() - 1; // Index for the pattern
            while (i >= 0) {
                comparisons++; // Increment comparison count
                char patternChar = pattern.charAt(i);
                char textChar = text.charAt((textIndex + i) - (pattern.length() - 1));
                // Check if characters match based on case sensitivity
                if (!charEquals(patternChar, textChar, caseSensitive)) {
                    // If not a match, shift the text index based on the character
                    textIndex += getShiftValue(text.charAt(textIndex));
                    break; // Exit inner loop to continue with the next text index
                }
                i--; // Move to the next character in the pattern
            }
            // If all characters matched, return the starting index of the match
            if (i == -1) {
                return textIndex - pattern.length() + 1;
            }
        }
        // If no match is found, return -1
        return -1;
    }

    // Method to compare two characters based on case sensitivity
    private static boolean charEquals(char c1, char c2, boolean caseSensitive) {
        return caseSensitive ? c1 == c2 : Character.toLowerCase(c1) == Character.toLowerCase(c2);
    }

    // Method to calculate shift values for each character in the pattern
    private static HashMap<Character, Integer> calcShiftValues(String pattern) {
        patternLength = pattern.length(); // Store the length of the pattern
        HashMap<Character, Integer> table = new HashMap<>(); // Initialize shift values table
        // Populate the shift values for each character in the pattern
        for (int i = pattern.length() - 2; i >= 0; i--) {
            char c = pattern.charAt(i);
            int finalI = i; // Final index for lambda expression
            table.computeIfAbsent(c, k -> pattern.length() - 1 - finalI);
        }
        return table; // Return the shift values table
    }

    // Method to get the shift value for a character
    private static Integer getShiftValue(char c) {
        return shiftValues.getOrDefault(c, patternLength); // Default to pattern length if not found
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        String text = scanner.nextLine(); // Read the text input
        String pattern = scanner.nextLine(); // Read the pattern input
        int position = findFirst(pattern, text); // Find the first occurrence of the pattern
        // Output the result based on the position found
        if (position != -1) {
            System.out.println("Pattern found at index: " + position);
        } else {
            System.out.println("Pattern not found.");
        }
        scanner.close(); // Close the scanner
    }
}
