import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize input scanner

        String z = scanner.next(); // Read input string
        int a = z.length(); // Assign size of the string to variable 'a'

        // Check if there are any consecutive identical characters in the string
        for (int i = 0; i < a - 1; i++) {
            // Check if current character is same as next character
            if (z.charAt(i) == z.charAt(i + 1)) {
                // If yes, print "Bad" and exit the program
                System.out.println("Bad");
                return; // Exit the program
            }
        }
        // If no consecutive identical characters are found, print "Good"
        System.out.println("Good");
    }
}
// <END-OF-CODE>
