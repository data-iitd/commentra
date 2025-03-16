import java.util.Scanner;

public class Main {
    // Initialize a new scanner for reading input from stdin
    private static Scanner sc = new Scanner(System.in);

    // Function to read an integer as input
    private static int scanInt() {
        return Integer.parseInt(scanString()); // Convert the string to integer and return
    }

    // Function to read a string as input
    private static String scanString() {
        return sc.next(); // Read the next token as a string and return
    }

    // Main function to execute the program
    public static void main(String[] args) {
        // Read the first three integers as input
        int r = scanInt();
        int D = scanInt();
        int x = scanInt();

        // Iterate through a loop 10 times
        for (int i = 1; i <= 10; i++) {
            // Calculate the new value of x using the given formula
            x = r * x - D;

            // Print the value of x to the console
            System.out.println(x);
        }
    }
}

// <END-OF-CODE>
