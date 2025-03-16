
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {

        // Create a Scanner object to read input from stdin
        Scanner scan = new Scanner(System.in);

        // Read the first line of input from stdin and save it to our variable, input_string
        String input_string = scan.nextLine();

        // Close the scanner object, because we've finished reading input
        scan.close();

        // Print a string literal saying "Hello, World." to stdout
        System.out.println("Hello, World.");

        // Print the input_string to stdout
        System.out.println(input_string);

        // END-OF-CODE
    }
}
