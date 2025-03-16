// Import necessary libraries
import java.util.Scanner;

// Define a function to log messages when debug mode is enabled
void log(String text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        System.out.println(text);
    }
}

// Function to parse input lines
String[] parse_input(String lines_as_string) {
    // Set the global debug flag
    debug = true;

    // Split the input string into lines
    String[] lines = lines_as_string.split("\n");

    // Extract the first character from the first line as the command
    String c = lines[0].split(" ")[0];

    // Return the command as a tuple
    return new String[] {c};
}

// Function to solve the problem based on the command
String solve(String c) {
    // Define the alphabet string
    String a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = a.indexOf(c);

    // Return the next character in the alphabet string
    return a.substring(i+1, i+2);
}

// Main function to execute the code
void main() {
    // Call the parse_input function to get the command
    String result = solve(parse_input(new Scanner(System.in).nextLine())[0]);

    // Check if the result is a list or a single string
    if (result.contains(" ")) {
        // If it's a list, print each element separately
        for (String r : result.split(" ")) {
            System.out.println(r);
        }
    } else {
        // If it's a single string, print it directly
        System.out.println(result);
    }
}

// Run the main function if the script is executed directly
if (args.length > 0) {
    main();
}

