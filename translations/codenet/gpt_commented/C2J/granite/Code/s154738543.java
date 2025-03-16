
import java.util.Scanner;

public class s154738543{
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the user and store it in variable x
        x = scanner.nextInt();

        // Calculate the cube of x and store the result in variable y
        y = x * x * x;

        // Print the result (the cube of x) to the console
        System.out.println(y);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
// 