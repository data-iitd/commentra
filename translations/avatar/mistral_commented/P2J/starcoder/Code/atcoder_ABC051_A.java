
// Import the Scanner class from the java.util package
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // Create a Scanner object
        Scanner input = new Scanner(System.in);

        // Read a line from input
        String input_string = input.nextLine();

        // Replace all commas with spaces in the input string
        String modified_string = input_string.replace(",", " ");

        // Print the modified string to the console
        System.out.println(modified_string);

    }

}
