public class Main {
    // Define a static boolean flag to enable debug mode
    static boolean debug = false;

    // Main method to execute the code
    public static void main(String[] args) {
        // Call the parseInput method to get the command
        String result = solve(parseInput());

        // Print the result
        System.out.println(result);
    }

    // Function to log messages when debug mode is enabled
    static void log(String text) {
        // Check if debug mode is enabled
        if (debug) {
            // Print the log message
            System.out.println(text);
        }
    }

    // Function to parse input lines
    static String parseInput() {
        // Initialize an empty string to store the input
        String input = "";

        // Read the input from stdin
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        if (scanner.hasNextLine()) {
            input = scanner.nextLine();
        }

        // Set the debug flag to true
        debug = true;

        // Return the input string
        return input;
    }

    // Function to solve the problem based on the command
    static String solve(String c) {
        // Define the alphabet string
        String a = "abcdefghijklmnopqrstuvwxyz";

        // Find the index of the command character in the alphabet string
        int i = a.indexOf(c);

        // Return the next character in the alphabet string
        return String.valueOf(a.charAt(i + 1));
    }
}
