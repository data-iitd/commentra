
import java.util.Scanner; // Import the Scanner class for input

public class s628937234{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user

        String s = scanner.nextLine(); // Read a string input from the user and store it in s

        // Construct the abbreviated version of the string
        String t = s.substring(0, 1); // Start with the first character of the input string
        t += String.valueOf(s.length() - 2); // Append the number of characters between the first and last characters
        t += s.substring(s.length() - 1); // Append the last character of the input string

        System.out.println(t); // Output the abbreviated string

        scanner.close(); // Close the Scanner object to release system resources
    }
}
