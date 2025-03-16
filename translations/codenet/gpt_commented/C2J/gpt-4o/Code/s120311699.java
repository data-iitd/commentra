import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read three integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the first number is less than the second and the second is less than the third
        if (a < b && b < c) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
