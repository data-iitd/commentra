
// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class s344381425{
    public static void main(String[] args) {
        // Create a new instance of the Scanner class to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declare and initialize three integer variables "a", "b", and "c"
        // with values read from the standard input using the nextInt method of the Scanner class
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the condition "a < b && b < c" is true using an if statement
        if (a < b && b < c) {
            // If the condition is true, print the string "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the string "No" to the standard output
            System.out.println("No");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}

// End of code