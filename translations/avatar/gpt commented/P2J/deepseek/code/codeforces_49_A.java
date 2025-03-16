import java.util.Scanner;

public class VowelCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();

        // Define a string of vowels (both lowercase and uppercase)
        String vo = "aeiouyAEIOUY";

        // Iterate through the input string in reverse order
        for (int i = a.length() - 1; i >= 0; i--) {
            // Check if the current character is a space or a question mark
            if (a.charAt(i) == ' ' || a.charAt(i) == '?') {
                continue; // Skip to the next iteration if it is a space or '?'
            } else {
                // Check if the current character is a vowel
                if (vo.indexOf(a.charAt(i)) != -1) {
                    System.out.println("YES"); // Print "YES" if it is a vowel
                } else {
                    System.out.println("NO");  // Print "NO" if it is not a vowel
                }
                break; // Exit the loop after processing the first non-space character
            }
        }
    }
}
