
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Method to check if the input string matches the given pattern
    public static boolean matchWordPattern(String pattern, String inputString) {
        // Maps to store the pattern-to-string and string-to-pattern mappings
        Map<Character, String> patternMap = new HashMap<>();
        Map<String, Character> strMap = new HashMap<>();
        // Start the backtracking process
        return backtrack(pattern, inputString, 0, 0, patternMap, strMap);
    }

    // Helper method to perform the backtracking for pattern matching
    private static boolean backtrack(String pattern, String inputString, int patternIndex, int strIndex, Map<Character, String> patternMap, Map<String, Character> strMap) {
        // If both pattern and input string are fully traversed, return true
        if (patternIndex == pattern.length() && strIndex == inputString.length()) {
            return true;
        }
        // If either pattern or input string is fully traversed, return false
        if (patternIndex == pattern.length() || strIndex == inputString.length()) {
            return false;
        }
        // Get the current character from the pattern
        char currentChar = pattern.charAt(patternIndex);
        // Check if the current character is already mapped
        if (patternMap.containsKey(currentChar)) {
            // Get the mapped string
            String mappedStr = patternMap.get(currentChar);
            // Check if the input string starts with the mapped string
            if (inputString.startsWith(mappedStr, strIndex)) {
                // Recursively check the next part of the pattern and input string
                return backtrack(pattern, inputString, patternIndex + 1, strIndex + mappedStr.length(), patternMap, strMap);
            } else {
                return false;
            }
        }
        // Try to map the current character to different substrings in the input string
        for (int end = strIndex + 1; end <= inputString.length(); end++) {
            String substring = inputString.substring(strIndex, end);
            if (strMap.containsKey(substring)) {
                continue;
            }
            // Map the current character to the substring
            patternMap.put(currentChar, substring);
            strMap.put(substring, currentChar);
            // Recursively check the next part of the pattern and input string
            if (backtrack(pattern, inputString, patternIndex + 1, end, patternMap, strMap)) {
                return true;
            }
            // Backtrack: remove the current mapping
            patternMap.remove(currentChar);
            strMap.remove(substring);
        }
        return false;
    }

    // Main method to take input and print the result
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pattern = sc.nextLine();
        String inputString = sc.nextLine();
        boolean result = matchWordPattern(pattern, inputString);
        System.out.println(result ? "True" : "False");
        sc.close();
    }
}