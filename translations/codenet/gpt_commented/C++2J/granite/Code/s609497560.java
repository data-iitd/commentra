
import java.util.Scanner; // Import the Scanner class from the java.util package to read user input

public class s609497560{ // Define a class named 's609497560' to encapsulate the program logic
    public static void main(String[] args) { // Define the main method as the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input from the console

        int a = scanner.nextInt(); // Read an integer value from the user and store it in 'a'

        // Calculate the expression a + a^2 + a^3 and output the result
        System.out.println(a + (a * a) + (a * a * a));

        scanner.close(); // Close the Scanner object to release system resources
    }
}
