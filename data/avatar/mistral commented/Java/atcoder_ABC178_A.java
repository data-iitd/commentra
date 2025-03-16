// Importing necessary Java libraries for this program
import java.util.Scanner;  // For user input
import java.io.PrintWriter; // For outputting results

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        // Creating a new Scanner object to read user input from the standard input
        Scanner scan = new Scanner(System.in);

        // Reading an integer value from the user input
        int x = Integer.parseInt(scan.next());

        // Determining a boolean value based on the condition x equals to 1
        boolean bool = x == 1 ? true : false;

        // Calculating the result based on the boolean value
        int result = !bool ? 1 : 0;

        // Creating a new PrintWriter object to write the output to the standard output
        PrintWriter out = new PrintWriter(System.out);

        // Writing the result to the standard output
        out.println(result);

        // Flushing the PrintWriter buffer to ensure the output is written immediately
        out.flush();

        // Closing the Scanner object to release system resources
        scan.close();
    }
}
