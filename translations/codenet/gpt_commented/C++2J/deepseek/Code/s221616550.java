public class PalindromeChecker {
    // Function to check if a given string is a palindrome
    public static boolean isPalindrome(String s) {
        // Loop through the first half of the string
        for (int i = 0; i < s.length() / 2; i++) {
            // Compare characters from the start and end of the string
            if (s.charAt(i) == s.charAt(s.length() - 1 - i))
                continue; // If they match, continue to the next iteration
            else
                return false; // If they don't match, return false
        }
        return true; // If all characters matched, return true
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine(); // Read input from the user

        // Check if the entire string is a palindrome and if the first half is also a palindrome
        if (isPalindrome(s) && isPalindrome(s.substring(0, s.length() / 2))) {
            System.out.println("Yes"); // Output "Yes" if both conditions are true
        } else {
            System.out.println("No"); // Output "No" if either condition is false
        }
    }
}
