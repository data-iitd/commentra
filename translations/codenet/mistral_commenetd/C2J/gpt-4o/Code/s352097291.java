import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        StringBuilder ans = new StringBuilder(); // A StringBuilder to store the output string
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Read a string from the standard input
        String c = scanner.next(); // Read a string and store it in 'c'

        // Process the string
        for (int i = 0; i < c.length(); i++) { // Iterate through each character in the string 'c'
            char currentChar = c.charAt(i); // Get the current character
            if (currentChar != 'B') { // If the current character is not 'B'
                ans.append(currentChar); // Append the character to the output string 'ans'
            } else { // If the current character is 'B'
                if (ans.length() > 0) { // Check if there is at least one character to remove
                    ans.deleteCharAt(ans.length() - 1); // Remove the last character from the output string 'ans'
                }
            }
        }

        // Print the output
        System.out.println(ans.toString()); // Print the final output string
    }
}

// <END-OF-CODE>
