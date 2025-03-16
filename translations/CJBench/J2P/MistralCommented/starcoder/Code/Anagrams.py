
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Private constructor to prevent instantiation of the class from outside

    public static boolean approach1(String s, String t) {
        if (s.length()!= t.length()) {
            return false;
        }
        # Convert both strings to character arrays for sorting
        c = s.toCharArray()
        d = t.toCharArray()

        # Sort both character arrays using Arrays.sort() method
        Arrays.sort(c)
        Arrays.sort(d)

        # Compare both sorted character arrays using Arrays.equals() method
        return Arrays.equals(c, d);
    }

    public static boolean approach2(String s, String t) {
        if (s.length()!= t.length()) {
            return false;
        }
        charCount = [0] * 26 # Initialize an integer array of size 26 to store character counts

        # Iterate through each character in string s and update its corresponding count in charCount array
        for i in range(s.length()):
            charCount[s.charAt(i) - 'a'] += 1
            charCount[t.charAt(i) - 'a'] -= 1 # Decrement the count of corresponding character in string t
        # Iterate through each count in charCount array and check if any count is not zero, if yes return false
        for count in charCount:
            if count!= 0:
                return false
        # If all counts are zero, then both strings are anagrams
        return true
    }

    public static boolean approach3(String s, String t) {
        # Same as approach2 but using HashMap instead of integer array
        if (s.length()!= t.length()) {
            return false;
        }
        charCountMap = {} # Initialize an empty HashMap to store character counts

        # Iterate through each character in string s and update its count in HashMap
        for c in s:
            charCountMap[c] = charCountMap.get(c, 0) + 1

        # Iterate through each character in string t and check if its count is zero in HashMap, if not return false
        for c in t:
            if c not in charCountMap or charCountMap[c] == 0:
                return false
            charCountMap[c] -= 1 # Decrement the count of corresponding character in HashMap
        # If all counts in HashMap are zero, then both strings are anagrams
        return all(count == 0 for count in charCountMap.values())
    }

    public static boolean approach4(String s, String t) {
        if (s.length()!= t.length()) {
            return false;
        }
        freq = [0] * 26 # Initialize an integer array of size 26 to store character frequencies

        # Iterate through each character in string s and increment its corresponding frequency in freq array
        for i in range(s.length()):
            freq[s.charAt(i) - 'a'] += 1
            freq[t.charAt(i) - 'a'] -= 1 # Decrement the frequency of corresponding character in string t
        # Iterate through each frequency in freq array and check if any frequency is not zero, if yes return false
        for count in freq:
            if count!= 0:
                return false
        # If all frequencies are zero, then both strings are anagrams
        return true
    }

    public static boolean approach5(String s, String t) {
        if (s.length()!= t.length()) {
            return false;
        }
        # Similar to approach4 but using HashMap instead of integer array
        freq = [0] * 26

        for i in range(s.length()):
            freq[s.charAt(i) - 'a'] += 1
            freq[t.charAt(i) - 'a'] -= 1
        for count in freq:
            if count!= 0:
                return false
        return true
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in) # Create a Scanner object to read input from the console

        s = scanner.nextLine() # Read the first string from the console
        t = scanner.nextLine() # Read the second string from the console
        approach = scanner.nextInt() # Read the approach number from the console

        result = None # Initialize a boolean variable to store the result of the comparison

        switch approach: # Switch statement to call the appropriate approach based on the input approach number
            case 1:
                result = approach1(s, t)
                break
            case 2:
                result = approach2(s, t)
                break
            case 3:
                result = approach3(s, t)
                break
            case 4:
                result = approach4(s, t)
                break
            case 5:
                result = approach5(s, t)
                break
            default:
                print("Invalid approach number.") # Print an error message if the approach number is invalid
                scanner.close() # Close the Scanner object
                return
        print("Are the strings anagrams? " + result) # Print the result of the comparison to the console

        scanner.close() # Close the Scanner object
    }
}

