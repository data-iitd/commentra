import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Approach 1: Check if two strings are anagrams by sorting
    public static boolean approach1(String s, String t) {
        // If lengths are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Convert strings to character arrays
        char[] c = s.toCharArray();
        char[] d = t.toCharArray();
        // Sort both character arrays
        Arrays.sort(c);
        Arrays.sort(d);
        // Check if sorted arrays are equal
        return Arrays.equals(c, d);
    }

    // Approach 2: Check if two strings are anagrams using character count
    public static boolean approach2(String s, String t) {
        // If lengths are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Array to count occurrences of each character (assuming lowercase a-z)
        int[] charCount = new int[26];
        // Count characters in both strings
        for (int i = 0; i < s.length(); i++) {
            charCount[s.charAt(i) - 'a']++;
            charCount[t.charAt(i) - 'a']--;
        }
        // Check if all counts are zero
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Approach 3: Same as Approach 2 (duplicate code)
    public static boolean approach3(String s, String t) {
        // If lengths are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Array to count occurrences of each character (assuming lowercase a-z)
        int[] charCount = new int[26];
        // Count characters in both strings
        for (int i = 0; i < s.length(); i++) {
            charCount[s.charAt(i) - 'a']++;
            charCount[t.charAt(i) - 'a']--;
        }
        // Check if all counts are zero
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Approach 4: Check if two strings are anagrams using a HashMap
    public static boolean approach4(String s, String t) {
        // If lengths are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // HashMap to count occurrences of each character
        HashMap<Character, Integer> charCountMap = new HashMap<>();
        // Count characters in the first string
        for (char c : s.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }
        // Decrease counts based on characters in the second string
        for (char c : t.toCharArray()) {
            // If character is not found or count is zero, they are not anagrams
            if (!charCountMap.containsKey(c) || charCountMap.get(c) == 0) {
                return false;
            }
            charCountMap.put(c, charCountMap.get(c) - 1);
        }
        // Check if all counts are zero
        return charCountMap.values().stream().allMatch(count -> count == 0);
    }

    // Approach 5: Similar to Approach 2 but using a different method
    public static boolean approach5(String s, String t) {
        // If lengths are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Array to count occurrences of each character (assuming lowercase a-z)
        int[] freq = new int[26];
        // Count characters in both strings
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }
        // Check if all counts are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the first string
        String s = scanner.nextLine();
        // Read the second string
        String t = scanner.nextLine();
        // Read the approach number
        int approach = scanner.nextInt();
        boolean result;
        // Switch case to select the approach based on user input
        switch (approach) {
            case 1:
                result = approach1(s, t);
                break;
            case 2:
                result = approach2(s, t);
                break;
            case 3:
                result = approach3(s, t);
                break;
            case 4:
                result = approach4(s, t);
                break;
            case 5:
                result = approach5(s, t);
                break;
            default:
                // Handle invalid approach number
                System.out.println("Invalid approach number.");
                scanner.close();
                return;
        }
        // Output the result of the anagram check
        System.out.println("Are the strings anagrams? " + result);
        // Close the scanner
        scanner.close();
    }
}
