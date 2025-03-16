import java.util.Scanner;
// Import the Scanner class for reading input

public class Main {
    // Define the Main class

    public static void main(String[] args) {
        // Main method is the entry point of the program
        int x;
        // Declare an integer variable x

        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input

        x = scanner.nextInt();
        // Read an integer value from the standard input and store it in variable x

        System.out.println(x * x * x);
        // Print the result of x cubed to the standard output

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// End of the Main class
