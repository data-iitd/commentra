// Import necessary modules
import java.util.Scanner;

// Define a function to log messages when debug mode is enabled
public static void log(String text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        System.out.println(text);
    }
}

// Function to parse input lines
public static String[] parse_input(String lines_as_string) {
    // Set the global debug flag
    global debug

    // Initialize an empty list to store the lines
    String[] lines = new String[0];

    // If lines_as_string is provided, set debug mode to True and parse lines
    if (lines_as_string!= null) {
        debug = true;
        lines = lines_as_string.split("\n");
    }

    // Extract the first character from the first line as the command
    String c = lines[0].split(" ")[0];

    // Return the command as a tuple
    return (c,);
}

// Function to solve the problem based on the command
public static String solve(String c) {
    // Define the alphabet string
    String a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = a.indexOf(c);

    // Return the next character in the alphabet string
    return a.substring(i+1, i+2);
}

// Main function to execute the code
public static void main(String[] args) {
    // Call the parse_input function to get the command
    String[] result = solve(*parse_input());

    // Check if the result is a list or a single string
    if (result instanceof List) {
        // If it's a list, print each element separately
        for (String r : result) {
            System.out.println(r);
        }
    } else {
        // If it's a single string, print it directly
        System.out.println(result);
    }
}

