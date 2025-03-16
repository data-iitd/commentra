

import java.util.Scanner;

public class s969060017{
    public static void main(String[] args) {
        // Declare two integer variables 'a' and 'b'
        int a, b;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integer values from the user input using scanner.nextInt()
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Check if 'b' is divisible by 'a' using if statement
        if (b % a == 0) {
            // If 'b' is divisible by 'a', print the sum of 'a' and 'b'
            System.out.println(a + b);
        } else {
            // If 'b' is not divisible by 'a', print the difference between 'b' and 'a'
            System.out.println(b - a);
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
