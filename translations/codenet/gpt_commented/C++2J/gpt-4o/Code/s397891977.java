import java.util.Scanner; // Import the Scanner class for user input

public class CircleArea {
    public static void main(String[] args) {
        int r; // Declare an integer variable 'r' to store the radius

        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the radius value from user input
        r = scanner.nextInt();

        // Calculate the area of the circle using the formula πr²
        // Here, we are using the simplified version by omitting π for demonstration
        System.out.println(r * r); // Output the calculated area (r squared)

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
