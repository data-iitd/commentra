
import java.util.Scanner;

// Flag to enable or disable debugging
boolean debug = false;

// Function to log debug messages
void log(String text) {
    if (debug) {
        System.out.println(text);
    }
}

// Function to parse input from the user or from a string
String[] parse_input(String lines_as_string) {
    boolean debug = false;  // Disable debug mode for standard input
    String[] lines = new String[1];
    
    // Check if input is provided as a string
    if (lines_as_string == null) {
        debug = false;  // Disable debug mode for standard input
        Scanner scanner = new Scanner(System.in);
        lines[0] = scanner.nextLine();  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        lines = lines_as_string.split("\n");
    }
    
    // Extract the first element from the first line as the character to process
    String c = lines[0].split(" ")[0];
    return new String[] { c };
}

// Function to solve the problem by finding the next character in the alphabet
String solve(String c) {
    String a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = a.indexOf(c);  // Find the index of the given character
    return a.substring(i + 1, i + 2);  // Return the next character in the alphabet
}

// Main function to execute the program logic
void main() {
    // Parse input and solve the problem
    String result = solve(parse_input(null)[0]);
    
    // Check if the result is a list and print each result
    if (result.contains("[")) {
        String[] results = result.split("\\[");
        for (String r : results) {
            System.out.println(r.replace("]", ""));
        }
    } else {
        // Print the single result
        System.out.println(result);
    }
}

// Entry point of the program
public static void main(String[] args) {
    new Main().main();
}

