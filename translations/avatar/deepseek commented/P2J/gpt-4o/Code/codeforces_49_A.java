import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to take input
        String a = scanner.nextLine();  // Take an input from the user
        char[] vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};  // Define an array of vowels

        // Iterate over the input string in reverse order
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {  // Check if the current character is a space or a question mark
                continue;  // Continue to the next iteration
            } else {
                boolean isVowel = false;  // Flag to check if the character is a vowel
                for (char v : vo) {  // Check if the current character is a vowel
                    if (a.charAt(i) == v) {
                        isVowel = true;  // Set flag to true if it is a vowel
                        break;  // Break the inner loop
                    }
                }
                if (isVowel) {
                    System.out.println("YES");  // Print "YES" if the character is a vowel
                } else {
                    System.out.println("NO");  // Print "NO" if the character is not a vowel
                }
                break;  // Break the loop after printing the result
            }
        }
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
