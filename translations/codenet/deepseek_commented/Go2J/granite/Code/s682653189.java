
import java.util.Scanner;

public class s682653189{
    public static void main(String[] args) {
        // Declare a string variable to store the input
        String s;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read a string input from the user and store it in `s`
        s = scanner.nextLine();

        // Iterate over each character in the string `s` and print 'x' for each character
        for (int i = 0; i < s.length(); i++) {
            System.out.print("x");
        }

        // Print a newline character to move to the next line
        System.out.println("");
    }
}
