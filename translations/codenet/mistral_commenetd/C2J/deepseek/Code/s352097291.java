import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String c = scanner.next(); // Read a string from the standard input and store it in the 'c' variable
        StringBuilder ans = new StringBuilder(); // An array to store the output string

        // Process the string
        for (int i = 0; i < c.length(); i++) { // Iterate through each character in the string 'c'
            char ch = c.charAt(i); // Get the current character
            if (ch != 'B') { // If the current character is not 'B'
                ans.append(ch); // Append the character to the output string 'ans'
            } else { // If the current character is 'B'
                if (ans.length() > 0) { // Check if the output string is not empty
                    ans.deleteCharAt(ans.length() - 1); // Remove the last character from the output string 'ans'
                }
            }
        }

        // Print the output
        System.out.println(ans.toString()); // Print the final output string
    }
}
