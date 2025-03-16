import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values
        int a, b, c, x, y;

        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Read five integer values from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Double the value of c
        c *= 2;

        // Check if the sum of a and b is less than or equal to c
        if (a + b <= c) {
            // If true, calculate and print the total cost using x and y
            System.out.println(a * x + b * y);
        } else {
            // If the sum of a and b is greater than c, check the value of x against y
            if (x <= y) {
                // If x is less than or equal to y, check if b is less than or equal to c
                if (b <= c) {
                    // If true, calculate and print the total cost considering c and the remaining b
                    System.out.println(c * x + (y - x) * b);
                } else {
                    // If b is greater than c, print the total cost using c and y
                    System.out.println(c * y);
                }
            } else {
                // If x is greater than y, check if a is less than or equal to c
                if (a <= c) {
                    // If true, calculate and print the total cost considering c and the remaining a
                    System.out.println(c * y + (x - y) * a);
                } else {
                    // If a is greater than c, print the total cost using c and x
                    System.out.println(c * x);
                }
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
