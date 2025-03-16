import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and a
        int x, a;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integer values from user input and store them in x and a
        x = scanner.nextInt();
        a = scanner.nextInt();

        // Check if x is greater than or equal to a
        // If true, print 10; otherwise, print 0
        System.out.println((x >= a) ? 10 : 0);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
