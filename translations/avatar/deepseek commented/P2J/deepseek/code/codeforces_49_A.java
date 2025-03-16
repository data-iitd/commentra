import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();  // Take an input from the user
        char[] vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};  // Define a list of vowels

        // Iterate over the input string in reverse order
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {  // Check if the current character is a space or a question mark
                continue;  // Continue to the next iteration
            } else {
                boolean isVowel = false;  // Initialize a boolean variable to check if the character is a vowel
                for (char c : vo) {  // Iterate over the list of vowels
                    if (a.charAt(i) == c) {  // Check if the current character is a vowel
                        isVowel = true;  // Set the boolean variable to true if the character is a vowel
                        break;  // Break the loop after finding the vowel
                    }
                }
                if (isVowel) {  // Check if the character is a vowel
                    System.out.println("YES");  // Print "YES" if the character is a vowel
                } else {
                    System.out.println("NO");  // Print "NO" if the character is not a vowel
                }
                break;  // Break the loop after printing the result
            }
        }
    }
}
