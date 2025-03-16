import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int a; // Declare a variable 'a' of type int to store user input
        a = scanner.nextInt(); // Read an integer value from standard input and store it in 'a'

        // Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
        System.out.println(3 * a * a); // Print the calculated area to the standard output

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
