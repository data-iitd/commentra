import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object

        // Read two integer values from the standard input using the Scanner object
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Calculate the difference between `6` and the sum of `a` and `b`
        int result = 6 - a - b;

        // Print the result to the standard output using System.out.println
        System.out.println(result);
    }
}
