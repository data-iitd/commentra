
import java.util.Scanner;

public class Main {
    // This is the entry point of our Java application
    public static void main(String[] args) {
        // Create a new Scanner object to read input from the standard input stream (System.in)
        Scanner sc = new Scanner(System.in);

        // Declare and initialize three integer variables: x, y, and z
        int x, y, z;

        // Read the first integer value (x) from the user input using the Scanner object
        x = sc.nextInt();

        // Read the second integer value (y) from the user input using the Scanner object
        y = sc.nextInt();

        // Read the third integer value (z) from the user input using the Scanner object
        z = sc.nextInt();

        // Print the values of z, x, and y in the order they were read from the user, separated by a space
        System.out.println(z + " " + x + " " + y);

        // Close the Scanner object to release the system resources
        sc.close();
    }
}