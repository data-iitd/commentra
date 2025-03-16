
import java.io.OutputStream; import java.io.IOException; import java.io.InputStream; import java.io.PrintWriter; import java.util.Scanner;

// Import statements: These are importing necessary classes from Java's standard libraries.

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Setting up the input stream to read from the console.
        OutputStream outputStream = System.out; // Setting up the output stream to write to the console.
        Scanner in = new Scanner(inputStream); // Creating a Scanner object to read input from the console.
        PrintWriter out = new PrintWriter(outputStream); // Creating a PrintWriter object to write output to the console.
        AStationAndBus solver = new AStationAndBus(); // Creating an instance of the AStationAndBus class.
        solver.solve(1, in, out); // Calling the solve method to execute the problem-solving logic.
        out.close(); // Closing the PrintWriter to flush the output and free resources.
    }

    // Main method: This is the entry point of the program.

    static class AStationAndBus {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next(); // Reading the input string from the Scanner.
            if (s.contains("A") && s.contains("B")) { // Checking if the string contains both 'A' and 'B'.
                out.println("Yes"); // Printing "Yes" if the condition is true.
            } else {
                out.println("No"); // Printing "No" if the condition is false.
            }
        }

        // AStationAndBus class: This class contains the logic for solving the problem.
        // solve method: This method is where the main logic of the problem is implemented.
    }
}

