import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read a string from the standard input

        int flag = 0; // Initialize a boolean flag

        for (int i = 0; i < s.length(); i++) { // Iterate through each character in the string 's'
            if (i % 2 == 0) { // Check if the current index 'i' is even
                switch (s.charAt(i)) { // Switch statement to check the character at the even index
                    case 'R': // If the character is 'R', do nothing and move to the next character
                    case 'U': // If the character is 'U', do nothing and move to the next character
                    case 'D': // If the character is 'D', do nothing and move to the next character
                        break;
                    default: // If the character is not 'R', 'U', or 'D', set the flag to 1
                        flag = 1;
                        break;
                }
            } else { // If the current index 'i' is odd
                switch (s.charAt(i)) { // Switch statement to check the character at the odd index
                    case 'L': // If the character is 'L', do nothing and move to the next character
                    case 'U': // If the character is 'U', do nothing and move to the next character
                    case 'D': // If the character is 'D', do nothing and move to the next character
                        break;
                    default: // If the character is not 'L', 'U', or 'D', set the flag to 1
                        flag = 1;
                        break;
                }
            }
        }

        if (flag == 0) { // If no invalid character was found during the iteration
            System.out.println("Yes"); // Output "Yes" to the standard output
        } else { // If an invalid character was found during the iteration
            System.out.println("No"); // Output "No" to the standard output
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
