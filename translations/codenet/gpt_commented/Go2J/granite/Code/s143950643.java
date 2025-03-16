
import java.util.Scanner; // Importing the Scanner class for reading user input

public class s143950643{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        int a = scanner.nextInt(); // Read an integer value from standard input and store it in 'a'

        // Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
        int area = 3 * a * a; // Calculate the area and store it in a variable 'area'

        System.out.println(area); // Print the calculated area to the standard output
    }
}
