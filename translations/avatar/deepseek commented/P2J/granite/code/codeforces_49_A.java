

import java.util.Scanner;  // Import the Scanner class from the java.util package

public class codeforces_49_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input from the user
        String a = scanner.nextLine();  // Read a string input from the user
        String[] vo = {"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"};  // Define an array of vowels

        // Iterate over the input string in reverse order
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a.charAt(i) =='' || a.charAt(i) == '?') {  // Check if the current character is a space or a question mark
                continue;  // Continue to the next iteration
            } else {
                if (contains(vo, String.valueOf(a.charAt(i)))) {  // Check if the current character is a vowel
                    System.out.println("YES");  // Print "YES" if the character is a vowel
                } else {
                    System.out.println("NO");  // Print "NO" if the character is not a vowel and break the loop
                }
                break;  // Break the loop after printing the result
            }
        }
    }

    public static boolean contains(String[] arr, String str) {  // Method to check if an array contains a specific string
        for (String s : arr) {
            if (s.equals(str)) {
                return true;  // Return true if the array contains the string
            }
        }
        return false;  // Return false if the array does not contain the string
    }
}

