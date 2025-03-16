import java.util.Scanner;
// Import the Scanner class from the java.util package to read input from the standard input stream

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Create a new Scanner object to read input from the standard input stream

        int n = scanner.nextInt();
        // Use the nextInt() method of the Scanner object to read the first integer (n) from the standard input stream

        int k = scanner.nextInt();
        // Use the nextInt() method of the Scanner object to read the second integer (k) from the standard input stream

        int x = n / k;
        // Calculate the integer division of n by k and assign the result to the variable x

        int y = n % k;
        // Calculate the remainder of n divided by k and assign the result to the variable y

        int z;
        // Declare the variable z

        if (y != 0) {
            z = x + 1 - x;
            // If the remainder y is non-zero, assign the value 1 to the variable z
        } else {
            z = x - x;
            // If the remainder y is zero, assign the value 0 to the variable z
        }

        System.out.println(z);
        // Use the System.out.println() method to print the value of z to the standard output stream

        scanner.close();
        // Close the Scanner object to free up resources
    }
}
