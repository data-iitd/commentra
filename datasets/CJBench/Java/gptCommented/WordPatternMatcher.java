import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to match a given pattern with an input string
    public static boolean matchWordPattern(String pattern, String inputString) {
        // Maps to store the relationship between pattern characters and substrings
        Map<Character, String> patternMap = new HashMap<>();
        Map<String, Character> strMap = new HashMap<>();
        // Start the backtracking process
        return backtrack(pattern, inputString, 0, 0, patternMap, strMap);
    }

    // Backtracking method to find a valid mapping of pattern to input string
    private static boolean backtrack(String pattern, String inputString, int patternIndex, int strIndex, Map<Character, String> patternMap, Map<String, Character> strMap) {
        // Check if both pattern and input string have been fully matched
        if (patternIndex == pattern.length() && strIndex == inputString.length()) {
            return true;
        }
        // If one of them is fully matched but the other is not, return false
        if (patternIndex == pattern.length() || strIndex == inputString.length()) {
            return false;
        }

        // Get the current character from the pattern
        char currentChar = pattern.charAt(patternIndex);
        
        // If the current character is already mapped to a substring
        if (patternMap.containsKey(currentChar)) {
            String mappedStr = patternMap.get(currentChar);
            // Check if the input string starts with the mapped substring at the current index
            if (inputString.startsWith(mappedStr, strIndex)) {
                // Continue to backtrack with the next character in the pattern and the updated index in the input string
                return backtrack(pattern, inputString, patternIndex + 1, strIndex + mappedStr.length(), patternMap, strMap);
            } else {
                return false; // Mapped substring does not match
            }
        }

        // Try to map the current pattern character to different substrings of the input string
        for (int end = strIndex + 1; end <= inputString.length(); end++) {
            String substring = inputString.substring(strIndex, end);
            // If the substring is already mapped to a different pattern character, skip it
            if (strMap.containsKey(substring)) {
                continue;
            }
            // Map the current character to the substring and vice versa
            patternMap.put(currentChar, substring);
            strMap.put(substring, currentChar);
            // Recursively backtrack with the new mappings
            if (backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap)) {
                return true; // Found a valid mapping
            }
            // If not successful, remove the mappings and try the next substring
            patternMap.remove(currentChar);
            strMap.remove(substring);
        }
        return false; // No valid mapping found
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the pattern and input string from user input
        String pattern = sc.nextLine();
        String inputString = sc.nextLine();
        // Check if the pattern matches the input string
        boolean result = matchWordPattern(pattern, inputString);
        // Output the result
        System.out.println(result ? "True" : "False");
        // Close the scanner
        sc.close();
    }
}
