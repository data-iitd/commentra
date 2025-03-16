import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Approach 1: Sorting the characters of both strings and comparing them.
    public static boolean approach1(String s, String t) {
        if (s.length() != t.length()) { // Check if lengths are different
            return false;
        }
        char[] c = s.toCharArray(); // Convert s to char array
        char[] d = t.toCharArray(); // Convert t to char array
        Arrays.sort(c); // Sort the char array c
        Arrays.sort(d); // Sort the char array d
        return Arrays.equals(c, d); // Compare sorted arrays
    }

    // Approach 2: Using a frequency array to count the characters in both strings and comparing the counts.
    public static boolean approach2(String s, String t) {
        if (s.length() != t.length()) { // Check if lengths are different
            return false;
        }
        int[] charCount = new int[26]; // Frequency array for characters
        for (int i = 0; i < s.length(); i++) { // Iterate through the strings
            charCount[s.charAt(i) - 'a']++; // Increment count for character in s
            charCount[t.charAt(i) - 'a']--; // Decrement count for character in t
        }
        for (int count : charCount) { // Check if all counts are zero
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Approach 3: Similar to approach 2 but using a different variable name.
    public static boolean approach3(String s, String t) {
        if (s.length() != t.length()) { // Check if lengths are different
            return false;
        }
        int[] charCount = new int[26]; // Frequency array for characters
        for (int i = 0; i < s.length(); i++) { // Iterate through the strings
            charCount[s.charAt(i) - 'a']++; // Increment count for character in s
            charCount[t.charAt(i) - 'a']--; // Decrement count for character in t
        }
        for (int count : charCount) { // Check if all counts are zero
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Approach 4: Using a HashMap to count the characters in one string and decrementing the counts while checking the second string.
    public static boolean approach4(String s, String t) {
        if (s.length() != t.length()) { // Check if lengths are different
            return false;
        }
        HashMap<Character, Integer> charCountMap = new HashMap<>(); // HashMap to count characters
        for (char c : s.toCharArray()) { // Count characters in s
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }
        for (char c : t.toCharArray()) { // Check characters in t
            if (!charCountMap.containsKey(c) || charCountMap.get(c) == 0) {
                return false;
            }
            charCountMap.put(c, charCountMap.get(c) - 1); // Decrement count
        }
        return charCountMap.values().stream().allMatch(count -> count == 0); // Check if all counts are zero
    }

    // Approach 5: Similar to approach 2 but using a different variable name.
    public static boolean approach5(String s, String t) {
        if (s.length() != t.length()) { // Check if lengths are different
            return false;
        }
        int[] freq = new int[26]; // Frequency array for characters
        for (int i = 0; i < s.length(); i++) { // Iterate through the strings
            freq[s.charAt(i) - 'a']++; // Increment count for character in s
            freq[t.charAt(i) - 'a']--; // Decrement count for character in t
        }
        for (int count : freq) { // Check if all counts are zero
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    // Main method to take input and call the appropriate approach based on user input.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        int approach = scanner.nextInt();
        boolean result;
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
                System.out.println("Invalid approach number.");
                scanner.close();
                return;
        }
        System.out.println("Are the strings anagrams? " + result);
        scanner.close();
    }
}
