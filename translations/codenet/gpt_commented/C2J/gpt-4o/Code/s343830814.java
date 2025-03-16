import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a buffer to hold the input string
        String buf;

        // Read a line of input from standard input (stdin) into the buffer
        Scanner scanner = new Scanner(System.in);
        buf = scanner.nextLine();

        // Calculate the length of the input string
        int len = buf.length();

        // Print the first character, the length of the string minus 3, and the second to last character
        System.out.printf("%c%d%c%n", buf.charAt(0), len - 3, buf.charAt(len - 2));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
