
import java.util.Scanner;

public class s201325376{
    public static void main(String[] args) {
        // Declare variables to hold the range (a, b) and the number (c)
        int a, b, c, i, count;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read three integers from user input: a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Initialize count to zero to keep track of how many numbers in the range divide c
        count = 0;

        // Loop through each integer i from a to b (inclusive)
        for (i = a; i <= b; i++) {
            // Check if c is divisible by i
            if (c % i == 0)
                // If divisible, increment the count
                count++;
        }

        // Print the total count of numbers that divide c
        System.out.println(count);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
