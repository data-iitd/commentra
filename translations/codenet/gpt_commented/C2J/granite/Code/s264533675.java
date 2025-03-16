
import java.util.Scanner;

public class s264533675{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read a line of input from the user and store it in the str variable
        String str = scanner.nextLine();

        // Replace the character at index 5 with a space
        str = str.substring(0, 5) + " " + str.substring(6);

        // Replace the character at index 13 with a space
        str = str.substring(0, 13) + " " + str.substring(14);

        // Print the modified string to the console
        System.out.println(str);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
