import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    // Method to check if a word is a palindrome (case-sensitive)
    public static boolean isMain(String word) {
        return isMain(word, false);
    }

    // Method to check if a word is a palindrome (case-insensitive)
    public static boolean isMainIgnoreCase(String word) {
        return isMain(word, true);
    }

    // Private helper method to check if a word is a palindrome
    private static boolean isMain(String word, boolean ignoreCase) {
        // Return false if the input word is null
        if (word == null) {
            return false;
        }
        // Convert the word to lowercase if case-insensitivity is required
        if (ignoreCase) {
            word = word.toLowerCase();
        }
        // Check for palindrome by comparing characters from both ends
        for (int i = 0; i < word.length() / 2; i++) {
            if (word.charAt(i) != word.charAt(word.length() - 1 - i)) {
                return false; // Return false if characters do not match
            }
        }
        return true; // Return true if the word is a palindrome
    }

    // Method to remove all palindromic words from a given string
    public static String removeMains(String string) {
        // Split the input string into words
        String[] words = string.split(",?\\s+");
        StringBuilder result = new StringBuilder();
        // Iterate through each word
        for (String word : words) {
            // If the word is not a palindrome, add it to the result
            if (!isMainIgnoreCase(word)) {
                if (result.length() > 0) {
                    result.append(", "); // Add a comma if result is not empty
                }
                result.append(word); // Append the non-palindromic word
            }
        }
        return result.toString(); // Return the resulting string
    }

    // Method to remove the nth occurrence of a palindromic word from a string
    public static String removeNthMain(String string, int n) {
        // Split the input string into words
        String[] words = string.split(",?\\s+");
        int counter = 0; // Counter for palindromic words
        StringBuilder result = new StringBuilder();
        // Iterate through each word
        for (String word : words) {
            // If the word is a palindrome, increment the counter
            if (isMainIgnoreCase(word)) {
                counter++;
                // Skip adding this word if it's the nth palindrome
                if (counter == n) {
                    continue;
                }
            }
            if (result.length() > 0) {
                result.append(", "); // Add a comma if result is not empty
            }
            result.append(word); // Append the word to the result
        }
        return result.toString(); // Return the resulting string
    }

    // Method to find the longest palindromic substring in a given string
    public static String longestMainSubstring(String str) {
        var result = str.substring(0, 1); // Initialize result with the first character
        // Iterate through each character in the string
        for (int i = 0; i < str.length(); i++) {
            // Check all substrings starting from the current character
            for (int j = str.length() - 1; j >= i + result.length() + 1; j--) {
                var currentString = str.substring(i, j); // Get the current substring
                // Update result if the current substring is longer and a palindrome
                if (currentString.length() > result.length() && isMain(currentString)) {
                    result = currentString;
                }
            }
        }
        return result; // Return the longest palindromic substring found
    }

    // Method to check if the characters of a string can form a palindrome
    public static boolean canFormMain(String str) {
        Set<Character> set = new HashSet<>(); // Set to track character occurrences
        // Iterate through each character in the string
        for (var ch : str.toCharArray()) {
            // Add character to set if not present, otherwise remove it
            if (!set.contains(ch)) {
                set.add(ch);
            } else {
                set.remove(ch);
            }
        }
        // A string can form a palindrome if at most one character has an odd count
        return set.size() <= 1;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input
        int option = sc.nextInt(); // Read the user's option
        sc.nextLine(); // Consume the newline character
        switch (option) {
            case 1:
                // Check if a word is a palindrome
                String word = sc.nextLine();
                System.out.println("Is Main: " + isMain(word));
                break;
            case 2:
                // Remove all palindromic words from a string
                String string = sc.nextLine();
                System.out.println("String after removing palindromes: " + removeMains(string));
                break;
            case 3:
                // Remove the nth palindromic word from a string
                String string2 = sc.nextLine();
                int n = sc.nextInt();
                System.out.println("String after removing nth palindrome: " + removeNthMain(string2, n));
                break;
            case 4:
                // Find the longest palindromic substring
                String string3 = sc.nextLine();
                System.out.println("Longest Main Substring: " + longestMainSubstring(string3));
                break;
            case 5:
                // Check if the characters can form a palindrome
                String string4 = sc.nextLine();
                System.out.println("Can form palindrome: " + canFormMain(string4));
                break;
            default:
                // Handle invalid option
                System.out.println("Invalid option");
        }
        sc.close(); // Close the Scanner
    }
}
