import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read a line of input from the user
        String s = sc.nextLine();
        
        // Get the length of the input string
        int length = s.length();
        
        // Initialize a character variable to store the last non-space, non-question mark character
        char ch = 0;
        
        // Loop through the string in reverse to find the last relevant character
        for (int i = length - 1; i >= 0; i--) {
            // Check if the current character is not a space or a question mark
            if (s.charAt(i) != ' ' && s.charAt(i) != '?') {
                ch = s.charAt(i); // Store the character
                break; // Exit the loop once the character is found
            }
        }
        
        // Convert the character to lowercase for uniform comparison
        ch = Character.toLowerCase(ch);
        
        // Check if the character is a vowel or 'y'
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
            System.out.println("YES"); // Print "YES" if it is a vowel
        } else {
            System.out.println("NO"); // Print "NO" if it is not a vowel
        }
    }
}

