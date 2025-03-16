import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the range (a, b) and the number (c)
        int a, b, c, count = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read three integers from user input: a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Loop through each integer i from a to b (inclusive)
        for (int i = a; i <= b; i++) {
            // Check if c is divisible by i
            if (c % i == 0) {
                // If divisible, increment the count
                count++;
            }
        }

        // Print the total count of numbers that divide c
        System.out.println(count);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
