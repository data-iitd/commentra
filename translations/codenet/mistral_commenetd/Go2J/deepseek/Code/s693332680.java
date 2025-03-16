// Importing necessary packages
import java.util.Scanner;

// Declaring class
public class Main {

    // Main method
    public static void main(String[] args) {
        // Creating a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declaring variables
        int x, a, b;

        // Reading input values from standard input
        x = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Logic block to check if b is less than or equal to a
        if (b - a <= 0) {
            System.out.println("delicious");
        } else if (b - a <= x) {
            System.out.println("safe");
        } else {
            System.out.println("dangerous");
        }
    }
}

// End-Of-Code
