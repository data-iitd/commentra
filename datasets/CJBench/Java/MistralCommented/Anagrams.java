
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Private constructor to prevent instantiation of the class from outside

    public static boolean approach1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        // Convert both strings to character arrays for sorting
        char[] c = s.toCharArray();
        char[] d = t.toCharArray();

        // Sort both character arrays using Arrays.sort() method
        Arrays.sort(c);
        Arrays.sort(d);

        // Compare both sorted character arrays using Arrays.equals() method
        return Arrays.equals(c, d);
    }

    public static boolean approach2(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] charCount = new int[26]; // Initialize an integer array of size 26 to store character counts

        // Iterate through each character in string s and update its corresponding count in charCount array
        for (int i = 0; i < s.length(); i++) {
            charCount[s.charAt(i) - 'a']++;
            charCount[t.charAt(i) - 'a']--; // Decrement the count of corresponding character in string t
        }

        // Iterate through each count in charCount array and check if any count is not zero, if yes return false
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }

        // If all counts are zero, then both strings are anagrams
        return true;
    }

    public static boolean approach3(String s, String t) {
        // Same as approach2 but using HashMap instead of integer array
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character, Integer> charCountMap = new HashMap<>(); // Initialize an empty HashMap to store character counts

        // Iterate through each character in string s and update its count in HashMap
        for (char c : s.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }

        // Iterate through each character in string t and check if its count is zero in HashMap, if not return false
        for (char c : t.toCharArray()) {
            if (!charCountMap.containsKey(c) || charCountMap.get(c) == 0) {
                return false;
            }
            charCountMap.put(c, charCountMap.get(c) - 1); // Decrement the count of corresponding character in HashMap
        }

        // If all counts in HashMap are zero, then both strings are anagrams
        return charCountMap.values().stream().allMatch(count -> count == 0);
    }

    public static boolean approach4(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] freq = new int[26]; // Initialize an integer array of size 26 to store character frequencies

        // Iterate through each character in string s and increment its corresponding frequency in freq array
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--; // Decrement the frequency of corresponding character in string t
        }

        // Iterate through each frequency in freq array and check if any frequency is not zero, if yes return false
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        // If all frequencies are zero, then both strings are anagrams
        return true;
    }

    public static boolean approach5(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        // Similar to approach4 but using HashMap instead of integer array
        int[] freq = new int[26];

        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        String s = scanner.nextLine(); // Read the first string from the console
        String t = scanner.nextLine(); // Read the second string from the console
        int approach = scanner.nextInt(); // Read the approach number from the console

        boolean result; // Initialize a boolean variable to store the result of the comparison

        switch (approach) { // Switch statement to call the appropriate approach based on the input approach number
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
                System.out.println("Invalid approach number."); // Print an error message if the approach number is invalid
                scanner.close(); // Close the Scanner object
                return;
        }

        System.out.println("Are the strings anagrams? " + result); // Print the result of the comparison to the console

        scanner.close(); // Close the Scanner object
    }
}

