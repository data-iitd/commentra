import java.util.Scanner;

public class Main {
    // Flag to enable or disable debugging
    private static boolean debug = false;

    // Function to log debug messages
    private static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    // Function to parse input from the user or from a string
    private static String[] parseInput(String linesAsString) {
        String[] lines = linesAsString.split("\n");
        // Extract the first element from the first line as the character to process
        String[] parts = lines[0].split(" ");
        return new String[]{parts[0]};
    }

    // Function to solve the problem by finding the next character in the alphabet
    private static char solve(String c) {
        String a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
        int i = a.indexOf(c);  // Find the index of the given character
        return a.charAt(i + 1);  // Return the next character in the alphabet
    }

    // Main function to execute the program logic
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();

        // Parse input and solve the problem
        String[] result = parseInput(input);
        char output = solve(result[0]);

        // Print the single result
        System.out.println(output);
    }
}
