
// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class s178339312{
    public static void main(String[] args) {
        // Create a new instance of the Scanner class to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declare a variable named x of type int
        int x;

        // Read an integer value from the standard input and assign it to the variable x
        x = scanner.nextInt();

        // Print the result of x cubed (x*x*x)
        System.out.println(x * x * x);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}

// End of code