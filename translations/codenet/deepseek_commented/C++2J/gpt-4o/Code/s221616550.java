import java.util.Scanner;

public class PalindromeChecker {
    // Function to check if a string is a palindrome
    public static boolean isPalindrome(String s) {
        // Loop through the first half of the string
        for (int i = 0; i < s.length() / 2; i++) {
            // Compare characters from the start and end of the string
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                // If any characters do not match, return false
                return false;
            }
        }
        // If all characters match, return true
        return true;
    }

    public static void main(String[] args) {
        // Declare a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);
        // Read the input string from the user
        String s = scanner.nextLine();
        // Check if the entire string and its first half are palindromes
        if (isPalindrome(s) && isPalindrome(s.substring(0, s.length() / 2))) {
            // Print "Yes" if both conditions are true
            System.out.println("Yes");
        } else {
            // Print "No" if either condition is false
            System.out.println("No");
        }
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
