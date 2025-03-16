
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    // Method to check if a given word is a main word (palindrome)
    public static boolean isMain(String word) {
        // Check if word is null, return false if it is
        if (word == null) {
            return false;
        }
        
        // If ignoreCase flag is true, convert word to lowercase
        if (ignoreCase) {
            word = word.toLowerCase();
        }
        
        // Check if the first half of the word is equal to the second half
        for (int i = 0; i < word.length() / 2; i++) {
            // Compare corresponding characters of the first and last halves
            if (word.charAt(i) != word.charAt(word.length() - 1 - i)) {
                // If they are not equal, return false
                return false;
            }
        }
        
        // If all checks pass, return true
        return true;
    }
    
    // Method to check if a given word is a main word (palindrome) ignoring case
    public static boolean isMainIgnoreCase(String word) {
        // Call isMain method with ignoreCase flag set to true
        return isMain(word, true);
    }
    
    // Method to remove all main words (palindromes) from a given string
    private static String removeMains(String string) {
        // Initialize an empty StringBuilder to store the result
        StringBuilder result = new StringBuilder();
        
        // Split the string into words using a regular expression
        String[] words = string.split(",?\\s+");
        
        // Iterate through each word
        for (String word : words) {
            // If the word is not a main word, add it to the result StringBuilder
            if (!isMainIgnoreCase(word)) {
                // Add a comma and a space before the word, if it's not the first one
                if (result.length() > 0) {
                    result.append(", ");
                }
                // Append the word to the result StringBuilder
                result.append(word);
            }
        }
        
        // Return the result as a String
        return result.toString();
    }
    
    // Method to remove the nth main word (palindrome) from a given string
    public static String removeNthMain(String string, int n) {
        // Initialize an empty StringBuilder to store the result
        StringBuilder result = new StringBuilder();
        
        // Split the string into words using a regular expression
        String[] words = string.split(",?\\s+");
        
        // Initialize a counter variable
        int counter = 0;
        
        // Iterate through each word
        for (String word : words) {
            // If the word is a main word, increment the counter
            if (isMainIgnoreCase(word)) {
                counter++;
                
                // If the counter equals the given n, skip this word and continue with the next one
                if (counter == n) {
                    continue;
                }
            }
            
            // Add a comma and a space before the word, if it's not the first one
            if (result.length() > 0) {
                result.append(", ");
            }
            
            // Append the word to the result StringBuilder
            result.append(word);
        }
        
        // Return the result as a String
        return result.toString();
    }
    
    // Method to find the longest main substring (palindrome) in a given string
    public static String longestMainSubstring(String str) {
        // Initialize an empty String to store the current result
        var result = str.substring(0, 1);
        
        // Iterate through each substring of the given string, starting from a length of 1
        for (int i = 0; i < str.length(); i++) {
            for (int j = str.length() - 1; j >= i + result.length() + 1; j--) {
                // Get the current substring
                var currentString = str.substring(i, j);
                
                // Check if the current substring is a main word (palindrome) and longer than the current result
                if (currentString.length() > result.length() && isMain(currentString)) {
                    // Update the result if the current substring is longer
                    result = currentString;
                }
            }
        }
        
        // Return the result as a String
        return result;
    }
    
    // Method to check if a given string can form a main word (palindrome)
    public static boolean canFormMain(String str) {
        // Initialize an empty HashSet to store unique characters
        Set<Character> set = new HashSet<>();
        
        // Iterate through each character in the given string
        for (var ch : str.toCharArray()) {
            // Add the character to the HashSet, removing it if it's already present
            if (!set.contains(ch)) {
                set.add(ch);
            } else {
                set.remove(ch);
            }
        }
        
        // Return true if the HashSet contains only one character, false otherwise
        return set.size() <= 1;
    }
    
    // Main method to read user input and call the appropriate methods based on the given option
    public static void main(String[] args) {
        // Initialize a Scanner object to read user input
        Scanner sc = new Scanner(System.in);
        
        // Read the user's option
        int option = sc.nextInt();
        
        // Read the user's input for option 2, 3, and 4
        sc.nextLine();
        
        // Switch on the user's option and call the appropriate method
        switch (option) {
            case 1:
                // Read a word from the user and print whether it's a main word or not
                String word = sc.nextLine();
                System.out.println("Is Main: " + isMain(word));
                break;
            case 2:
                // Read a string from the user and print the string after removing all main words
                String string = sc.nextLine();
                System.out.println("String after removing palindromes: " + removeMains(string));
                break;
            case 3:
                // Read a string and an integer from the user and print the string after removing the nth main word
                String string2 = sc.nextLine();
                int n = sc.nextInt();
                System.out.println("String after removing nth palindrome: " + removeNthMain(string2, n));
                break;
            case 4:
                // Read a string from the user and print the longest main substring (palindrome)
                String string3 = sc.nextLine();
                System.out.println("Longest Main Substring: " + longestMainSubstring(string3));
                break;
            case 5:
                // Read a string from the user and print whether it can form a main word (palindrome) or not
                String string4 = sc.nextLine();
                System.out.println("Can form palindrome: " + canFormMain(string4));
                break;
            default:
                // Print an error message if the user enters an invalid option
                System.out.println("Invalid option");
        }
        
        // Close the Scanner object
        sc.close();
    }
}