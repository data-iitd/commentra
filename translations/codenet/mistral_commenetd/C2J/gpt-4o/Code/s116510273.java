import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String mes = scanner.next(); // Read a string from the standard input

        // Logic starts here
        System.out.printf("%c%d%c%n", mes.charAt(0), mes.length() - 2, mes.charAt(mes.length() - 1)); // Print the first character, length - 2 and last character of the input string

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
