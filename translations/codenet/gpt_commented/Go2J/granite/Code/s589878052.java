
import java.util.Scanner; // Importing the Scanner class for reading input values

public class s589878052{
    public static void main(String[] args) {
        // Declare variables to hold the lengths of the two bases and the height
        int a, b, h;

        // Create a Scanner object to read input values from the user
        Scanner scanner = new Scanner(System.in);

        // Read input values for the two bases (a and b) and the height (h) from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Close the Scanner object to release system resources
        scanner.close();

        // Calculate the area of the trapezoid using the formula: Area = (a + b) * h / 2
        // and print the result to the console
        System.out.println((a + b) * h / 2);
    }
}
