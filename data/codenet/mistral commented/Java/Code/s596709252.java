
import java.util.*; // Importing the Utilities Package for Scanner Class

public class Main {

    public static void main(String[] args) {
        // Main method is the entry point of the Java program

        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object to read input from the user

        int x, y, z; // Declaring and initializing three integer variables

        // Reading user input for variables x, y, and z
        x = scanner.nextInt();
        y = scanner.nextInt();
        z = scanner.nextInt();

        // Closing the Scanner object to release system resources
        scanner.close();

        // Printing the values of z, x, and y in the order they were read from the user input
        System.out.println(z + " " + x + " " + y);
    }
}