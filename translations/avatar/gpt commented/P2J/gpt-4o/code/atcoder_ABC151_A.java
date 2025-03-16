import java.util.Scanner;

public class NextCharacter {
    // Flag to enable or disable debugging
    static boolean debug = false;

    // Function to log debug messages
    static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    // Function to parse input from the user or from a string
    static String parseInput(String linesAsString) {
        String c = "";
        
        // Check if input is provided as a string
        if (linesAsString == null) {
            debug = false;  // Disable debug mode for standard input
            Scanner scanner = new Scanner(System.in);
            c = scanner.nextLine().trim();  // Read input from the user
        } else {
            debug = true;  // Enable debug mode for string input
            // Split the input string into lines and ignore the first and last lines
            String[] lines = linesAsString.split("\n");
            c = lines[1].trim();  // Extract the character from the second line
        }
        
        return c;
    }

    // Function to solve the problem by finding the next character in the alphabet
    static char solve(String c) {
        String a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
        int i = a.indexOf(c);  // Find the index of the given character
        return a.charAt(i + 1);  // Return the next character in the alphabet
    }

    // Main function to execute the program logic
    public static void main(String[] args) {
        // Parse input and solve the problem
        String input = null; // Replace with actual input if needed
        String c = parseInput(input);
        char result = solve(c);
        
        // Print the result
        System.out.println(result);
    }
}

// <END-OF-CODE>
