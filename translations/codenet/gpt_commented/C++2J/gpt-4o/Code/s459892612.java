import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold input values
        int a, b, c;

        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read three integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the sum of a and b is greater than or equal to c
        if (a + b >= c) {
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
