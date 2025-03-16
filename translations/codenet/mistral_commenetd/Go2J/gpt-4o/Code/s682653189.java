import java.util.Scanner;

public class Main {
    // The main method is the entry point of the program.
    public static void main(String[] args) {
        // Initialize a variable "s" of type String.
        String s;

        // Create a Scanner object to read input from the standard input (usually the keyboard).
        Scanner scanner = new Scanner(System.in);

        // Read a single string from the standard input and store it in the variable "s".
        s = scanner.nextLine();

        // Iterate through each character in the string "s" using a for loop.
        for (int i = 0; i < s.length(); i++) {
            // Print "x" for each character in the string "s".
            System.out.print("x");
        }

        // Print a newline character to the standard output.
        System.out.println();

        // Close the scanner to prevent resource leaks.
        scanner.close();
    }
}

// <END-OF-CODE>
