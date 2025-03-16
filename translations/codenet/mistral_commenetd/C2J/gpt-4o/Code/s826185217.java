import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c, d; // Declare four integer variables

        a = scanner.nextInt(); // Read the first integer
        b = scanner.nextInt(); // Read the second integer
        c = scanner.nextInt(); // Read the third integer
        d = scanner.nextInt(); // Read the fourth integer

        if (a + b > c + d) { // Check if the sum of a and b is greater than the sum of c and d
            System.out.println("Left"); // If true, print "Left"
        } else if (a + b < c + d) { // Check if the sum of a and b is less than the sum of c and d
            System.out.println("Right"); // If true, print "Right"
        } else { // If neither of the above conditions is true
            System.out.println("Balanced"); // Print "Balanced"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
