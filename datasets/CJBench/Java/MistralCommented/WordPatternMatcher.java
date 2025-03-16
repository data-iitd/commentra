
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Initializes the method to check if the given word pattern matches the input string
    public static boolean matchWordPattern(String pattern, String inputString) {
        Map<Character, String> patternMap = new HashMap<>(); // Initialize an empty HashMap to store the mapping of characters to strings
        Map<String, Character> strMap = new HashMap<>(); // Initialize an empty HashMap to store the mapping of strings to characters

        // Recursive method to check if the pattern matches the input string
        return backtrack(pattern, inputString, 0, 0, patternMap, strMap);
    }

    // Recursive method to check if the pattern matches the input string
    private static boolean backtrack(String pattern, String inputString, int patternIndex, int strIndex, Map<Character, String> patternMap, Map<String, Character> strMap) {
        // Base case: if we have checked all characters in the pattern and all characters in the input string, then the pattern matches the input string
        if (patternIndex == pattern.length() && strIndex == inputString.length()) {
            return true;
        }

        // Base case: if we have checked all characters in the pattern or all characters in the input string, then the pattern does not match the input string
        if (patternIndex == pattern.length() || strIndex == inputString.length()) {
            return false;
        }

        char currentChar = pattern.charAt(patternIndex); // Get the current character in the pattern

        // If the current character in the pattern is already mapped to a string, check if the input string starts with that string
        if (patternMap.containsKey(currentChar)) {
            String mappedStr = patternMap.get(currentChar);
            if (inputString.startsWith(mappedStr, strIndex)) {
                // Recursively call the backtrack method with the updated pattern index and string index
                return backtrack(pattern, inputString, patternIndex + 1, strIndex + mappedStr.length(), patternMap, strMap);
            } else {
                // If the input string does not start with the mapped string, then the pattern does not match the input string
                return false;
            }
        }

        // If the current character in the pattern is not yet mapped to a string, try mapping it to different substrings in the input string
        for (int end = strIndex + 1; end <= inputString.length(); end++) {
            String substring = inputString.substring(strIndex, end); // Get the substring starting from the current string index to the end of the input string

            // If the substring is already mapped to a character, skip it and try the next substring
            if (strMap.containsKey(substring)) {
                continue;
            }

            // Map the current character in the pattern to the substring in the input string
            patternMap.put(currentChar, substring);
            strMap.put(substring, currentChar);

            // Recursively call the backtrack method with the updated pattern index and string index
            boolean result = backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap);

            // If the pattern matches the input string, return true
            if (result) {
                return true;
            }

            // If the pattern does not match the input string, unmap the current character and substring and try the next substring
            patternMap.remove(currentChar);
            strMap.remove(substring);
        }

        // If none of the substrings in the input string match the current character in the pattern, then the pattern does not match the input string
        return false;
    }

    // Main method to read the pattern and input string from the user and print the result
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a Scanner object to read input from the user

        String pattern = sc.nextLine(); // Read the pattern from the user
        String inputString = sc.nextLine(); // Read the input string from the user

        boolean result = matchWordPattern(pattern, inputString); // Call the matchWordPattern method with the pattern and input string

        System.out.println(result ? "True" : "False"); // Print the result to the console

        sc.close(); // Close the Scanner object
    }
}