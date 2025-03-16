import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b, c; // Declare and initialize three integer variables

        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the values of a, b, and c from the standard input using scanner
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        if (a + b >= c) { // Check if the sum of a and b is greater than or equal to c
            System.out.println("Yes"); // If the condition is true, print "Yes"
        } else {
            System.out.println("No"); // If the condition is false, print "No"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
