import java.util.Scanner;

public class Main {
    static boolean debug = false;

    // Function to log debug messages
    static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    // Function to parse input from either user input or a string
    static String parseInput(String linesAsString) {
        String c = "";
        if (linesAsString == null) {
            debug = false;
            Scanner scanner = new Scanner(System.in);
            c = scanner.nextLine();
        } else {
            debug = true;
            String[] lines = linesAsString.split("\n");
            c = lines[1].trim(); // Assuming the first line is not needed
        }
        return c;
    }

    // Function to solve the problem by finding the next character in the alphabet
    static char solve(String c) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        int i = a.indexOf(c);
        return a.charAt(i + 1);
    }

    // Main function to orchestrate the execution of the program
    public static void main(String[] args) {
        String input = parseInput(null); // Change null to a string for testing
        char result = solve(input);
        System.out.print(result);
    }
}

// <END-OF-CODE>
