import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x = 0, y = 0;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the user and store them in variables x and y respectively
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Print the product of x and y and the sum of 2 times x and 2 times y
        System.out.printf("%d %d\n", x * y, (2 * x) + (2 * y));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
