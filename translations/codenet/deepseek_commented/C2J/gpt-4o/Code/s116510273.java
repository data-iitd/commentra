import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String mes = scanner.next(); // Read a string input from the user

        // Calculate the length of the string excluding the first and last character
        int length = mes.length() - 2;

        // Print the first character, the calculated length, and the last character of the string
        System.out.printf("%c%d%c%n", mes.charAt(0), length, mes.charAt(mes.length() - 1));

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
