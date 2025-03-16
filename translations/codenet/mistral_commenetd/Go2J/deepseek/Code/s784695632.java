import java.util.Scanner; // Import the Scanner class for reading input.

public class Main {
    public static void main(String[] args) {
        // Define the main method as the entry point of our program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input.
        int x = scanner.nextInt(); // Read the value of variable "x" from the standard input.
        int y = scanner.nextInt(); // Read the value of variable "y" from the standard input.

        // Print the result of the expression "x + y/2" to the standard output.
        System.out.println(x + y / 2);

        // End of code.
    }
}
