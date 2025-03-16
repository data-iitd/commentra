import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include necessary imports
        // The code starts by importing the Scanner class for input operations.

        // Declare arrays
        // Two arrays, `train` and `bus`, are declared to store the values.
        int[] train = new int[2];
        int[] bus = new int[2];

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Input values
        // The values for `train` and `bus` are taken from the user.
        train[0] = scanner.nextInt();
        train[1] = scanner.nextInt();
        bus[0] = scanner.nextInt();
        bus[1] = scanner.nextInt();

        // Calculate the sum
        // The code then calculates the sum of the minimum values from both arrays.
        int result = Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]);

        // Output the result
        System.out.println(result);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
