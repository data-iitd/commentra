
import java.util.Scanner;

public class s863302171{
    public static void main(String[] args) {
        // Declare a variable 'n' of type String
        String n;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read a string input from the user using scanner.next()
        n = scanner.next();

        // Initialize a loop counter 'i'
        for (int i = 0; i < 3; i++) {
            // Check if the current character in the string 'n' is equal to '7'
            if (n.charAt(i) == '7') {
                // If yes, print "Yes" and exit the function
                System.out.println("Yes");
                return;
            }
        }

        // If no '7' is found in the first three characters, print "No"
        System.out.println("No");
    }
}

