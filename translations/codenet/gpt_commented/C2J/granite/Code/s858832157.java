
import java.util.Scanner;

public class s858832157{
    public static void main(String[] args) {
        // Initialize a counter variable 'i' to track the case number and a Scanner object to read user input
        int i = 1;
        Scanner scanner = new Scanner(System.in);

        // Start an infinite loop to continuously accept user input
        while (true) {
            // Read an integer input from the user
            int input = scanner.nextInt();

            // Check if the input is zero, which indicates the end of input
            if (input == 0) {
                // Exit the loop if the input is zero
                break;
            }

            // Print the case number and the input value
            System.out.printf("Case %d: %d%n", i, input);

            // Increment the case number for the next iteration
            i++;
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
