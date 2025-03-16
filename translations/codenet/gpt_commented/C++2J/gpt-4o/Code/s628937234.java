import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        String s = scanner.next(); // Read a string input from the user and store it in s
        String t; // Declare a string t for the output format

        // Construct the abbreviated version of the string
        t = s.charAt(0) + Integer.toString(s.length() - 2) + s.charAt(s.length() - 1); // Create the abbreviated string

        System.out.println(t); // Output the abbreviated string

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
