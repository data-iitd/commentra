import java.util.Scanner;
// Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        int n, k, x, y, z;
        // Declare five integer variables: n, k, x, y, and z

        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input

        n = scanner.nextInt();
        // Read the first integer (n) from the standard input

        k = scanner.nextInt();
        // Read the second integer (k) from the standard input

        x = n / k;
        // Calculate the integer division of n by k and assign the result to the variable x

        y = n % k;
        // Calculate the remainder of n divided by k and assign the result to the variable y

        if (y != 0) {
            z = x + 1 - x;
            // If the remainder y is non-zero, assign the value 1 to the variable z
        } else {
            z = x - x;
            // If the remainder y is zero, assign the value 0 to the variable z
        }

        System.out.println(z);
        // Print the value of z to the standard output

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// End of the Main class
