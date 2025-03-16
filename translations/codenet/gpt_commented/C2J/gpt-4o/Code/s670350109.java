import java.util.Scanner;

public class AnagramChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare character arrays to hold two strings
        String str1, str2;

        // Read two strings from user input
        str1 = scanner.nextLine();
        str2 = scanner.nextLine();

        // Get the length of the first string
        int i = str1.length();
        int t = i - 1;

        // Check if the lengths of the two strings are different
        if (str1.length() != str2.length()) {
            // If lengths are different, they cannot be anagrams
            System.out.println("NO");
        } else {
            // Reverse the first string
            StringBuilder temp = new StringBuilder();
            while (t >= 0) {
                temp.append(str1.charAt(t)); // Append characters from the end of str1 to temp
                t--;
            }

            // Compare the reversed string with the second string
            if (temp.toString().equals(str2)) {
                // If all characters match, the strings are anagrams
                System.out.println("YES");
            } else {
                // If not all characters match, they are not anagrams
                System.out.println("NO");
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
