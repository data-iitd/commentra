// Import necessary modules
import java.util.Scanner;

public class Main {
    // Define a debug flag
    static boolean debug = false;

    // Define a method to log messages when debug mode is enabled
    static void log(String text) {
        // Check if debug mode is enabled
        if (debug) {
            // Print the log message
            System.out.println(text);
        }
    }

    // Method to parse input lines
    static String[] parseInput(String linesAsString) {
        // Set the global debug flag
        debug = true;

        // Split the input string into lines
        String[] lines = linesAsString.split("\n");

        // Extract the first character from the first line as the command
        String command = lines[1].split(" ")[0];

        // Return the command as an array
        return new String[]{command};
    }

    // Method to solve the problem based on the command
    static String solve(String c) {
        // Define the alphabet string
        String a = "abcdefghijklmnopqrstuvwxyz";

        // Find the index of the command character in the alphabet string
        int i = a.indexOf(c);

        // Return the next character in the alphabet string
        return String.valueOf(a.charAt(i + 1));
    }

    // Main method to execute the code
    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input as a single string
        String input = scanner.useDelimiter("\\A").next();
        
        // Call the parseInput method to get the command
        String result = solve(parseInput(input)[0]);

        // Print the result
        System.out.println(result);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
