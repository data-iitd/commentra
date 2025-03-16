
import java.util.Scanner;

public class codeforces_59_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String txt = scanner.nextLine();
        int cu = 0;  // Counter for uppercase letters
        int cl = 0;  // Counter for lowercase letters

        // Iterate through each character in the input text
        for (int i = 0; i < txt.length(); i++) {
            char z = txt.charAt(i);
            // Check if the character is lowercase
            if (Character.isLowerCase(z)) {
                cl++;  // Increment lowercase counter
            } else {
                cu++;  // Increment uppercase counter
            }
        }

        // Compare the counts of uppercase and lowercase letters
        String out = "";
        if (cu > cl) {
            // If there are more uppercase letters, convert the text to uppercase
            out = txt.toUpperCase();
        } else {
            // If there are more lowercase letters or they are equal, convert the text to lowercase
            out = txt.toLowerCase();
        }

        // Print the resulting output
        System.out.println(out);
    }
}
