import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int i, j, k, n;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the value of n
        System.out.print("Enter the value of n: ");
        n = scanner.nextInt(); // Read an integer value from the user and store it in variable n

        // Calculate and print the result
        System.out.println("The result is: " + (24 + (24 - n)));

        // Close the Scanner object
        scanner.close();
    }
}
