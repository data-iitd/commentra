
import java.util.Scanner;

public class s116510273{
    public static void main(String[] args) {
        // Declare a character array to hold the input string with a maximum length of 100 characters
        char mes[] = new char[101];

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read a string from standard input and store it in the'mes' array
        scanner.nextLine().getChars(0, 100, mes, 0);

        // Print the first character of the string, the length of the string minus 2, and the last character of the string
        System.out.printf("%c%d%c\n", mes[0], mes.length - 2, mes[mes.length - 1]);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
