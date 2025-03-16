import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty string to store the resulting characters
        StringBuilder myStr = new StringBuilder();

        // Iterate through each character in the input string
        for (char c : s.toCharArray()) {
            // Check if the character is '0' or '1'
            if (c == '0' || c == '1') {
                // If it is, append it to the result string
                myStr.append(c);
            }
            // Check if the character is 'B' and the result string is not empty
            else if (c == 'B' && myStr.length() != 0) {
                // If it is, remove the last character from the result string
                myStr.deleteCharAt(myStr.length() - 1);
            }
        }

        // Print the final result string
        System.out.println(myStr.toString());
    }
}
// <END-OF-CODE>
