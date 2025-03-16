
import java.util.Scanner;

public class s235028939{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from standard input
        // n represents the number of rows, and m represents the number of columns
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Calculate the product of (n - 1) and (m - 1)
        // This represents the number of internal edges in a grid of n by m cells
        int result = (n - 1) * (m - 1);

        // Print the result to the console
        System.out.println(result);

        // Flush the output buffer to ensure all output is printed
        System.out.flush();
    }
}
