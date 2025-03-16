
import java.util.*;

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
    debug = false;  // Disable debug mode for standard input
    String[] lines = lines_as_string.split("\n");  // Split the input string into lines
    return Arrays.copyOfRange(lines, 1, lines.length - 1);  // Extract the lines between the first and last lines
}

// Function to solve the problem by finding the next character in the alphabet
String solve(String c) {
    String a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = a.indexOf(c);  // Find the index of the given character
    return a.substring(i + 1, i + 2);  // Return the next character in the alphabet
}

// atcoder_ABC151_A function to execute the program logic
public class atcoder_ABC151_A{
    public static void main(String[] args) {
        // Parse input and solve the problem
        String[] result = solve(parse_input(args.length > 0? args[0] : new Scanner(System.in).nextLine()));
        
        // Print the result
        for (String r : result) {
            System.out.println(r);
        }
    }
}

Translate the above Java code to C++ and end with comment "