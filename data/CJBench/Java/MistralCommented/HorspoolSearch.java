
import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    private static HashMap<Character, Integer> shiftValues; 
    private static Integer patternLength;
    private static int comparisons = 0; 

    // Method to find the first occurrence of a pattern in a text
    public static int findFirst(String pattern, String text) {
        return firstOccurrence(pattern, text, true);
    }

    // Recursive method to find the first occurrence of a pattern in a text
    private static int firstOccurrence(String pattern, String text, boolean caseSensitive) {
        shiftValues = calcShiftValues(pattern); // Calculate shift values for the pattern
        comparisons = 0;

        if (pattern.isEmpty()) { // Base case: if the pattern is empty, return -1
            return -1;
        }

        int textIndex = pattern.length() - 1; // Initialize textIndex to the last character of the pattern

        while (textIndex < text.length()) { // While textIndex is less than the length of the text
            int i = pattern.length() - 1; // Initialize i to the last character of the pattern

            // Loop through each character of the pattern from the last to the first
            while (i >= 0) {
                comparisons++; // Increment comparisons for each character comparison

                char patternChar = pattern.charAt(i); // Get the character of the pattern at index i
                char textChar = text.charAt((textIndex + i) - (pattern.length() - 1)); // Get the character of the text at the corresponding index

                // Compare the characters of the pattern and text, considering case sensitivity
                if (!charEquals(patternChar, textChar, caseSensitive)) {
                    textIndex += getShiftValue(text.charAt(textIndex)); // Shift textIndex based on the shift value of the character at textIndex
                    break; // Exit the inner loop if the characters don't match
                }

                i--; // Decrement i to compare the next character of the pattern with the text
            }

            // If all characters of the pattern match the corresponding characters in the text, return the index of the first match
            if (i == -1) {
                return textIndex - pattern.length() + 1;
            }

            textIndex++; // Increment textIndex to compare the next possible match in the text
        }

        // If no match is found, return -1
        return -1;
    }

    // Method to compare two characters, considering case sensitivity
    private static boolean charEquals(char c1, char c2, boolean caseSensitive) {
        return caseSensitive ? c1 == c2 : Character.toLowerCase(c1) == Character.toLowerCase(c2);
    }

    // Method to calculate shift values for a pattern
    private static HashMap<Character, Integer> calcShiftValues(String pattern) {
        patternLength = pattern.length();
        HashMap<Character, Integer> table = new HashMap<>();

        // Calculate shift values for each character in the pattern, from the last to the first
        for (int i = pattern.length() - 2; i >= 0; i--) {
            char c = pattern.charAt(i);
            int finalI = i;
            table.computeIfAbsent(c, k -> pattern.length() - 1 - finalI);
        }

        return table;
    }

    // Method to get the shift value for a character
    private static Integer getShiftValue(char c) {
        return shiftValues.getOrDefault(c, patternLength);
    }

    // Main method to read input from the user and call findFirst method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine(); // Read the text from the user
        String pattern = scanner.nextLine(); // Read the pattern from the user
        int position = findFirst(pattern, text); // Find the first occurrence of the pattern in the text

        if (position != -1) { // If the pattern is found, print the index of the first occurrence
            System.out.println("Pattern found at index: " + position);
        } else { // If the pattern is not found, print a message indicating that
            System.out.println("Pattern not found.");
        }

        scanner.close(); // Close the scanner after reading the input
    }
}