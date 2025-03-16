import java.util.Scanner; // Import Scanner for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String buf = scanner.nextLine(); // Read input from stdin

        // Step 4: Calculate the length of the input
        int len = buf.length();

        // Step 5: Print the first character, the length minus 3, and the second last character of the input
        System.out.printf("%c%d%c%n", buf.charAt(0), len - 3, buf.charAt(len - 2));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
