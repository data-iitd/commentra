import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Ask the user for a string input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty string variable to store the binary string
        StringBuilder myStr = new StringBuilder();

        // Iterate through each character in the user input string
        for (char c : s.toCharArray()) {
            // If the character is '0' or '1', append it to the binary string
            if (c == '0' || c == '1') {
                myStr.append(c);
            }
            // If the character is 'B', remove the last character from the binary string before 'B' was encountered
            else if (c == 'B' && myStr.length() != 0) {
                myStr.deleteCharAt(myStr.length() - 1);
            }
        }

        // Print the final binary string
        System.out.println(myStr.toString());
    }
}
// <END-OF-CODE>
